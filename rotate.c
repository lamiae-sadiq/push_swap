/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:05:17 by lsadiq            #+#    #+#             */
/*   Updated: 2023/04/12 00:44:08 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_ra(t_push **stack, int flag)
{
	t_push	*head;
	t_push	*new;

	head = *stack;
	if (head == NULL || head->next == NULL)
		return ;
	*stack = head->next;
	head->next = NULL;
	new = *stack;
	while (new->next)
		new = new->next;
	new->next = head;
	if (flag == 1)
		write(1, "ra\n", 3);
}

void move_rb(t_push **stack, int flag)
{
	t_push *head;
	t_push *new;

	head = *stack;
	if (head == NULL || head->next == NULL)
		return;
	*stack = head->next;
	head->next = NULL;
	new = *stack;
	while (new->next)
		new = new->next;
	new->next = head;
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	move_rr(t_push **stack1, t_push **stack2, int flag)
{
	if (!*stack1 || !(*stack1)->next || !*stack2 || !(*stack2)->next)
		return ;
	move_ra(stack1, flag);
	move_rb(stack2, flag);
	if (flag == 1)
		write(1, "rr\n", 3);
}
