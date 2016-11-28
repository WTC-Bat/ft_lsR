#include "ft_ls.h"

void	ls_recursion(t_ls *ls, t_lsargs *lsargs)
{
	t_lsargs	*rlsargs;
	t_ls		*rls;

	rlsargs = lsargs;
	while (ls != NULL)
	{
		if (ls->dir_path != NULL)
		{
			if ((ft_strequ(ls->dir_path, "./.") == 0) &&
				(ft_strequ(ls->dir_path, "./..") == 0))
			{
				rlsargs->path = ls->dir_path;
				rls = ls_init(rlsargs);
				ls_print(rls, rlsargs);
			}
		}
		ls = ls->next;
	}
}
