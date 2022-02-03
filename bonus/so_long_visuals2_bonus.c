/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_visuals2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:31:08 by ncarob            #+#    #+#             */
/*   Updated: 2022/02/02 23:34:55 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	ft_gen_player2(t_mlx *mlx, const char *direction, int frame)
{
	int	x;
	int	y;

	x = mlx->map->player->xpos;
	y = mlx->map->player->ypos;
	if (frame < 20)
	{
		if (!ft_strncmp(LEFT, direction, 4))
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->wnd_ptr,
				mlx->img_pl_2, x, y);
		else if (!ft_strncmp(RIGHT, direction, 5))
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->wnd_ptr,
				mlx->img_pr_2, x, y);
	}
	else if (frame < 40)
	{
		if (!ft_strncmp(LEFT, direction, 4))
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->wnd_ptr,
				mlx->img_pl_1, x, y);
		else if (!ft_strncmp(RIGHT, direction, 5))
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->wnd_ptr,
				mlx->img_pr_1, x, y);
	}
}

void	ft_gen_player(t_mlx *mlx, int x, int y, const char *direction)
{
	static const char	*local_direction;
	char				*string;
	static int			frame;

	string = ft_itoa(mlx->map->player->move);
	if (ft_strncmp(direction, NO, 2))
		local_direction = direction;
	ft_gen_grass(mlx, x, y);
	if (frame < 20)
	{
		ft_gen_player2(mlx, local_direction, frame);
		frame++;
	}
	else if (frame < 40)
	{
		ft_gen_player2(mlx, local_direction, frame);
		frame++;
	}
	mlx_string_put(mlx->mlx_ptr, mlx->wnd_ptr, x, y + 9, Y_COLOR, string);
	free(string);
	if (frame == 40)
		frame = 0;
}
