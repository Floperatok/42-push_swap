/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:34:59 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/04 13:52:35 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Shift all down all the nodes by one, the last node become the first one
void	rra(t_stack **lst_a)
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
	}
	else
		ft_printf("error rra\n");
}

// Shift all down all the nodes by one, the last node become the first one
void	rrb(t_stack **lst_b)
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
	}
	else
		ft_printf("error rrb\n");
}

// Shift all down all the nodes by one, the last node become the first one
void	rrr(t_stack **lst_a, t_stack **lst_b)
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
	}
	else
		ft_printf("error rrr\n");
}
