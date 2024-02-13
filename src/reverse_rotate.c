/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:34:59 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/13 17:52:26 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 *	Shift down all elements of stack a by 1.
 *	The last element becomes the first one.
*/
int	rra(t_stack **lst_a)
{
	t_stack	*node;
	t_stack	*tmp;

	if (*lst_a && (*lst_a)->next)
	{
		node = *lst_a;
		while (node->next->next)
			node = node->next;
		tmp = node;
		node = node->next;
		tmp->next = NULL;
		lstadd_front(lst_a, node);
		ft_printf("rra\n");
		return (1);
	}
	return (0);
}
/*
 *	Shift down all elements of stack b by 1.
 *	The last element becomes the first one.
*/
int	rrb(t_stack **lst_b)
{
	t_stack	*node;
	t_stack	*tmp;

	if (*lst_b && (*lst_b)->next)
	{
		node = *lst_b;
		while (node->next->next)
			node = node->next;
		tmp = node;
		node = node->next;
		tmp->next = NULL;
		lstadd_front(lst_b, node);
		ft_printf("rrb\n");
		return (1);
	}
	return (0);
}

/*
 *	rra and rrb at the same time.
*/
int	rrr(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*node;
	t_stack	*tmp;

	if (*lst_a && (*lst_a)->next && *lst_b && (*lst_b)->next)
	{
		node = *lst_a;
		while (node->next->next)
			node = node->next;
		tmp = node;
		node = node->next;
		tmp->next = NULL;
		lstadd_front(lst_a, node);
		node = *lst_b;
		while (node->next->next)
			node = node->next;
		tmp = node;
		node = node->next;
		tmp->next = NULL;
		lstadd_front(lst_b, node);
		ft_printf("rrr\n");
		return (1);
	}
	return (0);
}
