/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:45:45 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/06 13:09:30 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf.h"
# include <stdlib.h>
# include <limits.h>

# ifndef CUTTING
#  define CUTTING 4
# endif

typedef struct s_list
{
	int				content;
	int				index;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}					t_stack;

// Sort functions

void	tiny_sort(t_stack **lst_a);
void	quick_sort(t_stack **lst_a, t_stack **lst_b);
void	compute_all_costs(t_stack **lst_a, t_stack **lst_b);
void	do_moves(t_stack **lst_a, t_stack **lst_b, int *costs);
int		get_target_pos(int index, t_stack **lst_a);
void	final_rotation(t_stack **lst_a);

// List functions

int		lstsize(t_stack *node);
int		lstissorted(t_stack *node);
t_stack	*lstnew(int content);
void	lstadd_back(t_stack **lst, t_stack *new);
void	lstadd_front(t_stack **lst, t_stack *new);
void	lstclear(t_stack **lst);

// Operations functions

void	sa(t_stack **lst_a);
void	sb(t_stack **lst_b);
void	ss(t_stack **lst_a, t_stack **lst_b);
void	pa(t_stack **lst_a, t_stack **lst_b);
void	pb(t_stack **lst_a, t_stack **lst_b);
void	ra(t_stack **lst_a);
void	rb(t_stack **lst_b);
void	rr(t_stack **lst_a, t_stack **lst_b);
void	rra(t_stack **lst_a);
void	rrb(t_stack **lst_b);
void	rrr(t_stack **lst_a, t_stack **lst_b);

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

// Dev functions

void	lstprint(t_stack **lst_a, t_stack **lst_b);

#endif