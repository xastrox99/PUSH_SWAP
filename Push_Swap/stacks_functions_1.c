/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_functions_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:10:13 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/05/30 13:47:33 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rotate_a(t_stack **node, int a)
{
	t_stack	*tmp;

	if (*node)
	{
		tmp = (*node)->next;
		ft_lstlast(*node)->next = *node;
		(*node)->next = NULL;
		if (tmp)
			(*node) = tmp;
		tmp = NULL;
		if (a == 1)
			write(1, "ra\n", 3);
	}
}

void	rotate_b(t_stack **node, int a)
{
	t_stack	*tmp;

	if (*node)
	{
		tmp = (*node)->next;
		ft_lstlast(*node)->next = *node;
		(*node)->next = NULL;
		if (tmp)
			(*node) = tmp;
		tmp = NULL;
		if (a == 1)
			write(1, "rb\n", 3);
	}
}

void	rr(t_stack **node_a, t_stack **node_b)
{
	rotate_a(node_a, 0);
	rotate_b(node_b, 0);
	write(1, "rr\n", 3);
}

void	reverse_rotate_a(t_stack **node, int a)
{
	t_stack	*tmp;

	if (*node)
	{
		tmp = *node;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		tmp->next->next = (*node);
		*node = tmp->next;
		tmp->next = NULL;
		tmp = NULL;
		if (a == 1)
			write(1, "rra\n", 4);
	}
}

void	reverse_rotate_b(t_stack **node, int a)
{
	t_stack	*tmp;

	if (*node)
	{
		tmp = *node;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		tmp->next->next = (*node);
		*node = tmp->next;
		tmp->next = NULL;
		tmp = NULL;
		if (a == 1)
			write(1, "rrb\n", 4);
	}
}
