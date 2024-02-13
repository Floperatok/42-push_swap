/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:32:35 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/13 17:06:12 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_count_words(char const *s, char c)
{
	int	in_word;
	int	count;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*ft_word_dup(const char *src, char c)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (src[len] && src[len] != c)
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (*src && *src != c)
		word[i++] = *src++;
	word[i] = '\0';
	return (word);
}

static void	free_split(char **tab, int i)
{
	while (i >= 0)
		free(tab[i--]);
	free(tab);
}

/*
 *	Splits the string s according to the delimiter c into an array of strings.
 *	Each string of the array and the array are null-terminated.
 *	Memory for the new strings and the array is obtained with malloc(3), and can
 *	be freed with free(3).
 * 	ARGUMENT:
 * 		char const *s	: The string to split.
 * 		char c			: The delimiter.
 * 	RETURN VALUE:
 * 		char **	: Null-terminated array of null-terminated strings
 * 		Ft_split works as follow: 
 * 			ft_split("Hello world", ' ') returns {"Hello\0", "world\n", NULL}.
 * 		Note that the delimiter is not kept in the final result.
*/
char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word_count;
	int		i;

	if (!s)
		return (NULL);
	word_count = ft_count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		res[i] = ft_word_dup(s, c);
		if (!res[i])
		{
			free_split(res, i - 1);
			return (NULL);
		}
		s += ft_strlen(res[i++]);
	}
	res[i] = NULL;
	return (res);
}
