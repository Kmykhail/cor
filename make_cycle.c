//
// Created by Kostiantyn MYKHAILENKO on 4/26/18.
//
# include "main.h"

/*
int    make_cycle_second(t_main *main, t_process **proc)
{
	t_process *head;

	while (1) //1/2
	{
		head = *proc;
		dprintf(FD, "OUT\n");
		while (head)
		{
			dprintf(FD, "IN\n");
			dprintf(FD, "head->pc = %d\n", head->pc);
			dprintf(FD, "main->map[head->pc] = %d\n", main->map[head->pc]);
			if (main->map[head->pc] >= 16)
			{
				dprintf(FD, "GOOD 1\n");
				ft_print_error(5);
			}
			if (main->map[head->pc] != 1 &&  main->map[head->pc] != 8 && main->map[head->pc] != 12 \
			&& main->map[head->pc] != 15 && main->map[head->pc] != 16 && main->cur_cycle % main->label[head->pc][2] == 0 && main->cur_cycle != 0)
			{
				dprintf(FD, "GOOD 2\n");
				check_map(main, main->map[head->pc + 1]);
				ft_implement_command(main, head);
				head->index += ft_step_pc(main, main->map[head->pc], head);//изменить step на indx
				ITR++;
				break ;
			}
			else if (main->cur_cycle % main->label[head->pc][2] == 0 && main->cur_cycle != 0)
			{
				dprintf(FD, "GOOD 3\n");
				ft_implement_command(main, head);
				head->index = main->label[head->pc][3];
				head->pc += head->index;
				break ;
			}
			head = head->next;
		}
		if (main->map[head->pc] == 11 && main->cur_cycle % main->label[head->pc][2] == 0 && main->cur_cycle != 0)
		{
			dprintf(FD, "return 1\n");
			return (1);
		}
		main->cur_cycle++;
		dprintf(FD, "main->cur_cycle++ = %d\n", main->cur_cycle++);
	}
	dprintf(FD, "retrun 0\n");
	return (0);
}
*/

int		make_cycle_second(t_main *main, t_process **proc)
{
	t_process *head;

	while (1)
	{
		while (head)
		{
			/*dprintf(FD, "head %p\n", head);
			dprintf(FD, "head->pc %d\n", head->pc);*/
			if (main->map[head->pc] >= 16)
				ft_print_error(5);
			if (main->map[head->pc] != 1 &&  main->map[head->pc] != 8 && main->map[head->pc] != 12 \
 			&& main->map[head->pc] != 15 && main->map[head->pc] != 16 && main->cur_cycle % main->label[head->pc][2] == 0 && main->cur_cycle != 0)
			{
 				check_map(main, main->map[head->pc + 1]);
 				ft_implement_command(main, head);
 				head->index += ft_step_pc(main, main->map[head->pc], head);//изменить step на indx
 				ITR++;
 				return (1);
			}
			else if (main->cur_cycle % main->label[head->pc][2] == 0 && main->cur_cycle != 0)
			{
				ft_implement_command(main, head);
				head->index = main->label[head->pc][3];
				head->pc += head->index;
				return (1);
			}
			head =  head->next;
			main->cur_cycle++;
		}
	}
	return (0);
}

int     make_cycle(t_main *main)
{
	// t_process     *proc;


	if (make_cycle_second(main, &main->lst_proc))
		return (1);
	else
		return (0);

}
