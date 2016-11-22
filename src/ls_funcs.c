#include "ft_ls.h"

/*
**	Returns the name of the file. This is used to display symlinks.
**	If 'st->st_mode' is a link, the link name and actual name will be joined
**	and returned, otherwise 'd_name' is returned
*/
char	*ls_getname(char *d_name, struct stat *st, char *pth, t_lsargs *lsargs)
{
	char	*name;
	char	*lname;
	size_t	nlen;
	size_t	lnlen;

	lname = NULL;
	nlen = 0;
	lnlen = 0;
	if (S_ISLNK(st->st_mode) > 0)
	{
		if (lsargs->long_form == 1)
		{
			lname = (char *)malloc(sizeof(char) * 1024);
			readlink(pth, lname, 1024);
			nlen = ft_strlen(d_name);
			lnlen = ft_strlen(lname);
			name = (char *)malloc(sizeof(char) * (nlen + lnlen + 5)); // + 4?
			ft_strcpy(name, d_name);
			ft_strcat(name, " -> ");
			ft_strcat(name, lname);
			free(lname);
			return (name);
		}
	}
	return (d_name);
}

/*
**	Returns ls' base path joined with the filename specified in d_name
*/
char	*ls_getpath(t_lsargs *lsargs, char *d_name)
{
	char	*pth;
	size_t	pthlen;
	size_t	dnamelen;

	pthlen = ft_strlen(lsargs->path);
	dnamelen = ft_strlen(d_name);
	pth = (char *)malloc(sizeof(char) * (pthlen + dnamelen + 1));
	ft_strcpy(pth, lsargs->path);
	if (ft_strequ(pth, "./") == 0)
		ft_strcat(pth, "/");
	ft_strcat(pth, d_name);
	return (pth);
}
