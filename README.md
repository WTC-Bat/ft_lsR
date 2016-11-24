# ft_lsR

-	Check "ls_funcs.c -> ls_getpath" for leaks (Possible)
-	Error in libft -> ft_itoa
-	Should the ('t_ls') struct be reset to it's root after iterating through it?
	-	t_ls resets in:
		-	get_longest.c	->	get_longest()
		-	ls_format.c		->	format_hlinks()
		-	(possibly other places, double check)
