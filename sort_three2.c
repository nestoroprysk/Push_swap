/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 13:24:31 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/18 13:24:36 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/ft.h"
#include "push.h"

static void			ft_fill_s1_r_s2_rr_s3(int *array, int start, int stop)
{
	while (start <= stop)
		array[start++] = 1;
}

void				ft_sort_three_a(t_head *head)
{
	if ((head->a)->nb > (head->a->next)->nb\
		&& (head->a)->nb < (head->a->next->next)->nb)
		ft_fill_s1_r_s2_rr_s3(head->three_a, SWAP1, SWAP1);
	else if ((head->a->next->next)->nb > (head->a)->nb\
		&& (head->a->next->next)->nb < (head->a->next)->nb)
		ft_fill_s1_r_s2_rr_s3(head->three_a, ROT, REVROT);
	else if ((head->a->next->next)->nb < (head->a)->nb\
		&& (head->a->next->next)->nb > (head->a->next)->nb)
		ft_fill_s1_r_s2_rr_s3(head->three_a, SWAP1, REVROT);
	else if ((head->a)->nb < (head->a->next)->nb\
		&& (head->a)->nb > (head->a->next->next)->nb)
		ft_fill_s1_r_s2_rr_s3(head->three_a, ROT, SWAP3);
	else if ((head->a)->nb > (head->a->next)->nb\
		&& (head->a->next)->nb > (head->a->next->next)->nb)
		ft_fill_s1_r_s2_rr_s3(head->three_a, SWAP1, SWAP3);
}

void				ft_sort_three_b(t_head *head)
{
	if ((head->b)->nb < (head->b->next)->nb\
		&& (head->b->next)->nb < (head->b->next->next)->nb)
		ft_fill_s1_r_s2_rr_s3(head->three_b, SWAP1, SWAP3);
	else if ((head->b)->nb > (head->b->next)->nb\
		&& (head->b)->nb < (head->b->next->next)->nb)
		ft_fill_s1_r_s2_rr_s3(head->three_b, ROT, SWAP3);
	else if ((head->b->next->next)->nb > (head->b)->nb\
		&& (head->b->next->next)->nb < (head->b->next)->nb)
		ft_fill_s1_r_s2_rr_s3(head->three_b, SWAP1, REVROT);
	else if ((head->b->next->next)->nb < (head->b)->nb\
		&& (head->b->next->next)->nb > (head->b->next)->nb)
		ft_fill_s1_r_s2_rr_s3(head->three_b, ROT, REVROT);
	else if ((head->b)->nb < (head->b->next)->nb\
		&& (head->b)->nb > (head->b->next->next)->nb)
		ft_fill_s1_r_s2_rr_s3(head->three_b, SWAP1, SWAP1);
}

void				ft_sort_only_three_a(t_head *head)
{
	if ((head->a)->nb > (head->a->next)->nb\
		&& (head->a)->nb < (head->a->next->next)->nb)
		ft_fill_s1_r_s2_rr_s3(head->three_a, SWAP1, SWAP1);
	else if ((head->a->next->next)->nb > (head->a)->nb\
		&& (head->a->next->next)->nb < (head->a->next)->nb)
		ft_fill_s1_r_s2_rr_s3(head->three_a, REVROT, SWAP3);
	else if ((head->a->next->next)->nb < (head->a)->nb\
		&& (head->a->next->next)->nb > (head->a->next)->nb)
		ft_fill_s1_r_s2_rr_s3(head->three_a, ROT, ROT);
	else if ((head->a)->nb < (head->a->next)->nb\
		&& (head->a)->nb > (head->a->next->next)->nb)
		ft_fill_s1_r_s2_rr_s3(head->three_a, REVROT, REVROT);
	else if ((head->a)->nb > (head->a->next)->nb\
		&& (head->a->next)->nb > (head->a->next->next)->nb)
		ft_fill_s1_r_s2_rr_s3(head->three_a, SWAP2, REVROT);
}

void				ft_sort_only_three_b(t_head *head)
{
	if ((head->b)->nb < (head->b->next)->nb\
		&& (head->b->next)->nb < (head->b->next->next)->nb)
		ft_fill_s1_r_s2_rr_s3(head->three_b, SWAP2, REVROT);
	else if ((head->b)->nb > (head->b->next)->nb\
		&& (head->b)->nb < (head->b->next->next)->nb)
		ft_fill_s1_r_s2_rr_s3(head->three_b, REVROT, REVROT);
	else if ((head->b->next->next)->nb > (head->b)->nb\
		&& (head->b->next->next)->nb < (head->b->next)->nb)
		ft_fill_s1_r_s2_rr_s3(head->three_b, ROT, ROT);
	else if ((head->b->next->next)->nb < (head->b)->nb\
		&& (head->b->next->next)->nb > (head->b->next)->nb)
		ft_fill_s1_r_s2_rr_s3(head->three_b, REVROT, SWAP3);
	else if ((head->b)->nb < (head->b->next)->nb\
		&& (head->b)->nb > (head->b->next->next)->nb)
		ft_fill_s1_r_s2_rr_s3(head->three_b, SWAP1, SWAP1);
}
