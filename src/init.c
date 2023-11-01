/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:03:29 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/01 12:04:18 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	**fill_lst_multiple_args(t_list **lst, char **av, int ac)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = ac - 1;
	while (i > 0)
	{
		j = -1;
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]))
				return (lstclear(lst), NULL);
		tmp = lstnew(ft_atoi(av[i--]));
		if (!tmp)
			return (lstclear(lst), NULL);
		lstadd_front(lst, tmp);
	}
	return (lst);
}

t_list	**fill_lst_onearg(t_list **lst, char **av, int ac)
{
	t_list	*tmp;
	int		i;

	if (ac != 2)
		return (NULL);
	i = -1;
	while (av[1][++i])
		if (!ft_isdigit(av[1][i]) && !is_whitespace(av[1][i]))
			return (lstclear(lst), NULL);
	while (*av[1])
	{
		while (*av[1] && is_whitespace(*av[1]))
			av[1]++;
		if (*av[1])
		{
			tmp = lstnew(ft_atoi(av[1]));
			if (!tmp)
				return (lstclear(lst), NULL);
			lstadd_back(lst, tmp);
		}
		while (*av[1] && !is_whitespace(*av[1]))
			av[1]++;
	}
	return (lst);
}
