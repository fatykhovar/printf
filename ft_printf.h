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
int		min_number(int a, int b);
int		s_count(char *arg);
int		write_s(char *arg, t_list cur_list);
int		proc_s(char *arg, t_list cur_list);
void	hex_print(size_t arg, char reg, int *count);
int		print_p(size_t arg, int count, t_list cur_list);
int		proc_p(size_t arg, t_list cur_list);
int		hex_symb_count(size_t nb);
int		not_minus_x(unsigned int arg, char reg, int count, t_list cur_list);
int		proc_x(unsigned int arg, char reg, t_list cur_list);
void	dec_print(int nb, int *count);
int		symb_count(int nb, t_list cur_list);
int		max_number(int a, int b);
int		write_zero(int count);
int		write_space(int count);
int		print_neg(int count, int arg);
int		minus_pos(int count, int symbols, int arg, t_list cur_list);
int		neg(int count, int symbols, int arg, t_list cur_list);
int		pos(int count, int symbols, int arg, t_list cur_list);
int		proc_di(int arg, t_list cur_list);
void	unsign_pos_print(unsigned int nb, int *count);
int		unsign_symb_count(unsigned int nb);
int		unsigned_print(int count, unsigned int arg);
int		not_minus_u(int count, t_list cur_list, int symbols, unsigned int arg);
int		proc_u(unsigned int arg, t_list cur_list);
int		flags_accur(const char *str, t_list *cur_list, va_list ap);
int		flags(char *str, int i, t_list *cur_list, va_list ap);
void	main_cycle(va_list ap, char *str, int *count);
int		var_process(char *str, int *count, va_list ap);
int		ft_printf(const char *str, ...);

#endif