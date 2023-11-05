/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:43:53 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/06 00:26:01 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// reflechir à mieux nommer les fonction / variables
// reflechir aux pointeur qu'on envoi dans les fonctions

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
	// lstprint(&lst_a, &lst_b);
	return (lstclear(&lst_a), lstclear(&lst_b), 0);
}
