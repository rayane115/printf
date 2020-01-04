NAME = libft.a
SRCS = main.c\
		src/printf.c\
		src/ft_print_nb.c\
		src/ft_print_u.c\
		src/ft_print_x.c\
		src/ft_print_add.c\
		src/ft_print_string.c\
		src/ft_print_character.c\
		src/ft_verif_struct.c\


FLAGS = -Wall -Wextra  -Werror -g3
INCLUDES = include/ft_printf.h
LIB = libft/libft.a

all:	${NAME}

$(NAME):
	@(make -C libft)
	@(gcc $(FLAGS) $(SRCS) $(LIB) -I $(INCLUDES))
	@(./a.out)

clean:

f :
	@(make -C libft)
	@(gcc $(FLAGS) -fsanitize=address $(SRCS) $(LIB) -I $(INCLUDES))
	@(./a.out)

fclean:	clean
	@(make fclean -C libft)
	@(rm -rf a.out.dSYM)
	@(rm -rf a.out)

re:	fclean all

.PHONY:	all clean fclean re
