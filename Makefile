# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 15:31:20 by obouadel          #+#    #+#              #
#    Updated: 2021/12/20 16:14:56 by obouadel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

CHECKER= checker

LIBFT_DIR= ./libft
LIBFT_LIB= $(LIBFT_DIR)/libft.a

GNL_FILES=	./gnl/get_next_line.c \
			./gnl/get_next_line_utils.c \

GNL_HEADER=	./gnl/get_next_line.h

HEADER= push_swap.h \
		./libft/libft.h \

CC= gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = 	push_swap.c \
		check_sort.c \
		end_program.c \
		rotate.c \
		push_a.c \
		push_b.c \
		data_init.c \
		swap.c \
		data_check.c \
		reverse_rotate.c \

SRCS_CHECKER = 	./checkerfiles/checker.c \
				./checkerfiles/check_sort.c \
				./checkerfiles/end_program.c \
				./checkerfiles/rotate.c \
				./checkerfiles/push_a.c \
				./checkerfiles/push_b.c \
				./checkerfiles/data_init.c \
				./checkerfiles/swap.c \
				./checkerfiles/data_check.c \
				./checkerfiles/reverse_rotate.c \
				./checkerfiles/double_instruct.c \
		
OBJS = $(SRCS:.c=.o)
OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

all: $(NAME)
	@echo "\033[30;1m---> \033[0m PUSH_SWAP  \033[32;1m [OK] \033[0m"
%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT_LIB) $(HEADER) 
	@$(CC) $(CFLAGS) $(LIBFT_LIB) $(OBJS) -o $(NAME)

$(CHECKER): $(OBJS_CHECKER) $(LIBFT_LIB) $(HEADER) $(GNL_HEADER)
	@$(CC) $(CFLAGS) $(GNL_FILES) $(LIBFT_LIB) $(OBJS_CHECKER) -o $(CHECKER)
	@echo "\033[30;1m---> \033[0m CHECKER    \033[32;1m [OK] \033[0m"

$(LIBFT_LIB): 
	@make -C $(LIBFT_DIR)
	@echo "\033[30;1m---> \033[0m LIBFT      \033[32;1m [OK] \033[0m"

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_CHECKER)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "\033[30;1m---> \033[0m CLEAN      \033[32;1m [OK] \033[0m"


fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(CHECKER)
	@$(RM) $(LIBFT_LIB)

re: fclean all

.PHONY: all clean fclean re