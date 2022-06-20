/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:22:30 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/05/29 16:23:06 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rrr(t_stack **node_a, t_stack **node_b)
{
	reverse_rotate_a(node_a, 0);
	reverse_rotate_b(node_b, 0);
	write(1, "rrr\n", 4);
}
