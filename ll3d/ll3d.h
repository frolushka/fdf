/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll3d.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:56:09 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/13 22:06:56 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LL3D_H
# define LL3D_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define CAM_ISO	0
# define CAM_PER 	1

# define CAM_DSP	5
# define CAM_DSE	1
# define CAM_DFO	1

# define CAM_SP		0.1f
# define CAM_SE		1
# define CAM_FO		0.1f

# define SCREEN_X	1920
# define SCREEN_Y	1080

# define COLOR_WHITE	0xFFFFFF
# define COLOR_RED		0xFF0000
# define COLOR_GREEN	0x228B22
# define COLOR_BLUE		0x0000FF
# define COLOR_GRAY		0x555555
# define COLOR_LGRAY	0xAAAAAA
# define COLOR_BROWN	0x654321
# define COLOR_BLACK	0x000000

typedef struct		s_vec2
{
	int				x;
	int				y;
}					t_vec2;

typedef struct		s_vec3
{
	float			x;
	float			y;
	float			z;
}					t_vec3;

typedef struct		s_vec4
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vec4;

typedef struct		s_mtx4
{
	float			val[4][4];
}					t_mtx4;

typedef struct		s_image
{
	void			*image;
	char			*ptr;
	int				bpp;
	int				str;
	int				end;
	int				x;
	int				y;
}					t_image;

typedef struct		s_mlx
{
	int				width;
	int				height;
	t_image			*image;
	void			*mlx;
	void			*win;
}					t_mlx;

typedef struct		s_cam
{
	t_mtx4			*cam;
	t_vec3			*piv;
	int				mode;
	float			speed;
	float			ppu;
	float			sence;
	float			focus;
	struct s_cam	*add;
}					t_cam;

typedef struct		s_dots
{
	int				i;
	int				xc;
	int				yc;
	int				zmin;
	int				zmax;
	int				cm;
	t_vec4			**wb;
	t_vec3			**cb;
	t_vec2			**sb;
}					t_dots;

/*
** T_VEC2
*/

t_vec2				*vec2_init(void);
t_vec2				*vec2_new(int const x, int const y);
t_vec2				*vec2_sum(t_vec2 const *v1, t_vec2 const *v2);
t_vec2				*vec2_mult(t_vec2 const *v, int const s);
t_vec2				*vec2_copy(t_vec2 const *v);
void				vec2_print(t_vec2 const *v);
void				vec2_set(t_vec2 *v, const int x, const int y);

/*
** T_VEC3
*/

t_vec3				*vec3_init(void);
t_vec3				*vec3_new(float const x, float const y, float const z);
t_vec3				*vec3_sum(t_vec3 const *v1, t_vec3 const *v2);
t_vec3				*vec3_mult(t_vec3 const *v, float const s);
t_vec3				*vec3_copy(t_vec3 const *v);
void				vec3_print(t_vec3 const *v);
void				vec3_set(t_vec3 *v, const float x, const float y, const float z);

/*
** T_VEC4
*/

t_vec4				*vec4_init(void);
t_vec4				*vec4_new(float const x, float const y, float const z,
						float const w);
t_vec4				*vec4_sum(t_vec4 const *v1, t_vec4 const *v2);
t_vec4				*vec4_mult(t_vec4 const *v, float const s);
t_vec4				*vec4_copy(t_vec4 const *v);
void				vec4_print(t_vec4 const *v);
t_vec4				**dots4_cpy(const t_vec4 **src, const int xc, const int yc);

/*
** MATH
*/

int					ft_abs(int const x);
int					ft_sign(float const a);
float				ft_fabs(float const x);
void				ft_swap(int *a, int *b);
float				ft_fmin(const float a, const float b);
int					ft_min(const int a, const int b);
float				ft_fmax(const float a, const float b);
int					ft_max(const int a, const int b);
/*
** MTX4
*/

t_mtx4				*mtx4_init(float const val);
void				mtx4_clear(t_mtx4 *mtx);
t_mtx4				*mtx4_copy(t_mtx4 const *src);
void				mtx4_print(t_mtx4 const *src);
t_mtx4				*mtx4x3_mult(t_mtx4 const *a, t_mtx4 const *b,
					t_mtx4 *dst);
t_mtx4				*mtx4x4_mult(t_mtx4 const *a, t_mtx4 const *b,
					t_mtx4 *dst);
t_mtx4				*mtx4_get_rotation(float const x, float const y,
					float const z, float const a);

t_cam				*camera_init(void);
void				camera_move_x(t_cam *cam, float const a);
void				camera_move_y(t_cam *cam, float const a);
void				camera_move_z(t_cam *cam, float const a);
void				camera_rotate_x(t_cam *cam, float const a);
void				camera_rotate_y(t_cam *cam, float const a);
void	camera_rotate_custom(t_cam *cam, t_vec3 const *p, t_vec3 *axis, float const a);
void	camera_per_calc_piv(t_cam *cam);

void				dots_fill_cb(const t_vec4 *p, const t_mtx4 *c,
					t_vec3 *res);
void	dots_fill_sb_iso(const t_vec3 *p, t_vec2 *res, const float f);
void	dots_fill_sb_per(t_vec3 *point, t_vec2 *res, const t_cam *cam);
t_dots				*dots_init(int const x, int const y);
int					dots_print(t_dots *res);
void				dots_scale_y(t_dots *dots, float const s);
void	dots_color_update(t_dots *dots);

void				image_clear(t_image *img);
t_image				*image_init(t_mlx *mlx, int const x, int const y);
void				image_set_pixel(t_image *img, int const x, int const y,
					int const c);
int				image_draw_line(t_mlx const *mlx, t_vec2 const *v1,
					t_vec2 const *v2, t_vec2 const *c);

t_mlx				*mlx_init_ll3d(int width, int height, char *header);
t_mlx				*mlx_free_ll3d(t_mlx **mlx);

int 		color_lerp(int c1, int c2, float step);
int			color_get_default(const int z, const int cm);

#endif
