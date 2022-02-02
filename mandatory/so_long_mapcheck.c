/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mapcheck.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 03:07:05 by ncarob            #+#    #+#             */
/*   Updated: 2022/02/02 02:41:14 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

static int	ft_parse_outer_line(char *line, t_map *map)
{
	int	i;

	i = -1;
	while (line[++i] != '\0' && line[i] != '\n')
		if (line[i] != '1')
			return (1);
	if (map->lines == 0)
		map->width = i;
	map->char_1 += i;
	return (0);
}

static int	ft_parse_inner_line(char *line, t_map *map)
{
	int	i;

	i = -1;
	if (line[0] != '1' || line[map->width - 1] != '1')
		return (1);
	while (line[++i] != '\0' && line[i] != '\n')
	{
		if (line[i] == '0')
			map->char_0++;
		else if (line[i] == '1')
			map->char_1++;
		else if (line[i] == 'C')
			map->char_c++;
		else if (line[i] == 'E')
			map->char_e++;
		else if (line[i] == 'P')
			map->char_p++;
		else
			map->char_e++;
		if (map->char_p && !map->player)
			map->player = ft_init_player(i % map->width * 48, map->lines * 48);
	}
	return (0);
}

int	ft_map_validation(int fd, t_map *map)
{
	int			error;
	char		*line;
	char		*next_line;

	error = 0;
	line = get_next_line(fd);
	while (line)
	{
		next_line = get_next_line(fd);
		if (!map->lines || !next_line)
			error += ft_parse_outer_line(line, map);
		else
			error += ft_parse_inner_line(line, map);
		line[map->width] = 0;
		map->content = add_buffer(map->content, line);
		free(line);
		line = next_line;
		map->lines++;
	}
	if ((map->char_0 + map->char_1 + map->char_c + map->char_e + map->char_p
			!= map->lines * map->width) || map->char_e != 1
		|| map->char_p != 1 || map->char_c < 1 || error)
		return (1);
	return (0);
}

void	ft_generate_map(t_map *map, t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x * y < map->lines * map->width * 48 * 48)
	{
		if (map->content[y / 48 * map->width + x / 48] == '1')
			ft_gen_wall(mlx, x, y);
		else if (map->content[y / 48 * map->width + x / 48] == '0')
			ft_gen_grass(mlx, x, y);
		else if (map->content[y / 48 * map->width + x / 48] == 'E')
			ft_gen_exit(mlx, x, y);
		else if (map->content[y / 48 * map->width + x / 48] == 'P')
			ft_gen_player(mlx, x, y, RIGHT);
		else if (map->content[y / 48 * map->width + x / 48] == 'C')
			ft_gen_collectible(mlx, x, y);
		x += 48;
		if (x / 48 == map->width)
		{
			y += 48;
			x = 0;
		}
	}
}

t_map	*get_map(char *filename)
{
	int		fd;
	t_map	*map;

	if (ft_strrchr(filename, '/') && ft_strchr(filename, '.') - ft_strrchr(filename, '/') > 1)
		return (NULL);
	if (ft_strlen(filename) < 5 || ft_strncmp(".ber", &filename[ft_strlen(filename) - 4], 4))
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = ft_init_map(fd);
	close(fd);
	return (map);
}
