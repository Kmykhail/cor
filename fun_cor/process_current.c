/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_current.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:08:41 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 11:08:42 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../main.h"

void     ready_arg(t_main *main, t_process *proc)
{
    int     i;
    int     k;
    int     r;
    short int     num;
	int     test_2;
    
    // часть для значений
    main->ready_arg[0][0] = 0;
    main->ready_arg[1][0] = 0;
    main->ready_arg[2][0] = 0;
    // часть дял T_REG
    main->ready_arg[0][1] = 0;
    main->ready_arg[1][1] = 0;
    main->ready_arg[2][1] = 0;
    
    i = 0;
    k = 1;
    while (i < 3)
    {
        if (main->arg[i] == 1)
        {
            test_show_part_of_map(main, proc);
            num = main->map[proc->index];
            r = 0;
            main->ready_arg[i][1] = main->map[proc->index + 1 + k];
            while (r < 4)
            {
                main->ready_arg[i][0] = main->ready_arg[i][0] << 8;
                test_2 = proc->rg[main->ready_arg[i][1] - 1][r];
                main->ready_arg[i][0] = main->ready_arg[i][0] | test_2;
                r++;
            }
            k++;
        }
        else if (main->arg[i] == 2)
        {
            num = main->map[proc->index] - 1;
            num = main->label[num][3];
            while (num--)
            {
                main->ready_arg[i][0] = main->ready_arg[i][0] << 8;
                main->ready_arg[i][0] = main->ready_arg[i][0] | main->map[proc->index + 1 + k];
                k++;
            }
        }
        else if (main->arg[i] == 3 && (main->map[proc->index] == 2 || main->map[proc->index] == 10 || main->map[proc->index] == 11 || main->map[proc->index] == 14))
        {
            dprintf(FD, "k = %d \n", k);
            num = 0;
            num = num | main->map[proc->index + 1 + k++];
            dprintf(FD, "num = %d\n", num);
            num = num << 8;
            dprintf(FD, "num << 8 = %d\n", num);
            dprintf(FD, "main->map[proc->index + 1 + k++] = %d\n", main->map[proc->index + 1 + k]);
            num = num | main->map[proc->index + 1 + k++];
            dprintf(FD, "num = %d\n", num);
            num = num % IDX_MOD;
            dprintf(FD, "num = %d\n", num);
            r = 0;
            while (r < 4)
            {
                main->ready_arg[i][0] = main->ready_arg[i][0] << 8;
                main->ready_arg[i][0] = main->ready_arg[i][0] | main->map[proc->index + 1 + num++]; 
                r++;
            }
        }
        /*
        **  ВАРИАНТ РАБОТЫ ДЛЯ ST ST ST хорошо работатет !!!!!!!!!!!! возможно и для других
        */
        else if (main->arg[i] == 3 && main->map[proc->index] == 3)
        {
            num = 0;
            num = num | main->map[proc->index + 1 + k++];
            num = num << 8;
            num = num | main->map[proc->index + 1 + k++];
            
            dprintf(FD, "num = %d\n", num);
            
            num = num % IDX_MOD;
            
            dprintf(FD, "num = %d\n", num);
           
            r = 0;
            main->ready_arg[i][0] = num;
        }
        i++;
    }
    dprintf(FD, "______________________________\n");
    dprintf(FD, "RESALT ready_arg\n");
    dprintf(FD, "main->ready_arg[0][0] = %d\n", main->ready_arg[0][0]);
    dprintf(FD, "main->ready_arg[1][0] = %d\n", main->ready_arg[1][0]);
    dprintf(FD, "main->ready_arg[2][0] = %d\n", main->ready_arg[2][0]);

    dprintf(FD, "main->ready_arg[0][1] = %d\n", main->ready_arg[0][1]);
    dprintf(FD, "main->ready_arg[1][1] = %d\n", main->ready_arg[1][1]);
    dprintf(FD, "main->ready_arg[2][1] = %d\n", main->ready_arg[2][1]);
    dprintf(FD, "______________________________\n");
}

int     ft_step_pc(t_main *main, int num, t_process *proc)
{
	int     step;
	

    step = 2;
	if (main->arg[0])
	{
		if (main->arg[0] == 1)
			step += 1;
		if (main->arg[0] == 2)
			step += main->label[num - 1][3];
		if (main->arg[0] == 3)
			step += 2;
	}
	if (main->arg[1])
	{
		if (main->arg[1] == 1)
			step += 1;
		if (main->arg[1] == 2)
			step += main->label[num - 1][3];
		if (main->arg[1] == 3)
			step += 2;
	}
	if (main->arg[2])
	{
		if (main->arg[2] == 1)
			step += 1;
		if (main->arg[2] == 2)
			step += main->label[num - 1][3];
	}
	main->arg[0] = 0;
	main->arg[1] = 0;
	main->arg[2] = 0;
	return (step);
}

void    check_codage(t_main *main, uint8_t num)
{
	int     i;

	i = 1;
    main->arg[0] = 0;
    main->arg[1] = 0;
    main->arg[2] = 0;
	while (1)
	{
		if ((i == 1 || i == 2))
		{
			main->arg[0] = main->arg[0] << 1;
			main->arg[0] += (num >= 128) ? 1 : 0;
		}
		if (i == 3 || i == 4)
		{
			main->arg[1] = main->arg[1] << 1;
			main->arg[1] += (num >= 128) ? 1 : 0;
		}
		if (i == 5 || i == 6)
		{
			main->arg[2] = main->arg[2] << 1;
			main->arg[2] += (num >= 128) ? 1 :0;
		}
		if (num == 0)
			break ;
		num = num << 1;
		i++;
	}
    dprintf(FD, "main->arg[0] = %d\n", main->arg[0]);
    dprintf(FD, "main->arg[1] = %d\n", main->arg[1]);
    dprintf(FD, "main->arg[2] = %d\n", main->arg[2]);
}

