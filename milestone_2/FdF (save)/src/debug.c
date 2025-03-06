#include "../include/fdf.h"


void print_map(t_data *data)
{
	int i, j;

	if (!data || !data->map)
	{
		ft_printf("Aucune map à afficher.\n");
		return;
	}

	i = 0;
	while (i < data->height)
	{
		ft_printf("Ligne %d :\n", i);
		j = 0;
		while (1)
		{
			ft_printf("  Cellule[%d][%d] -> x: %d, y: %d, z: %d, color: 0x%X, special: %d, end: %d\n",
			 i, j,
			 data->map[i][j].x,
			 data->map[i][j].y,
			 data->map[i][j].z,
			 data->map[i][j].color,
			 data->map[i][j].special,
			 data->map[i][j].end);
			if (data->map[i][j].end)
				break;
			j++;
		}
		i++;
	}
}
