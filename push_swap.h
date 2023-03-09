/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 01:14:35 by lsadiq            #+#    #+#             */
/*   Updated: 2023/03/06 19:24:06 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
# include "libft/libft.h"

#define MAX_INT 2147483647
#define MIN_INT -2147483647 - 1

typedef struct s_push
{
	int	i;
	int	j;
	char	*str;	
}t_push;

#endif