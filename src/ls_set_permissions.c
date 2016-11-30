#include "ft_ls.h"

static void	ls_set_permissions2(t_ls *ls, struct stat *st, char *perms)
{
	if (st->st_mode & S_IXOTH)
		perms[9] = 'x';
	perms[10] = '\0';
	ls->perms = ft_strdup(perms);
	ft_strdel(&perms);
}

void		ls_set_permissions(t_ls *ls, struct stat *st)
{
	char	*perms;

	if ((perms = (char *)malloc(sizeof(char) * 11)) == NULL)
	{
		perms = NULL;
		return ;
	}
	ft_memset(perms, '-', 10);	//TEST - libft version may cause leaks
	if (S_ISDIR(st->st_mode) > 0)
		perms[0] = 'd';
	if (st->st_mode & S_IRUSR)
		perms[1] = 'r';
	if (st->st_mode & S_IWUSR)
		perms[2] = 'w';
	if (st->st_mode & S_IXUSR)
		perms[3] = 'x';
	if (st->st_mode & S_IRGRP)
		perms[4] = 'r';
	if (st->st_mode & S_IWGRP)
		perms[5] = 'w';
	if (st->st_mode & S_IXGRP)
		perms[6] = 'x';
	if (st->st_mode & S_IROTH)
		perms[7] = 'r';
	if (st->st_mode & S_IWOTH)
		perms[8] = 'w';
	ls_set_permissions2(ls, st, perms);
}
