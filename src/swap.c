/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:23:32 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/13 18:09:18 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 *	Swap the first 2 elements at the top of stack a.
 *	Do nothing if there is only one or no elements.
*/
int	sa(t_stack **lst_a)
{
	t_stack	*tmp;

	tmp = NULL;
	if ((*lst_a) && (*lst_a)->next)
	{
		if ((*lst_a)->next->next)
			tmp = (*lst_a)->next->next;
		(*lst_a)->next->next = (*lst_a);
		*lst_a = (*lst_a)->next;
		(*lst_a)->next->next = tmp;
		ft_printf("sa\n");
		return (1);
	}
	return (0);
}

/*
 *	Swap the first 2 elements at the top of stack b.
 *	Do nothing if there is only one or no elements.
*/
int	sb(t_stack **lst_b)
{
	t_stack	*tmp;

	tmp = NULL;
	if ((*lst_b) && (*lst_b)->next)
	{
		if ((*lst_b)->next->next)
			tmp = (*lst_b)->next->next;
		(*lst_b)->next->next = (*lst_b);
		*lst_b = (*lst_b)->next;
		(*lst_b)->next->next = tmp;
		ft_printf("sa\n");
		return (1);
	}
	return (0);
}

/*
 *	sa and sb at the same time.
*/
int	ss(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*tmp;

	if ((*lst_a) && (*lst_a)->next && (*lst_b) && (*lst_b)->next)
	{
		tmp = (*lst_a);
		(*lst_a) = (*lst_a)->next;
		(*lst_a)->next = tmp;
		(*lst_a)->next->next = NULL;
		tmp = (*lst_b);
		(*lst_b) = (*lst_b)->next;
		(*lst_b)->next = tmp;
		(*lst_b)->next->next = NULL;
		ft_printf("ss\n");
		return (1);
	}
	return (0);
}
