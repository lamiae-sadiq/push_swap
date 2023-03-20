/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 01:14:35 by lsadiq            #+#    #+#             */
/*   Updated: 2023/03/20 20:41:21 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
# include "libft/libft.h"

#define MAX_INT 2147483647
#define MIN_INT -2147483647 - 1

typedef struct s_push
{
	struct s_push  *next;
	int num;

}t_push;

t_push	*ft_stacklast(t_push *lst);
void	ft_stackadd_back(t_push **lst, t_push *new);
t_push	*ft_stacknew(int content);
int	check_double(t_push *str);
int	ft_strcmp(char *s1, char *s2);
bool		check_int(char **str);

#endif