/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:39:09 by okientzl          #+#    #+#             */
/*   Updated: 2025/03/13 14:28:51 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <errno.h>
# include <math.h>
# include "../lib/minilibx/mlx.h"
# include "../lib/ult_lib/include/ult_lib.h"

# define W_HEIGHT 2000
# define W_WIDTH 3000
# define ISO_AGL 0.523599

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_coord
{
	int		x;
	int		y;
	int		z;
	bool	special;
	bool	end;
	int		color;
}	t_coord;

typedef struct s_data
{
	void	*mlx;
	void	*window;
	t_img	img;
	char	*file_name;
	char	*title;
	int		fd;
	int		height;
	int		min_width;
	double	scale;
	t_coord	**map;
	int		error_code;
	char	*error_message;
	double	z_scale;
	int		x_off;
	int		y_off;
}	t_data;

typedef struct s_line_params
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_line_params;

typedef struct s_bbox
{
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	min_z;
	double	max_z;
	double	z_range;
}	t_bbox;

// error.c
void			ft_show_error(t_data *data);
void			ft_print_error(char *error_message, int code);

// ft_free.c
void			free_token(char **token);
void			free_height_map(t_data *data, int height);

// utils.c
bool			openfile(char *filename, t_data *data);
int				key_hook(int keycode, t_data *data);
int				close_app(t_data *data, bool	with_errors, bool all);
int				destroy_hook(void *param);
int				mouse_hook(int button, int x, int y, t_data *data);

// valid_map_file.c
bool			valid_map_file(t_data *data);

// fill_map.c
bool			fill_map(t_data *data);

// draw.c
void			draw_map(t_data *data);

// tools_draw.c
t_line_params	assign_struct_line(t_coord p0, t_coord p1, t_data *data);
t_coord			project_iso(t_coord pt, double scale, double z_scale);
int				ft_hextoint(const char *hex);
int				get_row_length(t_coord *row);
void			put_pixel(t_data *data, int x, int y, int color);

// compute_scale.c
void			compute_scale(t_data *data);

#endif
