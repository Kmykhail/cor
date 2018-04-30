//
// Created by Kostiantyn MYKHAILENKO on 4/26/18.
//
# include "main.h"

int     make_cycle(t_main *main)
{
    //while (1)
    //{
        (ITR) ? (init_vizual(main, ITR, 0)) : 0;
    	if (main->map[main->pc] >= 16)
    		ft_print_error(5);
    	if (main->map[main->pc] != 1 &&  main->map[main->pc] != 8 && main->map[main->pc] != 12 && main->map[main->pc] != 15 && main->map[main->pc] != 16)
    	{
            printf("UNOOOO\n");

           	check_map(main, main->map[main->pc]);

	        ft_implement_command(main);

	        STEP += ft_step_pc(main, main->map[main->pc]);

	        main->pc++;
            ITR++;
            printf("MAIN->PC:%d\n", main->pc);
		}
		else
		{
            printf("REDOOOOOOOOO\n");
			ft_implement_command(main);
            STEP = main->label[main->pc][3];
            main->pc += STEP;
            ITR++;
		}
        if (ITR == 2)
            return (0);
    //}
        //printf("STEP!!!!:%d\n", STEP);
        exit(1);
    return (1);
}