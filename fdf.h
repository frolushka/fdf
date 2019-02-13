/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 07:57:07 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/09 11:38:09 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "ll3d.h"
# include <stdlib.h>
# include <unistd.h>

# define SCREEN_NAME "fdf"

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_Q		12
# define KEY_E		14
# define KEY_F		3
# define KEY_R		15
# define KEY_T		17
# define KEY_ESC	53
# define KEY_ARROWL	123
# define KEY_ARROWR	124
# define KEY_ARROWD	125
# define KEY_ARROWU	126
# define KEY_1		83
# define KEY_2		84
# define KEY_3		85
# define KEY_4		86
# define KEY_5		87
# define KEY_6		88
# define KEY_7		89
# define KEY_8		91

typedef struct		s_mouse
{
	int				x;
	int				y;
	t_mlx			*mlx;
	t_cam			*cam;
	t_dots			*dots;
}					t_mouse;

int			read_dots(char *fn, t_dots **res);
void		solve_dots(t_dots *dots, const t_cam *cam);
int			print_dots(t_dots *res);

void		fill_screen(t_dots **d);
void		connect_dots(const t_mlx *c, t_dots **d);
void		redraw(const t_mlx *c, t_dots *dots, const t_cam *cam);
int			hook_mouse_move(int x, int y, t_mouse *mouse);
int			hook_key(const int key, t_mouse *mouse);
int			hook_wheel(int key, int x, int y, t_mouse *m);

// old reader

int			check_line_valid(char **line);
int			fill_dots(char *fn, t_dots **res);
int			get_size(char *fn, t_vec2 **res);
int			print_dots(t_dots *res);
int			read_dots(char *fn, t_dots **res);

int			get_color(char const *it);
int			free_all(char **line, char ***tmp, int fd);

int	hook_rot_debug(int key, t_mouse *mouse);
t_mouse	*mouse_init(t_mlx *mlx, t_cam *cam, t_dots *dots);

void	hook_camera_move_x(t_cam *cam, float const a);
void	hook_camera_move_y(t_cam *cam, float const a);
void	hook_camera_move_z(t_cam *cam, float const a);

void	hook_camera_change_speed(t_cam *cam, float const a);
void	hook_camera_change_sence(t_cam *cam, float const a);
void	hook_camera_change_focus(t_cam *cam, float const a);

void	dots_connect(t_dots *dots, const t_mlx *c);
void	dots_solve(t_dots *dots, const t_cam *cam);

void	hook_camera_rotate_x(t_cam *cam, float const a);
void	hook_camera_rotate_y(t_cam *cam, float const a);

#endif
