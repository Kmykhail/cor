/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 09:18:50 by ozharko           #+#    #+#             */
/*   Updated: 2018/04/24 09:18:52 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ********************`****************************************************** */

#include "../main.h"

int		choose_function_1(t_main *main, t_process *proc)
{
	if (main->map[proc->index] == 1 && !proc->cmd_cycle)//10
	{
		dprintf(FD, "FUN [%02x] ID [%d] CC = [%d] PC = [%d]\n", main->map[proc->index], proc->id, main->cur_cycle, proc->index);test_show_me_label_arg(main, proc);
		// dprintf(FD, "1__________________________________________\n");
		// dprintf(FD, "ID = %d\n", proc->id);
		// test_show_me_label_arg(main, proc);
		fun_live(main, proc);
		// test_show_me_label_arg(main, proc);
    	// dprintf(FD, "__________________________________________\n");
	}
	else if (main->map[proc->index] == 2 && !proc->cmd_cycle)//5
	{
		dprintf(FD, "FUN [%02x] ID [%d] CC = [%d] PC = [%d]\n", main->map[proc->index], proc->id, main->cur_cycle, proc->index);test_show_me_label_arg(main, proc);
		// dprintf(FD, "2__________________________________________\n");
		// dprintf(FD, "ID = %d\n", proc->id);
    	if (proc->id == 3)
    	{
    		// dprintf(FD, "\n\nstart___#######################\n");
    		test_show_me_label_arg(main, proc);
    		// dprintf(FD, "main->cur_cycle = %d\n", main->cur_cycle);
    		// dprintf(FD, "proc->index = %d\n", proc->index);
    		// dprintf(FD, "map = %x\n", main->map[proc->index]);
    		// dprintf(FD, "__carry = %d\n\n", proc->carry);
    		test_show_me_label_arg(main, proc);
    		// dprintf(FD, "end___#######################\n\n\n");
    	}
		fun_ld(main, proc);
    	// dprintf(FD, "__________________________________________\n");
	}
	else if (main->map[proc->index] == 3 && !proc->cmd_cycle)//5
	{
		dprintf(FD, "FUN [%02x] ID [%d] CC = [%d] PC = [%d]\n", main->map[proc->index], proc->id, main->cur_cycle, proc->index);test_show_me_label_arg(main, proc);
		// dprintf(FD, "3__________________________________________\n");
		// dprintf(FD, "ID = %d\n", proc->id);
		// test_show_me_label_arg(main, proc);
		fun_st(main, proc);
		// test_show_me_label_arg(main, proc);
    	// dprintf(FD, "__________________________________________\n");
	}
	else if (main->map[proc->index] == 4 && !proc->cmd_cycle)//10
	{
		dprintf(FD, "FUN [%02x] ID [%d] CC = [%d] PC = [%d]\n", main->map[proc->index], proc->id, main->cur_cycle, proc->index);test_show_me_label_arg(main, proc);
		// dprintf(FD, "4__________________________________________\n");
		// dprintf(FD, "ID = %d\n", proc->id);
    	if (proc->id == 3)
    	{
    		// dprintf(FD, "\n\nstart___#######################\n");
    		test_show_me_label_arg(main, proc);
    		// dprintf(FD, "main->cur_cycle = %d\n", main->cur_cycle);
    		// dprintf(FD, "proc->index = %d\n", proc->index);
    		// dprintf(FD, "map = %x\n", main->map[proc->index]);
    		// dprintf(FD, "__carry = %d\n\n", proc->carry);
    		test_show_me_label_arg(main, proc);
    		// dprintf(FD, "end___#######################\n\n\n");
    	}
		fun_add(main, proc);
    	// dprintf(FD, "__________________________________________\n");
	}
	else if (main->map[proc->index] == 5 && !proc->cmd_cycle)//10
	{
		dprintf(FD, "FUN [%02x] ID [%d] CC = [%d] PC = [%d]\n", main->map[proc->index], proc->id, main->cur_cycle, proc->index);test_show_me_label_arg(main, proc);
		// dprintf(FD, "5__________________________________________\n");
		// dprintf(FD, "ID = %d\n", proc->id);
    	if (proc->id == 3)
    	{
    		// dprintf(FD, "\n\nstart___#######################\n");
    		test_show_me_label_arg(main, proc);
    		// dprintf(FD, "main->cur_cycle = %d\n", main->cur_cycle);
    		// dprintf(FD, "proc->index = %d\n", proc->index);
    		// dprintf(FD, "map = %x\n", main->map[proc->index]);
    		// dprintf(FD, "__carry = %d\n\n", proc->carry);
    		test_show_me_label_arg(main, proc);
    		// dprintf(FD, "end___#######################\n\n\n");
    	}
		fun_sub(main, proc);
    	// dprintf(FD, "__________________________________________\n");
	}
	else if (main->map[proc->index] == 6 && !proc->cmd_cycle)//6
	{
		dprintf(FD, "FUN [%02x] ID [%d] CC = [%d] PC = [%d]\n", main->map[proc->index], proc->id, main->cur_cycle, proc->index);test_show_me_label_arg(main, proc);
		// dprintf(FD, "6__________________________________________\n");
		// dprintf(FD, "ID = %d\n", proc->id);
    	if (proc->id == 3)
    	{
    		// dprintf(FD, "\n\nstart___#######################\n");
    		test_show_me_label_arg(main, proc);
    		// dprintf(FD, "main->cur_cycle = %d\n", main->cur_cycle);
    		// dprintf(FD, "proc->index = %d\n", proc->index);
    		// dprintf(FD, "map = %x\n", main->map[proc->index]);
    		// dprintf(FD, "__carry = %d\n\n", proc->carry);
    		test_show_me_label_arg(main, proc);
    		// dprintf(FD, "end___#######################\n\n\n");
    	}
		fun_and(main, proc);
    	// dprintf(FD, "__________________________________________\n");
	}
	else if (main->map[proc->index] == 7 && !proc->cmd_cycle)//6
	{
		dprintf(FD, "FUN [%02x] ID [%d] CC = [%d] PC = [%d]\n", main->map[proc->index], proc->id, main->cur_cycle, proc->index);test_show_me_label_arg(main, proc);
		// dprintf(FD, "7__________________________________________\n");
		// dprintf(FD, "ID = %d\n", proc->id);
    	if (proc->id == 3)
    	{
    		// dprintf(FD, "\n\nstart___#######################\n");
    		test_show_me_label_arg(main, proc);
    		// dprintf(FD, "main->cur_cycle = %d\n", main->cur_cycle);
    		// dprintf(FD, "proc->index = %d\n", proc->index);
    		// dprintf(FD, "map = %x\n", main->map[proc->index]);
    		// dprintf(FD, "__carry = %d\n\n", proc->carry);
    		test_show_me_label_arg(main, proc);
    		// dprintf(FD, "end___#######################\n\n\n");
    	}
		fun_or(main, proc);
    	// dprintf(FD, "__________________________________________\n");
	}
	else if (main->map[proc->index] == 8 && !proc->cmd_cycle)//6
	{
		dprintf(FD, "FUN [%02x] ID [%d] CC = [%d] PC = [%d]\n", main->map[proc->index], proc->id, main->cur_cycle, proc->index);test_show_me_label_arg(main, proc);
		// dprintf(FD, "8__________________________________________\n");
		// dprintf(FD, "ID = %d\n", proc->id);
    	if (proc->id == 3)
    	{
    		// dprintf(FD, "\n\nstart___#######################\n");
    		test_show_me_label_arg(main, proc);
    		// dprintf(FD, "main->cur_cycle = %d\n", main->cur_cycle);
    		// dprintf(FD, "proc->index = %d\n", proc->index);
    		// dprintf(FD, "map = %x\n", main->map[proc->index]);
    		// dprintf(FD, "__carry = %d\n\n", proc->carry);
    		test_show_me_label_arg(main, proc);
    		// dprintf(FD, "end___#######################\n\n\n");
    	}
		fun_xor(main, proc);
    	// dprintf(FD, "__________________________________________\n");
	}
	return (1);
}

