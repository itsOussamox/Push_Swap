/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:48:07 by obouadel          #+#    #+#             */
/*   Updated: 2021/11/16 18:54:09 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

char	*ft_line(char **line, char **s_text)
{
	char	*forfree;
	int		tillnl;

	tillnl = 0;
	forfree = *s_text;
	while ((*s_text)[tillnl] != '\n' && (*s_text)[tillnl] != '\0')
		tillnl++;
	if (ft_strchr(*s_text, '\n'))
	{
		*line = ft_substr(*s_text, 0, tillnl + 1);
		*s_text = ft_strdup(*s_text + tillnl + 1);
	}
	else
	{
		*line = ft_strdup(forfree);
		*s_text = NULL;
	}
	ft_free(forfree);
	return (*line);
}

int	ft_fileread(int fd, char **buffer, char **s_text, char **line)
{
	int		bytes;
	char	*forfree;

	bytes = 1;
	while (!ft_strchr(*s_text, '\n') && bytes)
	{
		bytes = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[bytes] = '\0';
		forfree = *s_text;
		*s_text = ft_strjoin(*s_text, *buffer);
		ft_free(forfree);
	}
	ft_free(*buffer);
	ft_line(line, s_text);
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	*s_text = NULL;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!s_text)
		s_text = ft_strdup("");
	if (ft_fileread(fd, &buffer, &s_text, &line) == 0 && !*line)
	{
		ft_free(line);
		return (NULL);
	}
	return (line);
}
