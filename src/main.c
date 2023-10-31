/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:43:53 by nsalles           #+#    #+#             */
/*   Updated: 2023/10/31 06:02:33 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_bubblesort(t_list **lst_a, t_list **lst_b)
{
	int	size;
	int	i;
	int	operation_counter = 0; // delete before pushing

	size = lstsize(*lst_a) + 1;
	while (size--)
	{
		i = -1;
		if (lstissorted(*lst_a))
			return (operation_counter);
		while (++i < size - 1) // -1 car c'est inutile d'envoyer le dernier dans b
		{
			if ((*lst_a)->content > (*lst_a)->next->content)
			{
				sa(lst_a);
				pb(lst_a, lst_b);
				operation_counter += 2;
			}
			else
			{
				operation_counter++;
				pb(lst_a, lst_b);
			}
		}
		while ((*lst_b))
		{
			pa(lst_a, lst_b);
			operation_counter++;
		}
	}
	return (operation_counter);
}

int	main(int ac, char **av)
{
	t_list	**lst_a;
	t_list	*a;
	t_list	**lst_b;
	t_list	*b;
	int		i;

	if (ac < 2)
		return (0);

	// Creating the chained lists	
	i = ac - 1;
	a = NULL;
	b = NULL;
	lst_a = &a;
	lst_b = &b;
	while (i > 0)
		lstadd_front(lst_a, lstnew(ft_atoi(av[i--])));
	
	// Operating
	lstprint(lst_a, lst_b);
	ft_printf("Operations = %d\n", ft_bubblesort(lst_a, lst_b));
	lstprint(lst_a, lst_b);
	
	// Freeing
	lstclear(lst_a);
	lstclear(lst_b);
	return (0);
}
