/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:43:17 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/13 18:38:43 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 *	Convert a string to an int, if max or min int is depassed returns maxint+1.
*/
long	ft_atoi(char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] && nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign *= -1;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		result = result * 10 + (nptr[i++] - '0');
		if (result * sign > 2147483647 || result * sign < -2147483648)
			return (2147483648);
	}
	return (result * sign);
}

/*
 *	Returns a pointer to a new string which is a duplicate of the string.
 *	Memory for the new string is obtained with malloc(3), and can be freed with
 * 	free(3).
 * 	ARGUMENTS:
 * 		const char *s	: The string to copie.
 * 	RETURN VALUE:
 * 		char *	: On success, this function returns a pointer to the duplicated
 * 		string. It returns NULL if insufficient memory was available.
*/
char	*ft_strdup(char *s)
{
	char	*d;
	int		i;

	d = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (d == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

/*
 *	Prints str in the standard error stream.
*/
void	ft_print_error(char *str)
{
	write(2, str, ft_strlen(str));
}
