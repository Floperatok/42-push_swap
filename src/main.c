/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:43:53 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/01 13:10:27 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rotatesort(t_list **lst_a, t_list **lst_b)
{
	int	size;
	int	min;
	int	i;

	size = lstsize(*lst_a);
	while (!lstissorted(*lst_a) && size)
	{
		min = lstmin(*lst_a);
		i = -1;
		if (size - min < min && size > 1)
			while (++i < size - min)
				rra(lst_a);
		else if (size > 1)
			while (++i < min)
				ra(lst_a);
		if (!lstissorted(*lst_a))
			pb(lst_a, lst_b);
		size--;
	}
	while (*lst_b)
		pa(lst_a, lst_b);
}

int	main(int ac, char **av)
{
	t_list	**lst_a;
	t_list	*a;
	t_list	**lst_b;
	t_list	*b;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	lst_b = &b;
	lst_a = &a;
	if (has_whitespaces(av[1]))
		lst_a = fill_lst_onearg(lst_a, av, ac);
	else
		lst_a = fill_lst_multiple_args(lst_a, av, ac);
	if (!lst_a)
	{
		ft_printf("Error\n");
		return (0);
	}
	lstprint(lst_a, lst_b);
	return (lstclear(lst_a), lstclear(lst_b), 0);
}
