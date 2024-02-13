/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:15:04 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/13 17:51:18 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 *	Swap the first 2 elements at the top of stack a.
 *	Do nothing if there is only one or no elements.
*/
int	pa(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*tmp;

	if ((*lst_b))
	{
		tmp = (*lst_b)->next;
		lstadd_front(lst_a, (*lst_b));
		*lst_b = tmp;
		ft_printf("pa\n");
		return (1);
	}
	return (0);
}

/*
 *	Swap the first 2 elements at the top of stack b.
 *	Do nothing if there is only one or no elements.
*/
int	pb(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*tmp;

	if ((*lst_a))
	{
		tmp = (*lst_a)->next;
		lstadd_front(lst_b, (*lst_a));
		*lst_a = tmp;
		ft_printf("pb\n");
		return (1);
	}
	return (0);
}
