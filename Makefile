# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 10:12:21 by kbrousse          #+#    #+#              #
#    Updated: 2022/08/17 15:12:43 by kbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT = libft/libft.a

SRC = main.c			\
	clear_program.c		\
	child_1_process.c	\
	parent_process.c	\
	check_args.c

SRCS = $(addprefix src/, $(SRC))

CC = gcc

FLAGS =	-Wall -Wextra -Werror -g

OBJS = $(SRCS:.c=.o)

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@echo "\033[0;32m~*~*~*~*~*~*~*~*~*~*~*~*~*~*~"
	@echo "*                           *"
	@echo "~     Clean terminated!     ~"
	@echo "*           pipex           *"
	@echo "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\033[0m"

fclean: clean
	@make fclean -C libft --no-print-directory
	@rm -f $(NAME) $(BONUS)

re: fclean all

.c.o:
	@$(CC) $(FLAGS) -c -o $@ $< 
 
$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -Llibft -lft -Ilibft -o $(NAME)
	@echo "\033[0;32m~*~*~*~*~*~*~*~*~*~*~*~*~*~*~"
	@echo "*                           *"
	@echo "~  Compilation terminated!  ~"
	@echo "*           pipex           *"
	@echo "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\033[0m"

$(LIBFT):
	@make -C libft --no-print-directory

.PHONY: all clean fclean bonus re
