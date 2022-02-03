/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_events_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:55:07 by ncarob            #+#    #+#             */
/*   Updated: 2022/02/03 02:59:50 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	ft_move_enemies(t_mlx *mlx)
{
	int	cp_total_enemies;

	cp_total_enemies = mlx->map->total_enemies;
	while (cp_total_enemies--)
		ft_move_enemy(mlx, mlx->map->enemies[cp_total_enemies]);
}

static void	ft_move_player_part2(t_mlx *mlx, int delta_x, int delta_y)
{
	static const char	*direction;

	if (delta_x == 48)
		direction = RIGHT;
	else if (delta_x == -48)
		direction = LEFT;
	if (!direction)
		direction = RIGHT;
	mlx->map->content[(mlx->map->player->ypos) / 48 * mlx->map->width
		+ (mlx->map->player->xpos) / 48] = '0';
	mlx->map->content[(mlx->map->player->ypos + delta_y) / 48 * mlx->map->width
		+ (mlx->map->player->xpos + delta_x) / 48] = 'P';
	ft_gen_grass(mlx, mlx->map->player->xpos, mlx->map->player->ypos);
	mlx->map->player->xpos += delta_x;
	mlx->map->player->ypos += delta_y;
	ft_gen_player(mlx, mlx->map->player->xpos, mlx->map->player->ypos,
		direction);
	ft_move_enemies(mlx);
}

static void	ft_move_player(t_mlx *mlx, int delta_x, int delta_y)
{
	if (mlx->map->content[(mlx->map->player->ypos + delta_y) / 48
			* mlx->map->width + (mlx->map->player->xpos + delta_x) / 48] == '1'
		|| mlx->map->game_over)
		return ;
	else if (mlx->map->content[(mlx->map->player->ypos + delta_y) / 48
			* mlx->map->width + (mlx->map->player->xpos + delta_x) / 48] == 'C')
		mlx->map->char_c--;
	else if (mlx->map->content[(mlx->map->player->ypos + delta_y) / 48
			* mlx->map->width + (mlx->map->player->xpos + delta_x) / 48] == 'E')
	{
		if (mlx->map->char_c)
			return ;
		mlx->map->game_over = 1;
		ft_putendl_fd(WIN_TEXT, 1);
		mlx_clear_window(mlx->mlx_ptr, mlx->wnd_ptr);
		mlx_string_put(mlx->mlx_ptr, mlx->wnd_ptr, mlx->map->width * 24 - 28,
			mlx->map->lines * 24 + 2, 0xFF00FF00, "YOU WON!");
	}
	mlx->map->player->move++;
	if (!mlx->map->game_over)
		ft_move_player_part2(mlx, delta_x, delta_y);
}

int	ft_key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		ft_exit();
	if (keycode == KEY_W || keycode == KEY_UP)
		ft_move_player(mlx, 0, -48);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		ft_move_player(mlx, -48, 0);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		ft_move_player(mlx, 0, 48);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		ft_move_player(mlx, 48, 0);
	return (0);
}

int	ft_hook(t_mlx *mlx)
{
	if (!mlx->map->game_over)
		ft_gen_player(mlx, mlx->map->player->xpos, mlx->map->player->ypos, NO);
	return (0);
}
