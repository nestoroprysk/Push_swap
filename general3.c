/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 20:06:30 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/13 20:06:32 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/ft.h"
#include "push.h"

void				ft_make_older(t_stack *b)
{
	while (b)
	{
		if (b->c != EDGE)
			(b->c)++;
		b = b->next;
	}
}

void				ft_make_younger(t_stack *b)
{
	while (b)
	{
		if (b->c != EDGE)
			(b->c)--;
		b = b->next;
	}
}

int					ft_define_c(t_head *head)
{
	if (head->a && (head->a)->c != EDGE)
		return ((head->a)->c);
	if (head->b && (head->b)->c != EDGE)
		return ((head->b)->c);
	return (-1);
}

int					ft_count_upper_elems_of_layer(t_stack *list, int ch)
{
	int				nb;

	nb = 0;
	if (ch == EDGE || ch == -1)
		return (nb);
	while (list)
	{
		if (list->c != ch)
			break ;
		nb++;
		list = list->next;
	}
	return (nb);
}
