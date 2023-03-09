# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 02:27:46 by lsadiq            #+#    #+#              #
#    Updated: 2023/03/03 02:28:09 by lsadiq           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
SRCS	=	main.c 

OBJS	=	$(SRCS:.c=.o)

CC		=	cc

CFLAGS 	= 	-Wall -Wextra -Werror 

AR 		= ar rc


LINKS = \
    -I /usr/local/include -L /usr/local/lib \
     -lmlx -framework OpenGL -framework AppKit


LIBFT = libft/libft.a

NONE	=	'\033[0m'
GREEN	=	'\033[32m'
RED		=	'\033[1;91m'
GRAY	=	'\033[2;37m'
ITALIC	=	'\033[3m'

.c.o	:
			@echo $(ITALIC)$(GRAY) "    Compiling $<" $(NONE)
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all		:	$(NAME)

$(NAME)	: 	 $(LIBFT) $(OBJS)
			@echo $(GREEN) "Compiling $(NAME)..." $(NONE)
			@$(CC) $(CFLAGS) $(LINKS) $(OBJS) libft/libft.a -o $(NAME)
			@echo $(GREEN) "\n ~ Compiled !!" $(NONE)

$(LIBFT) :
			@echo $(GREEN) "Compiling libft..." $(NONE)
			@make -C libft/

clean	:
			@echo $(RED) "Removing libft..." $(NONE)
			@make clean -C libft/
			@echo $(RED) "Removing object files..." $(NONE)
			@rm -rf $(OBJS)

fclean	:	clean
			@echo $(RED) "Removing $(NAME)..." $(NONE)
			@rm -f $(NAME) $(NAME)
			@rm -rf libft/libft.a

re		:	fclean $(NAME)