//
// Created by Kostiantyn MYKHAILENKO on 4/26/18.
//
# include "main.h"


void	test_proc(t_main *main, t_process *proc)
{
	dprintf(FD, "YYYYYYYYYYYYYYYYY\n");
	while (proc)
	{
	dprintf(FD, "main->cur_cycle:%d", main->cur_cycle);
	dprintf(FD, "proc->pc:%5d\n", proc->pc);
	dprintf(FD, "proc->index:%5d\n", proc->index);
	dprintf(FD, "proc->nbr_pl:%x\n", proc->nbr_pl);
	dprintf(FD, "proc->live:%x\n", proc->live);
	dprintf(FD, "proc->live:%x\n", proc->live);
	dprintf(FD, "______________________________\n");
		proc = proc->next;
	}
}

int 	make_cycle_second(t_main *main, t_process **proc)
{
	t_process	*head;

	head = *proc;
    main->cur_cycle++;
	while (head)
	{
		if (main->map[head->index] >= 16)
			ft_print_error(1);
		if (main->map[head->index] != 1 && main->map[head->index] != 12 \
		&& main->map[head->index] != 15 && main->map[head->index] != 16)
		{
			check_codage(main, main->map[head->index + 1]);
			ft_implement_command(main, head);
		}
		else if (main->map[head->index] == 1 || main->map[head->index] == 12 \
		|| main->map[head->index] == 15 || main->map[head->index] == 16)
		{
			ft_implement_command(main, head);
			if (main->map[head->index] == 1)
				break ;
		}
		else
			return (0);
		head = head->next;
	}
	return (1);
}

int     make_cycle(t_main *main)
{
	// t_process	*proc;
	if (make_cycle_second(main, &main->lst_proc))
		return (1);
	else
		return (0);
}

