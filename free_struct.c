# include "main.h"

void	free_struct(t_main *main)
{
	t_process	*tmp;
	t_changes	*buff;
	int			i;

	i = 0;
	while (main->filename[i])
		ft_strdel(&(main)->filename[i++]);
	i = 0;
	while (i < MAX_PLAYERS)
		free(main->players[i++]);
	while ((*main).lst_proc)
	{
		tmp = (*main).lst_proc->next;
		free((*main).lst_proc);
		(*main).lst_proc = tmp;
	}
	(main->lst_proc) ? free(main->lst_proc) : 0;
	while ((*main).lst_changes)
	{
		buff = (*main).lst_changes->next;
		free((*main).lst_changes);
		(*main).lst_changes = buff;
	}
	(main->lst_changes) ? free(main->lst_changes) : 0;
}

void	free_changes(t_main *main)
{
	t_changes	*tmp;

	while (main->lst_changes)
	{
		tmp = main->lst_changes->next;
		free(main->lst_changes);
		main->lst_changes = NULL;
		main->lst_changes = tmp;
	}
	free(main->lst_changes);
}
