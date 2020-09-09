/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 16:59:20 by matascon          #+#    #+#             */
/*   Updated: 2020/09/09 16:59:31 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_gnl(int fd, char **line)
{
	char	*buffer;
	int		n_bytes;

	if (!line || !(buffer = (char *)malloc(2)) \
	|| !(*line = (char *)malloc(1)))
		return (-1);
	(*line)[0] = '\0';
	while ((n_bytes = read(fd, buffer, 1)) > 0)
	{
		buffer[1] = '\0';
		if (buffer[0] == '\n')
			break ;
		*line = ft_strsjoin(*line, buffer, 1, 0);
	}
	free(buffer);
	return (n_bytes);
}
