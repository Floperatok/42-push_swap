/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:23:32 by nsalles           #+#    #+#             */
/*   Updated: 2023/10/31 04:37:49 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Exchange the two firts elements of a
void	sa(t_list **lst_a)
{
	t_list	*tmp;

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
void	sb(t_list **lst_b)
{
	t_list	*tmp;

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
void	ss(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

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
void	pa(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	if ((*lst_b))
	{
		lstadd_front(lst_a, lstnew((*lst_b)->content));
		tmp = (*lst_b)->next;
		free((*lst_b));
		*lst_b = tmp;
		ft_printf("pa\n");
	}
	else
		ft_printf("error pa\n");
}

// Push from a to b
void	pb(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	if ((*lst_a))
	{
		lstadd_front(lst_b, lstnew((*lst_a)->content));
		tmp = (*lst_a)->next;
		free((*lst_a));
		*lst_a = tmp;
		ft_printf("pb\n");
	}
	else
		ft_printf("error pb\n");
}
