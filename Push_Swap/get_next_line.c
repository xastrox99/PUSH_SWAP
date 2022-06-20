/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:26:54 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/05/29 14:47:34 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

char	*get_final_line(char **data)
{
	char	*tmp;

	if (*data && **data != '\0')
	{
		tmp = *data;
		*data = NULL;
		return (tmp);
	}
	else
	{
		free(*data);
		*data = NULL;
		return (NULL);
	}
}

char	*get_line(char	**data)
{
	int		i;
	char	*line;
	char	*tmp;

	i = ft_strchr(*data, '\n');
	line = ft_substr(*data, 0, i + 1);
	tmp = *data;
	*data = ft_substr(*data, i + 1, ft_strlen(*data) - i);
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		buffer[BUFFER_SIZE + 1];
	int			k;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (data == NULL)
		data = ft_strdup("");
	while (ft_strchr(data, '\n') == -1)
	{
		k = read(fd, buffer, BUFFER_SIZE);
		if (k == 0)
			break ;
		if (k < 0)
		{
			free(data);
			data = NULL;
			return (NULL);
		}
		buffer[k] = '\0';
		data = ft_strjoin(data, buffer);
	}
	if (ft_strchr(data, '\n') == -1)
		return (get_final_line(&data));
	return (get_line(&data));
}
