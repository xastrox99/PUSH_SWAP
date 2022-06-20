/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:54:09 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/05/29 15:58:16 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack	*get_len(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	while (stack)
	{
		if (stack->lenght != -1)
			node = stack;
		stack = stack->next;
	}
	return (node);
}

t_stack	*find_element(t_stack *stack, int index)
{
	while (stack)
	{
		if (stack->index == index)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	index_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		stack->pre_index = -1;
		stack->lenght = 1;
		stack->mark = 0;
		stack->pair = -1;
		stack->flag = 0;
		stack->instruc = 0;
		i++;
		stack = stack->next;
	}
}

t_stack	*update_len(t_stack *node)
{
	t_stack	*ptr1;
	t_stack	*ptr2;

	ptr1 = node->next;
	while (ptr1)
	{
		ptr2 = node;
		while (ptr1 != ptr2)
		{
			if (ptr2->content < ptr1->content)
			{
				if ((ptr2->lenght + 1) > ptr1->lenght)
					ptr1->lenght = ptr2->lenght + 1;
				if ((ptr2->lenght + 1) >= ptr1->lenght)
					ptr1->pre_index = ptr2->index;
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	return (get_len(node));
}

int	ft_markup(t_stack *stack, t_stack *node)
{
	int	n;

	n = 0;
	while (node->pre_index != -1)
	{
		n++;
		node->mark = 1;
		node = find_element(stack, node->pre_index);
	}
	node->mark = 1;
	n++;
	return (n);
}
