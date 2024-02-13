/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:32:23 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/13 17:02:26 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/checker.h"

/*
 *	Compare the first and the second string, returns first ascii difference. 
 *	Returns 0 if no difference are found.
*/
static int	ft_strcmp(char *s1, char *s2)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	while (us1[i] != '\0' || us2[i] != '\0')
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	return (0);
}

/*
 *	Execute the given move on the stacks.
 *	Return 0 if success, -1 otherwise.
*/
static int	redo_move(char *line, t_stack **lst_a, t_stack **lst_b)
{
	if (!ft_strcmp(line, "sa\n"))
		return (sa(lst_a));
	if (!ft_strcmp(line, "pa\n"))
		return (pa(lst_a, lst_b));
	if (!ft_strcmp(line, "pb\n"))
		return (pb(lst_a, lst_b));
	if (!ft_strcmp(line, "ra\n"))
		return (ra(lst_a));
	if (!ft_strcmp(line, "rra\n"))
		return (rra(lst_a));
	if (!ft_strcmp(line, "rb\n"))
		return (rb(lst_b));
	if (!ft_strcmp(line, "rrb\n"))
		return (rrb(lst_b));
	if (!ft_strcmp(line, "rr\n"))
		return (rr(lst_a, lst_b));
	if (!ft_strcmp(line, "rrr\n"))
		return (rrr(lst_a, lst_b));
	return (-1);
}

/*
 *	Read on standard input for push_swap moves, executes these moves and print
 *	OK if the moves sorts the stack a, KO otherwise. Print Error if wrong
 *	move are received.
*/
static void	check(char *line, t_stack *lst_a, t_stack *lst_b)
{
	int		output;

	while (line)
	{
		output = redo_move(line, &lst_a, &lst_b);
		if (output == -1)
		{
			ft_print_error("Error\n");
			return (lstclear(&lst_a), lstclear(&lst_b), free(line));
		}
		else if (output == 0)
		{
			ft_printf("KO\n");
			return (lstclear(&lst_a), lstclear(&lst_b), free(line));
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (lstissorted(lst_a) && lstsize(lst_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	lstclear(&lst_a);
	lstclear(&lst_b);
}

int	main(int ac, char **av)
{
	t_stack	*lst_a;
	t_stack	*lst_b;
	char	*line;

	if (ac < 2)
		return (0);
	if (check_errors(ac, av))
	{
		ft_print_error("Error\n");
		return (0);
	}
	lst_a = create_stack(ac, av);
	if (!lst_a)
	{
		ft_print_error("Error\n");
		return (0);
	}
	lst_b = NULL;
	line = get_next_line(0);
	check(line, lst_a, lst_b);
	get_next_line(-1);
	return (0);
}
