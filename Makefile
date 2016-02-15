# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: droly <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/15 18:14:32 by droly             #+#    #+#              #
#    Updated: 2016/02/15 18:32:08 by droly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRC = apply_types.c		\
      apply_types2.c	\
      check_types.c		\
      ft_printf.c		\
      take_type.c		\

OBJ = $(SRC:.c=.o)

HEAD = ft_printf.h

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) makelibft
	@clang $(FLAGS) -c $(SRC) -I $(HEAD)
	@clang $(OBJ) libft/libft.a -o $(NAME)

makelibft:
	@make -C libft/
	@echo "Library included."

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	@echo "Objects cleaned."

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "Target cleaned."

re: fclean all

.PHONY: all makelibft clean fclean re
