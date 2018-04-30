// //
// //  create_main.c
// //  pr_corewar
// //
// //  Created by Kostiantyn MYKHAILENKO on 4/21/18.
// //  Copyright © 2018 Kostiantyn MYKHAILENKO. All rights reserved.
// //

// #include "../inc/function.h"

// /*
// ** главная функция по которой ходит каретка
// */

// void	ft_walk_on_array(t_main *main)
// {
// 	test_open(main);
//     int i = 0;
//     while (i < main->cnt_bot)				//
//         dprintf(FD, "%x  ", CODE_OF_BOT[i++]);   // распечать самого бота, без карты;
//     dprintf(FD, "\n");							//

//     main->pc = 0;
// 	while (1)
// 	{
//         dprintf(FD, "index:%d value:%d\n", main->pc, CODE_OF_BOT[main->pc]);   // где стала каретка (отлов команды);
// 		STEP = 1;
        
// 		if (CODE_OF_BOT[main->pc] >= 16)
// 			exit(1);
// 		if (CODE_OF_BOT[main->pc] != 1 &&  CODE_OF_BOT[main->pc] != 8 && CODE_OF_BOT[main->pc] != 12 && CODE_OF_BOT[main->pc] != 15 && CODE_OF_BOT[main->pc] != 16)
// 		{
// 			if (main->pc + 1 < main->cnt_bot) 					// что дает этот cnt_bot ?? для чего сравнени ?? ?????? main->cnt_bot - это вся длинна бота??















// 				ft_check_codage(main, CODE_OF_BOT[main->pc + 1]);







//             ft_implement_command(main, main->pc);





//             STEP += ft_step_pc(main, CODE_OF_BOT[main->pc]);















// 			main->pc += STEP;
// 		}
// 		else
// 		{
//             STEP = main->label[main->pc][3];
//             main->pc += STEP;
// 		}
// 		main->pc++;
// 	}
// }



