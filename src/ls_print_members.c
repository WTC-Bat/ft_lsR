#include "ft_ls.h"

static void	ls_print_members2(t_ls *ls)
{
	if (ls->dir_path != NULL)
		ft_putendl(ls->dir_path);
	else
		ft_putchar('\n');
}

void		ls_print_members(t_ls *ls)
{
	while (ls != NULL)
	{
		ft_putstr("Permissions:\t");
		ft_putendl(ls->perms);
		ft_putstr("Hardlinks:\t");
		ft_putnbr_endl(ls->hlinks);
		ft_putstr("User Name:\t");
		ft_putendl(ls->uname)l;
		ft_putstr("Group Name:\t");
		ft_putendl(ls->gname);
		ft_putstr("Size:\t");
		ft_putnbr_endl(ls->size);
		ft_putstr("Modification Time:\t");
		ft_putendl(ls->mod_time);
		ft_putstr("Name:\t");
		ft_putendl(ls->name);
		ft_putstr("Is Directory:\t");
		ft_putnbr_endl(ls->is_dir);
		ft_putstr("Directory Path:\t");
		ls_print_members2(ls);
		ft_putchar('\n');
		ls = ls->next;
	}
}
