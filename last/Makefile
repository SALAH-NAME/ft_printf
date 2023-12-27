# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souahidi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 11:40:23 by souahidi          #+#    #+#              #
#    Updated: 2023/12/27 11:48:22 by souahidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

NAME		=	libftprintf.a

CFILES 		=	ft_printf.c ft_onset.c ft_put_char.c reset_flags.c ft_handler.c \
				get_functions.c ft_initializer.c handle_point.c handle_minus.c \
				handle_hash.c handle_space.c handle_zero.c handle_width.c ft_put_nchar.c \
				mask_flags.c handle_char.c ft_print_sign.c ft_print_width.c ft_print_prefix.c \
				ft_print_zero.c ft_put_nstr.c handle_str.c ft_put_base.c ft_put_str.c ft_len_unbr.c \
				handle_lhex.c handle_uhex.c handle_uint.c handle_nbr.c ft_put_nbr.c ft_len_nbr.c handle_ptc.c\
				ft_atoi.c ft_isdigit.c ft_strlen.c handle_plus.c handle_add.c

CHEADER 	=	ft_printf.h

OFILES		=	$(CFILES:.c=.o)

AR 			= 	ar rcs
RM 			=	rm -f

all: $(NAME)

$(NAME): $(OFILES)

.c.o:
	$(CC) $(CFLAGS) -I. -c $< -o $@
	$(AR) $(NAME) $@

bonus:$(NAME)

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
