/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:36:02 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/13 17:48:57 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 *	Shift up all elements of stack a by 1. 
 *	The first element becomes the last one.
*/
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

/*
 *	Shift up all elements of stack b by 1. 
 *	The first element becomes the last one.
*/
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

/*
 *	Rotate the stacks a and b costs[0] and costs[1] times.
*/
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

/*
 *	Rotate the stack a until it's correctly placed.
*/
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
