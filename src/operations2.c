/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:10:45 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/01 05:36:45 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Shift up all nodes of stack by one, the first node become the last one
void	ra(t_list **lst_a)
{
	t_list	*tmp;

	if (*lst_a && (*lst_a)->next)
	{
		tmp = *lst_a;
		*lst_a = (*lst_a)->next;
		lstadd_back(lst_a, tmp);
		ft_printf("ra\n");
	}
	else
		ft_printf("error ra\n");
}

// Shift up all nodes of stack by one, the first node become the last one
void	rb(t_list **lst_b)
{
	t_list	*tmp;

	if (*lst_b && (*lst_b)->next)
	{
		tmp = *lst_b;
		*lst_b = (*lst_b)->next;
		lstadd_back(lst_b, tmp);
		ft_printf("rb\n");
	}
	else
		ft_printf("error rb\n");
}

// Shift up all nodes of stack by one, the first node become the last one
void	rr(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	if (*lst_a && *lst_b)
	{
		tmp = *lst_a;
		*lst_a = (*lst_a)->next;
		lstadd_back(lst_a, tmp);
		tmp = *lst_b;
		*lst_b = (*lst_b)->next;
		lstadd_back(lst_b, tmp);
		ft_printf("rr\n");
	}
	else
		ft_printf("error rr\n");
}
