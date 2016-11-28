#include "ft_ls.h"

void	ls_sort_az(t_ls *ls)
{
	t_ls	*root;
	t_ls	*next;

	root = ls;
	next = ls->next;
	while (next != NULL)
	{
		while (next != root)
		{
			if (ft_strcmp(root->name, next->name) > 0)
			{
				do_sort(root, next);
			}
			root = root->next;
		}
		root = ls;
		next = next->next;
	}
}

/*
**	Sorts 't_ls *ls' by name. If 'reverse' is 0, order is
**	ascending. If 'reverse' is 1, order is descending
*/
// static void	ls_sort_az(t_ls *ls, int reverse)
// {
// 	t_ls	*root;
// 	t_ls	*next;
//
// 	root = ls;
// 	next = ls->next;
// 	while (next != NULL)
// 	{
// 		while (next != root)
// 		{
// 			if (reverse == 0)
// 				if (ft_strcmp(root->name, next->name) > 0)
// 					do_sort(root, name)
// 			else if (reverse == 1)
// 				if (ft_strcmp(root->name, next->name) < 0)
// 					do_sort(root, name);
// 			root = root->next;
// 		}
// 		root = ls;
// 		next = next->next;
// 	}
// }

void	ls_rsort_az(t_ls *ls)
{
	t_ls	*root;
	t_ls	*next;

	root = ls;
	next = ls->next;
	while (next != NULL)
	{
		while (next != root)
		{
			if (ft_strcmp(root->name, next->name) < 0)
			{
				do_sort(root, next);
			}
			root = root->next;
		}
		root = ls;
		next = next->next;
	}
}

/*
**	Sorts 't_ls *ls' modification time. If 'reverse' is 0, order is
**	ascending. If 'reverse' is 1, order is descending
*/
// static void	ls_sort_mtime(t_ls *ls, int reverse)
// {
//
// }

void	ls_sort_mtime(t_ls *ls)
{
	t_ls	*root;
	t_ls	*next;

	root = ls;
	next = ls->next;
	while (next != NULL)
	{
		while (next != root)
		{
			if (root->ttmtime < next->ttmtime)
			{
				do_sort(root, next);
			}
			root = root->next;
		}
		root = ls;
		next = next->next;
	}
}

void	ls_rsort_mtime(t_ls *ls)
{
	t_ls	*root;
	t_ls	*next;

	root = ls;
	next = ls->next;
	while (next != NULL)
	{
		while (next != root)
		{
			if (root->ttmtime > next->ttmtime)
			{
				do_sort(root, next);
			}
			root = root->next;
		}
		root = ls;
		next = next->next;
	}
}
