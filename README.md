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
