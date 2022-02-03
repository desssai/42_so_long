/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_visuals_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 05:10:12 by ncarob            #+#    #+#             */
/*   Updated: 2022/02/02 23:35:02 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
	ft_gen_grass(mlx, x, y);
	if (ft_random_int(25))
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->wnd_ptr, mlx->img_c_1, x, y);
	else
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->wnd_ptr, mlx->img_c_2, x, y);
}

void	ft_gen_enemy(t_mlx *mlx, int x, int y)
{
	ft_gen_grass(mlx, x, y);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->wnd_ptr, mlx->img_nm, x, y);
}
