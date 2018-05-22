/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:48:12 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/01 15:48:14 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# define MAX_CMDS 5
# define CMD_LEN 5

# define MAX_NBRS 10000
# define NONE 0
# define EDGE -42

# define CALL_B 13
# define EXIT 0

# define ISDIGIT(x) ((x) >= '0' && (x) <= '9')

# define S(x) ((x) == 0 || (x) == 2 || (x) == 4)
# define R(x) ((x) == 1)
# define RR(x) ((x) == 3)

# define SWAP1 0
# define ROT 1
# define SWAP2 2
# define REVROT 3
# define SWAP3 4

# define BOTH 'b'
# define CHECKIFSORTED 'c'
# define STATS 's'
# define CMDS 'm'

# define STDERR 2

typedef struct		s_stack
{
	int				nb;
	int				c;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_cmds
{
	char			cmd[CMD_LEN];
	struct s_cmds	*next;
}					t_cmds;

typedef struct		s_head
{
	t_stack			*a;
	t_stack			*b;
	int				*s;
	t_cmds			*cmds;
	int				three_a[MAX_CMDS];
	int				three_b[MAX_CMDS];
	int				i;
}					t_head;

t_head				*ft_create_head(void);
void				ft_make_null(int *s, int len);
int					*ft_dup_stack(int *src, int nbrs);
t_stack				*ft_stack_to_lst(int *stack, int nbrs);
void				ft_print_all(t_head *head, int nbrs);

int					ft_all_is_layer(t_stack *list, int c);
int					ft_last_is_the_layer(t_stack *list, int c);
int					ft_min(t_stack *stack, int elems);
int					ft_find_first(int *array, int min);

void				ft_make_older(t_stack *b);
void				ft_make_younger(t_stack *b);
int					ft_define_c(t_head *head);
int					ft_count_upper_elems_of_layer(t_stack *list, int ch);

int					ft_sorted_till_edge_a(t_stack *list);
int					ft_sorted_till_edge_b(t_stack *list);
void				ft_make_edge(t_stack *stack);
int					*ft_read_argv(int nbrs, int argc, char **argv);
int					ft_sorted_a(t_stack *list);

int					ft_count_nbrs(int argc, char **argv);
void				ft_free_all(t_head *head, int *stack);

void				sa(t_head *head);
void				sb(t_head *head);
void				ss(t_head *head);
void				pa(t_head *head);
void				pb(t_head *head);

void				ra(t_head *head);
void				rb(t_head *head);
void				rr(t_head *head);
void				rra(t_head *head);
void				rrb(t_head *head);

void				rrr(t_head *head);
void				ft_create_cmd(t_head *head, char *cmd);
void				ft_print_cmds(t_cmds *list);

void				ft_sort(t_head *head);

void				ft_sort_two_or_three_a(t_head *head, int c);
void				ft_div_a(t_head *head, int elems);
void				ft_rot_back_the_layer_a(t_head *head, int c);

void				ft_sort_two_or_three_b(t_head *head, int c);
void				ft_div_b(t_head *head, int elems);
void				ft_rot_back_the_layer_b(t_head *head, int c);

void				ft_cut_cmds(t_head *head);

void				ft_quicksort(int *stack, int p, int r);

void				ft_sort_three(t_head *head);

void				ft_sort_three_a(t_head *head);
void				ft_sort_three_b(t_head *head);
void				ft_sort_only_three_a(t_head *head);
void				ft_sort_only_three_b(t_head *head);

int					ft_error(int argc, char **argv);
int					ft_invalid_string(char *ptr);

int					ft_contains_duplicates(int *sorted, int nbrs);
void				ft_exit(t_head *head, int *stack);

void				ft_enter_random_mode(char **argv);

#endif
