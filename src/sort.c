/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:22:29 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/06 00:33:39 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Sort in less than three step the chained list of size 3 or below
void	sort_in_three(t_stack **l)
{
	int	size;

	size = lstsize(*l);
	if (size > 3 || size < 2)
	{
		ft_printf("error size is not 2 or 3\n");
		return ;
	}
	if (size == 3 && (*l)->next->content > (*l)->next->next->content)
		ra(l);
	if (size == 3 && (*l)->next->content < (*l)->next->next->content)
	{
		if ((*l)->content > (*l)->next->next->content)
			ra(l);
		else if ((*l)->content > (*l)->next->content)
			sa(l);
	}
	if ((*l)->content > (*l)->next->content)
		sa(l);
	if (size == 3 && (*l)->next->content > (*l)->next->next->content)
		rra(l);
}

static void	pre_sort(t_stack **lst_a, t_stack **lst_b, int size)
{
	int		pivot;
	t_stack	*stop_mark;

	pivot = (int)(size / CUTTING) + 1;
	stop_mark = NULL;
	while (lstsize(*lst_a) > 3)
	{
		if ((stop_mark && *lst_a == stop_mark) && lstsize(*lst_a) > 3)
		{
			pivot += (int)(size / CUTTING) + 1;
			stop_mark = NULL;
		}
		if ((*lst_a)->index > pivot)
		{
			if (!stop_mark)
				stop_mark = *lst_a;
			if (*lst_b && (*lst_b)->index <= pivot - (int)(size / (CUTTING)))
				rr(lst_a, lst_b);
			else
				ra(lst_a);
		}
		else
			pb(lst_a, lst_b);
	}
}

static void	find_cheapest_move(t_stack **lst, int *costs)
{
	int		i;
	int		min;
	t_stack	*tmp;

	tmp = *lst;
	min = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
	costs[0] = tmp->cost_a;
	costs[1] = tmp->cost_b;
	while (tmp)
	{
		if (ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b) < min)
		{
			min = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
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
		// ft_printf("cheapest move : %d %d\n", costs[0], costs[1]);
		// lstprint(lst_a, lst_b);
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
		return (sort_in_three(lst_a));
	pre_sort(lst_a, lst_b, size);
	sort_in_three(lst_a);
	regroup(lst_a, lst_b);
	final_rotation(lst_a);
}

// static void	regroup(t_stack **lst_a, t_stack **lst_b)
// {
// 	int		size;
// 	int		max;
// 	int		pos;
// 	int		i;
// 	t_stack	*tmp;

// 	size = lstsize(*lst_b) + 1;
// 	while (--size)
// 	{
// 		pos = 0;
// 		max = 0;
// 		i = 0;
// 		tmp = *lst_b;
// 		while (tmp)
// 		{
// 			if (tmp->index > max)
// 			{
// 				pos = i;
// 				max = tmp->index;
// 			}
// 			tmp = tmp->next;
// 			i++;
// 		}
// 		if (pos > (int)(size / 2))
// 			while (pos++ < size)
// 				rrb(lst_b);
// 		else
// 			while (pos-- > 0)
// 				rb(lst_b);
// 		pa(lst_a, lst_b);
// 	}
// }









// static int	find_pivot(t_stack *lst_a, int size)
// {
// 	t_stack	*tmp;
// 	int		total;

// 	total = 0;
// 	tmp = lst_a;
// 	while (tmp)
// 	{
// 		total += tmp->index;
// 		tmp = tmp->next;
// 	}
// 	// return (total / (size + (size / 2)));
// 	return (total / size);
// }

// void	ft_rotatesort(t_stack **lst_a, t_stack **lst_b)
// {
// 	int	size;
// 	int	min;
// 	int	i;

// 	size = lstsize(*lst_a);
// 	while (!lstissorted(*lst_a) && size)
// 	{
// 		min = lstmin(*lst_a);
// 		i = -1;
// 		if (size - min < min && size > 1)
// 			while (++i < size - min)
// 				rra(lst_a);
// 		else if (size > 1)
// 			while (++i < min)
// 				ra(lst_a);
// 		if (!lstissorted(*lst_a))
// 			pb(lst_a, lst_b);
// 		size--;
// 	}
// 	while (*lst_b)
// 		pa(lst_a, lst_b);
// }