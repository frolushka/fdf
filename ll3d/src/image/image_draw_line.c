/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 07:50:40 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/12 17:44:09 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"
#include <stdio.h>

static int inline	color_set_brightness(int c, float br)
{
 	int	r;
 	int	g;
 	int	b;

	if (br > 1)
		br = 1;
 	r = ((c & 0xFF0000) >> 16) * br;
 	g = ((c & 0xFF00) >> 8) * br;
 	b = (c & 0xFF) * br;
 	return (r << 16 | g << 8 | b);
}

// static float	ft_ipart(float x)
// {
// 	return ((int)x);
// }

// static float	ft_round(float x)
// {
// 	return ((int)(x + 0.5f));
// }

// static float	ft_fpart(float x)
// {
// 	return ((float)x - (float)ft_ipart(x));
// }

// static float	ft_rfpart(float x)
// {
// 	return (1.0f - ft_fpart(x));
// }

// static void		image_draw_hor(t_mlx const *mlx, int *t)
// {
// 	while (DeltaX-- != 0)
// 	{
// 		x0 += XDir;
// 		image_set_pixel(mlx->image, x0, y0, color_lerp(C0, C1, (float)ft_fabs(x0 - x0t) / ft_fabs(x1 - x0t)));
// 	}
// }

int			image_draw_line(t_mlx const *mlx, t_vec2 const *v1,
				t_vec2 const *v2, t_vec2 const *c)
{
	// t_vec2	*v1c = vec2_copy(v1);
	// t_vec2	*v2c = vec2_copy(v2);

	// int	steep = ft_abs(v2c->y - v1c->y) > ft_abs(v2c->x - v1c->x);

	// if (steep)
	// {
	// 	ft_swap(&(v1c->x), &(v1c->y));
	// 	ft_swap(&(v2c->x), &(v2c->y));
	// }
	// if (v1c->x > v2c->x)
	// {
	// 	ft_swap(&(v1c->x), &(v2c->x));
	// 	ft_swap(&(v1c->y), &(v2c->y));
	// }

	// float	dx = v2c->x - v1c->x;
	// float	dy = v2c->y - v1c->y;
	// float	g = dy / dx;
	// if (dx == 0.0f)
	// 	g = 1;

	// int xpxl1 = v1c->x;
	// int xpxl2 = v2c->x;
	// float y = v1c->y;

	// if (steep)
    // {
    //     int x;
    //     for (x = xpxl1 ; x <=xpxl2 ; x++)
    //     {
	// 		int color = color_lerp(c->x, c->y,
	//  			ft_fabs(sqrt(x * x + y * y) - sqrt(v1c->x * v1c->x + v1c->y * v1c->y)) /
	// 			ft_fabs(sqrt(v2c->x * v2c->x + v2c->y * v2c->y) - sqrt(v1c->x * v1c->x + v1c->y * v1c->y))
	// 		);
	// 		int c1 = color_set_brightness(color, fPartOfNumber(y));
	// 		image_set_pixel(mlx->image, iPartOfNumber(y), x, c1);
	// 		int c2 = color_set_brightness(color, rfPartOfNumber(y));
	// 		image_set_pixel(mlx->image, iPartOfNumber(y) - 1, x, c2);
    //         y += g;
    //     }
    // }
    // else
    // {
    //     int x;
    //     for (x = xpxl1 ; x <=xpxl2 ; x++)
    //     {
    //         int color = color_lerp(c->x, c->y,
	//  			ft_fabs(sqrt(x * x + y * y) - sqrt(v1c->x * v1c->x + v1c->y * v1c->y)) /
	// 			ft_fabs(sqrt(v2c->x * v2c->x + v2c->y * v2c->y) - sqrt(v1c->x * v1c->x + v1c->y * v1c->y))
	// 		);
	// 		int c1 = color_set_brightness(color, fPartOfNumber(y));
	// 		image_set_pixel(mlx->image, x, iPartOfNumber(y), c1);
	// 		int c2 = color_set_brightness(color, rfPartOfNumber(y));
	// 		image_set_pixel(mlx->image, x, iPartOfNumber(y) - 1, c2);
    //         y += g;
    //     }
    // }
	// free(v1c);
	// free(v2c);
	// t_vec2 *d = vec2_new(ft_abs(v2->x - v1->x), ft_abs(v2->y - v1->y));
	// t_vec2 *s = vec2_new(ft_sign(v2->x - v1->x), ft_sign(v2->y - v1->y));
	// int err = (d->x > d->y ? d->x : -d->y) / 2;
	// int e2;
	// int xt = v1->x;
	// int	yt = v1->y;
	// while (xt != v2->x || yt != v2->y)
	// {
	// 	image_set_pixel(mlx->image, xt, yt,
	// 		color_lerp(c->x, c->y,
	// 			1 - (d->y > d->x ? (float)ft_fabs(yt - v2->y) / ft_fabs(v2->y - v1->y) :
	// 				(float)ft_fabs(xt - v2->x) / ft_fabs(v2->x - v1->x))
	// 		));
	// 	e2 = err;
	// 	if (e2 > -d->x)
	// 	{
	// 		err -= d->y;
	// 		xt += s->x;
	// 	}
	// 	if (e2 < d->y)
	// 	{
	// 		err += d->x;
	// 		yt += s->y;
	// 	}
	// }
	// free(d);
	// free(s);

	//  ПОПЫТКА 2

	// t_vec2	*a = vec2_copy(v1);
	// t_vec2	*b = vec2_copy(v2);

	// t_vec3 *d = vec3_new(b->x - a->x, b->y - a->y, 0);
	// if (ft_fabs(d->x) > ft_fabs(d->y))
	// {
	// 	if (b->x < a->x)
	// 	{
	// 		ft_swap(&(a->x), &(b->x));
	// 		ft_swap(&(a->y), &(b->y));
	// 	}
	// 	float g = d->y / d->x;
	// 	float xe = ft_round(a->x);
	// 	float ye = a->y + g * (xe - a->x);
	// 	float xg = ft_rfpart(a->x + 0.5f);
	// 	int xpxl1 = xe;
	// 	int ypxl1 = ft_ipart(ye);
	// 	image_set_pixel(mlx->image, xpxl1, ypxl1, color_set_brightness(0xFFFFFF, ft_rfpart(ye) * xg));
	// 	image_set_pixel(mlx->image, xpxl1, ypxl1 + 1, color_set_brightness(0xFFFFFF, ft_fpart(ye) * xg));
	// 	double in = ye + g;

	// 	xe = ft_round(b->x);
	// 	ye = b->y + g * (xe - b->x);
	// 	xg = ft_fpart(b->x + 0.5f);
	// 	int xpxl2 = xe;
	// 	int ypxl2 = ft_ipart(ye);
	// 	image_set_pixel(mlx->image, xpxl2, ypxl2, color_set_brightness(0xFFFFFF, ft_rfpart(ye) * xg));
	// 	image_set_pixel(mlx->image, xpxl2, ypxl2 + 1, color_set_brightness(0xFFFFFF, ft_fpart(ye) * xg));

	// 	int x;
	// 	for (x = xpxl1 + 1; x < xpxl2; x++)
	// 	{
	// 		image_set_pixel(mlx->image, x, ft_ipart(in), color_set_brightness(0xFFFFFF, ft_rfpart(in)));
	// 		image_set_pixel(mlx->image, x, ft_ipart(in) + 1, color_set_brightness(0xFFFFFF, ft_fpart(in)));
	// 		in += g;
    // 	}
	// }
	// else
	// {
	// 	if (b->y < a->y)
	// 	{
	// 		ft_swap(&(a->x), &(b->x));
	// 		ft_swap(&(a->y), &(b->y));
	// 	}
	// 	float g = d->y / d->x;
	// 	float ye = ft_round(a->y);
	// 	float xe = a->x + g * (ye - a->y);
	// 	float yg = ft_rfpart(a->y + 0.5f);
	// 	int ypxl1 = ye;
	// 	int xpxl1 = ft_ipart(xe);
	// 	image_set_pixel(mlx->image, xpxl1, ypxl1, color_set_brightness(0xFFFFFF, ft_rfpart(xe) * yg));
	// 	image_set_pixel(mlx->image, xpxl1 + 1, ypxl1, color_set_brightness(0xFFFFFF, ft_fpart(xe) * yg));
	// 	double in = xe + g;

	// 	ye = ft_round(b->y);
	// 	xe = b->x + g * (ye - b->y);
	// 	yg = ft_fpart(b->y + 0.5f);
	// 	int ypxl2 = ye;
	// 	int xpxl2 = ft_ipart(xe);
	// 	image_set_pixel(mlx->image, xpxl2, ypxl2, color_set_brightness(0xFFFFFF, ft_rfpart(xe) * yg));
	// 	image_set_pixel(mlx->image, xpxl2 + 1, ypxl2, color_set_brightness(0xFFFFFF, ft_fpart(xe) * yg));

	// 	int y;
	// 	for (y = ypxl1 + 1; y < ypxl2; y++)
	// 	{
	// 		image_set_pixel(mlx->image, ft_ipart(in), y, color_set_brightness(0xFFFFFF, ft_rfpart(in)));
	// 		image_set_pixel(mlx->image, ft_ipart(in) + 1, y, color_set_brightness(0xFFFFFF, ft_fpart(in)));
	// 		in += g;
    // 	}
	// }
	// (void)c;

	// ПОПЫТКА 3

	unsigned short dt[6];
	ft_bzero(&dt, 6 * sizeof(short));
	int	t[18];
	ft_bzero(&t, 18 * 4);
	t[10] = v1->x; // 10
	t[11] = v2->x; // 11
	t[12] = v1->y; // 12
	t[13] = v2->y; // 13
	t[14] = c->x; // 14
	t[15] = c->y; // 15

   /* Make sure the line runs top to bottom */
   if (t[12] > t[13]) {
	   ft_swap(&t[10], &t[11]);
	   ft_swap(&t[12], &t[13]);
	  ft_swap(&t[14], &t[15]);
   }
   /* Draw the initial pixel, which is always exactly intersected by
      the line and so needs no dt[4] */
	image_set_pixel(mlx->image, t[10], t[12], t[14]);

	t[16] = t[10];
	t[17] = t[12];
   if ((t[6] = t[11] - t[10]) >= 0) {
      t[9] = 1;
   } else {
      t[9] = -1;
      t[6] = -t[6]; /* make t[6] positive */
   }
   /* Special-case horizontal, vertical, and diagonal lines, which
      require no dt[4] because they go right through the center of
      every pixel */
   if ((t[7] = t[13] - t[12]) == 0) {
      /* Horizontal line */
      while (t[6]-- != 0) {
         t[10] += t[9];
		 image_set_pixel(mlx->image, t[10], t[12], color_lerp(t[14], t[15], (float)ft_fabs(t[10] - t[16]) / ft_fabs(t[11] - t[16])));
      }
      return (0);
   }

   if (t[6] == 0) {
      /* Vertical line */
      do {
         t[12]++;
		 image_set_pixel(mlx->image, t[10], t[12], color_lerp(t[14], t[15], (float)ft_fabs(t[12] - t[17]) / ft_fabs(t[13] - t[17])));
      } while (--t[7] != 0);
      return (0);
   }
   if (t[6] == t[7]) {
      /* Diagonal line */
      do {
         t[10] += t[9];
         t[12]++;
		 image_set_pixel(mlx->image, t[10], t[12], color_lerp(t[14], t[15], (float)ft_fabs(t[10] - t[16]) / ft_fabs(t[11] - t[16])));
      } while (--t[7] != 0);
      return (0);
   }
   /* Line is not horizontal, diagonal, or vertical */
   dt[2] = 0;  /* initialize the line error accumulator to 0 */
   /* # of bits by which to shift dt[2] to get intensity level */
   dt[0] = 8;
   /* Mask used to flip all bits in an intensity dt[4], producing the
      result (1 - intensity dt[4]) */
   dt[5] = 255;
   /* Is this an X-major or Y-major line? */
   if (t[7] > t[6]) {
      /* Y-major line; calculate 16-bit fixed-point fractional part of a
         pixel that X advances each time Y advances 1 pixel, truncating the
         result so that we won't overrun the endpoint along the X axis */
      dt[1] = ((unsigned long) t[6] << 16) / (unsigned long) t[7];
      /* Draw all pixels other than the first and last */
      while (--t[7]) {
         dt[3] = dt[2];   /* remember current accumulated error */
         dt[2] += dt[1];      /* calculate error for next pixel */
         if (dt[2] <= dt[3]) {
            /* The error accumulator turned over, so advance the X coord */
            t[10] += t[9];
         }
         t[12]++; /* Y-major, so always advance Y */
         /* The IntensityBits most significant bits of dt[2] give us the
            intensity dt[4] for this pixel, and the complement of the
            dt[4] for the paired pixel */
         dt[4] = dt[2] >> dt[0];
         image_set_pixel(mlx->image, t[10], t[12], color_set_brightness(color_lerp(t[14], t[15], (float)ft_fabs(t[10] - t[16]) / ft_fabs(t[11] - t[16])), (255.0f - dt[4]) / 255.0f));
		 image_set_pixel(mlx->image, t[10] + t[9], t[12], color_set_brightness(color_lerp(t[14], t[15], (float)ft_fabs(t[10] - t[16]) / ft_fabs(t[11] - t[16])), (255.0f - (dt[4] ^ dt[5])) / 255.0f)
		 );
      }
      /* Draw the final pixel, which is
         always exactly intersected by the line
         and so needs no dt[4] */
		 image_set_pixel(mlx->image, t[11], t[13], t[15]);
      return (0);
   }
   /* It's an X-major line; calculate 16-bit fixed-point fractional part of a
      pixel that Y advances each time X advances 1 pixel, truncating the
      result to avoid overrunning the endpoint along the X axis */
   dt[1] = ((unsigned long) t[7] << 16) / (unsigned long) t[6];
   /* Draw all pixels other than the first and last */
   while (--t[6]) {
      dt[3] = dt[2];   /* remember current accumulated error */
      dt[2] += dt[1];      /* calculate error for next pixel */
      if (dt[2] <= dt[3]) {
         /* The error accumulator turned over, so advance the Y coord */
         t[12]++;
      }
      t[10] += t[9]; /* X-major, so always advance X */
      /* The IntensityBits most significant bits of dt[2] give us the
         intensity dt[4] for this pixel, and the complement of the
         dt[4] for the paired pixel */
      dt[4] = dt[2] >> dt[0];
	  image_set_pixel(mlx->image, t[10], t[12], color_set_brightness(color_lerp(t[14], t[15], (float)ft_fabs(t[10] - t[16]) / ft_fabs(t[11] - t[16])), (255.0f - dt[4]) / 255.0f));
	  image_set_pixel(mlx->image, t[10], t[12] + 1, color_set_brightness(color_lerp(t[14], t[15], (float)ft_fabs(t[10] - t[16]) / ft_fabs(t[11] - t[16])), (255.0f - (dt[4] ^ dt[5])) / 255.0f));
   }
   /* Draw the final pixel, which is always exactly intersected by the line
      and so needs no dt[4] */
   image_set_pixel(mlx->image, t[11], t[13], t[15]);
   (void) c;
   return (0);

	// ================
	// ===============
	// ===============

// 	unsigned short IntensityShift, // 0
// 	ErrorAdj, // 1
// 	ErrorAcc; // 2
//    unsigned short ErrorAccTemp, // 3
//    Weighting, // 4
//    WeightingComplementMask; // 5
//    short DeltaX, // 6
//    DeltaY, // 7
//    Temp, // 8
//    XDir; // 9

// 	int x0 = v1->x; // 10
// 	int x1 = v2->x; // 11
// 	int y0 = v1->y; // 12
// 	int y1 = v2->y; // 13
// 	int C0 = c->x; // 14
// 	int C1 = c->y; // 15

//    /* Make sure the line runs top to bottom */
//    if (y0 > y1) {
//       Temp = y0; y0 = y1; y1 = Temp;
//       Temp = x0; x0 = x1; x1 = Temp;
// 	  ft_swap(&C0, &C1);
//    }
//    /* Draw the initial pixel, which is always exactly intersected by
//       the line and so needs no weighting */
// 	image_set_pixel(mlx->image, x0, y0, C0);

// 	int x0t = x0;
// 	int y0t = y0;
//    if ((DeltaX = x1 - x0) >= 0) {
//       XDir = 1;
//    } else {
//       XDir = -1;
//       DeltaX = -DeltaX; /* make DeltaX positive */
//    }
//    /* Special-case horizontal, vertical, and diagonal lines, which
//       require no weighting because they go right through the center of
//       every pixel */
//    if ((DeltaY = y1 - y0) == 0) {
//       /* Horizontal line */
//       while (DeltaX-- != 0) {
//          x0 += XDir;
// 		 image_set_pixel(mlx->image, x0, y0, color_lerp(C0, C1, (float)ft_fabs(x0 - x0t) / ft_fabs(x1 - x0t)));
//       }
//       return (0);
//    }

//    if (DeltaX == 0) {
//       /* Vertical line */
//       do {
//          y0++;
// 		 image_set_pixel(mlx->image, x0, y0, color_lerp(C0, C1, (float)ft_fabs(y0 - y0t) / ft_fabs(y1 - y0t)));
//       } while (--DeltaY != 0);
//       return (0);
//    }
//    if (DeltaX == DeltaY) {
//       /* Diagonal line */
//       do {
//          x0 += XDir;
//          y0++;
// 		 image_set_pixel(mlx->image, x0, y0, color_lerp(C0, C1, (float)ft_fabs(x0 - x0t) / ft_fabs(x1 - x0t)));
//       } while (--DeltaY != 0);
//       return (0);
//    }
//    /* Line is not horizontal, diagonal, or vertical */
//    ErrorAcc = 0;  /* initialize the line error accumulator to 0 */
//    /* # of bits by which to shift ErrorAcc to get intensity level */
//    IntensityShift = 8;
//    /* Mask used to flip all bits in an intensity weighting, producing the
//       result (1 - intensity weighting) */
//    WeightingComplementMask = 255;
//    /* Is this an X-major or Y-major line? */
//    if (DeltaY > DeltaX) {
//       /* Y-major line; calculate 16-bit fixed-point fractional part of a
//          pixel that X advances each time Y advances 1 pixel, truncating the
//          result so that we won't overrun the endpoint along the X axis */
//       ErrorAdj = ((unsigned long) DeltaX << 16) / (unsigned long) DeltaY;
//       /* Draw all pixels other than the first and last */
//       while (--DeltaY) {
//          ErrorAccTemp = ErrorAcc;   /* remember current accumulated error */
//          ErrorAcc += ErrorAdj;      /* calculate error for next pixel */
//          if (ErrorAcc <= ErrorAccTemp) {
//             /* The error accumulator turned over, so advance the X coord */
//             x0 += XDir;
//          }
//          y0++; /* Y-major, so always advance Y */
//          /* The IntensityBits most significant bits of ErrorAcc give us the
//             intensity weighting for this pixel, and the complement of the
//             weighting for the paired pixel */
//          Weighting = ErrorAcc >> IntensityShift;
//          image_set_pixel(mlx->image, x0, y0, color_set_brightness(color_lerp(C0, C1, (float)ft_fabs(x0 - x0t) / ft_fabs(x1 - x0t)), (255.0f - Weighting) / 255.0f));
// 		 image_set_pixel(mlx->image, x0 + XDir, y0, color_set_brightness(color_lerp(C0, C1, (float)ft_fabs(x0 - x0t) / ft_fabs(x1 - x0t)), (255.0f - (Weighting ^ WeightingComplementMask)) / 255.0f)
// 		 );
//       }
//       /* Draw the final pixel, which is
//          always exactly intersected by the line
//          and so needs no weighting */
// 		 image_set_pixel(mlx->image, x1, y1, C1);
//       return (0);
//    }
//    /* It's an X-major line; calculate 16-bit fixed-point fractional part of a
//       pixel that Y advances each time X advances 1 pixel, truncating the
//       result to avoid overrunning the endpoint along the X axis */
//    ErrorAdj = ((unsigned long) DeltaY << 16) / (unsigned long) DeltaX;
//    /* Draw all pixels other than the first and last */
//    while (--DeltaX) {
//       ErrorAccTemp = ErrorAcc;   /* remember current accumulated error */
//       ErrorAcc += ErrorAdj;      /* calculate error for next pixel */
//       if (ErrorAcc <= ErrorAccTemp) {
//          /* The error accumulator turned over, so advance the Y coord */
//          y0++;
//       }
//       x0 += XDir; /* X-major, so always advance X */
//       /* The IntensityBits most significant bits of ErrorAcc give us the
//          intensity weighting for this pixel, and the complement of the
//          weighting for the paired pixel */
//       Weighting = ErrorAcc >> IntensityShift;
// 	  image_set_pixel(mlx->image, x0, y0, color_set_brightness(color_lerp(C0, C1, (float)ft_fabs(x0 - x0t) / ft_fabs(x1 - x0t)), (255.0f - Weighting) / 255.0f));
// 	  image_set_pixel(mlx->image, x0, y0 + 1, color_set_brightness(color_lerp(C0, C1, (float)ft_fabs(x0 - x0t) / ft_fabs(x1 - x0t)), (255.0f - (Weighting ^ WeightingComplementMask)) / 255.0f));
//    }
//    /* Draw the final pixel, which is always exactly intersected by the line
//       and so needs no weighting */
//    image_set_pixel(mlx->image, x1, y1, C1);
//    (void) c;
//    return (0);
}
