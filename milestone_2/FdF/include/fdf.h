/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:39:09 by okientzl          #+#    #+#             */
/*   Updated: 2025/02/13 17:54:55 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <errno.h>
# include "../lib/minilibx/mlx.h"
# include "../lib/ult_lib/ult_lib.h"
# include "color.h"
# include "hooks_key.h"

# define W_HEIGHT 768
# define W_WIDTH 1366

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
	char	*file_name;
	char	*title;
	int		fd;
	t_coord	***map;
	int		error_code;
	char	*error_message;
}              t_data;
// error.c
void	ft_show_error(t_data *data);
void	ft_print_error(char *error_message, int code);

// utils.c
int		openfile(char *filename, t_data *data);
void	make_title(t_data *data);

#endif
