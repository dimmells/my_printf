# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/29 14:45:07 by ahryhory          #+#    #+#              #
#    Updated: 2018/02/21 19:14:50 by dmelnyk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

SRC =

SRC += ft_printf.c
SRC += get_specifier_len.c
SRC += max.c
SRC += print_arg.c
SRC += print_str.c
SRC += print_int.c
SRC += print_percent.c
SRC += print_hex.c
SRC += print_octal.c
SRC += print_ui.c
SRC += print_char.c
SRC += print_wchar_t.c
SRC += print_pointer.c
SRC += print_wstr.c
SRC += get_flag.c
SRC += get_length.c
SRC += get_precision.c
SRC += get_width.c
SRC += get_specifier_info.c
SRC += get_bin_size.c
SRC += get_size_wchar_t.c
SRC += get_argument_int.c
SRC += get_argument_base.c
SRC += struct_init.c
SRC += add_space_tostr.c
SRC += add_zeroes.c
SRC += add_sign.c
SRC += add_precision.c
SRC += add_space.c
SRC += add_space_towstr.c
SRC += itoa_base.c
SRC += ft_putwchar_t.c
SRC += ft_putwstr.c
SRC += ft_str_toupper.c
SRC += ft_wstrlen.c
SRC += ft_strcat.c
SRC += ft_strcmp.c
SRC += ft_strdup.c
SRC += ft_striteri.c
SRC += ft_strlen.c
SRC += ft_strncat.c
SRC += ft_strnequ.c
SRC += ft_strsplit.c
SRC += ft_strtrim.c
SRC += ft_strchr.c
SRC += ft_strcpy.c
SRC += ft_strequ.c
SRC += ft_strjoin.c
SRC += ft_strmap.c
SRC += ft_strncmp.c
SRC += ft_strnew.c
SRC += ft_strstr.c
SRC += ft_strnstr.c
SRC += ft_strclr.c
SRC += ft_strdel.c
SRC += ft_striter.c
SRC += ft_strlcat.c
SRC += ft_strmapi.c
SRC += ft_strncpy.c
SRC += ft_strrchr.c
SRC += ft_strsub.c
SRC += ft_isascii.c
SRC += ft_isdigit.c
SRC += ft_isprint.c
SRC += ft_isalpha.c
SRC += ft_toupper.c
SRC += ft_tolower.c
SRC += ft_atoi.c
SRC += ft_itoa.c
SRC += ft_bzero.c
SRC += ft_isalnum.c
SRC += ft_putchar.c
SRC += ft_putchar_fd.c
SRC += ft_putendl.c
SRC += ft_putendl_fd.c
SRC += ft_putnbr.c
SRC += ft_putnbr_fd.c
SRC += ft_putstr.c
SRC += ft_putstr_fd.c
SRC += ft_memalloc.c
SRC += ft_memccpy.c
SRC += ft_memchr.c
SRC += ft_memcmp.c
SRC += ft_memcpy.c
SRC += ft_memdel.c
SRC += ft_memmove.c
SRC += ft_memset.c
SRC += ft_lstnew.c
SRC += ft_lstdelone.c
SRC += ft_lstdel.c
SRC += ft_lstadd.c
SRC += ft_lstiter.c
SRC += ft_lstmap.c
SRC += ft_strsort.c
SRC += ft_lstaddlast.c
SRC += ft_itoa_base.c
SRC += ft_intsort.c

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@gcc $(FLAGS) -I. -c $<

clean:
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)
re:	fclean all

