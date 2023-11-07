/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:43:53 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/07 14:25:45 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	quick_sort(t_stack **lst_a, t_stack **lst_b)
{
	int	size;
	int	cut;

	size = lstsize(*lst_a);
	if (size <= 1)
		return ;
	else if (size <= 3)
		return (tiny_sort(lst_a));
	if (size < 200)
		cut = 2;
	else
		cut = 4;
	pre_sort(lst_a, lst_b, size, cut);
	tiny_sort(lst_a);
	regroup(lst_a, lst_b);
	final_rotation(lst_a);
}

int	main(int ac, char **av)
{
	t_stack	*lst_a;
	t_stack	*lst_b;

	if (ac < 2)
		return (0);
	if (check_errors(ac, av))
	{
		ft_printf("Error\n");
		return (0);
	}
	lst_a = create_stack(ac, av);
	if (!lst_a)
	{
		ft_printf("Error\n");
		return (0);
	}
	lst_b = NULL;
	if (!lstissorted(lst_a))
		quick_sort(&lst_a, &lst_b);
	return (lstclear(&lst_a), lstclear(&lst_b), 0);
}
