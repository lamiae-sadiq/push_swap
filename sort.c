/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:08:34 by lsadiq            #+#    #+#             */
/*   Updated: 2023/03/27 21:38:39 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sort(t_push **stack)
{
    t_push *tmp;

    tmp = *stack;
    while(tmp->next)
    {
        if(tmp->num > tmp->next->num)
            return(0);
        tmp = tmp->next;
    }
    return(1);
}