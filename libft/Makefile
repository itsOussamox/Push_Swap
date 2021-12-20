# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 10:36:02 by obouadel          #+#    #+#              #
#    Updated: 2021/12/13 19:54:01 by obouadel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
FLAGS=-Wall -Wextra -Werror
AR= ar rcs
RM =rm  -rf
FILES= ft_isdigit ft_memset ft_strjoin ft_isprint\
	ft_putchar_fd ft_strlcat ft_substr ft_atoi ft_itoa ft_putendl_fd\
	ft_strlcpy ft_tolower ft_bzero ft_putnbr_fd ft_strlen\
	ft_toupper ft_calloc ft_memchr ft_putstr_fd ft_strmapi ft_isalnum\
	ft_memcmp ft_strncmp ft_isalpha ft_memcpy ft_strchr\
	ft_strnstr ft_isascii ft_memmove ft_strdup ft_strrchr\
	ft_strtrim ft_striteri ft_split
BONUSFILES= ft_lstadd_front ft_lstnew ft_lstsize ft_lstlast ft_lstadd_back\
	ft_lstdelone ft_lstiter ft_lstclear
SRC = $(FILES:=.c)
OBJ= $(FILES:=.o)
BONUS_OBJS= $(BONUSFILES:=.o)
NAME =libft.a


all: $(NAME) clean

$(NAME):$(OBJ)
	@$(AR) $(NAME) $(OBJ)
%.o : %.c libft.h
	@$(CC) $(FLAGS) -c $< -o $@

bonus: $(BONUS_OBJS)
	@$(AR) $(NAME) $(BONUS_OBJS)
clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJ) $(BONUS_OBJS)

fclean: clean
	@$(RM) $(NAME)

re : fclean all

.PHONY:all clean fclean re