/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 00:20:45 by ncarob            #+#    #+#             */
/*   Updated: 2022/02/03 17:28:56 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

# define NO "NO"
# define EX "EXIT"
# define LEFT "LEFT"
# define RIGHT "RIGHT"

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

# define X_EVENT_KEY_EXIT 17
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_MOUSE_PRESS 4

# define E_PATH "./textures/exit.xpm"
# define G_PATH "./textures/grass.xpm"
# define W1_PATH "./textures/wall1.xpm"
# define W2_PATH "./textures/wall2.xpm"
# define PR1_PATH "./textures/PR_1.xpm"
# define PR2_PATH "./textures/PR_2.xpm"
# define PL1_PATH "./textures/PL_1.xpm"
# define PL2_PATH "./textures/PL_2.xpm"
# define C1_PATH "./textures/collectible1.xpm"
# define C2_PATH "./textures/collectible2.xpm"

# define WIN_TEXT "\033[92mYou have won.\033[0m"
# define MOVE_TEXT "\033[93mCurrent move: \033[0m"
# define LOSE_TEXT "\033[91mYou have lost.\033[0m"
# define ESC_TEXT "\033[92mClosing the game.\033[0m"
# define ERR_TEXT "Error"

typedef struct s_player {
	int	xpos;
	int	ypos;
}	t_player;

typedef struct s_map {
	int			game_over;
	char		*content;
	int			error;
	int			width;
	int			lines;
	int			char_1;
	int			char_0;
	int			char_p;
	int			char_e;
	int			char_c;
	t_player	*player;
}	t_map;

typedef struct s_mlx {
	void	*img_e;
	void	*img_0;
	void	*img_1_1;
	void	*img_1_2;
	void	*img_c_1;
	void	*img_c_2;
	void	*img_pl_1;
	void	*img_pl_2;
	void	*img_pr_1;
	void	*img_pr_2;
	void	*wnd_ptr;
	void	*mlx_ptr;
	t_map	*map;
}	t_mlx;

int			ft_exit(void);
int			ft_terminate(t_map *map);
int			ft_random_int(int probability);

int			ft_key_hook(int keycode, t_mlx *mlx);

t_mlx		*ft_init_mlx(t_map *map);
t_map		*ft_init_map(int fd);
t_player	*ft_init_player(int x, int y);

t_map		*ft_get_map(char *filename);
int			ft_map_validation(int fd, t_map *map);
void		ft_generate_map(t_map *map, t_mlx *mlx);

void		ft_gen_exit(t_mlx *mlx, int x, int y);
void		ft_gen_wall(t_mlx *mlx, int x, int y);
void		ft_gen_grass(t_mlx *mlx, int x, int y);
void		ft_gen_collectible(t_mlx *mlx, int x, int y);
void		ft_gen_player(t_mlx *mlx, int x, int y, const char *direction);

#endif /* SO_LONG_H */