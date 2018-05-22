/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:27:50 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/18 17:27:52 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/ft.h"
#include "push.h"

int					ft_count_nbrs(int argc, char **argv)
{
	int				i;
	char			*ptr;
	int				count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		ptr = argv[i];
		while (*ptr)
		{
			if (ISDIGIT(*ptr) && !ISDIGIT(*(ptr + 1)))
				count++;
			ptr++;
		}
		i++;
	}
	return (count);
}

static void			ft_free_cmds(t_cmds *cursor, t_cmds *temp)
{
	while (cursor)
	{
		temp = cursor;
		cursor = cursor->next;
		free(temp);
	}
}

static void			ft_free_a_b(t_stack *cursor, t_stack *temp)
{
	while (cursor)
	{
		temp = cursor;
		cursor = cursor->next;
		free(temp);
	}
}

void				ft_free_all(t_head *head, int *stack)
{
	ft_free_a_b(head->a, head->a);
	ft_free_a_b(head->b, head->b);
	ft_free_cmds(head->cmds, head->cmds);
	if (head && head->s)
		free(head->s);
	free(stack);
	free(head);
}

int					ft_sorted_a(t_stack *list)
{
	while (list && list->next)
	{
		if (list->nb > (list->next)->nb)
			return (0);
		list = list->next;
	}
	return (1);
}
