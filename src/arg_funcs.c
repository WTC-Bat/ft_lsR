#include "ft_ls.h"

/*
**	As 'ls' cannot be run on a file (ie. ls /bin/who), this function only checks
**	if the argument (arg) is a path to a directory.
*/
int			arg_ispath(char *arg)
{
	struct stat	*st;
	int			ispath;

	st = (struct stat *)malloc(sizeof(struct stat));
	ispath = 0;
	if (lstat(arg, st) == 0)
		if (S_ISDIR((*st).st_mode) > 0)
			ispath = 1;
	free(st);
	return (ispath);
}

/*
**	Returns 1 if all arguments are valid, otherwise returns 0
*/
static int	args_are_valid(int argc, char **argv)
{
	int		scnt;

	scnt = 1;
	if (argc == 1)
		return (1);
	else
	{
		while (argv[scnt] != NULL)
		{
			if (arg_ispath(argv[scnt]) == 0 && argv[scnt][0] != '-')
				return (0);
			scnt++;
		}
	}
	return (1);
}

/*
**	If arguments are present, checks that the arguments are valid and sets
**	'lsargs' members.
*/
void		analyze_args(int argc, char **argv, t_lsargs *lsargs)
{
	int			scnt;
	int			ccnt;

	scnt = 1;
	ccnt = 0;
	lsargs_init(argc, argv, lsargs);
	if (args_are_valid(argc, argv) == 0)
	{
		ft_putendl_fd("Error: Invalid argument present.", 2);
		exit(1);
	}
	while (argv[scnt] != NULL)
	{
		if (argv[scnt][0] == '-')
		{
			if (arg_ispath(argv[scnt]) == 0)
			{
				ccnt++;
				while (argv[scnt][ccnt] != '\0')
				{
					lsargs_set(argv[scnt][ccnt], lsargs);
					ccnt++;
				}
			}
		}
		ccnt = 0;
		scnt++;
	}
}
