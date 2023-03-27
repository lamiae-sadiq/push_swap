/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:05:17 by lsadiq            #+#    #+#             */
/*   Updated: 2023/03/26 01:05:08 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move_ra(t_push **stack)
{
    t_push *head;
    t_push *new;
    
    head = *stack;
    if(head == NULL || head->next == NULL)
        return ;
    // ra ==  Shift up all elements of stack a by 1. The first element becomes the last one.
    *stack = head->next;
    head->next = NULL;
    new = *stack;
    while(new->next)
        new = new->next;
    new->next = head;
    write(1, "ra\n", 3);
}

void move_rb(t_push **stack)
{
    t_push *head;
    t_push *new;
    
    head = *stack;
    if(head == NULL || head->next == NULL)
        return ;
    // ra ==  Shift up all elements of stack a by 1. The first element becomes the last one.
    *stack = head->next;
    head->next = NULL;
    new = *stack;
    while(new->next)
        new = new->next;
    new->next = head;
    write(1, "rb\n", 3);
}

void move_rr(t_push **stack1, t_push **stack2)
{
    move_ra(stack1);
    move_rb(stack2);
    write(1, "rr\n", 3);
}