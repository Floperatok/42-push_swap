/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:32:35 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/03 18:16:04 by nsalles          ###   ########.fr       */
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
