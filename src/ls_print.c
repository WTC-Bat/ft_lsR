#include "ft_ls.h"

static void	print_total_blocks(t_ls *ls, t_lsargs *lsargs)
{
	ft_putendl("CHEESE");
}

static void	ls_print_entry_long(t_ls *ls)
{

}

static void	ls_print_entry_basic(t_ls *ls)
{

}

static void	do_print(t_ls *ls, t_lsargs *lsargs)
{
	if (lsargs->long_form == 1)
	{
		print_total_blocks(ls, lsargs);
	}
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
		//do_print();
	}
}
