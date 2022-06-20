/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:54:24 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/06/02 15:06:06 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_putchar_fd(char c)
{
	int	fd;

	fd = 0;
	write(fd, &c, 1);
}

void	ft_lstadd_front(t_stack **alst, t_stack *new)
{
	new->next = *alst;
	*alst = new;
}

t_stack	*ft_lstlast(t_stack	*lst)
{
	t_stack	*ptr;

	ptr = lst;
	if (!ptr)
		return (NULL);
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	return (ptr);
}

size_t	ft_atoi(const char *str)
{
	int		i;
	size_t	res;
	int		sign;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\v' || str[i] == '\r' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		res = res * 10 + (str[i++] - '0');
	if (res > 2147483647)
		return (-1);
	return ((int)(res * sign));
}

void	ft_putnbr_fd(int nb)
{
	int	fd;

	fd = 0;
	if (nb == -2147483648)
	{
		ft_putchar_fd('-');
		ft_putchar_fd('2');
		ft_putnbr_fd(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar_fd('-');
		ft_putnbr_fd(nb * -1);
	}
	else if (nb > 9)
	{
		ft_putnbr_fd(nb / 10);
		ft_putnbr_fd(nb % 10);
	}
	else if (nb >= 0 && nb <= 9)
		ft_putchar_fd(nb + '0');
}
