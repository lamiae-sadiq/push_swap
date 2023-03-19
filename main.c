/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:08:35 by lsadiq            #+#    #+#             */
/*   Updated: 2023/03/09 15:15:07 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdbool.h>

//check the sign
bool		check_int(char *str)
{
	bool	is_int;
	int		i;
	int 	j;

	i = 0;
	j = 0;
	is_int = true;
	while(str[i])
	{
		 if ((str[i] == '-' || str[i] == '+') && j == 0)
			j++;
		else if(!(str[i] >= '0' && str[i] <= '9'))
		{
				is_int = false;
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

int	check_double(char **str)
{
	int i;
	int j;

	i = 0;
	while(str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (!ft_strcmp(str[j], str[i]))
				return(0);
			j++;
		}
		i++; 
	}
	return(1);
}

int main(int argc, char **argv)
{
	int i;
	int cm;

	i = 1;
	if(argc > 2)
	{
		while(argv[i])
		{
			cm = check_int(&argv[i][0]);
			if(cm == 0 || check_double(&argv[i]) == 0){
				printf("weirdo\n");
				break;
			}
			i++;
		}
	}
}
