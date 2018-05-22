/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:37:27 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/13 17:37:29 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/ft.h"
#include "push.h"

void				ft_sort_two_or_three_a(t_head *head, int c)
{
	int				elems;

	elems = ft_count_upper_elems_of_layer(head->a, c);
	if (elems == 3)
	{
		(head->a)->c = EDGE;
		(head->a->next)->c = EDGE;
		(head->a->next->next)->c = EDGE;
		ft_sort_three(head);
	}
	else if (elems == 2)
	{
		if ((head->a)->nb > (head->a->next)->nb\
			&& head->b && (head->b)->next\
			&& (head->b)->nb < (head->b->next)->nb)
			ss(head);
		else if ((head->a)->nb > (head->a->next)->nb)
			sa(head);
		(head->a)->c = EDGE;
		(head->a->next)->c = EDGE;
	}
	else if (elems == 1)
		(head->a)->c = EDGE;
}

static int			ft_mean_a(t_head *head, int elems)
{
	int				mid;
	int				mean;
	int				i_first;

	mid = (elems % 2 == 0) ? elems / 2 : (elems + 1) / 2;
	i_first = ft_find_first(head->s, ft_min(head->a, elems));
	mean = (head->s)[mid + i_first - 1];
	return (mean);
}

void				ft_div_a(t_head *head, int elems)
{
	int				mean;
	int				i;

	mean = ft_mean_a(head, elems);
	i = 0;
	if (elems % 2 != 0)
		elems++;
	if (ft_sorted_till_edge_a(head->a))
		ft_make_edge(head->a);
	while ((head->a)->c != EDGE && i < elems / 2)
	{
		if ((head->a)->nb <= mean)
		{
			i++;
			pb(head);
		}
		else
			ra(head);
	}
}

void				ft_rot_back_the_layer_a(t_head *head, int c)
{
	if (!(head->b) || c == EDGE)
		return ;
	if (ft_all_is_layer(head->a, c))
		return ;
	while (ft_last_is_the_layer(head->a, c))
		rra(head);
}
