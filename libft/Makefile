# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrousse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 12:29:47 by kbrousse          #+#    #+#              #
#    Updated: 2022/07/20 20:42:03 by kbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CHAR  =		ft_isalpha.c       \
			ft_isdigit.c       \
			ft_isalnum.c       \
			ft_isascii.c       \
			ft_isprint.c       \
			ft_toupper.c       \
			ft_tolower.c       \
			ft_strupcase.c     \
			ft_strlowcase.c    \
			ft_strcapitalize.c

STR   =		ft_strlen.c    \
			ft_strlcat.c   \
			ft_strlcpy.c   \
			ft_strcpy.c    \
			ft_strncpy.c   \
			ft_strchr.c    \
			ft_strrchr.c   \
			ft_strncmp.c   \
			ft_strnstr.c   \
			ft_strjoin.c   \
			ft_substr.c    \
			ft_strmapi.c   \
			ft_strtrim.c   \
			ft_striteri.c  \
			ft_split.c     \
			ft_strdup.c    \
			ft_extension.c 

MEMORY =	ft_memset.c  \
			ft_bzero.c   \
			ft_memcpy.c  \
			ft_memmove.c \
			ft_calloc.c  \
			ft_memchr.c  \
			ft_memcmp.c  \

OUTPUT =	ft_putchar.c    \
			ft_putchar_fd.c \
			ft_putstr_fd.c  \
			ft_putstr.c     \
			ft_putendl_fd.c \
			ft_putnbr_fd.c  \
			ft_putnbr.c

OTHER  =	ft_itoa.c \
			ft_atoi.c

LL     =	ft_lstnew.c       \
			ft_lstadd_front.c \
			ft_lstadd_back.c  \
			ft_lstsize.c      \
			ft_lstlast.c      \
			ft_lstiter.c      \
			ft_lstdelone.c    \
			ft_lstclear.c     \
			ft_lstmap.c

GNL_TDL    =	get_next_line_bonus.c       \
				get_next_line_utils_bonus.c

FT_PRINTF =	ft_printf.c              \
			ft_printer_functions.c   \
			ft_specifier_requested.c 

FT_PRINTF_ERROR = ft_printf_error.c				\
				ft_printer_functions_error.c	\
				ft_specifier_asked_error.c 

SRCS   =	$(addprefix CHAR/, $(CHAR))					\
			$(addprefix STR/, $(STR))					\
			$(addprefix MEMORY/, $(MEMORY))				\
			$(addprefix PUT/, $(OUTPUT))				\
			$(addprefix ATOI-ITOA/, $(OTHER))			\
			$(addprefix LL/, $(LL))						\
			$(addprefix GNL_TDL/, $(GNL_TDL))				\
			$(addprefix FT_PRINTF/, $(FT_PRINTF))			\
			$(addprefix FT_PRINTF_ERROR/, $(FT_PRINTF_ERROR))
	

FLAGS =	-Wall -Wextra -Werror

OBJS =	$(SRCS:.c=.o)

CC =	gcc

all: $(NAME)
	
clean:
	@rm -f $(OBJS)
	@echo "\033[0;32m~*~*~*~*~*~*~*~*~*~*~*~*~*~*~"
	@echo "*                           *"
	@echo "~     Clean terminated!     ~"
	@echo "*           libft           *"
	@echo "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\033[0m"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.c.o:
	@$(CC) $(FLAGS) -I. -c $< -o $@ 
 
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "\033[0;32m~*~*~*~*~*~*~*~*~*~*~*~*~*~*~"
	@echo "*                           *"
	@echo "~  Compilation terminated!  ~"
	@echo "*           libft           *"
	@echo "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\033[0m"


.PHONY: all clean fclean re bonus
