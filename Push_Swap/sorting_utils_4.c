/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:04:41 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/05/29 16:14:58 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

void	config_instruc_b(t_stack *b, int l_b, int l_a)
{
	while (b)
	{
		if (b->pair <= l_a / 2 && b->index <= l_b / 2)
			b->instruc = ft_max(b->index, b->pair);
		else if (b->pair > l_a / 2 && b->index <= l_b / 2)
			b->instruc = l_a - b->pair + 1 + b->index;
		else if (b->pair <= l_a / 2 && b->index > l_b / 2)
			b->instruc = b->pair + l_b - b->index + 1;
		else if (b->pair > l_a / 2 && b->index > l_b / 2)
			b->instruc = ft_max((l_a - b->pair + 1), (l_b - b->index + 1));
		b = b->next;
	}
}

void	index_instruc(t_stack *stack_a, t_stack *stack_b)
{
	int	tmp_b;
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(stack_a);
	len_b = ft_lstsize(stack_b);
	tmp_b = len_b;
	while (stack_a)
	{
		if (stack_a->index >= len_a / 2)
				stack_a->flag = 1;
		else
			stack_a->flag = 0;
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		if (stack_b->index >= tmp_b / 2)
				stack_b->flag = 1;
		else
			stack_b->flag = 0;
		stack_b = stack_b->next;
	}
}

t_stack	*best_element(t_stack *stack)
{
	t_stack	*node;
	t_stack	*tmp;

	tmp = stack;
	node = tmp;
	while (tmp)
	{
		if (tmp->instruc <= node->instruc)
			node = tmp;
		tmp = tmp->next;
	}
	return (node);
}

void	top_element_a(t_stack **stack, t_stack *node)
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
				reverse_rotate_a(stack, 1);
			else
				rotate_a(stack, 1);
		}
	}
}
