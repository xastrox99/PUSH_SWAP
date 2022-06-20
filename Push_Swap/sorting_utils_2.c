/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:55:18 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/05/29 15:58:06 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	find_lentab(t_stack *node)
{
	t_stack	*highest_node;

	if (!node)
		return (0);
	highest_node = update_len(node);
	return (ft_markup(node, highest_node));
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b, int len)
{
	while (len > 0)
	{
		if ((*stack_a)->mark == 0)
		{
			push_b(stack_a, stack_b);
			len--;
		}
		else
		{
			rotate_a(stack_a, 1);
		}
	}
	rotate_a(stack_a, 1);
}

void	pair_element(t_stack *stack_a, t_stack *node_b)
{
	t_stack	*head;

	head = stack_a;
	while (stack_a->next)
	{
		if (node_b->content < stack_a->next->content
			&& node_b->content > stack_a->content)
		{
			node_b->pair = stack_a->next->index;
			return ;
		}
		stack_a = stack_a->next;
	}
	if (node_b->content > stack_a->content && node_b->content < head->content)
	{
		node_b->pair = head->index;
		return ;
	}
	node_b->pair = (find_min_head(head))->index;
}

void	check_for_min_elem(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b)
	{
		pair_element(stack_a, stack_b);
		stack_b = stack_b->next;
	}
}

void	re_index_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a->index = i;
		i++;
		stack_a = stack_a->next;
	}
	i = 0;
	while (stack_b)
	{
		stack_b->index = i;
		i++;
		stack_b = stack_b->next;
	}
}
