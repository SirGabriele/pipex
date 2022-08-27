# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 10:12:21 by kbrousse          #+#    #+#              #
#    Updated: 2022/08/27 17:11:32 by kbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

BONUS = .bonus_verif.txt

LIBFT = libft/libft.a

SRC = main.c		\
	clear_program.c

SRC_BONUS = main_bonus.c	\
	clear_program_bonus.c

INIT = init_pipex.c

INIT_BONUS = init_pipex.c		\
	init_pipex_here_doc_bonus.c

CHECK = check_args.c		\
	verify_files_access.c	\
	verify_cmd_access.c

CHECK_BONUS = check_args_bonus.c	\
	verify_files_access.c			\
	verify_files_access_here_doc.c	\
	verify_cmd_access.c				\
	verify_cmd_access_here_doc.c

LL = ft_lstnew_pipex.c		\
	ft_lstaddback_pipex.c

EXEC =	two_commands_requested.c

EXEC_BONUS = prepare_bonus.c			\
	two_commands_requested_bonus.c		\
	several_commands_requested_bonus.c	\
	here_doc_requested.c

SRCS = $(addprefix src/, $(SRC))		\
	$(addprefix src/init/, $(INIT))		\
	$(addprefix src/check/, $(CHECK))	\
	$(addprefix src/LL/, $(LL))			\
	$(addprefix src/exec/, $(EXEC))

SRCS_BONUS = $(addprefix src/, $(SRC_BONUS))	\
	$(addprefix src/init/, $(INIT_BONUS))		\
	$(addprefix src/check/, $(CHECK_BONUS))		\
	$(addprefix src/LL/, $(LL))					\
	$(addprefix src/exec/, $(EXEC_BONUS))

CC = gcc

FLAGS =	-Wall -Wextra -Werror -g

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
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

$(BONUS): $(LIBFT) $(OBJS_BONUS)
	@$(CC) $(FLAGS) $(OBJS_BONUS) -Llibft -lft -Ilibft -o $(NAME)
	@echo "\033[0;32m~*~*~*~*~*~*~*~*~*~*~*~*~*~*~"
	@echo "*                           *"
	@echo "~  Compilation terminated!  ~"
	@echo "*           pipex           *"
	@echo "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\033[0m"
	@touch $(BONUS)

bonus: $(BONUS)

$(LIBFT):
	@make -C libft --no-print-directory

.PHONY: all clean fclean bonus re
