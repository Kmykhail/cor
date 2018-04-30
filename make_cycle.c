//
// Created by Kostiantyn MYKHAILENKO on 4/26/18.
//
# include "main.h"

int     make_cycle(t_main *main)
{
    //while (1)
    //{
    // dprintf(FD, "4423432\n\n\n\n");

        // main->cur_cycle++;
        //main->lst_proc->index++;

        //main->cur_cycle++;
        dprintf(FD, "\nmain->lst_proc->nbr_pl:%d\n", main->lst_proc->nbr_pl);
    	//dprintf(FD, "QQQ:%d", main->lst_changes->cycle_init);
        if (main->map[main->pc] >= 16)
    		ft_print_error(5);
    	if (main->map[main->pc] != 1 &&  main->map[main->pc] != 8 && main->map[main->pc] != 12 && main->map[main->pc] != 15 && main->map[main->pc] != 16)
    	{
           	check_map(main, main->map[main->pc + 1]);

	        ft_implement_command(main);

	        STEP += ft_step_pc(main, main->map[main->pc]);

	        main->pc++;
            ITR++;
		}
		else
		{
			ft_implement_command(main);
            STEP = main->label[main->pc][3];
            main->pc += STEP;
		}
        // ITR = 0;
        dprintf(FD, "ITR = %d\n", ITR);
        if (ITR == 2)
        {
             dprintf(FD, "RETURN 0\n");
            return (0);
        }
        dprintf(FD, "RETURN 1\n");
    //}
        // exit(1);
    (ITR) ? (init_vizual(main, 0, 0)) : 0;
    return (1);
}