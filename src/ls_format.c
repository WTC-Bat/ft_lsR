#include "ft_ls.h"

static void	format_hlinks(t_ls *ls, size_t longest)
{
	t_ls	*root;
	char	*tmp;
	char	*out;
	size_t	len;

	ft_putendl("FORMAT_HLINKS");

	root = ls;
	// out = (char *)malloc(sizeof(char) * (longest + 1));
	while (ls != NULL)
	{
		tmp = ft_itoa(ls->hlinks);
		len = ft_strlen(tmp);
		out = (char *)malloc(sizeof(char) * (longest + 1));
		if (len < longest)
		{
			//reverse for right-hand padding
			ft_memset(out, ' ', (longest - len));
			ft_strcat(out, tmp);
		}
		else
		{
			out = ft_strdup(tmp);
		}
		ls->strhlinks = ft_strdup(out);
		ls = ls->next;
		// free(tmp);
		out = NULL;
		free(out);
	}
	ls = root;
}

// static void	format_size(t_ls *ls)
// {
//
// }
//
// static void	format_uname(t_ls *ls)
// {
//
// }
//
// static void	format_gname(t_ls *ls)
// {
//
// }

void		ls_format(t_ls *ls)
{
	// t_ls	*root;
	size_t	hlen;
	// size_t	slen;
	// size_t	ulen;
	// size_t	glen;

	hlen = get_longest(ls, 'h');
	format_hlinks(ls, hlen);
	// slen = get_longest(t_ls *ls, 's');
	// ulen = get_longest(t_ls *ls, 'u');
	// glen = get_longest(t_ls *ls, 'g');
}
