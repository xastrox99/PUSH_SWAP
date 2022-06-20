/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:10:44 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/05/29 16:20:08 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **node)
{
	t_stack	*tmp;

	if (*node)
	{
		tmp = (*node)->next;
		(*node)->next = tmp->next;
		tmp->next = (*node);
		(*node) = tmp;
		tmp = NULL;
	}
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **node)
{
	t_stack	*tmp;

	if (*node)
	{
		tmp = (*node)->next;
		(*node)->next = tmp->next;
		tmp->next = (*node);
		(*node) = tmp;
		tmp = NULL;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack **node_a, t_stack **node_b)
{
	swap_a(node_a);
	swap_b(node_b);
	write(1, "ss\n", 3);
}

void	push_b(t_stack **node_a, t_stack **node_b)
{
	t_stack	*tmp;

	if (*node_a)
	{
		tmp = (*node_a)->next;
		(*node_a)->next = *node_b;
		*node_b = *node_a;
		*node_a = tmp;
		tmp = NULL;
	}
	write(1, "pb\n", 3);
}

void	push_a(t_stack **node_a, t_stack **node_b)
{
	t_stack	*tmp;

	if (*node_b)
	{
		tmp = (*node_b)->next;
		(*node_b)->next = *node_a;
		*node_a = *node_b;
		*node_b = tmp;
		tmp = NULL;
	}
	write(1, "pa\n", 3);
}
