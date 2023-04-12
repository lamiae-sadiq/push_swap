/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:08:35 by lsadiq            #+#    #+#             */
/*   Updated: 2023/04/11 11:13:18 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_int(char **av)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (av[i])
	{
		j = 0;
		k = 0;
		while (av[i][k])
		{
			if ((av[i][k] == '-' || av[i][k] == '+') && j == 0)
				j++;
			else if (!(av[i][k] >= '0' && av[i][k] <= '9'))
				return (false);
			k++;
		}
		i++;
	}
	return (true);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	check_double(t_push *av)
{
	t_push	*holder;
	t_push	*cmp;

	holder = av;
	while (holder)
	{
		cmp = holder->next;
		while (cmp)
		{
			if (holder->num == cmp->num)
				return (0);
			cmp = cmp->next;
		}
		holder = holder->next;
	}
	return (1);
}
