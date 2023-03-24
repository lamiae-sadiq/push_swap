/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 01:14:35 by lsadiq            #+#    #+#             */
/*   Updated: 2023/03/22 23:00:45 by lsadiq           ###   ########.fr       */
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
void	move_sa(t_push *stack, int flag);
void	move_sb(t_push *stack, int flag);
void	swap(t_push *stack);
t_push	*ft_stacknew(int content);
void	ft_stackadd_back(t_push **lst, t_push *new);
int		check_double(t_push *str);
int		ft_strcmp(char *s1, char *s2);
bool	check_int(char **str);
void	lastfirst(t_push *head);
void firstlast(t_push *stack);


#endif