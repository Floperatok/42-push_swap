/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:45:45 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/01 13:19:32 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/ft_printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

// Sort functions

void	ft_rotatesort(t_list **lst_a, t_list **lst_b);

// List functions

int		lstmin(t_list *node);
int		lstsize(t_list *node);
int		lstissorted(t_list *node);
t_list	*lstnew(long content);
void	lstadd_back(t_list **lst, t_list *new);
void	lstadd_front(t_list **lst, t_list *new);
void	lstclear(t_list **lst);

// Operations functions

void	sa(t_list **lst_a);
void	sb(t_list **lst_b);
void	ss(t_list **lst_a, t_list **lst_b);
void	pa(t_list **lst_a, t_list **lst_b);
void	pb(t_list **lst_a, t_list **lst_b);
void	ra(t_list **lst_a);
void	rb(t_list **lst_b);
void	rr(t_list **lst_a, t_list **lst_b);
void	rra(t_list **lst_a);
void	rrb(t_list **lst_b);
void	rrr(t_list **lst_a, t_list **lst_b);

// Miscellaneous functions

int		ft_isdigit(int c);
int		is_wspace(char c);
int		has_whitespaces(char *str);
long	ft_atoi(char *nptr);
t_list	**fill_lst_multiple_args(t_list **lst, char **av, int ac);
t_list	**fill_lst_onearg(t_list **lst, char **av, int ac);

// Dev functions (delete before pushing)

void	lstprint(t_list **lst_a, t_list **lst_b);

#endif