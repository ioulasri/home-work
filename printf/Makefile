SRCS = srcs/ft_printf.c srcs/ft_functions1.c srcs/ft_functions2.c srcs/ft_functions3.c
NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)
LIB = ar rc
CC = cc
RM = rm -rf
CFLAGS =

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)
	$(CC) $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all