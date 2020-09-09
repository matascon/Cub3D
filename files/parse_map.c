/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:26:52 by matascon          #+#    #+#             */
/*   Updated: 2020/09/09 17:05:28 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_map(t_env *env, char *ptr_file)
{
	int	x;
	int	y;

	while (*ptr_file && *ptr_file != '\n')
	{
		if (!ft_isspace(*ptr_file))
			ft_exit(env, ERROR_4);
		ptr_file++;
	}
	ptr_file++;
	ft_find_dimensions(ptr_file, &x, &y);
	ft_book_and_save_dimensions(env, x, y);
	ft_fill_map(env, x, y);
	ft_overwrite_map(env, ptr_file, y);
	ft_check_errors_map(env);
}
