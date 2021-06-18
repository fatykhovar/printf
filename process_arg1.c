#include "ft_printf.h"

int	proc_c(char arg)
{
	write(1, &arg, 1);
	return (1);
}

int	proc_s(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		write(1, &arg[i], 1);
		i++;
	}
	return (i);
}

void	hex_print(unsigned int arg, char reg, int *count)
{
	char	c;

	if (arg < 0)
		return ;
	if (arg % 16 < 10)
		c = arg % 16 + '0';
	else
		c = reg + arg % 16 - 10;
	hex_print(arg / 16, reg, count);
	write (1, &c, 1);
	(*count)++;
}

int	proc_p(unsigned int arg)
{
	int	count;

	count = 2;
	write(1, "0x", 2);
	hex_print(arg, 'A', &count);
	return (count);
}

int	proc_x(unsigned int arg, char reg)
{
	int	count;

	count = 0;
	if (reg == 'x')
		hex_print(arg, 'a', &count);
	if (reg == 'X')
		hex_print(arg, 'A', &count);
	return (count);
}

void	dec_print(int nb, int *count)
{
	char	c;

	c = nb % 10 + '0';
	if (nb <= 0)
	{
		return ;
	}
	dec_print(nb / 10, count);
	write(1, &c, 1);
	(*count)++;
}

int	proc_di(int arg)
{
	int	count;

	count = 0;
	if (arg == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (arg == 0)
		{
			write(1, "0", 1);
			return (1);
		}
		else
		{
			if (arg > 0)
				dec_print(arg, &count);
			else
			{
				write(1, "-", 1);
				dec_print(-1 *arg, &count);
			}
			return (count);
		}
	}
}

void	unsign_print(int nb, int *count)
{
	char	c;

	c = nb % 10 + '0';
	if (nb <= 0)
	{
		return ;
	}
	unsign_print(nb / 10, count);
	write(1, &c, 1);
	(*count)++;
}

int	proc_u(unsigned int arg)
{
	int	count;

	count = 0;
	if (arg == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		unsign_print(arg, &count);
		return (count);
	}
}

