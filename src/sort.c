/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:22:29 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/07 18:18:44 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*change_pivot(int *pivot, int size, int cut)
{
	*pivot += (size / cut);
	return (NULL);
}

void	pre_sort(t_stack **lst_a, t_stack **lst_b, int size, int cut)
{
	int		pivot;
	t_stack	*stop_mark;

	pivot = (size / cut);
	stop_mark = change_pivot(&pivot, size, cut);
	while (lstsize(*lst_a) > 3)
	{
		if ((stop_mark && *lst_a == stop_mark) && lstsize(*lst_a) > 3)
			stop_mark = change_pivot(&pivot, size, cut);
		if ((*lst_a)->index > pivot)
		{
			if (!stop_mark)
				stop_mark = *lst_a;
			if (*lst_b && (*lst_b)->index <= pivot - size / (cut * 1.6))
				rr(lst_a, lst_b);
			else
				ra(lst_a);
		}
		else
		{
			pb(lst_a, lst_b);
			if (pivot == size && (*lst_b)->index <= pivot - size / (cut * 1.6))
				rb(lst_b);
		}
	}
}

static int	total_node_cost(t_stack *node)
{
	if ((node->cost_a > 0 && node->cost_b > 0) || \
		(node->cost_a < 0 && node->cost_b < 0))
		return (ft_max(ft_abs(node->cost_a), ft_abs(node->cost_b)));
	return (ft_abs(node->cost_a) + ft_abs(node->cost_b));
}

static void	find_cheapest_move(t_stack **lst, int *costs)
{
	int		min;
	t_stack	*tmp;
	int		cost;

	tmp = *lst;
	min = total_node_cost(tmp);
	costs[0] = tmp->cost_a;
	costs[1] = tmp->cost_b;
	while (tmp)
	{
		cost = total_node_cost(tmp);
		if (cost < min)
		{
			min = cost;
			costs[0] = tmp->cost_a;
			costs[1] = tmp->cost_b;
		}
		tmp = tmp->next;
	}
}

void	regroup(t_stack **lst_a, t_stack **lst_b)
{
	int	*costs;

	costs = (int *)malloc(sizeof(int) * 2);
	while (*lst_b)
	{
		compute_all_costs(lst_a, lst_b);
		find_cheapest_move(lst_b, costs);
		do_moves(lst_a, lst_b, costs);
	}
	free(costs);
}
