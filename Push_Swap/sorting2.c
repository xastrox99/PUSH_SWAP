/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:06:36 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/05/29 16:46:45 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort2(t_stack **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap_a(stack_a);
}

void	sort3(t_stack **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
	{
		if (((*stack_a)->next->content < (*stack_a)->next->next->content)
			&& ((*stack_a)->content > (*stack_a)->next->next->content))
			reverse_rotate_a(stack_a, 1);
		else
			swap_a(stack_a);
	}
	if ((*stack_a)->content > (*stack_a)->next->next->content)
		reverse_rotate_a(stack_a, 1);
	if ((*stack_a)->content < (*stack_a)->next->next->content \
	&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		swap_a(stack_a);
		rotate_a(stack_a, 1);
	}
}

void	sort4(t_stack **stack_a, t_stack **stack_b)
{
	top_element_a(stack_a, find_min_head(*stack_a));
	push_b(stack_a, stack_b);
	sort3(stack_a);
	push_a(stack_a, stack_b);
}

void	sort4_5(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		sort2(stack_a);
	else if (size == 3)
		sort3(stack_a);
	else if (size == 4)
		sort4(stack_a, stack_b);
	else if (size == 5)
	{
		top_element_a(stack_a, find_min_head(*stack_a));
		push_b(stack_a, stack_b);
		sort4(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
}
