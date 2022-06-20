/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:53:52 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/06/02 15:05:46 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	numcompare(int a, int b)
{
	if (a == b)
		return (0);
	else
		return (1);
}

int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_stack	*ptr;

	i = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

void	clr_list(t_stack **head)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (head && *head)
	{
		temp = (*head)->next;
		while (temp && (temp != *head))
		{
			temp2 = temp;
			temp = temp->next;
			free(temp2);
		}
		free(*head);
		*head = NULL;
	}
}
