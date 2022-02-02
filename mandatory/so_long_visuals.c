/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_visuals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 05:10:12 by ncarob            #+#    #+#             */
/*   Updated: 2022/02/02 02:30:20 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_gen_grass(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->wnd_ptr, mlx->img_0, x, y);
}

void	ft_gen_exit(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->wnd_ptr, mlx->img_e, x, y);
}

void	ft_gen_wall(t_mlx *mlx, int x, int y)
{
	if (ft_random_int(25))
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->wnd_ptr, mlx->img_1_1, x, y);
	else
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->wnd_ptr, mlx->img_1_2, x, y);
}

void	ft_gen_collectible(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->wnd_ptr, mlx->img_0, x, y);
	if (ft_random_int(25))
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->wnd_ptr, mlx->img_c_1, x, y);
	else
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->wnd_ptr, mlx->img_c_2, x, y);
}

void	ft_gen_player(t_mlx *mlx, int x, int y, const char *direction)
{
	static const char	*local_direction;

	if (ft_strncmp(direction, NO, 2))
		local_direction = direction;
	ft_gen_grass(mlx, x, y);
	if (!ft_strncmp(local_direction, LEFT, 4))
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->wnd_ptr,
			mlx->img_pl_1, x, y);
	else if (!ft_strncmp(local_direction, RIGHT, 5))
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->wnd_ptr,
			mlx->img_pr_1, x, y);
}
