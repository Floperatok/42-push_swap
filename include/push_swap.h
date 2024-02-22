/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:45:45 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/22 17:49:07 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}					t_stack;

// Sort functions

void	push_swap(int ac, char **av);
void	tiny_sort(t_stack **lst_a);
void	quick_sort(t_stack **lst_a, t_stack **lst_b);
void	pre_sort(t_stack **lst_a, t_stack **lst_b, int size, int cut);
void	regroup(t_stack **lst_a, t_stack **lst_b);
void	compute_all_costs(t_stack **lst_a, t_stack **lst_b);
int		get_target_pos(int index, t_stack **lst_a);
void	do_moves(t_stack **lst_a, t_stack **lst_b, int *costs);
void	final_rotation(t_stack **lst_a);

// List functions

int		lstsize(t_stack *node);
int		lstissorted(t_stack *node);
t_stack	*lstnew(int content);
void	lstadd_back(t_stack **lst, t_stack *new);
void	lstadd_front(t_stack **lst, t_stack *new);
void	lstclear(t_stack **lst);

// Operations functions

int		sa(t_stack **lst_a);
int		sb(t_stack **lst_b);
int		ss(t_stack **lst_a, t_stack **lst_b);
int		pa(t_stack **lst_a, t_stack **lst_b);
int		pb(t_stack **lst_a, t_stack **lst_b);
int		ra(t_stack **lst_a);
int		rb(t_stack **lst_b);
int		rr(t_stack **lst_a, t_stack **lst_b);
int		rra(t_stack **lst_a);
int		rrb(t_stack **lst_b);
int		rrr(t_stack **lst_a, t_stack **lst_b);

// Miscellaneous functions

int		check_errors(int ac, char **av);
int		ft_strlen(char *str);
int		ft_tablen(char **tab);
int		ft_abs(int n);
int		ft_max(int a, int b);
long	ft_atoi(char *nptr);
t_stack	*create_stack(int ac, char **av);
char	*ft_strdup(char *s);
void	free_tab(char **tab);
char	**ft_split(char const *s, char c);
void	ft_print_error(char *str);

// Dev functions

void	lstprint(t_stack **lst_a, t_stack **lst_b);

#endif