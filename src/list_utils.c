/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:08:00 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/01 13:20:51 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Check if the chained list following the node is sorted by ascending order
int	lstissorted(t_list *node)
{
	if (!node)
		return (1);
	while (node->next)
	{
		if (node->next->content < node->content)
			return (0);
		node = node->next;
	}
	return (1);
}

// Add a node to the front of the chained list
void	lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

// Add a node to the back of the chained list
void	lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	new->next = NULL;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

// Create a new node, returns NULL if content isn't in integer value range
t_list	*lstnew(long content)
{
	t_list	*new;

	if (content > 2147483647 || content < -2147483648)
		return (NULL);
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

// Clear and free all the chained list
void	lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	lst = NULL;
}
