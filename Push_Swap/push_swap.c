/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:46:54 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/05/30 16:24:56 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*node_a;
	t_stack	*node_b;

	node_a = NULL;
	node_b = NULL;
	check_in(ac, av, &node_a);
	sort_stack(&node_a, &node_b);
}
