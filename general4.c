/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 18:55:53 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/17 18:55:55 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/ft.h"
#include "push.h"

int					ft_sorted_till_edge_a(t_stack *list)
{
	while (list && list->next)
	{
		if (list->nb > (list->next)->nb)
			return (0);
		if (list->c == EDGE)
			return (1);
		list = list->next;
	}
	return (1);
}

int					ft_sorted_till_edge_b(t_stack *list)
{
	while (list && list->next)
	{
		if (list->nb < (list->next)->nb)
			return (0);
		if (list->c == EDGE)
			return (1);
		list = list->next;
	}
	return (1);
}

void				ft_make_edge(t_stack *stack)
{
	while (stack && stack->c != EDGE)
	{
		stack->c = EDGE;
		stack = stack->next;
	}
}

int					*ft_read_argv(int nbrs, int argc, char **argv)
{
	int				*stack;
	int				i;
	int				j;
	char			*ptr;

	i = 0;
	j = 1;
	CHECK(stack = malloc(sizeof(int) * nbrs));
	ft_make_null(stack, nbrs);
	while (j < argc)
	{
		ptr = argv[j++];
		while (*ptr)
		{
			if (ISDIGIT(*ptr) || *ptr == '-')
			{
				stack[i++] = ft_atoi(ptr);
				while (ISDIGIT(*ptr) || *ptr == '-')
					ptr++;
			}
			else
				ptr++;
		}
	}
	return (stack);
}
