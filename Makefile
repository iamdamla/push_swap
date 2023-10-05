# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: derblang <derblang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 10:09:46 by derblang          #+#    #+#              #
#    Updated: 2023/03/20 11:16:33 by derblang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = srcs/main.c srcs/ft_check_args.c srcs/utils.c srcs/ft_newnode.c srcs/ft_stackadd_bottom.c \
		srcs/ft_stacknew.c srcs/ft_stackadd_top.c srcs/ft_stackinsert.c srcs/ft_stackdisplay.c \
		srcs/ft_stacksize.c srcs/ft_stackclear.c srcs/actions.c srcs/rules1.c srcs/rules2.c \
		srcs/rules3.c srcs/algorithm.c srcs/algorithm2.c srcs/position.c
	
OBJS =  ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
		@$(MAKE) -C ./libft
		@gcc $(FLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

debug: $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -fsanitize=address -o $(NAME)

clean:
		@$(RM) $(OBJS)
		@$(MAKE) clean -C ./libft
		
fclean: clean
		@$(RM) $(NAME)
		@$(MAKE) fclean -C ./libft
		
re: fclean all

.PHONY: all clean fclean re libmlx