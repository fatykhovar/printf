#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_list
{
	char			type;
	int				minus;
	int				zero;
	int				accur;
	struct s_list	*next;
}	t_list;
int		proc_c(char arg);
int		proc_s(char *arg);
void	hex_print(unsigned int arg, char reg, int *count);
int		proc_p(unsigned int arg);
int		proc_x(unsigned int arg, char reg);
void	dec_print(int nb, int *count);
int		proc_di(int arg);
void	unsign_print(int nb, int *count);
int		proc_u(unsigned int arg);
int		var_process(const char *str, int *count, va_list ap);
int		ft_printf(const char *str, ...);

#endif