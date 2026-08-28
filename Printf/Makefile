NAME = libftprintf.a

CC = cc
WFLAGS = -Wall -Wextra -Werror

SOURCE = count_hex_len.c print_pointer.c print_hex.c ft_printf.c \
		print_symbol.c print_string.c print_number.c
OBJECT = $(SOURCE:.c=.o)

HEADER = ft_printf.h

AR = ar
ARFLAGS = -rcs

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJECT)
	$(AR) $(ARFLAGS) $(NAME) $(OBJECT)

%.o : %.c $(HEADER)
	$(CC) $(WFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJECT)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
