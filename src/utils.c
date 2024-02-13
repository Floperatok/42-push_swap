/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:22:45 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/13 18:35:29 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 *	Returns the size of the string.
*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
 *	Returns the size of the NULL terminated array of strings.
*/
int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

/*
 *	Returns the absolute value of n.
*/
int	ft_abs(int n)
{
	if (n < 0)
		return (n * (-1));
	return (n);
}

/*
 *	Returns the maximum value between a and b. 
*/
int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	if (a < b)
		return (b);
	return (a);
}

/*
 *	Free the array of strings.
*/
void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}
