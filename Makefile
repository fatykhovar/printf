SRCS =		ft_printf.c proc_c.c proc_di_utils.c proc_di.c proc_p.c\
			proc_s.c proc_u.c proc_u_utils.c proc_x.c
OBJS =		$(SRCS:.c=.o)
NAME =		libftprintf.a
GCC =		gcc
ARRC =		ar rc
RLIB =		ranlib
RM =		rm -f
CFLAGS =	-Wall -Wextra -Werror

.c.o:
			$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(ARRC) $(NAME) $(OBJS)
			$(RLIB) $(NAME)

clean:
			$(RM) $(OBJS)
			
fclean:		clean
			$(RM) $(NAME) 

re:			fclean all

.PHONY:		all clean clean fclean re