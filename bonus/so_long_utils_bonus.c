/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 04:27:10 by ncarob            #+#    #+#             */
/*   Updated: 2022/02/03 17:23:39 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

t_map	*ft_init_map(int fd)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->content = NULL;
	map->enemies = NULL;
	map->player = NULL;
	map->game_over = 0;
	map->char_0 = 0;
	map->char_1 = 0;
	map->char_p = 0;
	map->char_e = 0;
	map->char_c = 0;
	map->width = 0;
	map->lines = 0;
	map->error = 0 + ft_map_validation(fd, map);
	map->total_enemies = map->char_0 / 40;
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
	player->move = 0;
	return (player);
}

t_mlx	*ft_init_mlx(t_map *map)
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
	mlx->img_nm = mlx_xpm_file_to_image(mlx->mlx_ptr, NM_PATH, &x, &y);
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

t_enemy	*ft_init_enemy(t_map *map, int pos)
{
	t_enemy	*enemy;

	enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (!enemy)
		return (NULL);
	enemy->xpos = pos % map->width;
	enemy->ypos = pos / map->width;
	return (enemy);
}

void	ft_clear_enemies(t_enemy **enemies, int total_enemies)
{
	while (total_enemies >= 0)
		free(enemies[total_enemies-- - 1]);
	free(enemies);
}
