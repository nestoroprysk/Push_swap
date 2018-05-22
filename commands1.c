/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:30:59 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/13 17:31:02 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/ft.h"
#include "push.h"

void				sa(t_head *head)
{
	t_stack		*head_a;

	if (head->a && (head->a)->next)
	{
		head_a = head->a;
		head->a = head_a->next;
		head_a->next = (head->a)->next;
		(head->a)->next = head_a;
	}
	(head->i)++;
	ft_create_cmd(head, "sa");
}

void				sb(t_head *head)
{
	t_stack		*head_b;

	if (head->b && (head->b)->next)
	{
		head_b = head->b;
		head->b = head_b->next;
		head_b->next = (head->b)->next;
		(head->b)->next = head_b;
	}
	(head->i)++;
	ft_create_cmd(head, "sb");
}

void				ss(t_head *head)
{
	t_stack		*head_a;
	t_stack		*head_b;

	if (head->a && (head->a)->next)
	{
		head_a = head->a;
		head->a = head_a->next;
		head_a->next = (head->a)->next;
		(head->a)->next = head_a;
	}
	if (head->b && (head->b)->next)
	{
		head_b = head->b;
		head->b = head_b->next;
		head_b->next = (head->b)->next;
		(head->b)->next = head_b;
	}
	(head->i)++;
	ft_create_cmd(head, "ss");
}

void				pa(t_head *head)
{
	t_stack		*node;

	if (head->b)
	{
		node = head->b;
		head->b = (head->b)->next;
		node->next = head->a;
		head->a = node;
	}
	(head->i)++;
	ft_create_cmd(head, "pa");
}

void				pb(t_head *head)
{
	t_stack		*node;

	if (head->a)
	{
		node = head->a;
		head->a = (head->a)->next;
		node->next = head->b;
		head->b = node;
	}
	(head->i)++;
	ft_create_cmd(head, "pb");
}
