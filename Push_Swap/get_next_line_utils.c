/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:40:47 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/05/29 16:58:51 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

char	*ft_strdup(char *s1)
{
	char	*pt;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	pt = (char *)malloc(sizeof(char) * i + 1);
	if (pt == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		pt[i] = s1[i];
		i++;
	}
	pt[i] = '\0';
	return (pt);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*pt;

	i = 0;
	j = (size_t)start;
	if (!s)
		return (NULL);
	while (s[j] != '\0')
		j++;
	if (start > ft_strlen(s))
		pt = malloc(sizeof(char));
	else if (j < len)
		pt = malloc(sizeof(char) * j + 1);
	else
		pt = malloc(sizeof(char) * len + 1);
	if (!pt)
		return (NULL);
	while (s[start] != '\0' && i < len && start < j)
		pt[i++] = s[start++];
	pt[i] = '\0';
	return (pt);
}

int	ft_strchr( char *s, int c)
{
	int		j;
	char	cs;

	j = 0;
	cs = (char )c;
	while (s[j])
	{
		if (s[j] == cs)
			return (j);
		j++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*pt;
	char	*ss1;
	char	*ss2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ss1 = s1;
	ss2 = s2;
	if (!ss1 && ss2)
		return (ft_strdup(ss2));
	pt = malloc(sizeof(char ) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (pt == NULL)
		return (NULL);
	while (ss1[i])
	{
		pt[i] = ss1[i];
		i++;
	}
	while (ss2[j])
		pt[i++] = ss2[j++];
	pt[i] = '\0';
	free(s1);
	return (pt);
}
