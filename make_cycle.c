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
			dprintf(FD, "head->index = %d\n", head->index);
			dprintf(FD, "main->map[head->index] = %d\n", main->map[head->index]);
			if (main->map[head->index] >= 16)
			{
				dprintf(FD, "GOOD 1\n");
				ft_print_error(5);
			}
			if (main->map[head->index] != 1 &&  main->map[head->index] != 8 && main->map[head->index] != 12 \
			&& main->map[head->index] != 15 && main->map[head->index] != 16 && main->cur_cycle % main->label[head->index][2] == 0 && main->cur_cycle != 0)
			{
				dprintf(FD, "GOOD 2\n");
				check_map(main, main->map[head->index + 1]);
				ft_implement_command(main, head);
				head->index += ft_step_pc(main, main->map[head->index], head);//изменить step на indx
				ITR++;
				break ;
			}
			else if (main->cur_cycle % main->label[head->index][2] == 0 && main->cur_cycle != 0)
			{
				dprintf(FD, "GOOD 3\n");
				ft_implement_command(main, head);
				head->index = main->label[head->index][3];
				head->index += head->index;
				break ;
			}
			head = head->next;
		}
		if (main->map[head->index] == 11 && main->cur_cycle % main->label[head->index][2] == 0 && main->cur_cycle != 0)
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

int 	make_cycle_second(t_main *main, t_process **proc)
{
	t_process	*head;

	head = *proc;
    dprintf(FD, "//////////////////////////////////////////\n");
	while (head)
	{
		dprintf(FD, "WHAT_COMMAND:%d\n", main->map[head->index]);
		if (main->map[head->index] >= 16)
			ft_print_error(1);
		dprintf(FD, "CHE_TO TAM\n");
		if (main->map[head->index] != 1 && main->map[head->index] != 12 \
		&& main->map[head->index] != 15 && main->map[head->index] != 16)
		{
			dprintf(FD, "COMMAND_A:%d\n", main->map[head->index]);
			check_codage(main, main->map[head->index + 1]);
			ft_implement_command(main, head);
		}
		else if (main->map[head->index] == 1 || main->map[head->index] == 12 \
		|| main->map[head->index] == 15 || main->map[head->index] == 16)
		{
			dprintf(FD, "COMMAND_B:%d\n", main->map[head->index]);
			ft_implement_command(main, head);
            break ;
		}
		else
			return (0);
		head = head->next;
	}
	main->cur_cycle++;
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

