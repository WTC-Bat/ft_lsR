#include "ft_ls.h"

int		main(int argc, char **argv)
{
	// t_ls		*ls;
	t_lsargs	*lsargs;

	lsargs = (t_lsargs *)malloc(sizeof(t_lsargs));
	analyze_args(argc, argv, lsargs);
	// ls = ls_init(lsargs);
	free(lsargs->path);
	free(lsargs);
	return (0);
}
