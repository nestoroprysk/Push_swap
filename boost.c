/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boost.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:55:34 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/13 17:55:36 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/ft.h"
#include "push.h"

static int			ft_cut(t_cmds *cmds, char *a, char *b)
{
	t_cmds			*temp;
	int				flag;

	flag = 0;
	while (cmds && cmds->next && cmds->next->next)
	{
		if (ft_strequ((cmds->next)->cmd, a)\
			&& ft_strequ((cmds->next->next)->cmd, b))
		{
			flag = 1;
			temp = cmds->next;
			cmds->next = cmds->next->next->next;
			free(temp->next);
			free(temp);
		}
		else
			cmds = cmds->next;
	}
	return (flag);
}

static void			ft_fill_cmd(char *dst, char *src)
{
	while ((*dst++ = *src++) != '\0')
		;
}

static int			ft_cut_and_insert(t_cmds *cmds, char *a, char *b, char *i)
{
	t_cmds			*temp;
	t_cmds			*new;
	int				flag;

	flag = 0;
	while (cmds && cmds->next && cmds->next->next)
	{
		if (ft_strequ((cmds->next)->cmd, a)\
			&& ft_strequ((cmds->next->next)->cmd, b))
		{
			flag = 1;
			temp = cmds->next;
			CHECK(new = malloc(sizeof(cmds)));
			ft_fill_cmd(new->cmd, i);
			new->next = cmds->next->next->next;
			cmds->next = new;
			free(temp->next);
			free(temp);
		}
		else
			cmds = cmds->next;
	}
	return (flag);
}

void				ft_cut_cmds(t_head *head)
{
	int				flag;

	flag = 1;
	while (flag != 0)
	{
		flag = 0;
		while (ft_cut(head->cmds, "rra", "ra"))
			flag += 2;
		while (ft_cut(head->cmds, "rrb", "rb"))
			flag += 2;
		while (ft_cut(head->cmds, "pa", "pb"))
			flag += 2;
		while (ft_cut(head->cmds, "pb", "pa"))
			flag += 2;
		while (ft_cut_and_insert(head->cmds, "rra", "rr", "rb"))
			flag++;
		while (ft_cut_and_insert(head->cmds, "rrb", "rr", "ra"))
			flag++;
		(head->i) -= flag;
	}
}
