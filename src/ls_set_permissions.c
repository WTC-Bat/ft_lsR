#include "ft_ls.h"

// static void	ls_set_permissions2(t_ls *ls, struct stat *st, char *perms)
static void	ls_set_permissions2(t_ls *ls, char *perms)
{
	perms[10] = '\0';
	ls->perms = perms;
}

void		ls_set_permissions(t_ls *ls, struct stat *st)
{
	char	*perms;

	perms = (char *)malloc(sizeof(char) * 11);
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
	if (st->st_mode & S_IXOTH)
		perms[9] = 'x';
	ls_set_permissions2(ls, perms);
}
