/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 19:52:33 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/18 19:52:36 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/ft.h"
#include "push.h"

static int			ft_too_long(char *str)
{
	int				i;
	int				sign;

	i = 0;
	sign = PLUS;
	if (str[i] == '-')
	{
		str++;
		sign = MINUS;
	}
	while (*str == '0')
		str++;
	if (!ISDIGIT(*str))
		return (0);
	while (ISDIGIT(str[i]))
		i++;
	if (i == 10)
	{
		if ((sign == MINUS && ft_atoi(str - 1) >= 0)\
			|| (sign == PLUS && ft_atoi(str) <= 0))
			return (1);
	}
	else if (i > 10)
		return (1);
	return (0);
}

int					ft_invalid_string(char *ptr)
{
	int				flag;

	while (*ptr)
	{
		flag = 0;
		if ((ISDIGIT(*ptr) || (*ptr == '-' && ISDIGIT(*(ptr + 1))))\
			&& !ft_too_long(ptr))
			while (ISDIGIT(*ptr) || *ptr == '-')
			{
				if (*ptr == '-' && flag == 1)
					return (1);
				if (*ptr == '-')
					flag = 1;
				ptr++;
			}
		else if (*ptr == ' ')
			ptr++;
		else
			return (1);
	}
	return (0);
}

int					ft_error(int argc, char **argv)
{
	int				j;

	j = 1;
	while (j < argc)
		if (ft_invalid_string(argv[j++]))
			return (1);
	return (0);
}

int					ft_contains_duplicates(int *sorted, int nbrs)
{
	int				i;

	i = 0;
	if (nbrs == 0)
		return (0);
	while (i < nbrs - 1)
	{
		if (sorted[i] >= sorted[i + 1])
			break ;
		i++;
	}
	if (i == nbrs - 1)
		return (0);
	return (1);
}

void				ft_exit(t_head *head, int *stack)
{
	ft_free_all(head, stack);
	ft_printf("{fd}{red}Error{eoc}\n", STDERR);
	exit(0);
}
