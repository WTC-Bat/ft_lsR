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
	int				hlinks;
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
	struct s_file	*next;
}					t_ls;

void	analyze_args(int argc, char **argv, t_lsargs *lsargs);
void	lsargs_init(int argc, char **argv, t_lsargs *lsargs);
int		arg_ispath(char *arg);
void	lsargs_set(char c, t_lsargs *lsargs);

#endif