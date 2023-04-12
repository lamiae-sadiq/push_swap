/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:08:13 by lsadiq            #+#    #+#             */
/*   Updated: 2023/04/11 21:38:42 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_push **stack)
{
	t_push	*new;
	int		i;
	int		j;
	int		k;

	new = *stack;
	i = (*stack)->num;
	j = (*stack)->next->num;
	k = (*stack)->next->next->num;
	if (i < j && j > k && i > k)
		move_rra(stack, 1);
	if (i > k && i > j && j > k)
	{
		move_sa(stack, 1);
		move_rra(stack, 1);
	}
	if (i < j && i < k && j > k)
	{
		move_rra(stack, 1);
		move_sa(stack, 1);
	}
	if (i > j && j < k && k > i && k > j)
		move_sa(stack, 1);
	if (i > j && i > k && j < k)
		move_ra(stack, 1);
}

void	sort_four(t_push **stack1, t_push **stack2)
{
	t_push	*new;
	int		min;

	new = *stack1;
	min = find_smallest(stack1);
	while (new->next)
	{
		if (new->num == min)
		{
			move_pb(stack1, stack2, 1);
			sort_three(stack1);
			move_pa(stack2, stack1, 1);
			break ;
		}
		else if (new->num != min)
			move_rra(stack1, 1);
		new = *stack1;
	}
}

int	find_smallest(t_push **stack)
{
	t_push	*head;
	int		min;

	head = *stack;
	min = (*stack)->num;
	while (head)
	{
		if (head->num < min)
			min = head->num;
		head = head->next;
	}
	return (min);
}

void	sort_five(t_push **stack1, t_push **stack2)
{
	t_push	*new;
	int		min;

	new = *stack1;
	min = find_smallest(stack1);
	while (new)
	{
		if (new->num == min)
		{
			move_pb(stack1, stack2, 1);
			sort_four(stack1, stack2);
			move_pa(stack2, stack1, 1);
			break ;
		}
		else if (new->num != min)
			move_rra(stack1, 1);
		new = *stack1;
	}
}
