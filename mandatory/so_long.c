/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 00:04:14 by ncarob            #+#    #+#             */
/*   Updated: 2022/02/02 02:30:03 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_map	*ft_init_map(int fd)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->content = NULL;
	map->player = NULL;
	map->char_0 = 0;
	map->char_1 = 0;
	map->char_p = 0;
	map->char_e = 0;
	map->char_c = 0;
	map->width = 0;
	map->lines = 0;
	map->error = 0 + ft_map_validation(fd, map);
	return (map);
}

t_player	*ft_init_player(int x, int y)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->xpos = x;
	player->ypos = y;
	return (player);
}

t_mlx	*ft_mlx_init(t_map *map)
{
	t_mlx	*mlx;
	int		x;
	int		y;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->mlx_ptr = mlx_init();
	mlx->wnd_ptr = mlx_new_window(mlx->mlx_ptr, map->width * 48,
			map->lines * 48, "so_long");
	mlx->img_e = mlx_xpm_file_to_image(mlx->mlx_ptr, E_PATH, &x, &y);
	mlx->img_0 = mlx_xpm_file_to_image(mlx->mlx_ptr, G_PATH, &x, &y);
	mlx->img_1_1 = mlx_xpm_file_to_image(mlx->mlx_ptr, W1_PATH, &x, &y);
	mlx->img_1_2 = mlx_xpm_file_to_image(mlx->mlx_ptr, W2_PATH, &x, &y);
	mlx->img_c_1 = mlx_xpm_file_to_image(mlx->mlx_ptr, C1_PATH, &x, &y);
	mlx->img_c_2 = mlx_xpm_file_to_image(mlx->mlx_ptr, C2_PATH, &x, &y);
	mlx->img_pl_1 = mlx_xpm_file_to_image(mlx->mlx_ptr, PL1_PATH, &x, &y);
	mlx->img_pl_2 = mlx_xpm_file_to_image(mlx->mlx_ptr, PL2_PATH, &x, &y);
	mlx->img_pr_1 = mlx_xpm_file_to_image(mlx->mlx_ptr, PR1_PATH, &x, &y);
	mlx->img_pr_2 = mlx_xpm_file_to_image(mlx->mlx_ptr, PR2_PATH, &x, &y);
	mlx->map = map;
	return (mlx);
}

int	so_long(char *filename)
{
	t_map	*map;
	t_mlx	*mlx;

	map = get_map(filename);
	if (!map)
		return (ft_terminate(NULL));
	mlx = ft_mlx_init(map);
	ft_generate_map(map, mlx);
	mlx_hook(mlx->wnd_ptr, X_EVENT_KEY_PRESS, 0, &ft_key_hook, mlx);
	mlx_hook(mlx->wnd_ptr, X_EVENT_KEY_EXIT, 0, &ft_exit, NULL);
	mlx_loop(mlx->mlx_ptr);
	mlx_clear_window(mlx->mlx_ptr, mlx->wnd_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		so_long(argv[1]);
	else
		return (ft_terminate(NULL));
	return (0);
}
