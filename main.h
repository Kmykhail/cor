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
// # define EXEC_CODE 	main->exec_code
# define BUFFSIZE		1
# define U_INT 		4294967282
# define ERROR 		main->error
# define PC_INDEX	head->index
# define STEP 		main->steper
# define FD 		main->ddddd
# define FD4 		main->fffff
# define _USAGE 	0
# define NO_READ_FILE 1
# define BOT_NAME 2
# define COMM 3
# define MAGIC 4
# define INVALID_COMMAND 6
# define EXEC_CODE_NULL 7
# define SIZE_DIFFER 8
# define TOO_MANY 9
/*
typedef struct			s_process
{
	uint8_t 			rg[16][4];
	int 				cmd_cycle;
	int 				pc;//счеткик
	int					index;//индех элемнта на (в) карте игрока
	unsigned char		nbr_pl;//кто порадил (player#) ff fe fd 
	unsigned int		live;//инкремент
	int 				carry;
	int 				itr;
	struct s_process	*next;
}						t_process;
*/
typedef struct			s_process
{
	int					rg[16];
	int 				cmd_cycle;
	int 				pc;//счеткик
	int					index;//индех элемнта на (в) карте игрока
	unsigned char		nbr_pl;//кто порадил (player#) ff fe fd 
	unsigned int		live;//инкремент
	int 				carry;
	int 				id;
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
	unsigned char		nbr_pl;// номер игрока
	char 				player_name[PROG_NAME_LENGTH + 1];
	char 				comment[COMMENT_LENGTH + 1];
	unsigned int		ll_cycle;//last live
	unsigned int		live_cur_per;// обну/лили  переменную z
	unsigned int		live_last_per;// переде переменной z обнулением закинули сюда
	int					exec_code;
}						t_player;

typedef struct			s_main
{
	int 				id;
	int					steper;//в нем храниться 
	unsigned int		cp_cl_to_die;
	int 				label[16][4];// таблица
	uint8_t 			arg[3];
	short int 			ready_arg[3][2];//
	int 				coor_of_p[4];//стартовые индексы для каждого игрока
	char				*filename[5];
	unsigned char		map[MEM_SIZE];//
	t_player			*players[MAX_PLAYERS];
	unsigned char		cnt_pl;//количество игроков
	unsigned int		cur_cycle;//вызвал меня ++
	unsigned int		cl_to_die;//вместо константы cycle_to die
	unsigned int		mx_check;
	t_process			*lst_proc;
	unsigned int		nbr_proc;//number process
	t_changes			*lst_changes;//изменения внести в список
	t_player			*last_live_player;
	int 				finish;//конец игры, finish = 1
	int 				error;
	int 				ddddd;
	int 				fffff;
}						t_main;

void					init_players(t_main *main, int indx);
int						make_cycle(t_main *main);//kmykhail
int						print_error(int code, char *value, int *res);//kmykhail
void					ft_table_label(t_main *main);//kmykhail
int						valid_bots(t_main *main, int ac, char **av);//kmykhail
void					check_codage(t_main *main, uint8_t num);//kmykhail
void					init_vizual(t_main *main, int start, int end);//kmykhail
void					lst_newchanges(t_main *main, t_process *proc, int i, int fin, int ch);
int 					is_numeric(char *s);
void					free_struct(t_main *main);
void					free_changes(t_main *main);
void					copy_changes(t_main *main);
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
void	 		show_ld(t_main *main, t_process *proc);
void		    test_show_me_label_arg(t_main *main, t_process *proc);
void    		test_show_part_of_map(t_main *main, t_process *proc);
#endif
