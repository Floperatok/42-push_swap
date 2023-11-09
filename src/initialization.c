/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:03:29 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/09 08:23:33 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Gives following index in size order to the list, convenient for sorting 
static void	assign_index(t_stack **lst, int size)
{
	int		max;
	t_stack	*tmp;
	t_stack	*highest;

	while (--size > 0)
	{
		highest = NULL;
		max = INT_MIN;
		tmp = *lst;
		while (tmp)
		{
			if (tmp->content == INT_MIN && !tmp->index)
				tmp->index = 1;
			if (tmp->content > max && !tmp->index)
			{
				max = tmp->content;
				highest = tmp;
				tmp = *lst;
			}
			else
				tmp = tmp->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}

char	**get_args(int ac, char **av)
{
	char	**args;
	int		i;
	int		has_space;

	i = -1;
	has_space = 0;
	while (av[1][++i])
		if (av[1][i] == ' ')
			has_space = 1;
	if (has_space)
		return (ft_split(av[1], ' '));
	args = (char **)malloc(sizeof(char *) * (ac));
	if (!args)
		return (NULL);
	i = -1;
	while (++i < ac - 1)
		args[i] = ft_strdup(av[i + 1]);
	args[i] = NULL;
	return (args);
}

// Check if there is non numeric characters or wrong minus sign in args
int	check_carac(char **args)
{
	int	i;
	int	j;

	i = -1;
	while (args[++i])
	{
		if (args[i][0] == '-')
		{
			if (ft_strlen(args[i]) == 1)
				return (1);
			j = 0;
		}
		else
			j = -1;
		while (args[i][++j])
			if (args[i][j] < '0' || args[i][j] > '9')
				return (1);
	}
	return (0);
}

// Check if there is any error in av, returns 1 if error is found, 0 otherwise
int	check_errors(int ac, char **av)
{
	char	**args;
	long	*int_args;
	int		i;
	int		j;

	args = get_args(ac, av);
	if (!args)
		return (1);
	if (check_carac(args))
		return (free_tab(args), 1);
	int_args = (long *)malloc(sizeof(long) * (ft_tablen(args)));
	if (!int_args)
		return (free_tab(args), 1);
	i = -1;
	while (args[++i])
	{
		int_args[i] = ft_atoi(args[i]);
		if (int_args[i] > INT_MAX || int_args[i] < INT_MIN)
			return (free(int_args), free_tab(args), 1);
		j = -1;
		while (++j < i)
			if (int_args[i] == int_args[j])
				return (free(int_args), free_tab(args), 1);
	}
	return (free(int_args), free_tab(args), 0);
}

// Create the stack a and assign it's indexes
t_stack	*create_stack(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*tmp;
	char	**args;
	int		i;

	args = get_args(ac, av);
	if (!args)
		return (NULL);
	i = 0;
	stack = lstnew(ft_atoi(args[0]));
	if (!stack)
		return (free_tab(args), NULL);
	while (args[++i])
	{
		tmp = lstnew(ft_atoi(args[i]));
		if (!tmp)
			return (lstclear(&stack), free_tab(args), NULL);
		lstadd_back(&stack, tmp);
	}
	free_tab(args);
	assign_index(&stack, lstsize(stack) + 1);
	return (stack);
}
