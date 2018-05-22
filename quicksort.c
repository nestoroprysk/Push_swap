/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:57:05 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/13 17:57:07 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/ft.h"
#include "push.h"

static void			ft_swap(int *a, int *b)
{
	int				temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int			ft_partition(int *stack, int p, int r)
{
	int				x;
	int				i;
	int				j;

	x = stack[r];
	i = p - 1;
	j = p;
	while (j <= r - 1)
	{
		if (stack[j] <= x)
		{
			i++;
			ft_swap(&stack[i], &stack[j]);
		}
		j++;
	}
	ft_swap(&stack[i + 1], &stack[r]);
	return (i + 1);
}

void				ft_quicksort(int *stack, int p, int r)
{
	int				q;

	if (p < r)
	{
		q = ft_partition(stack, p, r);
		ft_quicksort(stack, p, q - 1);
		ft_quicksort(stack, q + 1, r);
	}
}
