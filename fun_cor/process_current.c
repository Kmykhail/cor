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

/*
** main->map[main->pc + 1 + k]; прибавление 1 должно быть в виде переменной которая покажет есть ли кожэдж у данной функции
*/
void     ready_arg(t_main *main)
{
    int     i;
    int     k;
    int     r;
    int     num;
	int     test_2;
    // int     curr;
    
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
        if (main->arg[i] == 1) 		 // (если аргумент регист в котором надо взять значение внутри)
        {
            num = main->map[main->pc];
            r = 0;
            main->ready_arg[i][1] = main->map[main->pc + 1 + k];  // записать номер T_REG 
            while (r < 4)
            {
                main->ready_arg[i][0] = main->ready_arg[i][0] << 8;
                test_2 = main->rg[num - 1][r];
                main->ready_arg[i][0] = main->ready_arg[i][0] | test_2;
                r++;
            }
            // dprintf(FD, "main->ready->arg[%i][0] = %d\n", i, main->ready_arg[i][0]);
            k++;
        }
        else if (main->arg[i] == 2)
        {
            num = main->map[main->pc];   // беру текущею позицию на карте;
            num = main->label[num][3];     // эту позицию вставляю в поиск строки в лейбл и беру размер T_DIR // num = РАЗМЕР T_DIR
            while (num--)
            {
                main->ready_arg[i][0] = main->ready_arg[i][0] << 8;
                main->ready_arg[i][0] = main->ready_arg[i][0] | main->map[main->pc + 1 + k];  // 0b 68 00 00 00 01
                k++;
            }
            // dprintf(FD, "main->ready->arg[%i][0] = %d\n", i, main->ready_arg[i][0]);
        }
        /*
        ** для функции ldi надо считать T_IND "4 байта считаные с позиции ((T_IND % IDX_MOD) плюс текущая позиция PC)."
        */
        else if (main->arg[i] == 3 && (main->map[main->pc] == 2 || main->map[main->pc] == 3 || main->map[main->pc] == 10 || main->map[main->pc] == 11 || main->map[main->pc] == 14))
        {
            num = 0;
            num = num | main->map[main->pc + 1 + k++];
            num = num << 8;
            num = num | main->map[main->pc + 1 + k++];
            num = num % IDX_MOD;
            r = 0;
            while (r < 4)
            {
                main->ready_arg[i][0] = main->ready_arg[i][0] << 8;
                main->ready_arg[i][0] = main->ready_arg[i][0] | main->map[main->pc + 1 + num++]; 
                r++;
            }
        }
        /*
        ** отдельное условие для ld КАК ОН ТУТ ПЕРЕЗАПИШЕТСЯ
        */
        else if (main->arg[i] == 3 && (main->map[main->pc] == 2))
        {
            num = 0;
            num = num | main->map[main->pc + 1 + k++];
            num = num << 8;
            num = num | main->map[main->pc + 1 + k++];
            num = num % IDX_MOD; // ключевой момоент IND для этой функции
            r = 0;
            while (r < 4)
            {
                main->ready_arg[i][0] = main->ready_arg[i][0] << 8;
                main->ready_arg[i][0] = main->ready_arg[i][0] | main->map[main->pc + 1 + num++]; 
                r++;
            }
        }
        else if (main->arg[i] == 3)
        {
        	num = 0;
        	num = num | main->map[main->pc + 1 + k++];
        	num = num << 8;
        	num = num | main->map[main->pc + 1 + k++];
        	r = 0;
        	while (r < 4)
        	{
                main->ready_arg[i][0] = main->ready_arg[i][0] << 8;
                main->ready_arg[i][0] = main->ready_arg[i][0] | main->map[main->pc + 1 + num++]; 
                r++;
        	}
        }
        i++;
    }
}

int     ft_step_pc(t_main *main, int num)
{
	int     step;
	
	step = 0;
	if (main->arg[0])
	{
		if (main->arg[0] == 1)
			step += 1;
		if (main->arg[0] == 2)
			step += main->label[num][3];
		if (main->arg[0] == 3)
			step += 2;
	}
	if (main->arg[1])
	{
		if (main->arg[1] == 1)
			step += 1;
		if (main->arg[1] == 2)
			step += main->label[num][3];
		if (main->arg[1] == 3)
			step += 2;
	}
	if (main->arg[2])
	{
		if (main->arg[2] == 1)
			step += 1;
		if (main->arg[2] == 2)
			step += main->label[num][3];
	}
	main->arg[0] = 0;
	main->arg[1] = 0;
	main->arg[2] = 0;
    printf(">>>>>>>step<<<<<<:%d\n", step);
	return (step);
}

void    check_map(t_main *main, uint8_t num)
{
	int     i;

	i = 1;
	// main->codage = num;     // зачем нам знать это codage если у нас все будет в 	uint8_t arg[3];    ready_arg[3][2]; ????????????????????????????
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
}

