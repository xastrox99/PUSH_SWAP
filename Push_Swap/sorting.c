/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:32:07 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/05/30 13:15:01 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	double_rotate_dec(t_stack **a, t_stack **b, t_stack *n_a, t_stack *n_b)
{
	if (n_a->flag == 0 && n_b->flag == 0)
		double_r(a, b, n_a, n_b);
	else if (n_a->flag == 0 && n_b->flag == 1)
		double_ra_rrb(a, b, n_a, n_b);
	else if (n_a->flag == 1 && n_b->flag == 0)
		double_rb_rra(a, b, n_a, n_b);
	else
		double_rr(a, b, n_a, n_b);
}

void	move_best_element(t_stack **stack_a, t_stack **stack_b, t_stack *n_b)
{
	int		len_a;
	int		len_b;
	t_stack	*node_a;

	len_a = ft_lstsize(*stack_a);
	len_b = ft_lstsize(*stack_b);
	node_a = find_element((*stack_a), n_b->pair);
	if (node_a->flag != n_b->flag)
	{
		top_element_a(stack_a, node_a);
		top_element_b(stack_b, n_b);
	}
	else
		double_rotate_dec(stack_a, stack_b, node_a, n_b);
}

void	ft_sorting(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*best_node;
	int		len_b;
	int		len_a;

	len_b = ft_lstsize(*stack_b);
	len_a = ft_lstsize(*stack_a);
	config_instruc_b(*stack_b, len_b, len_a);
	best_node = best_element(*stack_b);
	move_best_element(stack_a, stack_b, best_node);
}

t_stack	*find_min_head(t_stack *stack)
{
	t_stack	*min;
	t_stack	*tmp;

	tmp = stack;
	min = stack;
	while (tmp)
	{
		if (min->content > tmp->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	if (sorted(*stack_a))
		return ;
	if (ft_lstsize(*stack_a) <= 5)
		sort4_5(stack_a, stack_b, ft_lstsize(*stack_a));
	else
	{
		index_stack(*stack_a);
		len = find_lentab(*stack_a);
		push_to_b(stack_a, stack_b, ft_lstsize(*stack_a) - len);
		while ((*stack_b))
		{
			re_index_stack(*stack_a, *stack_b);
			index_instruc(*stack_a, *stack_b);
			check_for_min_elem(*stack_a, *stack_b);
			ft_sorting(stack_a, stack_b);
			push_a(stack_a, stack_b);
		}
		top_element_a(stack_a, find_min_head(*stack_a));
	}
}
