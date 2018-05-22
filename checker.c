/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 14:59:06 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/18 14:59:08 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/ft.h"
#include "push.h"

static int			ft_do_op(t_head *head, char *line)
{
	if (ft_strequ(line, "sa"))
		sa(head);
	else if (ft_strequ(line, "sb"))
		sb(head);
	else if (ft_strequ(line, "ss"))
		ss(head);
	else if (ft_strequ(line, "pa"))
		pa(head);
	else if (ft_strequ(line, "pb"))
		pb(head);
	else if (ft_strequ(line, "ra"))
		ra(head);
	else if (ft_strequ(line, "rb"))
		rb(head);
	else if (ft_strequ(line, "rr"))
		rr(head);
	else if (ft_strequ(line, "rra"))
		rra(head);
	else if (ft_strequ(line, "rrb"))
		rrb(head);
	else if (ft_strequ(line, "rrr"))
		rrr(head);
	else
		return (0);
	return (1);
}

static void			ft_get_cmds(t_head *head, int *stack, int v, int nbrs)
{
	char			*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (!ft_do_op(head, line))
		{
			ft_strdel(&line);
			ft_exit(head, stack);
		}
		ft_strdel(&line);
		if (v == ON)
			ft_print_all(head, nbrs);
	}
}

int					main(int argc, char **argv)
{
	t_head			*head;
	int				*stack;
	int				nbrs;
	int				v;

	if (argc == 1)
		return (0);
	stack = NULL;
	v = ft_strequ(argv[1], "-v") ? ON : OFF;
	head = ft_create_head();
	if ((nbrs = ft_count_nbrs(argc - v, &argv[v])) > MAX_NBRS\
		|| ft_error(argc - v, &argv[v]))
		ft_exit(head, stack);
	stack = ft_read_argv(nbrs, argc - v, &argv[v]);
	head->s = ft_dup_stack(stack, nbrs);
	ft_quicksort(head->s, 0, nbrs - 1);
	if (ft_contains_duplicates(head->s, nbrs))
		ft_exit(head, stack);
	head->a = ft_stack_to_lst(stack, nbrs);
	ft_get_cmds(head, stack, v, nbrs);
	(ft_sorted_a(head->a) && !(head->b))\
	? ft_printf("{green}OK{eoc}\n") : ft_printf("{red}KO{eoc}\n");
	ft_free_all(head, stack);
	return (0);
}
