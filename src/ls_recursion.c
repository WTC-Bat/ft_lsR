#include "ft_ls.h"

//TMP RECUR VERSION FOR TESTING HIDDEN ".git" directory...
void	ls_recursion(t_ls *ls, t_lsargs *lsargs)
{
	t_lsargs	*rlsargs;
	t_ls		*rls;

	rlsargs = lsargs;
	while (ls != NULL)
	{
		if (ls->is_dir == 1)
		{
			if ((ft_endswith(ls->dir_path, "/.") == 0) && (ft_endswith(ls->dir_path, "/..") == 0))
			{
				// ft_putendl(ls->dir_path);
				ft_strdel(&(rlsargs)->path);
				rlsargs->path = ft_strdup(ls->dir_path);
				ft_putstr("RLSARGS->PATH:\t");
				ft_putendl(ls->dir_path);
				rls = ls_init(rlsargs);
				ls_print(rls, rlsargs);
			}
		}
		ls = ls->next;
	}
}

// void	ls_recursion(t_ls *ls, t_lsargs *lsargs)
// {
// 	t_lsargs	*rlsargs;
// 	// t_ls		*rls;
//
// 	rlsargs = lsargs;
// 	while (ls != NULL)
// 	{
// 		if (ls->dir_path != NULL)
// 		{
// 			if (ft_startswith(ls->dir_path, "./."))
// 			{
// 				if (rlsargs->show_all)
// 				{
// 					//process
// 				}
// 			}
// 			else
// 			{
// 				//process
// 			}
// 		}
// 		ls = ls->next;
// 	}
// }
