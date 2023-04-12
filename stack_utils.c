/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 08:23:30 by lsadiq            #+#    #+#             */
/*   Updated: 2023/04/11 21:40:12 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*ft_stacklast(t_push *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_stackadd_back(t_push **lst, t_push *new)
{
	t_push	*p;

	if (lst)
	{
		if (*lst)
		{
			p = ft_stacklast(*lst);
			p->next = new;
		}
		else
		{
			*lst = new;
		}
	}
}

t_push	*ft_stacknew(int content)
{
	t_push	*new;

	new = malloc(sizeof(t_push));
	if (!new)
		return (NULL);
	new->num = content;
	new->next = NULL;
	return (new);
}

int	ft_lstsizee(t_push **stack)
{
	t_push	*cur;
	int		size;

	cur = *stack;
	size = 0;
	if (!(*stack))
		return (0);
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return (size);
}
