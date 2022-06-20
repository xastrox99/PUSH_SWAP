/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:58:06 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/06/02 15:06:40 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_exit(t_stack **a)
{
	ft_putstr_fd("error\n");
	clr_list(a);
	exit(0);
}

int	check_num(char *str)
{
	int	i;

	i = -1;
	if ((str[0] == '-' || str[0] == '+') && str[1])
		i++;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int	check_double(char *str)
{
	int		i;
	int		j;
	char	**numbers;

	i = 0;
	numbers = ft_split(str);
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (numcompare(ft_atoi(numbers[i]), ft_atoi(numbers[j])) == 0)
				return (0);
			else if (ft_atoi(numbers[i]) > MAXINT)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	check_in(int ac, char **av, t_stack **a)
{
	int		i;
	char	**str;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (++i < ac)
	{
		str = ft_split(av[i]);
		tmp = ft_strjoin(tmp, *str);
		tmp = ft_strjoin(tmp, " ");
		if (!*str)
			ft_exit(a);
		while (*str)
		{
			if (!check_num(*str) || !check_double(tmp))
				ft_exit(a);
			else
			{
				ft_lstadd_back(a, ft_lstnew(ft_atoi(*str)));
			}
			str++;
		}
	}
}
