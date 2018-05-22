/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:32:20 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/13 17:32:23 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/ft.h"
#include "push.h"

void				ra(t_head *head)
{
	t_stack			*node;
	t_stack			*cursor;

	if (head->a && (head->a)->next)
	{
		node = head->a;
		head->a = (head->a)->next;
		cursor = head->a;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = node;
		node->next = NULL;
	}
	(head->i)++;
	ft_create_cmd(head, "ra");
}

void				rb(t_head *head)
{
	t_stack			*node;
	t_stack			*cursor;

	if (head->b && (head->b)->next)
	{
		node = head->b;
		head->b = (head->b)->next;
		cursor = head->b;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = node;
		node->next = NULL;
	}
	(head->i)++;
	ft_create_cmd(head, "rb");
}

void				rr(t_head *head)
{
	t_stack			*node;
	t_stack			*cursor;

	if (head->a && (head->a)->next)
	{
		node = head->a;
		head->a = (head->a)->next;
		cursor = head->a;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = node;
		node->next = NULL;
	}
	if (head->b && (head->b)->next)
	{
		node = head->b;
		head->b = (head->b)->next;
		cursor = head->b;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = node;
		node->next = NULL;
	}
	(head->i)++;
	ft_create_cmd(head, "rr");
}

void				rra(t_head *head)
{
	t_stack			*node;
	t_stack			*cursor;

	if (head->a && (head->a)->next)
	{
		cursor = head->a;
		while (cursor->next->next)
			cursor = cursor->next;
		node = cursor->next;
		cursor->next = NULL;
		node->next = head->a;
		head->a = node;
	}
	(head->i)++;
	ft_create_cmd(head, "rra");
}

void				rrb(t_head *head)
{
	t_stack			*node;
	t_stack			*cursor;

	if (head->b && (head->b)->next)
	{
		cursor = head->b;
		while (cursor->next->next)
			cursor = cursor->next;
		node = cursor->next;
		cursor->next = NULL;
		node->next = head->b;
		head->b = node;
	}
	(head->i)++;
	ft_create_cmd(head, "rrb");
}
