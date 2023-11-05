/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 05:40:10 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/04 13:52:09 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Return the pos of the minimum content in the chained list following the node
int	lstmin(t_stack *node)
{
	int	index;
	int	i;
	int	min;

	index = 0;
	i = 0;
	if (!node)
		return (0);
	min = node->content;
	while (node)
	{
		if (min > node->content)
		{
			min = node->content;
			index = i;
		}
		node = node->next;
		i++;
	}
	return (index);
}

// Return the size of the chained list following the node
int	lstsize(t_stack *node)
{
	int	i;

	i = 0;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}

// Return 1 if the content is found in the list following the node, 0 otherwise
int	is_inlst(t_stack *node, int content)
{
	while (node)
	{
		if (node->content == content)
			return (1);
		node = node->next;
	}
	return (0);
}
