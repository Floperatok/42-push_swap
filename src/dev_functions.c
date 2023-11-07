/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 05:34:12 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/06 17:09:26 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Print the content of the lists
void	lstprint(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *lst_a;
	tmp_b = *lst_b;
	while (tmp_a || tmp_b)
	{
		if (tmp_a)
		{
			ft_printf("%d (%d)(%d)", tmp_a->index, \
			tmp_a->cost_a, tmp_a->cost_b);
			tmp_a = tmp_a->next;
		}
		else
			ft_printf("\t");
		ft_printf("\t");
		if (tmp_b)
		{
			ft_printf("%d (%d)(%d)", tmp_b->index, \
			tmp_b->cost_a, tmp_b->cost_b);
			tmp_b = tmp_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("_\t\t_\na\t\tb\n\n");
}
