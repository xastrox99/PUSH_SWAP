/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:20:39 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/05/29 16:58:46 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*ptr;

	ptr = malloc(sizeof(t_stack));
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr)
		ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}
