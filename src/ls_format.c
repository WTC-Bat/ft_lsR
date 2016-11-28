#include "ft_ls.h"

/*reset ls to root after iterating?*/
static void		format_hlinks(t_ls *ls, size_t longest)
{
	char	*hstr;
	char	*pad;
	size_t	len;
	size_t	padlen;

	while (ls != NULL)
	{
		hstr = ft_strdup(ft_itoa(ls->hlinks)); //ft_itoa allocation is un-freeable. need to take a look
		len = ft_strlen(hstr);
		padlen = longest - len;
		if (padlen > 0)
		{
			if ((pad = (char *)malloc(sizeof(char) * padlen)) == NULL)
			{
				if (hstr != NULL)
				{
					ls->strhlinks = ft_strdup(hstr);
					continue;
				}
			}
			ft_memset(pad, ' ', padlen);
			pad[padlen] = '\0';
			ls->strhlinks = ft_strjoin(pad, hstr);
			ft_strdel(&pad);
		}
		else
		{
			ls->strhlinks = ft_strdup(hstr);
		}
		ft_strdel(&hstr);
		ls = ls->next;
	}
}

static void	format_size(t_ls *ls, size_t longest)
{
	char	*sstr;
	char	*pad;
	size_t	len;
	size_t	padlen;

	while (ls != NULL)
	{
		sstr = ft_strdup(ft_itoa(ls->size));
		len = ft_strlen(sstr);
		padlen = longest - len;
		if (padlen > 0)
		{
			if ((pad = (char *)malloc(sizeof(char) * padlen)) == NULL)
			{
				if (sstr != NULL)
				{
					ls->strsize = ft_strdup(sstr);
					continue;
				}
			}
			ft_memset(pad, ' ', padlen);
			pad[padlen] = '\0';
			ls->strsize = ft_strjoin(pad, sstr);
			ft_strdel(&pad);
		}
		else
		{
			ls->strsize = ft_strdup(sstr);
		}
		ft_strdel(&sstr);
		ls = ls->next;
	}
}


static void	format_uname(t_ls *ls, size_t longest)
{
	char	*ustr;
	char	*pad;
	size_t	len;
	size_t	padlen;

	while (ls != NULL)
	{
		// ustr = ft_strdup(ls->uname);
		// len = ft_strlen(ustr);
		len = ft_strlen(ls->uname);
		padlen = longest - len;
		if (padlen > 0)
		{
			if ((pad = (char *)malloc(sizeof(char) * padlen)) == NULL)
				continue;
			ft_memset(pad, ' ', padlen);
			pad[padlen] = '\0';
			ustr = ft_strdup(ls->uname);
			ft_strdel(&(ls)->uname);
			ls->uname = ft_strjoin(pad, ustr);
			ft_strdel(&ustr);
			ft_strdel(&pad);
		}
		ls = ls->next;
	}
}


// static void	format_gname(t_ls *ls, size_t longest)
// {
//
// }


void		ls_format(t_ls *ls)
{
	size_t	hlen;
	size_t	slen;
	size_t	ulen;
	size_t	glen;

	hlen = get_longest(ls, 'h');
	format_hlinks(ls, hlen);
	slen = get_longest(ls, 's');
	format_size(ls, slen);
	ulen = get_longest(ls, 'u');
	format_uname(ls, ulen);
	glen = get_longest(ls, 'g');
	//format_gname(ls, glen);
}
