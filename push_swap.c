/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:02:29 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/13 17:02:32 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/ft.h"
#include "push.h"

int					main(int argc, char **argv)
{
	t_head			*head;
	int				nbrs;
	int				*stack;

	if (argc == 6 && ft_strequ(argv[1], "-r") && !ft_invalid_string(argv[2])\
		&& ft_strequ(argv[3], "-t") && !ft_invalid_string(argv[4]))
	{
		ft_enter_random_mode(argv);
		return (0);
	}
	stack = NULL;
	head = ft_create_head();
	if ((nbrs = ft_count_nbrs(argc, argv)) > MAX_NBRS || ft_error(argc, argv))
		ft_exit(head, stack);
	stack = ft_read_argv(nbrs, argc, argv);
	head->s = ft_dup_stack(stack, nbrs);
	ft_quicksort(head->s, 0, nbrs - 1);
	if (ft_contains_duplicates(head->s, nbrs))
		ft_exit(head, stack);
	head->a = ft_stack_to_lst(stack, nbrs);
	ft_sort(head);
	ft_cut_cmds(head);
	ft_print_cmds(head->cmds);
	ft_free_all(head, stack);
	return (0);
}
