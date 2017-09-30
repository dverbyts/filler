# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/22 15:14:37 by dverbyts          #+#    #+#              #
#    Updated: 2017/09/22 15:14:38 by dverbyts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

CFLAGS = -Wall -Wextra -Werror

SRC = filler.c filler_check.c filler_read.c

OBJ = $(SRC:.c=.o)

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	@gcc $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all
