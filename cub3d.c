/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matascon <matascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:25:51 by matascon          #+#    #+#             */
/*   Updated: 2020/09/08 16:59:27 by matascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Remember, errors are defined in cub3d.h
*/

int	main(int argc, char **argv)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	env->mlx_ptr = NULL;
	env->win_ptr = NULL;
	if (argc == 2 || argc == 3)
	{
		ft_read_file(env, argv[1]);
		ft_parse_file(env);
		ft_init_missing_values(env);
		ft_app(env);
	}
	else if (argc > 3)
		ft_putendl_fd(ERROR_1, 1);
	else
		ft_putendl_fd(ERROR_0, 1);
	ft_exit(env, NULL);
	return (0);
}
