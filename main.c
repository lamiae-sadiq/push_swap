/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:08:35 by lsadiq            #+#    #+#             */
/*   Updated: 2023/03/21 11:36:48 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdbool.h>

bool		check_int(char **av)
{
	bool	is_int;
	int		i;
	int 	j;
	int		k;

	i = 1;
	j = 0;
	is_int = true;
	while(av[i])
	{
		k = 0;
		while(av[i][k])
		{
			 if ((av[i][k] == '-' || av[i][k] == '+') && j == 0)
				j++;
			else if(!(av[i][k] >= '0' && av[i][k] <= '9'))
					is_int = false;
			k++;
		}
		i++;
	}
	return(is_int);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

int	check_double(t_push *av)
{
	t_push *holder;
	t_push *cmp;

	
	holder = av;
	while (holder)
	{
		cmp = holder->next;
		while(cmp)
		{
			if(holder->num == cmp->num)
				return(0);
			cmp = cmp->next;
		}
		holder = holder->next;
	}
	return(1);
}
