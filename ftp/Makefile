# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souahidi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 11:40:23 by souahidi          #+#    #+#              #
#    Updated: 2023/11/22 20:20:09 by souahidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS	=	-Wall -Wextra -g\
#-Werror

NAME		=	libftprintf.a

LIBFT		=	./libft/libft.a

SRC_DIRS= ./src
INC_DIRS= ./includes

CFILES 	= ft_printf.c \
		  flags_handle_1.c specifier_handle_1.c utiles.c print_flags.c \
		  initializer.c get_functions.c
## CBFILES = _bonus.c \

CHEADER = ft_printf.h
## CBHEADER= ft_printf_bonus.h

OFILES	=	$(CFILES:.c=.o)
## OBFILES = $(CBFILES:.c=.o)

AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OFILES)

.c.o:
	$(CC) $(CFLAGS) -I. -c $< -o $@
	$(AR) $(NAME) $@

## bonus: $(OBFILES)

m:$(NAME) $(LIBFT)
	$(CC) $(CFLAGS) main.c $(NAME) $(LIBFT)


mf:$(NAME)
	$(CC) $(CFLAGS) -g -fsanitize=address main.c libftprintf.a

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean m

.PHONY: all clean fclean re bonus
