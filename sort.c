/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:36:08 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/13 17:36:10 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/ft.h"
#include "push.h"

static void			ft_pa_or_pb(t_head *head, int all_edge)
{
	if (all_edge)
		while (head->b && (head->b)->c == EDGE)
			pa(head);
	else
		while (head->a && (head->a)->c == EDGE)
			pb(head);
}

static int			ft_sort_a(t_head *head)
{
	int				c;
	int				elems;

	c = ft_define_c(head);
	while ((elems = ft_count_upper_elems_of_layer(head->a, c)) > 3)
	{
		ft_div_a(head, elems);
		ft_make_older(head->b);
		ft_rot_back_the_layer_a(head, c);
	}
	ft_sort_two_or_three_a(head, c);
	ft_pa_or_pb(head, ft_all_is_layer(head->a, EDGE));
	if (head->b)
		return (CALL_B);
	return (EXIT);
}

void				ft_sort(t_head *head)
{
	int				c;
	int				elems;

	if (!head || !(head->a))
		return ;
	while (ft_sort_a(head) != EXIT)
	{
		c = ft_define_c(head);
		while ((elems = ft_count_upper_elems_of_layer(head->b, c)) > 3)
		{
			ft_div_b(head, elems);
			ft_make_younger(head->a);
			ft_rot_back_the_layer_b(head, c);
		}
		ft_sort_two_or_three_b(head, c);
		ft_pa_or_pb(head, ft_all_is_layer(head->a, EDGE));
	}
}
