/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:07:20 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/05/28 18:39:27 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ptr1;
	char	*ptr2;

	i = -1;
	if (!dest && !src)
		return (NULL);
	ptr1 = (char *)dest;
	ptr2 = (char *)src;
	while (++i < n)
		ptr1[i] = ptr2[i];
	return (dest);
}

static int	words_calculator(const char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] == '\0')
			return (len);
		len++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (len);
}

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_alloc(char **ptr, const char *s, char c, int i)
{
	ptr[i] = (char *)malloc((word_len(s, c) + 1) * sizeof(char));
	if (!ptr[i])
	{
		free(ptr);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s)
{
	int		i;
	int		x;
	char	c;
	char	**ptr;

	c = ' ';
	x = words_calculator(s, c);
	ptr = (char **)malloc((x + 1) * sizeof(char *));
	if (!ptr || s == NULL)
		return (NULL);
	i = -1;
	while (++i < x && *s)
	{
		while (*s && ((*s == c) || (*s == ' ')))
			s++;
		if (*s == '\0')
			break ;
		if (!ft_alloc(ptr, s, c, i))
			return (NULL);
		ft_memcpy(ptr[i], s, word_len(s, c));
		ptr[i][word_len(s, c)] = '\0';
		s = s + word_len(s, c);
	}
	ptr[i] = NULL;
	return (ptr);
}
