/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:08:34 by lsadiq            #+#    #+#             */
/*   Updated: 2023/03/30 01:32:55 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_push **stack)
{
	t_push *tmp;

	tmp = *stack;
	while(tmp->next)
	{
	if (tmp->num > tmp->next->num)
	return(0);
	tmp = tmp->next;
	}
	return(1);
}

void	sort_three(t_push **stack)
{
	t_push *new;

	new = *stack;
	int i = (*stack)->num;
	int j = (*stack)->next->num;
	int k = (*stack)->next->next->num;
	// 2  12  0  ==> 0 2 12
	if (i < j && j > k && i > k)
		move_rra(stack);
	// 12 2 0 ===> 2 12 0 ===> 0 2 12 
	if (i > k && i > j && j > k)
	{
		move_sa(stack, 1);
		move_rra(stack);
	}
	// 0 12 2 ==> 2 0 12 ===> 0 2 12
	if (i < j && i < k && j > k)
	{
		move_rra(stack);
		move_sa(stack, 1);
	}
	// 2 0 12 ==> 0 2 12
	if (i > j && j < k && k > i && k > j)
		move_sa(stack, 1);
	// 12 0 2 ==> 0 2 12
	if (i > j && i > k && j < k)
		move_ra(stack);
}

void	sort_four(t_push **stack1, t_push **stack2)
{
	t_push *new;

	new = *stack1;

	while(new->next)
	{
		
	}
	
}