/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:22:45 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/01 18:52:34 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	is_wspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

// If str has whitespace returns 1, else 0
int	has_whitespaces(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (is_wspace(str[i]))
			return (1);
	return (0);
}

// Convert a string to an int, if max or min int is depassed returns maxint+1
long	ft_atoi(char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] && (nptr[i] >= 9 && nptr[i] <= 13)) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign *= -1;
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i++] - '0');
		if (result * sign > 2147483647 || result * sign < -2147483648)
			return (2147483648);
	}
	return (result * sign);
}
