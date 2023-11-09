/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:10:45 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/08 21:40:09 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Shift up all nodes of stack by one, the first node become the last one
int	ra(t_stack **lst_a)
{
	t_stack	*tmp;

	if (*lst_a && (*lst_a)->next)
	{
		tmp = *lst_a;
		*lst_a = (*lst_a)->next;
		lstadd_back(lst_a, tmp);
		ft_printf("ra\n");
		return (1);
	}
	return (0);
}

// Shift up all nodes of stack by one, the first node become the last one
int	rb(t_stack **lst_b)
{
	t_stack	*tmp;

	if (*lst_b && (*lst_b)->next)
	{
		tmp = *lst_b;
		*lst_b = (*lst_b)->next;
		lstadd_back(lst_b, tmp);
		ft_printf("rb\n");
		return (1);
	}
	return (0);
}

// Shift up all nodes of stack by one, the first node become the last one
int	rr(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*tmp;

	if (*lst_a && *lst_b)
	{
		tmp = *lst_a;
		*lst_a = (*lst_a)->next;
		lstadd_back(lst_a, tmp);
		tmp = *lst_b;
		*lst_b = (*lst_b)->next;
		lstadd_back(lst_b, tmp);
		ft_printf("rr\n");
		return (1);
	}
	return (0);
}
