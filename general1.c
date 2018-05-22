/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:13:07 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/13 17:13:09 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/ft.h"
#include "push.h"

t_head				*ft_create_head(void)
{
	t_head			*head;

	CHECK(head = malloc(sizeof(t_head)));
	head->a = NULL;
	head->b = NULL;
	head->s = NULL;
	head->cmds = NULL;
	head->i = 0;
	return (head);
}

void				ft_make_null(int *s, int len)
{
	int				i;

	i = 0;
	while (i < len)
	{
		s[i] = 0;
		i++;
	}
}

int					*ft_dup_stack(int *src, int nbrs)
{
	int				*stack;
	int				i;

	CHECK(stack = malloc(sizeof(int) * nbrs));
	ft_make_null(stack, nbrs);
	i = 0;
	while (i < nbrs)
	{
		stack[i] = src[i];
		i++;
	}
	return (stack);
}

t_stack				*ft_stack_to_lst(int *stack, int nbrs)
{
	int				i;
	t_stack			*node;
	t_stack			*cursor;
	t_stack			*head;

	i = 0;
	head = NULL;
	if (nbrs == 0)
		return (head);
	CHECK(node = malloc(sizeof(t_stack)));
	node->nb = stack[i++];
	node->next = NULL;
	head = node;
	node->c = NONE;
	cursor = node;
	while (i < nbrs)
	{
		CHECK(node = malloc(sizeof(t_stack)));
		node->nb = stack[i++];
		node->c = NONE;
		node->next = NULL;
		cursor->next = node;
		cursor = cursor->next;
	}
	return (head);
}

void				ft_print_all(t_head *head, int nbrs)
{
	int				i;
	t_stack			*c_a;
	t_stack			*c_b;
	int				*c_s;

	i = 0;
	c_a = head->a;
	c_b = head->b;
	c_s = head->s;
	while (i < nbrs)
	{
		printf("%4i.|%-+10i|", i, (c_a) ? c_a->nb : 0);
		if (c_a)
			c_a = c_a->next;
		printf("%4i.|%-+10i|", i, (c_b) ? c_b->nb : 0);
		if (c_b)
			c_b = c_b->next;
		printf("%4i.|%-+10i|", i, (*c_s));
		c_s++;
		i++;
		printf("\n");
	}
}
