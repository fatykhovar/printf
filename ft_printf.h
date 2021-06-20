#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_list
{
	int	minus;
	int	zero;
	int	width;
	int	accur;
}	t_list;
int		proc_c(char arg, t_list cur_list);
int		proc_s(char *arg, t_list cur_list);
void	hex_print(unsigned int arg, char reg, int *count);
int		proc_p(unsigned int arg, t_list cur_list);
int		proc_x(unsigned int arg, char reg, t_list cur_list);
void	dec_print(int nb, int *count);
int		proc_di(int arg, t_list cur_list);
void	unsign_print(int nb, int *count);
int		proc_u(unsigned int arg, t_list cur_list);
int		flags_accur(const char *str, int *count, t_list *cur_list, va_list ap);
int		flags(char *str, int *count, t_list *cur_list, va_list ap);
void	main_cycle(va_list ap, char *str, int *count);
int		var_process(char *str, int *count, va_list ap);
int		ft_printf(const char *str, ...);

#endif