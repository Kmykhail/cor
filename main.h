/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:05:14 by kshyshki          #+#    #+#             */
/*   Updated: 2018/04/18 12:05:16 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "op.h"
# include "stdlib.h"
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "function.h"
# include <fcntl.h>

# define TOTAL_SIZE PROG_NAME_LENGTH + COMMENT_LENGTH
# define STEP main->steper
# define ITR main->var_crap->itr
# define FD main->ddddd
# define FD2 main.ddddd

typedef struct			s_process
{
	uint8_t 			rg[16][4];
	int 				cmd_cycle;
	int 				pc;//счеткик
	int					index;//индех элемнта на (в) карте игрока
	unsigned char		nbr_pl;//кто порадил (player#) ff fe fd 
	unsigned int		live;//инкремент
	int 				carry;
	struct s_process	*next;
}						t_process;

typedef struct			s_changes // все измениня кидаю в голову (push head)
{
	int					start;// стартовый индекс на карте выгрузки
	int					finish; // конечный индекс-----//---------
	unsigned int		cycle_init;//цикл на котором произошла выгрузка
//	t_process			*process;// какой процес//????
	unsigned char		nbr_pl;
	//КОРОЧЕ НЕ БУДЕТ УКАЗАТЕЛЯ НА ПРОЦЕСС, А БУДЕТ ПЕРЕМЕННАЯ В КОТОРОЙ БУДЕТ ХРАНИТЬСЯ НОМЕР (nNBR_LIVE), просто копируй
	struct s_changes	*next;
}						t_changes;

typedef struct			s_player
{
	int					cnt_bot;
	int 				bot_name;
	int 				comm;
	unsigned char		nbr_pl;// номер игрока
	char 				player_name[PROG_NAME_LENGTH + 1];
	char 				comment[COMMENT_LENGTH + 1];
	unsigned int		ll_cycle;//last live
	unsigned int		live_cur_per;// обну/лили  переменную z
	unsigned int		live_last_per;// переде переменной z обнулением закинули сюда
}						t_player;

typedef	struct			s_crap
{
	int					itr;
}						t_crap;	

typedef struct			s_main
{
	int 				cmd_cycle;
	int 				tmp_fork;
	int 				steper;//в нем храниться 
	int 				label[16][4];// таблица
	int					code_codage[3];// ????? 
	uint8_t 			arg[3];
    unsigned int 		ready_arg[3][2];//
	int 				coor_of_p[4];
	char				*filename[5];
	unsigned char		map[MEM_SIZE];//
	t_player			*players[MAX_PLAYERS];
	unsigned char		cnt_pl;//количество игроков
	unsigned int		cur_cycle;//вызвал меня ++
	unsigned int		cl_to_die;//вместо константы cycle_to die
	t_process			*lst_proc;
	unsigned int		nbr_proc;//number process
	t_changes			*lst_changes;//изменения внести в список
	t_player			*last_live_player;
	t_crap				*var_crap;
	int 				finish;//конец игры, finish = 1
	int 				ddddd;

}						t_main;

void					init_players(t_main *main, int indx);
int						make_cycle(t_main *main);//kmykhail
int						ft_print_error(int code);//kmykhail
void					ft_table_label(t_main *main);//kmykhail
void					valid_bots(t_main *main, int ac, char **av);//kmykhail
void					check_codage(t_main *main, uint8_t num);//kmykhail
void					init_vizual(t_main *main, int start, int end);//kmykhail
void					lst_newchanges(t_main *main, t_process *proc, int i, int fin, int ch);
t_process				*lst_newproc(t_main *main, int pl_indx);
/*
** FUNCTION 
*/




int				is_has_arg(unsigned char arg);
void    		ft_implement_command(t_main *main, t_process *proc);
void		    ready_arg(t_main *main, t_process *proc);
int     		ft_step_pc(t_main *main, int num, t_process *proc);

void			fun_live(t_main *main, t_process *proc);
void			fun_ld(t_main *main, t_process *proc);
void			fun_st(t_main *main, t_process *proc);
void			fun_add(t_main *main, t_process *proc);
void			fun_sub(t_main *main, t_process *proc);
void			fun_and(t_main *main, t_process *proc);
void			fun_or(t_main *main, t_process *proc);
void			fun_xor(t_main *main, t_process *proc);
void			fun_zjmp(t_main *main, t_process *proc);
void			fun_ldi(t_main *main, t_process *proc);
void			fun_sti(t_main *main, t_process *proc);
void			fun_fork(t_main *main, t_process *proc);
void			fun_lld(t_main *main, t_process *proc);
void			fun_lldi(t_main *main, t_process *proc);
void			fun_lfork(t_main *main, t_process *proc);
void			fun_aff(t_main *main, t_process *proc);






/*
 **				PART OF TEST FUNCTION (ALL DEL)
 */
void			test_open(t_main *main);
void		    test_show_me_label_arg(t_main *main, t_process *proc);
void    		test_show_part_of_map(t_main *main, t_process *proc);
#endif
