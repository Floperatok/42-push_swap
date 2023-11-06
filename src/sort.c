/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:22:29 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/06 13:05:52 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	pre_sort(t_stack **lst_a, t_stack **lst_b, int size, int cut)
{
	int		pivot;
	t_stack	*stop_mark;

	pivot = (int)(size / cut) + 1;
	stop_mark = NULL;
	while (lstsize(*lst_a) > 3)
	{
		if ((stop_mark && *lst_a == stop_mark) && lstsize(*lst_a) > 3)
		{
			pivot += (int)(size / cut) + 1;
			stop_mark = NULL;
		}
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
			pb(lst_a, lst_b);
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
	int		i;
	int		min;
	t_stack	*tmp;
	int		cost;

	tmp = *lst;
	min = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
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
		i++;
	}
}

static void	regroup(t_stack **lst_a, t_stack **lst_b)
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

void	quick_sort(t_stack **lst_a, t_stack **lst_b)
{
	int	size;

	size = lstsize(*lst_a);
	if (size <= 1)
		return ;
	else if (size <= 3)
		return (tiny_sort(lst_a));
	pre_sort(lst_a, lst_b, size, CUTTING);
	tiny_sort(lst_a);
	regroup(lst_a, lst_b);
	final_rotation(lst_a);
}
