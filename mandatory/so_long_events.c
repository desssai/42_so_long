/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:55:07 by ncarob            #+#    #+#             */
/*   Updated: 2022/02/02 02:13:35 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_move_player_part2(t_mlx *mlx, int delta_x, int delta_y)
{
	static const char	*direction;

	if (!direction)
		direction = NO;
	else if (delta_x == 48)
		direction = RIGHT;
	else if (delta_x == -48)
		direction = LEFT;
	mlx->map->content[(mlx->map->player->ypos) / 48 * mlx->map->width
		+ (mlx->map->player->xpos) / 48] = '0';
	mlx->map->content[(mlx->map->player->ypos + delta_y) / 48 * mlx->map->width
		+ (mlx->map->player->xpos + delta_x) / 48] = 'P';
	ft_gen_grass(mlx, mlx->map->player->xpos, mlx->map->player->ypos);
	mlx->map->player->xpos += delta_x;
	mlx->map->player->ypos += delta_y;
	ft_gen_player(mlx, mlx->map->player->xpos,
		mlx->map->player->ypos, direction);
}

void	ft_move_player(t_mlx *mlx, int delta_x, int delta_y)
{
	static int	counter;

	if (mlx->map->content[(mlx->map->player->ypos + delta_y) / 48
			* mlx->map->width + (mlx->map->player->xpos + delta_x) / 48] == '1')
		return ;
	else if (mlx->map->content[(mlx->map->player->ypos + delta_y) / 48
			* mlx->map->width + (mlx->map->player->xpos + delta_x) / 48] == 'C')
		mlx->map->char_c--;
	else if (mlx->map->content[(mlx->map->player->ypos + delta_y) / 48
			* mlx->map->width + (mlx->map->player->xpos + delta_x) / 48] == 'E')
	{
		if (mlx->map->char_c)
			return ;
		exit(0);
	}
	counter += 1;
	ft_putstr_fd(MOVE_TEXT, 1);
	ft_putnbr_fd(counter, 1);
	ft_putchar_fd('\n', 1);
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
