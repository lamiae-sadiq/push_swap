/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:39:49 by lsadiq            #+#    #+#             */
/*   Updated: 2023/04/11 21:45:04 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_push
{
	struct s_push	*next;
	int				num;
	int				index;
}t_push;

typedef struct s_swap
{
	t_push	*top;
}t_swap;

t_push	*ft_stacklast(t_push *lst);
t_push	*ft_stacknew(int content);
int		check_double(t_push *str);
int		ft_strcmp(char *s1, char *s2);
int		check_sort(t_push **stack);
int		find_smallest(t_push **stack);
int		ft_lstsizee(t_push **stack);
int		sorted_arr(int *a);
void	swap(t_push *stack);
void	ft_stackadd_back(t_push **lst, t_push *new);
bool	check_int(char **str);
void	lastfirst(t_push **head);
void	firstlast(t_push *stack);
void	push(t_push *stack1, t_push *stack2);
void	move_sa(t_push **stack, int flag);
void	move_sb(t_push **stack, int flag);
void	move_ra(t_push **stack, int flag);
void	move_rb(t_push **stack, int flag);
void	move_ss(t_push **stack1, t_push **stack2, int flag);
void	move_rr(t_push **stack1, t_push **stack2, int flag);
void	move_rra(t_push **stack, int flag);
void	move_rrb(t_push **stack, int flag);
void	move_rrr(t_push **stack1, t_push **stack2, int flag);
void	move_pa(t_push **stack_b, t_push **stack_a, int flag);
void	move_pb(t_push **stack1, t_push **stack2, int flag);
void	sort_three(t_push **stack);
void	sort_four(t_push **stack1, t_push **stack2);
void	sort_five(t_push **stack1, t_push **stack2);
void	sorting(t_push **stack1, t_push **stack2, int ac);
void	stack_to_arr(t_push **stack, int *array);
void	sort_arr(int *arr, int size);
void	sort_big_numbers(t_push **stack1, t_push **stack2, int *arr, int i);
void	move_to_stack_b(t_push **stack1, t_push **stack2, int size, int chunk);
void	ft_assign_index(t_push **stack, int *arr, int size);
void	ft_assignn_index(t_push **lst, int *arr);
void	back_to_a(t_push **stack1, t_push **stack2, int size);
void	fill_stack(int ac, char **av, t_push **stack);
char	*get_next_line(int fd);

#endif