CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = ft_printchar.c ft_printf.c ft_printhex.c ft_printhexc.c ft_printint.c ft_printptr.c\
ft_printstr.c ft_printuint.c ft_swap.c helper.c push_swap.c

OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h push_swap.h

NAME = push_swap

all : $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@
		
clean:		 
	$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)
			
re:		fclean $(NAME)

.PHONY : all clean fclean re
