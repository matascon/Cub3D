/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 16:56:51 by matascon          #+#    #+#             */
/*   Updated: 2020/09/09 17:09:21 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	write_bmp(t_env *env)
{
	int				i;
	int				j;
	int				color;
	unsigned char	zero[3];

	ft_bzero(zero, 3);
	i = env->height_screen - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < env->width_screen)
		{
			color = env->get_data[i * env->width_screen + j];
			write(env->bmp.fd, &color, 3);
			j++;
		}
		if (env->bmp.padding > 0)
			write(env->bmp.fd, &zero, env->bmp.padding);
		i--;
	}
}

static void	write_headers(t_env *env)
{
	env->bmp.file_header[0] = (unsigned char)('B');
	env->bmp.file_header[1] = (unsigned char)('M');
	env->bmp.file_header[2] = (unsigned char)(env->bmp.size_file);
	env->bmp.file_header[3] = (unsigned char)(env->bmp.size_file >> 8);
	env->bmp.file_header[4] = (unsigned char)(env->bmp.size_file >> 16);
	env->bmp.file_header[5] = (unsigned char)(env->bmp.size_file >> 24);
	env->bmp.file_header[10] = (unsigned char)(14 + 40);
	env->bmp.info_header[0] = (unsigned char)(40);
	env->bmp.info_header[4] = (unsigned char)(env->width_screen);
	env->bmp.info_header[5] = (unsigned char)(env->width_screen >> 8);
	env->bmp.info_header[6] = (unsigned char)(env->width_screen >> 16);
	env->bmp.info_header[7] = (unsigned char)(env->width_screen >> 24);
	env->bmp.info_header[8] = (unsigned char)(env->height_screen);
	env->bmp.info_header[9] = (unsigned char)(env->height_screen >> 8);
	env->bmp.info_header[10] = (unsigned char)(env->height_screen >> 16);
	env->bmp.info_header[11] = (unsigned char)(env->height_screen >> 24);
	env->bmp.info_header[12] = (unsigned char)(1);
	env->bmp.info_header[14] = (unsigned char)(24);
}

static void	create_header(t_env *env)
{
	ft_bzero(env->bmp.file_header, 14);
	ft_bzero(env->bmp.info_header, 40);
	env->bmp.size_file = 14 + 40 + (3 * env->width_screen + \
	env->bmp.padding) * env->height_screen;
	write_headers(env);
	write(env->bmp.fd, &env->bmp.file_header, 14);
	write(env->bmp.fd, &env->bmp.info_header, 40);
}

void		ft_bmp(t_env *env)
{
	env->bmp.padding = env->width_screen % 4;
	if ((env->bmp.fd = open("Cub3D.bmp", O_WRONLY | O_TRUNC | \
	O_CREAT, 0777)) < 0)
		ft_exit(env, ERROR_15);
	create_header(env);
	write_bmp(env);
	close(env->bmp.fd);
	ft_exit(env, "¡PROGRAM EXECUTED SUCCESSFULLY!");
}
