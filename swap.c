/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:02:02 by lsadiq            #+#    #+#             */
/*   Updated: 2023/03/25 16:05:00 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  move_sa(t_push **stack, int flag)
{
    int tmp;

    tmp = (*stack)->num;
    (*stack)->num = (*stack)->next->num;
    (*stack)->next->num = tmp;
    if(flag == 1)
        printf("sa\n");
}

void  move_sb(t_push **stack, int flag)
{
    int tmp;

    tmp = (*stack)->num;
    (*stack)->num = (*stack)->next->num;
    (*stack)->next->num = tmp;
    if(flag == 1)
        printf("sb\n");
}

void move__ss(t_push **stack1, t_push **stack2, int flag)
{
    move_sa(stack1, flag);
    move_sb(stack2, flag);
    write(1, "ss\n", 3);
}