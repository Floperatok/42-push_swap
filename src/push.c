/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:15:04 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/09 08:24:15 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Push from b to a
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

// Push from a to b
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
