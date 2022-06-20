/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:46:18 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/05/30 13:14:11 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	check_rest(char *msg, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(msg, "rr\n"))
	{
		rotate_a(a, 0);
		rotate_b(b, 0);
	}
	else if (!ft_strncmp(msg, "rrr\n"))
	{
		reverse_rotate_a(a, 0);
		reverse_rotate_b(b, 0);
	}
	else if (!ft_strncmp(msg, "ss\n"))
	{
		swap_b(b);
		swap_a(a);
	}
	else
		ft_exit(0);
}

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	check_function(char *msg, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(msg, "ra\n"))
		rotate_a(a, 0);
	else if (!ft_strncmp(msg, "rb\n"))
		rotate_b(b, 0);
	else if (!ft_strncmp(msg, "sa\n"))
		swap_a(a);
	else if (!ft_strncmp(msg, "sb\n"))
		swap_b(b);
	else if (!ft_strncmp(msg, "rra\n"))
		reverse_rotate_a(a, 0);
	else if (!ft_strncmp(msg, "rrb\n"))
		reverse_rotate_b(b, 0);
	else if (!ft_strncmp(msg, "pa\n"))
		push_a(a, b);
	else if (!ft_strncmp(msg, "pb\n"))
		push_b(a, b);
	else
		check_rest(msg, a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*str;

	if (ac == 1)
		return (0);
	check_in(ac, av, &a);
	str = get_next_line(0);
	while (str)
	{
		check_function(str, &a, &b);
		str = get_next_line(0);
	}
	if (sorted(a))
		ft_putstr_fd("ok\n");
	else
		ft_putstr_fd("ko\n");
}
