//
// Created by Kostiantyn MYKHAILENKO on 4/26/18.
//
# include "main.h"

int 	make_cycle_second(t_main *main, t_process **proc)
{
	t_process	*head;

	head = *proc;
    main->cur_cycle++;
	while (head)
	{
        dprintf(FD, "MAP @@@@@@@@@@@@@@@@@@@@@@@ main->map[head->index] %x\n", main->map[head->index]);
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

