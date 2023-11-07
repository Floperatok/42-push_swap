/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:51:52 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/07 13:43:23 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Check if the chained list following the node is sorted by ascending order
int	lstissorted(t_stack *node)
{
	if (!node)
		return (1);
	while (node->next)
	{
		if (node->next->content < node->content)
			return (0);
		node = node->next;
	}
	return (1);
}

static int	find_highest_pos(t_stack *node)
{
	int	highest;
	int	pos;
	int	i;

	pos = 0;
	highest = node->index;
	i = 0;
	while (node)
	{
		if (highest < node->index)
		{
			highest = node->index;
			pos = i;
		}
		i++;
		node = node->next;
	}
	return (pos);
}

// Sort in less than three step the chained list of size 3 or below
void	tiny_sort(t_stack **lst_a)
{
	int	size;
	int	highest_pos;

	size = lstsize(*lst_a);
	if (size > 3 || size < 2)
	{
		ft_printf("error size is not 2 or 3\n");
		return ;
	}
	highest_pos = find_highest_pos(*lst_a);
	if (size == 2)
	{
		if (!lstissorted(*lst_a))
			sa(lst_a);
	}
	else
	{
		if (highest_pos == 0)
			ra(lst_a);
		else if (highest_pos == 1)
			rra(lst_a);
		if ((*lst_a)->index > (*lst_a)->next->index)
			sa(lst_a);
	}
}

// Compute the number of moves b needed to perfectly store the node in a
static void	compute_cost(t_stack *node, int pos, int size_b, t_stack **lst_a)
{
	int	size_a;
	int	target_pos;

	if (pos > size_b / 2)
		node->cost_b = pos - size_b;
	else
		node->cost_b = pos;
	size_a = lstsize(*lst_a);
	target_pos = get_target_pos(node->index, lst_a);
	if (target_pos > size_a / 2)
		node->cost_a = target_pos - size_a;
	else
		node->cost_a = target_pos;
}

// Compute the number of moves of all the nodes in b
void	compute_all_costs(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*tmp;
	int		pos;
	int		size_b;

	tmp = *lst_b;
	size_b = lstsize(*lst_b);
	pos = 0;
	while (tmp)
	{
		compute_cost(tmp, pos, size_b, lst_a);
		pos++;
		tmp = tmp->next;
	}
}
