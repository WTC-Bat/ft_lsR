#include "ft_ls.h"

void	ls_recursion(t_ls *ls, t_lsargs *lsargs)
{
	t_lsargs	*rlsargs;
	t_ls		*rls;

	rlsargs = lsargs;
	while (ls != NULL)
	{
		if (ls->is_dir == 1)
		{
			rlsargs->path = ls->dir_path;
			ft_putendl(rlsargs->path);
			rls = ls_init(rlsargs);
			ls_print(rls, rlsargs);
			ft_putchar('\n');
		}
	}
}
