/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:33:56 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/13 17:33:58 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/ft.h"
#include "push.h"

void				rrr(t_head *head)
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
	ft_create_cmd(head, "rrr");
}

static void			ft_fill_cmd(char *dst, char *src)
{
	while ((*dst++ = *src++) != '\0')
		;
}

void				ft_create_cmd(t_head *head, char *cmd)
{
	t_cmds			*node;
	t_cmds			*cursor;

	CHECK(node = malloc(sizeof(t_cmds)));
	if (!(head->cmds))
		head->cmds = node;
	else
	{
		cursor = head->cmds;
		while (cursor && cursor->next)
			cursor = cursor->next;
		cursor->next = node;
	}
	ft_fill_cmd(node->cmd, cmd);
	node->next = NULL;
}

void				ft_print_cmds(t_cmds *list)
{
	while (list)
	{
		ft_printf("%s\n", list->cmd);
		list = list->next;
	}
}
