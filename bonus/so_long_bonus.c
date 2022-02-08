/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 00:04:14 by ncarob            #+#    #+#             */
/*   Updated: 2022/02/03 17:23:27 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	so_long(char *filename)
{
	t_map	*map;
	t_mlx	*mlx;

	map = ft_get_map(filename);
	if (!map || map->error)
	{
		ft_terminate(map);
		return ;
	}
	mlx = ft_init_mlx(map);
	map->enemies = ft_init_enemies(map);
	ft_generate_map(map, mlx);
	mlx_hook(mlx->wnd_ptr, X_EVENT_KEY_PRESS, 0, &ft_key_hook, mlx);
	mlx_hook(mlx->wnd_ptr, X_EVENT_KEY_EXIT, 0, &ft_exit, NULL);
	mlx_loop_hook(mlx->mlx_ptr, &ft_hook, mlx);
	mlx_loop(mlx->mlx_ptr);
	mlx_clear_window(mlx->mlx_ptr, mlx->wnd_ptr);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		so_long(argv[1]);
	else
		return (ft_terminate(NULL));
	return (0);
}
