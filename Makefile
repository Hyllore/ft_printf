# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: droly <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/15 18:14:32 by droly             #+#    #+#              #
#    Updated: 2016/02/17 13:55:58 by droly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = apply_types.c		\
	  apply_types2.c	\
	  check_types.c		\
	  ft_printf.c		\
	  take_type.c		\

SRCLIBFT = ft_memset.c		\
		   ft_bzero.c		\
		   ft_memcpy.c		\
		   ft_memccpy.c		\
		   ft_memmove.c		\
		   ft_memchr.c		\
		   ft_memcmp.c		\
		   ft_strlen.c		\
		   ft_strdup.c		\
		   ft_strcpy.c		\
		   ft_strncpy.c		\
		   ft_strcat.c		\
		   ft_strncat.c		\
		   ft_strlcat.c		\
		   ft_strchr.c		\
		   ft_strrchr.c		\
		   ft_strstr.c		\
		   ft_strnstr.c		\
		   ft_strcmp.c		\
		   ft_strncmp.c		\
		   ft_atoi.c		\
		   ft_isalpha.c		\
		   ft_isdigit.c		\
		   ft_isalnum.c		\
		   ft_isascii.c		\
		   ft_isprint.c		\
		   ft_toupper.c		\
		   ft_tolower.c		\
		   ft_memalloc.c	\
		   ft_memdel.c		\
		   ft_strnew.c		\
		   ft_strdel.c		\
		   ft_strclr.c		\
		   ft_striter.c		\
		   ft_striteri.c	\
		   ft_strmap.c		\
		   ft_strmapi.c		\
		   ft_strequ.c		\
		   ft_strnequ.c		\
		   ft_strsub.c		\
		   ft_strjoin.c		\
		   ft_strtrim.c		\
		   ft_itoa.c		\
		   ft_putchar.c		\
		   ft_putstr.c		\
		   ft_strsplit.c	\
		   ft_putendl.c		\
		   ft_putchar_fd.c	\
		   ft_putstr_fd.c	\
		   ft_putendl_fd.c	\
		   ft_putnbr.c		\
		   ft_putnbr_fd.c	\
		   ft_lstnew.c		\
		   ft_lstdelone.c	\
		   ft_lstdel.c		\
		   ft_lstadd.c		\
		   ft_lstmap.c		\
		   ft_lstiter.c		\
		   ft_utoa.c		\
		   ft_itoa_base.c	\
		   ft_putnbr_u.c

OBJ = $(SRC:.c=.o)

OBJLIBFT = $(SRCLIBFT:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -c $(addprefix  libft/,$(SRCLIBFT))
	@ar rc $(NAME) $(OBJ) $(OBJLIBFT)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) -o $@ -c $< $(FLAGS) -I libft/

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJLIBFT)

fclean: clean
	@rm -f $(NAME)

re: fclean all
