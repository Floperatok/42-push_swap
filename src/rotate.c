/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:10:45 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/13 17:54:11 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 *	Shift up all nodes of stack a by one.
 *	The first node become the last one.
*/
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

/*
 *	Shift up all nodes of stack b by one.
 *	The first node become the last one.
*/
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

/*
 *	ra and rb at the same time.
*/
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