int		choose_function_2(t_main *main, t_process *proc)
{
	if (main->map[proc->index] == 9 && !proc->cmd_cycle)//20
	{
		dprintf(FD, "FUN [%02x] ID [%d] CC = [%d] PC =[%d]\n", main->map[proc->index], proc->id, main->cur_cycle, proc->index);test_show_me_label_arg(main, proc);
		// dprintf(FD, "9__________________________________________\n");
		// dprintf(FD, "ID = %d\n", proc->id);
    	if (proc->id == 3)
    	{
    		// dprintf(FD, "\n\nstart___#######################\n");
    		test_show_me_label_arg(main, proc);
    		// dprintf(FD, "main->cur_cycle = %d\n", main->cur_cycle);
    		// dprintf(FD, "proc->index = %d\n", proc->index);
    		// dprintf(FD, "map = %x\n", main->map[proc->index]);
    		// dprintf(FD, "__carry = %d\n\n", proc->carry);
    		test_show_me_label_arg(main, proc);
    		// dprintf(FD, "end___#######################\n\n\n");
    	}
		fun_zjmp(main, proc);
		// dprintf(FD, "__________________________________________\n");
	}
	else if (main->map[proc->index] == 10 && !proc->cmd_cycle)//25
	{
		dprintf(FD, "FUN [%02x] ID [%d] CC = [%d] PC =[%d]\n", main->map[proc->index], proc->id, main->cur_cycle, proc->index);test_show_me_label_arg(main, proc);
		// dprintf(FD, "10__________________________________________\n");
		// dprintf(FD, "ID = %d\n", proc->id);
		// test_show_me_label_arg(main, proc);
		fun_ldi(main, proc);
		// test_show_me_label_arg(main, proc);
		// dprintf(FD, "__________________________________________\n");
	}
	else if (main->map[proc->index] == 11 && !proc->cmd_cycle)//25
	{
		dprintf(FD, "FUN [%02x] ID [%d] CC = [%d] PC =[%d]\n", main->map[proc->index], proc->id, main->cur_cycle, proc->index);test_show_me_label_arg(main, proc);
		// dprintf(FD, "11__________________________________________\n");
		// dprintf(FD, "ID = %d\n", proc->id);
		// test_show_me_label_arg(main, proc);
		fun_sti(main, proc);
		// test_show_me_label_arg(main, proc);
		// dprintf(FD, "__________________________________________\n");
	}
	else if (main->map[proc->index] == 12 && !proc->cmd_cycle)//800
	{
		dprintf(FD, "FUN [%02x] ID [%d] CC = [%d] PC =[%d]\n", main->map[proc->index], proc->id, main->cur_cycle, proc->index);test_show_me_label_arg(main, proc);
		// dprintf(FD, "12__________________________________________\n");
		// dprintf(FD, "ID = %d\n", proc->id);
		// test_show_me_label_arg(main, proc);
		fun_fork(main, proc);
		// test_show_me_label_arg(main, proc);
		// dprintf(FD, "__________________________________________\n");
	}
	else if (main->map[proc->index] == 13 && !proc->cmd_cycle)//10
	{
		dprintf(FD, "FUN [%02x] ID [%d] CC = [%d] PC =[%d]\n", main->map[proc->index], proc->id, main->cur_cycle, proc->index);test_show_me_label_arg(main, proc);
		// dprintf(FD, "13__________________________________________\n");
		// dprintf(FD, "ID = %d\n", proc->id);
    	if (proc->id == 3)
    	{
    		// dprintf(FD, "\n\nstart___#######################\n");
    		test_show_me_label_arg(main, proc);
    		// dprintf(FD, "main->cur_cycle = %d\n", main->cur_cycle);
    		// dprintf(FD, "proc->index = %d\n", proc->index);
    		// dprintf(FD, "map = %x\n", main->map[proc->index]);
    		// dprintf(FD, "__carry = %d\n\n", proc->carry);
    		test_show_me_label_arg(main, proc);
    		// dprintf(FD, "end___#######################\n\n\n");
    	}
		fun_lld(main, proc);
		// dprintf(FD, "__________________________________________\n");
	}
	else if (main->map[proc->index] == 14 && !proc->cmd_cycle)//50
	{
		dprintf(FD, "FUN [%02x] ID [%d] CC = [%d] PC =[%d]\n", main->map[proc->index], proc->id, main->cur_cycle, proc->index);test_show_me_label_arg(main, proc);
		// dprintf(FD, "14__________________________________________\n");
		// dprintf(FD, "ID = %d\n", proc->id);
    	if (proc->id == 3)
    	{
    		// dprintf(FD, "\n\nstart___#######################\n");
    		test_show_me_label_arg(main, proc);
    		// dprintf(FD, "main->cur_cycle = %d\n", main->cur_cycle);
    		// dprintf(FD, "proc->index = %d\n", proc->index);
    		// dprintf(FD, "map = %x\n", main->map[proc->index]);
    		// dprintf(FD, "__carry = %d\n\n", proc->carry);
    		test_show_me_label_arg(main, proc);
    		// dprintf(FD, "end___#######################\n\n\n");
    	}
		fun_lldi(main, proc);
		// dprintf(FD, "__________________________________________\n");
	}
	else if (main->map[proc->index] == 15 && !proc->cmd_cycle)//1000
	{
		dprintf(FD, "FUN [%02x] ID [%d] CC = [%d] PC =[%d]\n", main->map[proc->index], proc->id, main->cur_cycle, proc->index);test_show_me_label_arg(main, proc);
		// dprintf(FD, "15__________________________________________\n");
		// dprintf(FD, "ID = %d\n", proc->id);
		// test_show_me_label_arg(main, proc);
		fun_lfork(main, proc);
		// test_show_me_label_arg(main, proc);
		// dprintf(FD, "__________________________________________\n");
	}
	else if (main->map[proc->index] == 16 && !proc->cmd_cycle)//2
	{
		dprintf(FD, "FUN [%02x] ID [%d] CC = [%d] PC =[%d]\n", main->map[proc->index], proc->id, main->cur_cycle, proc->index);test_show_me_label_arg(main, proc);
		// dprintf(FD, "16__________________________________________\n");
		// dprintf(FD, "ID = %d\n", proc->id);
		// test_show_me_label_arg(main, proc);
		fun_aff(main, proc);
		// test_show_me_label_arg(main, proc);
		// dprintf(FD, "__________________________________________\n");
	}
	return (1);
}


void    ft_implement_command(t_main *main, t_process *proc)
{
	dprintf(FD, "^^^^^^^: %d\n", proc->cmd_cycle);
    if (main->map[proc->index] >= 1 && main->map[proc->index] < 9)
    {
    	// dprintf(FD, "proc->cmd_cycle = %d\n", proc->cmd_cycle);
        if (choose_function_1(main, proc))
        {
        	// dprintf(FD, "proc->cmd_cycle = %d\n", proc->cmd_cycle);
        	return ;
        }
    }
    else if (main->map[proc->index] >=9 && main->map[proc->index] <= 16)
    {
    	// dprintf(FD, "proc->cmd_cycle = %d\n", proc->cmd_cycle);
        if (choose_function_2(main, proc))
        {
        	// dprintf(FD, "proc->cmd_cycle = %d\n", proc->cmd_cycle);
        	return ;
        }        
    }
    else
    {
    	proc->index += 1;
    	//proc->cmd_cycle--;
    }
}
