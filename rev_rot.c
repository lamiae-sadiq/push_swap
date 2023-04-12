/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:05:25 by lsadiq            #+#    #+#             */
/*   Updated: 2023/04/11 21:28:54 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_rra(t_push **stack, int flag)
{
	t_push	*first;
	t_push	*new;

	first = *stack;
	if (first == NULL || first->next == NULL)
		return ;
	new = (*stack)->next;
	while (new->next)
	{
		first = new;
		new = new->next;
	}
	first->next = NULL;
	new->next = *stack;
	*stack = new;
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	move_rrb(t_push **stack, int flag)
{
	t_push	*first;
	t_push	*new;

	first = *stack;
	if (first == NULL || first->next == NULL)
		return ;
	new = (*stack)->next;
	while (new->next)
	{
		first = new;
		new = new->next;
	}
	first->next = NULL;
	new->next = *stack;
	*stack = new;
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	move_rrr(t_push **stack1, t_push **stack2, int flag)
{
	if (!*stack1 || !(*stack1)->next || !*stack2 || !(*stack2)->next)
		return ;
	move_rra(stack1, flag);
	move_rrb(stack2, flag);
	if (flag == 1)
		write(1, "rrr\n", 4);
}
