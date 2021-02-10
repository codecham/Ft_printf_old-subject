LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS =      ft_printf.c 						\
			sources/ft_flags_display.c 			\
			sources/ft_flags_parse.c 			\
			sources/ft_flags.c					\
			sources/ft_itoa_hexa.c				\
			sources/ft_print_char.c				\
			sources/ft_print_hexa.c				\
			sources/ft_print_int.c				\
			sources/ft_print_pointeur.c			\
			sources/ft_print_pourcent.c			\
			sources/ft_print_string.c			\
			sources/ft_print_unsigned_int.c		\
			sources/ft_print_var.c				\
			sources/ft_uitoa.c					\
			sources/ft_utils.c					\
			sources/ft_utils2.c					\
			sources/ft_litoa.c
		
SURPL_O = 	ft_flags_display.o 			\
			ft_flags_parse.o 			\
			ft_flags.o					\
			ft_itoa_hexa.o				\
			ft_print_char.o				\
			ft_print_hexa.o				\
			ft_print_int.o				\
			ft_print_pointeur.o			\
			ft_print_pourcent.o			\
			ft_print_string.o			\
			ft_print_unsigned_int.o		\
			ft_print_var.o				\
			ft_uitoa.o					\
			ft_utils.o					\
			ft_utils2.o					\
			ft_litoa.o

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O) 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
