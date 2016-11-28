#include "ft_ls.h"

static void	print_total_blocks(t_ls *ls, t_lsargs *lsargs)
{
	int		blocks;

	blocks = 0;
	ft_putstr("total ");
	while (ls != NULL)
	{
		if (lsargs->show_all == 0)
		{
			if (ls->name[0] != '.')
				blocks += ls->block_count;
		}
		else
		{
			blocks += ls->block_count;
		}
		ls = ls->next;
	}
}

static void	ls_print_entry_basic(t_ls *ls)
{
	ft_putstr(ls->name);
	if (ls->next == NULL)
		ft_putchar('\n');
	else
		ft_putchar(' ');
}

static void	ls_print_entry_long(t_ls *ls)
{
	ft_putstr(ls->perms);
	ft_putchar(' ');
	ft_putstr(ls->strhlinks);
	ft_putchar(' ');
	ft_putstr(ls->uname);
	ft_putchar(' ');
	ft_putstr(ls->gname);
	ft_putchar(' ');
	ft_putstr(ls->strsize);
	ft_putchar(' ');
	ft_putstr(ls->mod_time);
	ft_putchar(' ');
	ft_putstr(ls->name);
	ft_putchar('\n');
}

static void	do_print(t_ls *ls, t_lsargs *lsargs)
{
	if (lsargs->long_form == 1)
		print_total_blocks(ls, lsargs);
	while (ls != NULL)
	{
		if (ls->name[0] == '.')
		{
			if (lsargs->show_all == 1)
			{
				if (lsargs->long_form == 1)
					ls_print_entry_long(ls);
				else
					ls_print_entry_basic(ls);
			}
		}
		else
		{
			if (lsargs->long_form == 1)
				ls_print_entry_long(ls);
			else
				ls_print_entry_basic(ls);
		}
		ls = ls->next;
	}
}

void		ls_print(t_ls *ls, t_lsargs *lsargs)
{
	if (lsargs->all_members == 1)
		ls_print_members(ls);
	else
	{
		if (lsargs->order_time == 1)
		{
			if (lsargs->reverse == 1)
				ls_rsort_mtime(ls);
			else
				ls_sort_mtime(ls);
		}
		else
		{
			if (lsargs->reverse == 1)
				ls_rsort_az(ls);
			else
				ls_sort_az(ls);
		}
		do_print(ls, lsargs);
	}
}
