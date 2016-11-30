# ft_lsR

-	Check "ls_funcs.c -> ls_getpath" for leaks (Possible)
-	Error in libft -> ft_itoa
-	Should the ('t_ls') struct be reset to it's root after iterating through it?
	-	t_ls resets in:
		-	get_longest.c	->	get_longest()
		-	ls_format.c		->	format_hlinks()
		-	(possibly other places, double check)
-	Double check on freeing structs

-	'format_*' functions do left padding. For right padding, instead of
	"ft_strjoin(pad, 'var')," swap 'pad' and ''var''.
	IE. "ft_strjoin('var', pad)"

-	'format_hlinks' and 'format_size' in 'ls_format.c' are over 25 lines
-	go over 'format_uname' and 'format_gname' in 'ls_format.c' and make sure
	the logic is all correct

-	'do_sort.c' doesn't use any "memory copying functions" (ft_strdup, etc),
	could this lead to errors?

-	Sorting done using original functions. May be possible to do ascending and
	descending in the same function instead of two separate functions, as it is
	now.

-	To have the output match macos 'ls', and extra ' ' char should be padded
	onto the member in question. Comapre outputs for more.

-	Seems to be a problem with 'perms' on certain files.
	(Tested on '.git' directory)
	-	'ft_ls2' doesn't have this problem ???
		(Maybe try fix padding in 'ft_ls2')
