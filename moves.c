/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:35:10 by lsadiq            #+#    #+#             */
/*   Updated: 2023/03/23 18:00:02 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  move_sa(t_push *stack, int flag)
{
    int tmp;

    tmp = stack->num;
    stack->num = stack->next->num;
    stack->next->num = tmp;
    if(flag == 1)
        printf("sa\n");
}

void  move_sb(t_push *stack, int flag)
{
    int tmp;

    tmp = stack->num;
    stack->num = stack->next->num;
    stack->next->num = tmp;
    if(flag == 1)
        printf("sb\n");
}

void lastfirst(t_push *head)
{
    t_push *last = head;
    t_push *perv;
    int temp;

    while (last->next != NULL) {
        perv = last;
        last = last->next;
    }
    temp = head->num;
    head->num = last->num;
    perv->next = NULL;
    printf("ra\n");
}

void firstlast(t_push *stack)
{
    t_push *last;
    // t_push *perv;
    t_push *tmp;
    // int temp;
    last = stack;
    tmp = stack->next;
    while(tmp->next)
    {
        last = tmp;
        tmp = tmp->next;
    }
    last->next = NULL;
    // printf("%d\n", last->num);
    tmp->next = stack;
    stack = tmp;
    printf("hello\n");
    // printf("%d\n", last->next->num);
    // last->num = stack->num;
    // stack = stack->next;
    //  last->num = stack->num;
    // tmp = stack;
    // stack = stack->next;
    // printf("%d\n", last->num);
    // printf("%d\n", last->num);
}