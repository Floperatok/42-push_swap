/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:43:53 by nsalles           #+#    #+#             */
/*   Updated: 2023/10/31 15:25:35 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_rotatesort(t_list **lst_a, t_list **lst_b)
{
	int	size;
	int	min;
	int	i;
	int	operation_counter = 0; // delete before pushing

	size = lstsize(*lst_a);
	while (!lstissorted(*lst_a) && size)
	{
		min = lstmin(*lst_a);
		i = -1;
		if (size - min < min && size > 1)
			while (++i < size - min)
			{
				operation_counter++;
				rra(lst_a);
			}
		else if (size > 1)
			while (++i < min)
			{
				operation_counter++;
				ra(lst_a);
			}
		if (!lstissorted(*lst_a))
		{
			operation_counter++;
			pb(lst_a, lst_b);
		}
		size--;
	}
	while (*lst_b)
	{
		operation_counter++;
		pa(lst_a, lst_b);
	}
	return (operation_counter);
}

int	ft_bubblesort(t_list **lst_a, t_list **lst_b)
{
	int	size;
	int	i;
	int	operation_counter = 0; // delete before pushing

	size = lstsize(*lst_a) + 1;
	while (!lstissorted(*lst_a) &&size--)
	{
		i = -1;
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
		while (*lst_b)
		{
			pa(lst_a, lst_b);
			operation_counter++;
		}
	}
	return (operation_counter);
}


// penser à changer le format d'input, tout prendre sous une seule chaine
// de caractère
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
	ft_printf("Operations = %d\n", ft_rotatesort(lst_a, lst_b));
	// ft_printf("Operations bubble sort = %d\n", ft_bubblesort(lst_a, lst_b));
	lstprint(lst_a, lst_b);
	
	// Freeing
	lstclear(lst_a);
	lstclear(lst_b);
	return (0);
}
