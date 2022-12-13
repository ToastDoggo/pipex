# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rehernan <rehernan@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 17:13:43 by rehernan          #+#    #+#              #
#    Updated: 2022/06/06 17:58:17 by rehernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = ./SRC/pipex.c ./SRC/main_n_check.c ./SRC/utils.c

HEADER_FILES = ./SRC/pipex.h ./ft_printf/ft_printf.h ./ft_printf/libft/libft.h

CFLAGS = -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

$(NAME): $(SRC) ft_printf/libftprintf.a
	$(CC) $(SRC) $(CFLAGS) -g libftprintf.a -o $(NAME)
	@echo "Compiled succesfully!"
ft_printf/libftprintf.a:
	make -C ft_printf
	cp ft_printf/libftprintf.a .
	@echo "Making libftprintf..."
clean:
	@echo "Executable files are gone."
fclean: clean
	rm -f $(NAME)
	make -C ft_printf fclean
	rm -f libftprintf.a
	@echo "This is squeaky clean!"
re: fclean all
	@echo "Compiling again was succesful!"

.PHONY: all clean fclean re