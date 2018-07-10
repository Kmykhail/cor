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
# include "../lib/libft.h"
# include "../lib/ft_printf.h"
# include <fcntl.h>

# define TOTAL_SIZE PROG_NAME_LENGTH + COMMENT_LENGTH
# define _USAGE 	0
# define NO_READ_FILE 1
# define BOT_NAME 2
# define COMM 3
# define MAGIC 4
# define INVALID_COMMAND 6
# define EXEC_CODE_NULL 7
# define SIZE_DIFFER 8
# define TOO_MANY 9
# define STPC ft_step_pc(m, m->map[p->index % MEM_SIZE])
# define LC live_cur_per(main->lst_proc, main->players[i]->nbr_pl)
# define PRINT_ERROR print_error(_USAGE, NULL, &res)
# define CMP ft_strcmp
# define MAP_BYTE main->map[main->lst_proc->index]
# define U_INT 		4294967282
# define ERROR 		main->error
# define PC_INDEX	head->index
# define LOOK_NAME (cnt >= PROG_NAME_LENGTH + 12 && cnt < 2188 && !ERROR)
# define MS (4*1024)
# define XM (2*256)

typedef struct			s_process
{
	int					id;
	int					rg[16];
	int					cmd_cycle;
	int					pc;
	int					index;
	unsigned char		nbr_pl;
	unsigned int		live;
	unsigned int		s_live;
	int					carry;
	struct s_process	*next;
}						t_process;

typedef struct			s_changes
{
	int					start;
	int					finish;
	unsigned int		cycle_init;
	unsigned char		nbr_pl;
	struct s_changes	*next;
}						t_changes;

typedef struct			s_player
{
	int					cnt_bot;
	unsigned char		nbr_pl;
	char				player_name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	unsigned int		ll_cycle;
	unsigned int		live_cur_per;
	unsigned int		live_last_per;
	int					exec_code;
}						t_player;

typedef struct			s_main
{
	int					count_id;
	int					itr;
	int					ch;
	unsigned int		cp_cur_cycle;
	unsigned int		cp_cl_to_die;
	int					label[16][4];
	uint8_t				arg[3];
	int					coor_of_p[4];
	char				*filename[5];
	unsigned char		map[MEM_SIZE];
	t_player			*players[MAX_PLAYERS + 1];
	unsigned char		cnt_pl;
	unsigned int		cur_cycle;
	unsigned int		cl_to_die;
	unsigned int		mx_check;
	t_process			*lst_proc;
	unsigned int		nbr_proc;
	t_changes			*lst_changes;
	t_player			*last_live_player;
	int					finish;
	int					error;
}						t_main;

void					init_players(t_main *main, int indx);
int						is_numeric(char *s);
int						make_cycle(t_main *main);
int						make_cycle_second(t_main *m, t_process **proc);
int						print_error(int code, char *value, int *res);
void					print_dump(t_main *main, int man_cycle);
void					print_champion(t_main *main);
void					ft_table_label(t_main *main);
void					read_bots(t_main *main, t_player *pl, int i, int fd);
void					check_codage(t_main *main, uint8_t num);
void					init_vizual(t_main *main, int start, int end);
void					lst_newchanges(t_main *m, t_process *p, int i, int f);
int						is_numeric(char *s);
void					free_struct(t_main *main);
void					free_changes(t_main *main);
void					copy_changes(t_main *main);
void					find_idex_to_start(t_main *main);
t_process				*lst_newproc(t_main *main, int pl_indx);

int						is_has_arg(unsigned char arg);
void					ft_implement_command(t_main *main, t_process *proc);
void					ready_arg(t_main *main, t_process *proc);
int						ft_step_pc(t_main *main, int num);
void					fun_live(t_main *main, t_process *proc);
void					fun_ld(t_main *main, t_process *proc);
void					fun_st(t_main *main, t_process *proc);
void					fun_add(t_main *main, t_process *proc);
void					fun_sub(t_main *main, t_process *proc);
void					fun_and(t_main *main, t_process *proc);
void					fun_or(t_main *main, t_process *proc);
void					fun_xor(t_main *main, t_process *proc);
void					fun_zjmp(t_main *main, t_process *proc);
void					fun_ldi(t_main *main, t_process *proc);
void					fun_sti(t_main *main, t_process *proc);
void					fun_fork(t_main *main, t_process *proc);
void					fun_lld(t_main *main, t_process *proc);
void					fun_lldi(t_main *main, t_process *proc);
void					fun_lfork(t_main *main, t_process *proc);
void					fun_aff(t_main *main, t_process *proc);
void					unvalid_only_step(t_main *main, t_process *proc);
void					fun_and_reg_reg(t_main *m, t_process *p);
void					fun_and_reg_dir(t_main *m, t_process *p);
void					fun_and_reg_ind(t_main *m, t_process *p);
void					fun_and_dir_reg(t_main *m, t_process *p);
void					fun_and_dir_dir(t_main *m, t_process *p);
void					fun_and_dir_ind(t_main *m, t_process *p);
void					fun_and_ind_reg(t_main *m, t_process *p);
void					fun_and_ind_dir(t_main *m, t_process *p);
void					fun_and_ind_ind(t_main *m, t_process *p);
void					fun_or_reg_reg(t_main *m, t_process *p);
void					fun_or_reg_dir(t_main *m, t_process *p);
void					fun_or_reg_ind(t_main *m, t_process *p);
void					fun_or_dir_reg(t_main *m, t_process *p);
void					fun_or_dir_dir(t_main *m, t_process *p);
void					fun_or_dir_ind(t_main *m, t_process *p);
void					fun_or_ind_reg(t_main *m, t_process *p);
void					fun_or_ind_dir(t_main *m, t_process *p);
void					fun_or_ind_ind(t_main *m, t_process *p);
void					fun_xor_reg_reg(t_main *m, t_process *p);
void					fun_xor_reg_dir(t_main *m, t_process *p);
void					fun_xor_reg_ind(t_main *m, t_process *p);
void					fun_xor_dir_reg(t_main *m, t_process *p);
void					fun_xor_dir_dir(t_main *m, t_process *p);
void					fun_xor_dir_ind(t_main *m, t_process *p);
void					fun_xor_ind_reg(t_main *m, t_process *p);
void					fun_xor_ind_dir(t_main *m, t_process *p);
void					fun_xor_ind_ind(t_main *m, t_process *p);
void					fun_ldi_reg_reg(t_main *m, t_process *p);
void					fun_ldi_reg_dir(t_main *m, t_process *p);
void					fun_ldi_dir_reg(t_main *m, t_process *p);
void					fun_ldi_dir_dir(t_main *m, t_process *p);
void					fun_lldi_reg_reg(t_main *m, t_process *p);
void					fun_lldi_reg_dir(t_main *m, t_process *p);
void					fun_lldi_dir_reg(t_main *m, t_process *p);
void					fun_lldi_dir_dir(t_main *m, t_process *p);
void					fun_sti_dir_reg(t_main *m, t_process *p);
void					fun_sti_ind_reg(t_main *m, t_process *p);
void					fun_sti_dir_dir(t_main *m, t_process *p);
void					fun_sti_ind_dir(t_main *m, t_process *p);
#endif
