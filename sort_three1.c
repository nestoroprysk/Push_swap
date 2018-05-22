/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:28:43 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/13 17:28:45 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/ft.h"
#include "push.h"

static void			ft_help1(t_head *head, int i)
{
	if (S(i))
		ss(head);
	else if (R(i))
		rr(head);
	else if (RR(i))
		rrr(head);
}

static void			ft_help2(t_head *head, int i)
{
	if (S(i))
		sa(head);
	else if (R(i))
		ra(head);
	else if (RR(i))
		rra(head);
}

static void			ft_help3(t_head *head, int i)
{
	if (S(i))
		sb(head);
	else if (R(i))
		rb(head);
	else if (RR(i))
		rrb(head);
}

static int			ft_only_three(t_stack *list)
{
	int				i;

	i = 0;
	while (list && i < 4)
	{
		i++;
		list = list->next;
	}
	if (i == 3)
		return (1);
	return (0);
}

void				ft_sort_three(t_head *head)
{
	int				i;

	i = 0;
	ft_make_null(head->three_a, MAX_CMDS);
	ft_make_null(head->three_b, MAX_CMDS);
	if (head->a && (head->a)->next && (head->a)->next->next)
		ft_only_three(head->a)\
		? ft_sort_only_three_a(head) : ft_sort_three_a(head);
	if (head->b && (head->b)->next && (head->b)->next->next)
		ft_only_three(head->b)\
		? ft_sort_only_three_b(head) : ft_sort_three_b(head);
	while (i < MAX_CMDS)
	{
		if ((head->three_a)[i] == ON && (head->three_b)[i] == ON)
			ft_help1(head, i);
		else if ((head->three_a)[i] == ON)
			ft_help2(head, i);
		else if ((head->three_b)[i] == ON)
			ft_help3(head, i);
		i++;
	}
}
