/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:09:50 by lsadiq            #+#    #+#             */
/*   Updated: 2023/04/11 22:05:37 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long		nb;
	int			sign;

	sign = 1;
	nb = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - 48);
		if ((nb > 2147483647 && sign == 1) || (nb > 2147483648 && sign == -1))
			exit(write(2, "Error\n", 7));
		str++;
	}
	return (nb * sign);
}
