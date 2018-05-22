/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:15:04 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/19 15:15:06 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/ft.h"
#include "push.h"

static int			*ft_generate_nbrs(int nbrs)
{
	FILE			*file;
	int				nb;
	int				i;
	int				*stack;

	file = fopen("/dev/random", "r");
	i = 0;
	CHECK(stack = malloc(sizeof(int) * nbrs));
	while (i < nbrs)
	{
		fread(&nb, sizeof(nb), 1, file);
		stack[i++] = nb;
	}
	fclose(file);
	return (stack);
}

static int			ft_count_ops(int nbrs, char ch)
{
	t_head			*head;
	int				*stack;
	int				cmds;

	head = ft_create_head();
	stack = ft_generate_nbrs(nbrs);
	head->s = ft_dup_stack(stack, nbrs);
	ft_quicksort(head->s, 0, nbrs - 1);
	if (ft_contains_duplicates(head->s, nbrs))
		return (ft_count_ops(nbrs, ch));
	head->a = ft_stack_to_lst(stack, nbrs);
	ft_sort(head);
	ft_cut_cmds(head);
	cmds = head->i;
	if (ch == BOTH)
		(ft_sorted_a(head->a) && !(head->b))\
		? ft_printf("{green}OK{eoc}{bold} %i{eoc}\n", cmds)\
		: ft_printf("{red}KO{eoc}{bold} %i{eoc}\n", cmds);
	else if (ch == CHECKIFSORTED)
		(ft_sorted_a(head->a) && !(head->b))\
		? ft_printf("{green}OK{eoc}\n") : ft_printf("{red}KO{eoc}\n");
	else if (ch == CMDS)
		ft_print_cmds(head->cmds);
	ft_free_all(head, stack);
	return (cmds);
}

void				ft_calculate_and_print_results(int *stack, int nbrs)
{
	int				i;
	uintmax_t		sum;

	i = 0;
	sum = 0;
	while (i < nbrs)
		sum += stack[i++];
	ft_quicksort(stack, 0, nbrs - 1);
	ft_printf("{bold}Lowest: {under}%i{eoc}\n", stack[0]);
	ft_printf("{bold}Highest: {under}%i{eoc}\n", stack[nbrs - 1]);
	ft_printf("{bold}Median: {under}%i{eoc}\n"\
		, stack[((nbrs - 1) % 2 == 0) ? (nbrs - 1) / 2 : nbrs / 2]);
	ft_printf("{bold}Mean: {under}%ji{eoc}\n", sum / nbrs);
}

static char			ft_define_ch(char **argv)
{
	char			ch;

	if (ft_strequ(argv[5], "-cs"))
		ch = BOTH;
	else if (ft_strequ(argv[5], "-c"))
		ch = CHECKIFSORTED;
	else if (ft_strequ(argv[5], "-s"))
		ch = STATS;
	else if (ft_strequ(argv[5], "-cmds"))
		ch = CMDS;
	else
	{
		ft_printf("{fd}{red}Error{eoc}\n", STDERR);
		exit(0);
	}
	return (ch);
}

void				ft_enter_random_mode(char **argv)
{
	int				times;
	int				nbrs;
	int				i;
	int				*results;
	char			ch;

	i = 0;
	if ((nbrs = ft_atoi(argv[2])) > MAX_NBRS || nbrs < 1\
		|| (times = ft_atoi(argv[4])) < 1)
	{
		ft_printf("{fd}{red}Error{eoc}\n", STDERR);
		return ;
	}
	ch = ft_define_ch(argv);
	CHECK(results = malloc(sizeof(int) * times));
	while (i < times)
		results[i++] = ft_count_ops(nbrs, ch);
	if (ch == BOTH || ch == STATS)
		ft_calculate_and_print_results(results, times);
	free(results);
}
