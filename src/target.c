/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:25:12 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/13 18:33:14 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 *	Same as get_target_pos but in the case where the index is higher than
 *	all the indexes in the stack a.
*/
static int	get_maxindex_pos(t_stack **lst)
{
	t_stack	*tmp;
	int		max;
	int		i;
	int		pos;

	i = 0;
	tmp = *lst;
	max = tmp->index;
	pos = 0;
	while (tmp)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (pos + 1);
}

/*
 *	Returns the position of in th stack a where the index must be to 
 *	be sorted.
*/
int	get_target_pos(int index, t_stack **lst_a)
{
	t_stack	*tmp;
	int		pos;
	int		i;
	long	target;

	target = LONG_MAX;
	i = 0;
	tmp = *lst_a;
	while (tmp)
	{
		if (tmp->index > index && tmp->index < target)
		{
			target = tmp->index;
			pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	if (target != LONG_MAX)
		return (pos);
	return (get_maxindex_pos(lst_a));
}
