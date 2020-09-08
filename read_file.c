/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:26:56 by matascon          #+#    #+#             */
/*   Updated: 2020/09/07 17:26:57 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	save_file(t_env *env, char *name_file)
{
	char	*line;
	int		fd;

	fd = open(name_file, O_RDONLY);
	if (fd == -1)
		ft_exit(env, ERROR_3);
	env->file.file = (char*)malloc(1);
	env->file.file[0] = '\0';
	while (ft_gnl(fd, &line))
	{
		line = ft_strsjoin(line, "\n", 1, 0);
		env->file.file = ft_strsjoin(env->file.file, line, 1, 1);
	}
	line = ft_strsjoin(line, "\n", 1, 0);
	env->file.file = ft_strsjoin(env->file.file, line, 1, 1);
	close(fd);
}

static int	check_extension(char *name_file)
{
	char	*ptr;

	ptr = ft_strnstr(name_file, ".cub", ft_strlen(name_file));
	if (!ptr)
		return (0);
	/*
	** ¡WATCH OUT ON THIS PART, IT COULD GIVE YOU PROBLEMS IN FUTURE
	*/
	ptr = ptr + 4;
	if (*ptr != '\0')
		return (0);
	return (1);
}

void		ft_read_file(t_env *env, char *name_file)
{
	if (!check_extension(name_file))
		ft_exit(env, ERROR_2);
	save_file(env, name_file);
}
