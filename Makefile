NAME = libftprintf.a

SRCS = 		src/printf.c\
		src/ft_print_nb.c\
		src/ft_print_u.c\
		src/ft_print_x.c\
		src/ft_print_add.c\
		src/ft_print_string.c\
		src/ft_print_character.c\
		src/ft_verif_struct.c\

O_FILES =   $(SRCS:.c=.o)

LIBFT   =       libft.a

CFLAGS =    -Wall -Wextra -Werror
 
HEADER =    ft_printf.h

.PHONY =    all clean fclean re bonus

all : $(NAME)

$(NAME):    $(LIBFT) $(O_FILES) 
	ar crs $(NAME) $(O_FILES)

$(LIBFT):
	cd libft; make re; make clean; cd ..
	cp libft/$(LIBFT) $(NAME)

.c.o:
	gcc $(CFLAGS) -I${HEADER} -c $< -o $(<:.c=.o)

clean:
	rm -rf $(O_FILES)

fclean: clean
	cd libft; rm -f $(LIBFT); cd ..
	rm -f $(NAME)

re : fclean all
