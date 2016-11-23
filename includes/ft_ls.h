#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <pwd.h>
# include <unistd.h>
# include <time.h>
# include <grp.h>
# include <sys/stat.h>
# include "../libft/libft.h"

typedef struct	s_lsargs
{
	int			show_all;
	int			long_form;
	int			recursive;
	int			reverse;
	int			order_time;
	int			all_members;
	char		*path;
}				t_lsargs;

/*typedef struct s_file*/
typedef struct		s_ls
{
	char			*perms;
	// int				hlinks;
	nlink_t			hlinks;
	char			*strhlinks;
	char			*uname;
	char			*gname;
	size_t			size;
	char			*strsize;
	time_t			ttmtime;
	char			*mod_time;
	blkcnt_t		block_count;
	char			*name;
	int				is_dir;
	char			*dir_path;
	struct s_ls		*next;
}					t_ls;

/*arg_funcs.c*/
void	analyze_args(int argc, char **argv, t_lsargs *lsargs);
int		arg_ispath(char *arg);
/*format_funcs.c*/
char	*format_time(time_t *ttmtime);
/*get_longest.c*/
// int		longest_hlinks(t_ls *ls);
// int		longest_size(t_ls *ls);
// int		longest_uname(t_ls *ls);
// int		longest_gname(t_ls *ls);
int		get_longest(t_ls *ls, char c);
/*ls_format.c*/
void	ls_format(t_ls *ls);
/*ls_funcs.c*/
char	*ls_getpath(t_lsargs *lsargs, char *d_name);
char	*ls_getname(char *d_name, struct stat *st, char *pth, t_lsargs *lsargs);
void	ls_set_dirpath(t_ls *ls, struct stat *st, char *pth);
void	ls_set_stringvalues(t_ls *ls);
void	t_ls_free(t_ls *ls);
/*ls_set_permissions.c*/
void	ls_set_permissions(t_ls *ls, struct stat *st);
/*lsargs_funcs.c*/
void	lsargs_init(int argc, char **argv, t_lsargs *lsargs);
void	lsargs_set(char c, t_lsargs *lsargs);

#endif
