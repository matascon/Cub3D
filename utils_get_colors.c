/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:27:01 by matascon          #+#    #+#             */
/*   Updated: 2020/09/07 17:27:01 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_errors_color(t_env *env, int type, int type_error)
{
	if (!type_error)
	{
		if (type == F)
			ft_exit(env, ERROR_10);
		else
			ft_exit(env, ERROR_11);
	}
	else
	{
		if (type_error == 1)
			ft_exit(env, ERROR_12);
		else
			ft_exit(env, ERROR_6);
	}
}

static void	assign_color(t_env *env, int color, int i, int type)
{
	if (!i)
		color = color * pow(2, 16);
	else if (i == 1)
		color = color * pow(2, 8);
	else
		color = color * pow(2, 0);
	if (type == F)
		env->rc.color.floor += color;
	else
		env->rc.color.roof += color;
}

static char	*pop_color(t_env *env, int *color, char *ptr, int type)
{
	*color = ft_atoi(ptr);
	while ((*ptr >= '0' && *ptr <= '9') || \
	*ptr == '-' || *ptr == '+')
		ptr++;
	if (*color < 0 || *color > 255)
		check_errors_color(env, type, 1);
	if (!(*ptr))
		check_errors_color(env, type, 2);
	return (ptr);
}

char		*ft_aux_colors(t_env *env, char *ptr, int type)
{
	int	i;
	int	rgb[3];

	i = 0;
	while (*ptr && i < 3)
	{
		if (ft_isspace(*ptr))
			ptr++;
		else if (!(*ptr >= '0' && *ptr <= '9') && \
		*ptr != '-' && *ptr != '+')
			check_errors_color(env, type, 0);
		else
		{
			ptr = pop_color(env, &rgb[i], ptr, type);
			assign_color(env, rgb[i], i, type);
			i++;
			while (ft_isspace(*ptr) && i < 3)
				ptr++;
			if (*ptr != ',' && i < 3)
				check_errors_color(env, type, 0);
			else if (*ptr == ',' && i < 3)
				ptr++;
		}
	}
	return (ptr);
}
