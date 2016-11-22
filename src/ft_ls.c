#include "ft_ls.h"

static void	ls_getelems2(t_ls *current, struct stat *st)
{
	struct passwd	*pd;
	struct group	*gp;

	pd = getpwuid(st->st_uid);
	gp = getgrgid(st->st_gid);
	ls_set_permissions(current, st);	//current->perms = ls_set_permissions(st)

	//TMP
	// int cnt = 0;
	// while (cnt < 11)
	// {
	// 	ft_putendl(current->perms[cnt])
	// }
	ft_putstr("PERMS:");
	ft_putendl(current->perms);
	//TMP
}

static void	ls_getelems(DIR *d, t_lsargs *lsargs, t_ls *ls)
{
	struct dirent	*dent;
	struct stat		*st;
	t_ls			*current;
	// struct t_ls		*root;	//?
	char			*pth;

	ls = NULL;
	st = (struct stat *)malloc(sizeof(struct stat));
	while ((dent = readdir(d)) != NULL)
	{
		pth = ls_getpath(lsargs, dent->d_name);
		lstat(pth, st);
		current = (t_ls *)malloc(sizeof(t_ls));
		current->name = ls_getname(dent->d_name, st, pth, lsargs);

		ls_getelems2(current, st);

		free(pth);//? or below?
	}
	free(st);//?
	//free(path);//? or above
}

static void	ls_init(t_lsargs *lsargs, t_ls *ls)
{
	DIR		*d;

	d = opendir(lsargs->path);
	if (d == NULL)
	{
		ft_putstr_fd("Error: unable to opendir - ", 2);
		ft_putendl_fd(lsargs->path, 2);
		exit(1);
	}
	ls_getelems(d, lsargs, ls);
	closedir(d);
	// free(d);	//?
}

int			main(int argc, char **argv)
{
	t_ls		*ls;
	t_lsargs	*lsargs;

	ls = (t_ls *)malloc(sizeof(t_ls));
	lsargs = (t_lsargs *)malloc(sizeof(t_lsargs));
	analyze_args(argc, argv, lsargs);
	// ls = ls_init(lsargs);
	ls_init(lsargs, ls);
	free(lsargs->path);
	free(lsargs);
	return (0);
}
