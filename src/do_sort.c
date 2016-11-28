#include "ft_ls.h"

static void	do_sort3(t_ls *root, t_ls *next)
{
	char	*tmp_name;
	int		tmp_is_dir;
	char	*tmp_dir_path;

	tmp_name = root->name;
	tmp_is_dir = root->is_dir;
	tmp_dir_path = root->dir_path;
	root->name = next->name;
	root->is_dir = next->is_dir;
	root->dir_path = next->dir_path;
	next->name = tmp_name;
	next->is_dir = tmp_is_dir;
	next->dir_path = tmp_dir_path;
}

static void	do_sort2(t_ls *root, t_ls *next)
{
	size_t		tmp_size;
	char		*tmp_strsize;
	time_t		tmp_ttmtime;
	char		*tmp_mod_time;
	blkcnt_t	tmp_block_count;

	tmp_size = root->size;
	tmp_strsize = root->strsize;
	tmp_ttmtime = root->ttmtime;
	tmp_mod_time = root->mod_time;
	tmp_block_count = root->block_count;
	root->size = next->size;
	root->strsize = next->strsize;
	root->ttmtime = next->ttmtime;
	root->mod_time = next->mod_time;
	root->block_count = next->block_count;
	next->size = tmp_size;
	next->strsize = tmp_strsize;
	next->ttmtime = tmp_ttmtime;
	next->mod_time = tmp_mod_time;
	next->block_count = tmp_block_count;
	do_sort3(root, next);
}

void		do_sort(t_ls *root, t_ls *next)
{
	char	*tmp_perms;
	int		tmp_hlinks;
	char	*tmp_strhlinks;
	char	*tmp_uname;
	char	*tmp_gname;

	tmp_perms = root->perms;
	tmp_hlinks = root->hlinks;
	tmp_strhlinks = root->strhlinks;
	tmp_uname = root->uname;
	tmp_gname = root->gname;
	root->perms = next->perms;
	root->hlinks = next->hlinks;
	root->strhlinks = next->strhlinks;
	root->uname = next->uname;
	root->gname = next->gname;
	next->perms = tmp_perms;
	next->hlinks = tmp_hlinks;
	next->strhlinks = tmp_strhlinks;
	next->uname = tmp_uname;
	next->gname = tmp_gname;
	do_sort2(root, next);
}
