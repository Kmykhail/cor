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
	int					index;//индех элемнта на (в) карте игрока
	unsigned char		nbr_pl;//кто порадил (player#) ff fe fd 
	unsigned int		live;//инкремент
	struct s_process	*next;
}						t_process;

typedef struct			s_changes // все измениня кидаю в голову (push head)
{
	int					start;// стартовый индекс на карте выгрузки
	int					finish; // конечный индекс-----//---------
	unsigned int		cycle_init;//цикл на котором произошла выгрузка
	t_process			*process;// какой процес
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
	int 				pc;//счеткик
	int 				label[16][4];// таблица
	int 				steper;//в нем храниться 
	int					code_codage[3];// ????? 
	uint8_t 			arg[3];
    int 				ready_arg[3][2];//
	uint8_t 			rg[16][4];			
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

int						make_cycle(t_main *main);//kmykhail
int						ft_print_error(int code);//kmykhail
void					ft_table_label(t_main *main);//kmykhail
void					valid_bots(t_main *main, int ac, char **av);//kmykhail
void					check_map(t_main *main, uint8_t num);//kmykhail
void					init_vizual(t_main *main, int start, int end);//kmykhail



/*
** FUNCTION 
*/




int				is_has_arg(unsigned char arg);
void			choose_function_1(t_main *main);
void			choose_function_2(t_main *main);
void			ft_implement_command(t_main *main);
void			ready_arg(t_main *main);
int     		ft_step_pc(t_main *main, int num);

/*
 void	fun_live()
 */
void			fun_ld(t_main *main);
void			fun_st(t_main *main);
void			fun_add(t_main *main);
void			fun_sub(t_main *main);
void			fun_and(t_main *main);
void			fun_or(t_main *main);
void			fun_xor(t_main *main);
void			fun_zjmp(t_main *main);
void			fun_ldi(t_main *main);
void			fun_sti(t_main *main);
/*
 void	fun_fork()
 */
void			fun_lld(t_main *main);
void			fun_lldi(t_main *main);
/*
 void	fun_lfork()
 */
void			fun_aff(t_main *main);






/*
 **				PART OF TEST FUNCTION (ALL DEL)
 */
void			test_open(t_main *main);
void			test_show_me_label_arg(t_main *main);
#endif
