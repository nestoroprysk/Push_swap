/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:37:34 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/13 17:37:36 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/ft.h"
#include "push.h"

void				ft_sort_two_or_three_b(t_head *head, int c)
{
	int				elems;

	elems = ft_count_upper_elems_of_layer(head->b, c);
	if (elems == 3)
	{
		(head->b)->c = EDGE;
		(head->b->next)->c = EDGE;
		(head->b->next->next)->c = EDGE;
		ft_sort_three(head);
	}
	else if (elems == 2)
	{
		if ((head->b)->nb < (head->b->next)->nb\
			&& head->a && (head->a)->next\
			&& (head->a)->nb > (head->a->next)->nb)
			ss(head);
		else if ((head->b)->nb < (head->b->next)->nb)
			sb(head);
		(head->b)->c = EDGE;
		(head->b->next)->c = EDGE;
	}
	else if (elems == 1)
		(head->b)->c = EDGE;
}

static int			ft_mean_b(t_head *head, int elems)
{
	int				mid;
	int				mean;
	int				i_first;

	mid = (elems % 2 == 0) ? 1 + (elems / 2) : (elems + 1) / 2;
	i_first = ft_find_first(head->s, ft_min(head->b, elems));
	mean = (head->s)[mid + i_first - 1];
	return (mean);
}

void				ft_div_b(t_head *head, int elems)
{
	int				mean;
	int				i;

	mean = ft_mean_b(head, elems);
	i = 0;
	if (elems % 2 != 0)
		elems++;
	if (ft_sorted_till_edge_b(head->b))
		ft_make_edge(head->b);
	while ((head->b)->c != EDGE && i < elems / 2)
	{
		if ((head->b)->nb >= mean)
		{
			i++;
			pa(head);
		}
		else
			rb(head);
	}
}

void				ft_rot_back_the_layer_b(t_head *head, int c)
{
	if (!(head->b) || c == EDGE)
		return ;
	if (ft_all_is_layer(head->b, c))
		return ;
	while (ft_last_is_the_layer(head->b, c))
		rrb(head);
}
