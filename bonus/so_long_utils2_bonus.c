/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 00:13:16 by ncarob            #+#    #+#             */
/*   Updated: 2022/02/03 17:23:42 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_exit(void)
{
	ft_putendl_fd(ESC_TEXT, 1);
	exit(0);
}

int	ft_random_int(int probability)
{
	static int	res;
	char		*str;

	res += 1234;
	res *= res;
	str = ft_itoa(res);
	str[6] = 0;
	res = ft_atoi(str + 2);
	free(str);
	if (res >= probability * 100)
		return (1);
	else
		return (0);
}

int	ft_terminate(t_map *map)
{
	if (map)
	{
		if (map->player)
			free(map->player);
		if (map->content)
			free(map->content);
		free(map);
	}
	ft_putendl_fd(ERR_TEXT, 2);
	return (1);
}
