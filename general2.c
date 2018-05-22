/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:18:54 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/13 17:18:57 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/ft.h"
#include "push.h"

int					ft_all_is_layer(t_stack *list, int c)
{
	while (list)
	{
		if (list->c != c)
			return (0);
		list = list->next;
	}
	return (1);
}

int					ft_last_is_the_layer(t_stack *list, int c)
{
	if (!list)
		return (0);
	if (list)
	{
		while (list->next)
			list = list->next;
	}
	if (list->c == c)
		return (1);
	return (0);
}

int					ft_min(t_stack *stack, int elems)
{
	int				min;

	if (elems < 1 || !stack)
		return (0);
	min = stack->nb;
	stack = stack->next;
	elems--;
	while (elems-- && stack)
	{
		if (min > stack->nb)
			min = stack->nb;
		stack = stack->next;
	}
	return (min);
}

int					ft_find_first(int *array, int min)
{
	int				i;

	i = 0;
	while (array[i] != min)
		i++;
	return (i);
}
