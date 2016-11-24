#include "ft_ls.h"

/*
**	char c == h|s|u|g (hlinks, size, uname, gname)
*/
int	get_longest(t_ls *ls, char c)
{
	// t_ls	*root;
	size_t	len;
	size_t	longest;
	char	*tmp;

	ft_putendl("GET_LONGEST");

	// root = ls;
	len = 0;
	longest = 0;
	while (ls != NULL)
	{
		if (c == 'h')
			tmp = ft_itoa(ls->hlinks);	//ft_strdup the ft_itoa return? but then ft_itoa's malloc will be ignored and un-freeable
		else if (c == 's')
			tmp = ft_itoa(ls->size);
		else if (c == 'u')
			tmp = ft_strdup(ls->uname);
		else if (c == 'g')
			tmp = ft_strdup(ls->gname);
		len = ft_strlen(tmp);
		if (len > longest)
			longest = len;
		// ft_strdel(&tmp);	//free(tmp);	//malloc error. why?
		ls = ls->next;
	}
	// ls = root;
	ft_putendl("RETURNING");
	return (longest);
}
