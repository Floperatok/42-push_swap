/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:23:32 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/04 13:52:19 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Exchange the two firts elements of a
void	sa(t_stack **lst_a)
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
	}
	else
		ft_printf("error sa\n");
}

// Exchange the two firts elements of b
void	sb(t_stack **lst_b)
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
	}
	else
		ft_printf("error sa\n");
}

// Exchange the two firts elements of a and b
void	ss(t_stack **lst_a, t_stack **lst_b)
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
	}
	else
		ft_printf("error ss\n");
}

// Push from b to a
void	pa(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*tmp;

	if ((*lst_b))
	{
		tmp = (*lst_b)->next;
		lstadd_front(lst_a, (*lst_b));
		*lst_b = tmp;
		ft_printf("pa\n");
	}
	else
		ft_printf("error pa\n");
}

// Push from a to b
void	pb(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*tmp;

	if ((*lst_a))
	{
		tmp = (*lst_a)->next;
		lstadd_front(lst_b, (*lst_a));
		*lst_a = tmp;
		ft_printf("pb\n");
	}
	else
		ft_printf("error pb\n");
}
