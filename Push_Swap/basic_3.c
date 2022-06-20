/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:57:07 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/06/02 15:05:33 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++ != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char *s)
{
	int	i;
	int	fd;

	i = 0;
	fd = 0;
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	print_node(t_stack *node_a)
{
	t_stack	*tmp;

	tmp = node_a;
	while (tmp)
	{
		ft_putchar_fd('\n');
		tmp = tmp->next;
	}
	ft_putstr_fd("----------------------------\n");
}

int	sorted(t_stack *a)
{
	t_stack	*tmp;

	if (!a)
		return (0);
	tmp = a;
	while (tmp->next)
	{
		if (tmp->content >= tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
