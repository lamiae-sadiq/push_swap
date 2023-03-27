/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:05:25 by lsadiq            #+#    #+#             */
/*   Updated: 2023/03/26 01:44:59 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    move_rra(t_push **stack)
{
    //Shift down all elements of stack a by 1. The last element becomes the first one.
    t_push *first;
    t_push *new;
    
    first = *stack;
    new = (*stack)->next;
    while(new->next)
    {
       first = new;
       new = new->next; 
    }
    first->next = NULL;
    new->next = *stack;
    *stack = new;
}

void    move_rrb(t_push **stack)
{
    //Shift down all elements of stack a by 1. The last element becomes the first one.
    t_push *first;
    t_push *new;
    
    first = *stack;
    new = (*stack)->next;
    while(new->next)
    {
       first = new;
       new = new->next; 
    }
    first->next = NULL;
    new->next = *stack;
    *stack = new;
}

void    move_rrr(t_push **stack1, t_push **stack2)
{
    move_rra(stack1);
    move_rrb(stack2);
}
