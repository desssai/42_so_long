/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_enemies_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 23:38:55 by ncarob            #+#    #+#             */
/*   Updated: 2022/02/03 17:23:30 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

t_enemy	**ft_init_enemies(t_map *map)
{
	int		i;
	t_enemy	**enemies;

	enemies = (t_enemy **)malloc(sizeof(t_enemy *) * (map->total_enemies + 1));
	if (!enemies)
		return (NULL);
	i = -1;
	enemies[map->total_enemies] = NULL;
	while (map->content[++i] != '\n' && map->content[i]
		&& map->total_enemies >= 0)
	{
		if (map->content[i] == '0')
		{
			if (map->total_enemies && ft_random_int(90))
			{
				enemies[map->total_enemies - 1] = ft_init_enemy(map, i);
				map->content[i] = 'N';
				map->total_enemies--;
			}
		}
		if (map->total_enemies >= 0 && !map->content[i])
			i = -1;
	}
	map->total_enemies = map->char_0 / 40;
	return (enemies);
}

static int	ft_check_for_player(t_mlx *mlx, t_enemy *enemy)
{
	if (mlx->map->content[(enemy->ypos - 1)
			* mlx->map->width + enemy->xpos] == 'P')
		return (0);
	else if (mlx->map->content[(enemy->ypos + 1)
			* mlx->map->width + enemy->xpos] == 'P')
		return (1);
	else if (mlx->map->content[enemy->ypos
			* mlx->map->width + enemy->xpos - 1] == 'P')
		return (2);
	else if (mlx->map->content[enemy->ypos
			* mlx->map->width + enemy->xpos + 1] == 'P')
		return (3);
	return (-1);
}

static int	ft_get_random_direction(t_mlx *mlx, t_enemy *enemy)
{
	int		r_move;
	int		empty;

	empty = 0;
	while (!empty)
	{
		r_move = rand() % 4;
		if (r_move == 0 && mlx->map->content[(enemy->ypos - 1)
				* mlx->map->width + enemy->xpos] == '0')
			empty = 1;
		else if (r_move == 1 && mlx->map->content[(enemy->ypos + 1)
				* mlx->map->width + enemy->xpos] == '0')
			empty = 1;
		else if (r_move == 2 && mlx->map->content[enemy->ypos
				* mlx->map->width + enemy->xpos - 1] == '0')
			empty = 1;
		else if (r_move == 3 && mlx->map->content[enemy->ypos
				* mlx->map->width + enemy->xpos + 1] == '0')
			empty = 1;
	}
	return (r_move);
}

void	ft_move_enemy(t_mlx *mlx, t_enemy *enemy)
{
	int	r_move;

	r_move = ft_check_for_player(mlx, enemy);
	if (r_move == -1)
		r_move = ft_get_random_direction(mlx, enemy);
	mlx->map->content[enemy->ypos * mlx->map->width + enemy->xpos] = '0';
	ft_gen_grass(mlx, enemy->xpos * 48, enemy->ypos * 48);
	if (r_move == 0)
		enemy->ypos -= 1;
	else if (r_move == 1)
		enemy->ypos += 1;
	else if (r_move == 2)
		enemy->xpos -= 1;
	else if (r_move == 3)
		enemy->xpos += 1;
	mlx->map->content[enemy->ypos * mlx->map->width + enemy->xpos] = 'N';
	if (!ft_strchr(mlx->map->content, 'P'))
	{
		mlx->map->game_over = 1;
		mlx_clear_window(mlx->mlx_ptr, mlx->wnd_ptr);
		mlx_string_put(mlx->mlx_ptr, mlx->wnd_ptr, mlx->map->width * 24 - 28,
			mlx->map->lines * 24 + 2, 0xFFFF0000, "YOU SUCK!");
	}
	else
		ft_gen_enemy(mlx, enemy->xpos * 48, enemy->ypos * 48);
}
