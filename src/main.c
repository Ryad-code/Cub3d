#include "../cub3D.h"

int main(int ac, char **av)
{
	t_mlx	mlx;

	mlx.frame = 1;

	ft_args(ac, av);		//CHECKING ARGS
	ft_get_infos(&mlx, av[1]);	//GETTING INFOS (POS, MAP, TEXTURES)
	ft_parse_text(&mlx);		//INFOS PARSING

//	ft_display_map(&mlx);
	mlx.mlx = mlx_init();//..............INIT WINDOW
	mlx.win = mlx_new_window(mlx.mlx, S_WIDTH, S_HEIGHT, "cub3D");

	mlx.buff01.img = mlx_new_image(mlx.mlx, S_WIDTH, S_HEIGHT);
	mlx.buff01.addr = mlx_get_data_addr(mlx.buff01.img, &mlx.buff01.bpp,
		&mlx.buff01.l_len, &mlx.buff01.endian);
//............................................................................
	mlx.text.img = mlx_xpm_file_to_image(mlx.mlx, "./textures/bricksheight.xpm", &mlx.text.img_width, &mlx.text.img_height);
	if(mlx.text.img)
		mlx.text.addr = mlx_get_data_addr(mlx.text.img, &mlx.text.bit_per_pixel, &mlx.text.line_lenght, &mlx.text.endian);
	else
		return (-1);
	ft_vector(&mlx, &mlx.buff01);//........................................3D DISPLAY
//.............................................................................PUT IMAGES TO WINDOW
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.buff01.img, 0, 0);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.text.img, 0, 0);
//.............................................................................TEST
	printf("t_bpp = %d, t_len = %d\n", mlx.text.bit_per_pixel, mlx.text.line_lenght);

	mlx_hook(mlx.win, 2, 1L<<0, ft_next_frame, &mlx);//....................KEY_HOOK
	mlx_loop(mlx.mlx);
	return (0);
}
