/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:02:02 by lsadiq            #+#    #+#             */
/*   Updated: 2023/04/11 22:08:32 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_sa(t_push **stack, int flag)
{
	int	tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = tmp;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	move_sb(t_push **stack, int flag)
{
	int	tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = tmp;
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	move_ss(t_push **stack1, t_push **stack2, int flag)
{
	if (!*stack1 || !(*stack1)->next || !*stack2 || !(*stack2)->next)
		return ;
	move_sa(stack1, 1);
	move_sb(stack2, 1);
	if (flag == 1)
		write(1, "ss\n", 3);
}
