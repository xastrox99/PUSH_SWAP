/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:15:37 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/05/10 18:04:25 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_lstadd_back(t_stack **alst, t_stack *new)
{
	t_stack	*ptr;

	if (*alst != NULL && new != NULL)
	{
		ptr = *alst;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = new;
		new->next = NULL;
	}
	else
	{
		if (new)
		{
			*alst = new;
			new->next = NULL;
		}
		else
		{
			*alst = NULL;
		}
	}
}
