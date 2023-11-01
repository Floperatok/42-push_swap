/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:03:29 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/01 20:35:07 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Create, test and add the node to the list, return 1 if success 0 otherwise
static int	create_node(t_list **lst, char *str)
{
	t_list	*node;
	long	n;

	n = ft_atoi(str);
	if (n > 2147483647 || n < -2147483648 || is_inlst(*lst, n))
		return (0);
	node = lstnew(n);
	if (!node)
		return (0);
	lstadd_back(lst, node);
	return (1);
}

t_list	**fill_lst_multiple_args(t_list **lst, char **av, int ac)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = -1;
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]) && (av[i][j] != '-' \
			|| (av[i][j] == '-' && !ft_isdigit(av[i][j + 1]))))
				return (lstclear(lst), NULL);
		if (!create_node(lst, av[i]))
			return (lstclear(lst), NULL);
		i++;
	}
	return (lst);
}

t_list	**fill_lst_onearg(t_list **lst, char **av, int ac)
{
	int		i;

	if (ac != 2)
		return (NULL);
	i = -1;
	while (av[1][++i])
	{
		if ((!ft_isdigit(av[1][i]) && !is_wspace(av[1][i])) \
		&& (av[1][i] != '-' || (av[1][i] == '-' && !ft_isdigit(av[1][i + 1]))))
			return (lstclear(lst), NULL);
	}
	while (*av[1] && is_wspace(*av[1]))
		av[1]++;
	while (*av[1])
	{
		if (!*av[1] || !create_node(lst, av[1]))
			return (lstclear(lst), NULL);
		while (*av[1] && !is_wspace(*av[1]))
			av[1]++;
		while (*av[1] && is_wspace(*av[1]))
			av[1]++;
	}
	return (lst);
}
