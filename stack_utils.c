/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 08:23:30 by lsadiq            #+#    #+#             */
/*   Updated: 2023/03/20 20:49:28 by lsadiq           ###   ########.fr       */
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
			*lst = new;
	}
}

t_push	*ft_stacknew(int content)
{
	t_push	*new;

	new = malloc(sizeof(t_push));
	if (!new)
		return (NULL);
	new->num = content;
    // new->count = 0;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}