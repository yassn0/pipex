# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 14:25:32 by yfradj            #+#    #+#              #
#    Updated: 2025/01/23 12:40:02 by yfradj           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Werror -Wextra

WAY = srcs/pipex/
WAY_BONUS = srcs/pipex_bonus/

SRCS = \
	$(WAY)main.c \
	$(WAY)path.c \
	
SRCS_BONUS = \
	$(WAY_BONUS)main_bonus.c \
	$(WAY_BONUS)main_case.c \
	$(WAY_BONUS)utils.c \
	$(WAY_BONUS)limiter.c \
	$(WAY_BONUS)special_case.c \
	$(WAY_BONUS)path.c \
	$(WAY_BONUS)free.c \
	
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = pipex
NAME_BONUS = pipex_bonus

$(NAME): $(OBJS)
	@make -C libft --no-print-directory
	$(CC) $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)

bonus : $(OBJS_BONUS)
	@make -C libft --no-print-directory
	$(CC) $(FLAGS) $(OBJS_BONUS) libft/libft.a -o $(NAME_BONUS)
	
clean:
	@make clean -C libft --no-print-directory
	@rm -f $(OBJS) $(OBJS_BONUS)
	
fclean: clean
	@make fclean -C libft --no-print-directory
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all fclean clean bonus re

