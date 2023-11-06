/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:36:02 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/06 00:49:34 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate_a(t_stack **lst_a, int cost)
{
	while (cost > 0)
	{
		ra(lst_a);
		cost--;
	}
	while (cost < 0)
	{
		rra(lst_a);
		cost++;
	}
}

static void	rotate_b(t_stack **lst_b, int cost)
{
	while (cost > 0)
	{
		rb(lst_b);
		cost--;
	}
	while (cost < 0)
	{
		rrb(lst_b);
		cost++;
	}
}

void	do_moves(t_stack **lst_a, t_stack **lst_b, int *costs)
{
	while (costs[0] > 0 && costs[1] > 0)
	{
		rr(lst_a, lst_b);
		costs[0]--;
		costs[1]--;
	}
	while (costs[0] < 0 && costs[1] < 0)
	{
		rrr(lst_a, lst_b);
		costs[0]++;
		costs[1]++;
	}
	rotate_a(lst_a, costs[0]);
	rotate_b(lst_b, costs[1]);
	pa(lst_a, lst_b);
}

void	final_rotation(t_stack **lst_a)
{
	int	size;
	int	index;

	size = lstsize(*lst_a);
	index = (*lst_a)->index;
	if (index > size / 2)
		while (index++ < size + 1)
			ra(lst_a);
	else
		while (--index)
			rra(lst_a);
}
