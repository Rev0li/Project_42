/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:39:09 by okientzl          #+#    #+#             */
/*   Updated: 2025/03/07 16:53:09 by okientzl         ###   ########.fr       */
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

typedef struct s_transform {
    int x_off;
    int y_off;
} t_transform;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_line_params {
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
} t_line_params;

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
    void 	*mlx;
    void 	*window;
	t_img	img;
	char	*file_name;
	char	*title;
	int		fd;
	int		height;
	int		min_width;
	int		scale;
	t_coord	**map;
	int		error_code;
	char	*error_message;
}	t_data;


// error.c
void	ft_show_error(t_data *data);
void	ft_print_error(char *error_message, int code);

// ft_free.c
void	free_map(t_data *data);
void	free_data(t_data *data);
void	free_token(char **token);

// utils.c
int		openfile(char *filename, t_data *data);
void	make_title(t_data *data);
int		ft_hextoint(const char *hex);
int		get_row_length(t_coord *row);
void	put_pixel(t_data *data, int x, int y, int color);

// valid_map_file.c
bool	valid_map_file(t_data *data);

// fill_map.c
bool	fill_map(t_data *data);

// draw.c
void	draw_map(t_data *data);
t_coord	project_iso(t_coord pt, int scale);

// compute_scale.c
int	compute_scale(t_data *data);

#endif
