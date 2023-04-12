NAME	=	push_swap
BONUS_NAME	= 	checker_me
SRCS	=	push_swap.c stack_utils.c check_int.c small_sort.c swap.c rotate.c rev_rot.c push.c sort.c big_numbers.c cnv_stack.c
BSRCS	= 	checker.c get_next_line.c get_next_line_utils.c stack_utils.c check_int.c small_sort.c swap.c rotate.c rev_rot.c push.c sort.c big_numbers.c cnv_stack.c

OBJS	=	$(SRCS:.c=.o)
BOBJS	=	$(BSRCS:.c=.o)
CC		=	cc

CFLAGS 	= 	-Wall -Wextra -Werror #-fsanitize=address -g3

AR 		= ar rc

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
			@$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)
			@echo $(GREEN) "\n ~ Compiled !!" $(NONE)

$(LIBFT) :
			@echo $(GREEN) "Compiling libft..." $(NONE)
			@make -C libft/
			@make bonus -C libft/

bonus :		$(LIBFT) $(BOBJS)
			@echo $(GREEN) "Compiling $(NAME)..." $(NONE)
			@$(CC) $(CFLAGS) $(BOBJS) libft/libft.a -o $(BONUS_NAME)
			@echo $(GREEN)"- Compiled -"$(NONE)
clean	:
			@echo $(RED) "Removing libft..." $(NONE)
			@make clean -C libft/
			@make clean -C libft/
			@echo $(RED) "Removing object files..." $(NONE)
			@rm -rf $(OBJS) $(BOBJS)

fclean	:	clean
			@echo $(RED) "Removing $(NAME)..." $(NONE)
			@rm -f $(NAME) $(BONUS_NAME)
			@rm -rf libft/libft.a


re		:	fclean $(NAME)