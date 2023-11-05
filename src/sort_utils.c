/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:51:52 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/05 23:21:46 by nsalles          ###   ########.fr       */
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

// Compute the number of moves b needed to perfectly store the node in a
static void	compute_cost(t_stack *node, int pos, int size_b, t_stack **lst_a)
{
	int	target_pos;
	int	size_a;

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

// void	bubble_sort(int *tab, int size)
// {
// 	int	i;
// 	int	j;
// 	int cmp;

// 	if (!tab || size == 0)
// 		return ;
// 	i = 0;
// 	while (++i < size)
// 	{
// 		j = -1;
// 		while (++j < size - i)
// 		{
// 			if (tab[j] > tab[j + 1])
// 			{
// 				cmp = tab[j];
// 				tab[j] = tab[j + 1];
// 				tab[j + 1] = cmp;
// 			}
// 		}
// 	}
// }
