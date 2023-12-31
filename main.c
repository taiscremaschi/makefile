/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolzan- <tbolzan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:06:28 by tbolzan-          #+#    #+#             */
/*   Updated: 2023/06/29 14:48:59 by tbolzan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


/*int	main()
{

	void	*img;
	void	*mlx;
	void	*mlx_win;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1900, 1080, "tatazinha!");
	mlx_loop(mlx);
	img = mlx_new_image(mlx, 1900, 1080);
}*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 1920/2, 1080/2);
	mlx_loop(mlx);
}

