/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:02:00 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/05/29 16:13:45 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	top_element_b(t_stack **stack, t_stack *node)
{
	int	l;

	l = ft_lstsize(*stack);
	while (l)
	{
		if (node->content == (*stack)->content)
			break ;
		else
		{
			if (node->index > l / 2)
				reverse_rotate_b(stack, 1);
			else
				rotate_b(stack, 1);
		}
	}
}

void	double_r(t_stack **a, t_stack **b, t_stack *node_a, t_stack *node_b)
{
	while ((*a)->content != node_a->content && (*b)->content != node_b->content)
	{
		rr(a, b);
	}
	while ((*a)->content != node_a->content)
	{
		rotate_a(a, 1);
	}
	while ((*b)->content != node_b->content)
	{
		rotate_b(b, 1);
	}
}

void	double_rr(t_stack **a, t_stack **b, t_stack *node_a, t_stack *node_b)
{
	while ((*a)->content != node_a->content && (*b)->content != node_b->content)
	{
		rrr(a, b);
	}
	while ((*b)->content != node_b->content)
	{
		reverse_rotate_b(b, 1);
	}
	while ((*a)->content != node_a->content)
	{
		reverse_rotate_a(a, 1);
	}
}

void	double_ra_rrb(t_stack **a, t_stack **b, t_stack *n_a, t_stack *n_b)
{
	while ((*b)->content != n_b->content)
	{
		reverse_rotate_b(b, 1);
	}
	while ((*a)->content != n_a->content)
	{
		rotate_a(a, 1);
	}
}

void	double_rb_rra(t_stack **a, t_stack **b, t_stack *n_a, t_stack *n_b)
{
	while ((*a)->content != n_a->content)
		reverse_rotate_a(a, 1);
	while ((*b)->content != n_b->content)
		rotate_b(b, 1);
}
