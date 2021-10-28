#include "../cub3D.h"

int main(int ac, char **av)
{
	t_mlx	mlx;

	mlx.frame = 1;

	ft_args(ac, av);		//CHECKING ARGS
	ft_get_infos(&mlx, av[1]);	//GETTING INFOS (POS, MAP, TEXTURES)
	ft_parse_text(&mlx);		//INFOS PARSING

	mlx.mlx = mlx_init();//..............INIT WINDOW
	mlx.win = mlx_new_window(mlx.mlx, S_WIDTH, S_HEIGHT, "cub3D");

	mlx.buff01.img = mlx_new_image(mlx.mlx, S_WIDTH, S_HEIGHT);
	mlx.buff01.addr = mlx_get_data_addr(mlx.buff01.img, &mlx.buff01.bpp,
		&mlx.buff01.l_len, &mlx.buff01.endian);
//............................................................................
	if (ft_init_texture(&mlx) < 0)
		return (-1);
	ft_vector(&mlx, &mlx.buff01);//........................................3D DISPLAY
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.buff01.img, 0, 0);
	
	mlx_hook(mlx.win, 2, 1L<<0, ft_next_frame, &mlx);//....................KEY_HOOK
	mlx_loop(mlx.mlx);
	return (0);
}
