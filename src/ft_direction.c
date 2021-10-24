#include "../cub3D.h"

double	ft_se(t_mlx *mlx, double x, double y, double angle, int square[])
{
	int	i;
	double	seg_x;
	double	seg_y;
	double	angle_a;
	double	angle_b;
	double	hypo;

	(void)square;
	i = 0;
	seg_x = 1 - x;
	seg_y = 1 - y;
	angle_a = angle;
	angle_b = (PI / 2) - angle_a;
	if (seg_x / cos(angle_a) <= seg_y / cos(angle_b))
	{
		while (mlx->player.y + mlx->player.hit1_y <= 10 && mlx->player.x + mlx->player.hit1_x <= 10
		&& mlx->map.grid[(int)((int)mlx->player.y + mlx->player.hit1_y)][(int)((int)mlx->player.x + mlx->player.hit1_x)] != '1')
		{
			hypo = (seg_x + i) / cos(angle_a);
			mlx->player.hit1_x = 1 + i;
			mlx->player.hit1_y = y + sqrt((hypo * hypo) - ((seg_x + i) * (seg_x + i)));
			i++;
		}
		i = 0;
		while (mlx->player.y + mlx->player.hit2_y <= 10 && mlx->player.x + mlx->player.hit2_x <= 10
		&& mlx->map.grid[(int)((int)mlx->player.y + mlx->player.hit2_y)][(int)((int)mlx->player.x + mlx->player.hit2_x)] != '1')
		{
			mlx->player.hit2_x = x + sqrt((((seg_y + i) / cos(angle_b)) * ((seg_y + i) / cos(angle_b))) - ((seg_y + i) * (seg_y + i    )));
			mlx->player.hit2_y = 1 + i;
			i++;
		}

	}
	else if (seg_y / cos(angle_b) <= seg_x / cos(angle_a))
	{
		while (mlx->player.y + mlx->player.hit1_y <= 10 && mlx->player.x + mlx->player.hit1_x <= 10
		&& mlx->map.grid[(int)((int)mlx->player.y + mlx->player.hit1_y)][(int)((int)mlx->player.x + mlx->player.hit1_x)] != '1')
		{
			hypo = (seg_y + i) / cos(angle_b);
			mlx->player.hit1_x = x + sqrt((hypo * hypo) - ((seg_y + i) * (seg_y + i)));
			mlx->player.hit1_y = 1 + i;
			i++;
		}
		i = 0;
		while (mlx->player.y + mlx->player.hit2_y <= 10 && mlx->player.x + mlx->player.hit2_x <= 10
		&& mlx->map.grid[(int)((int)mlx->player.y + mlx->player.hit2_y)][(int)((int)mlx->player.x + mlx->player.hit2_x)] != '1')
		{
			mlx->player.hit2_x = 1 + i;
			mlx->player.hit2_y = y + sqrt((((seg_x + i) / cos(angle_a)) * ((seg_x + i) / cos(angle_a))) - ((seg_x + i) * (seg_x + i)));
			i++;
		}
	}
	return (hypo);

}

double	ft_sw(t_mlx *mlx, double x, double y, double angle, int square[])
{
	int	i;
	double	seg_x;
	double	seg_y;
	double angle_a;
	double angle_b;
	double hypo;
	
	(void)square;
	i = 0;
	seg_x = x;
	seg_y = 1 - y;
	angle_a = angle - (PI / 2);
	angle_b = (PI / 2) - angle_a;
	if (seg_x / cos(angle_b) <= seg_y / cos(angle_a))
	{
		while (mlx->player.y + mlx->player.hit1_y <= 10 && mlx->player.x + mlx->player.hit1_x >= 1
		&& mlx->map.grid[(int)((int)mlx->player.y + mlx->player.hit1_y)][(int)((int)mlx->player.x + mlx->player.hit1_x - 1)] != '1')
		{
			hypo = (seg_x + i) / cos(angle_b);
			mlx->player.hit1_x = 0 - i;
			mlx->player.hit1_y = y + sqrt((hypo * hypo) - ((seg_x + i) * (seg_x + i)));
			i++;
		}
		i = 0;
		while (mlx->player.y + mlx->player.hit2_y <= 10 && mlx->player.x + mlx->player.hit2_x >= 0
		&& mlx->map.grid[(int)((int)mlx->player.y + mlx->player.hit2_y)][(int)((int)mlx->player.x + mlx->player.hit2_x)] != '1')
		{
			mlx->player.hit2_x = x - sqrt((((seg_y + i) / cos(angle_a)) * ((seg_y + i) / cos(angle_a))) - ((seg_y + i) * (seg_y + i)));
			mlx->player.hit2_y = 1 + i;
			i++;
		}
		printf("grid[%d][%d]\n", (int)((int)mlx->player.y + mlx->player.hit1_y), (int)((int)mlx->player.x + mlx->player.hit1_x));
	}
	else if (seg_y / cos(angle_a) <= seg_x / cos(angle_b))
	{
		while (mlx->player.y + mlx->player.hit1_y <= 10 && mlx->player.x + mlx->player.hit1_x >= 0
		&& mlx->map.grid[(int)((int)mlx->player.y + mlx->player.hit1_y)][(int)((int)mlx->player.x + mlx->player.hit1_x)] != '1')
		{
			hypo = (seg_y + i) / cos(angle_a);
			mlx->player.hit1_x = x - sqrt((hypo * hypo) - ((seg_y + i) * (seg_y + i)));
			mlx->player.hit1_y = 1 + i;
			i++;
		}
		i = 0;
		while (mlx->player.y + mlx->player.hit2_y <= 10 && mlx->player.x + mlx->player.hit2_x >= 0
		&& mlx->map.grid[(int)((int)mlx->player.y + mlx->player.hit2_y)][(int)((int)mlx->player.x + mlx->player.hit2_x)] != '1')
		{
			mlx->player.hit2_x = 0 - i;
			mlx->player.hit2_y = y + sqrt((((seg_x + i) / cos(angle_b)) * ((seg_x + i) / cos(angle_b))) - ((seg_x + i) * (seg_x + i)));
			i++;
		}
	}
	return (hypo);
}
//....................................................................................A refaire au propre...
double	ft_nw(t_mlx *mlx, double x, double y, double angle, int square[])
{
	int	i;
	double	seg_x;
	double	seg_y;
	double	angle_a;
	double	angle_b;
	double	hypo;

	(void)square;
	i = 0;
	seg_x = x;
	seg_y = y;
	angle_a = angle - PI;
	angle_b = (PI / 2) - angle_a;
	if (seg_x / cos(angle_a) <= seg_y / cos(angle_b))
	{
		while (mlx->player.y + mlx->player.hit1_y >= 0 && mlx->player.x + mlx->player.hit1_x >= 0
		&& mlx->map.grid[(int)((int)mlx->player.y + mlx->player.hit1_y - 1)][(int)((int)mlx->player.x + mlx->player.hit1_x - 1)] != '1')
		{
			hypo = (seg_x + i) / cos(angle_a);
			mlx->player.hit1_x = 0 - i;
			mlx->player.hit1_y = y - sqrt((hypo * hypo) - ((seg_x + i) * (seg_x + i)));
			i++;
		}
		i = 0;
		while (mlx->player.y + mlx->player.hit2_y >= 0 && mlx->player.x + mlx->player.hit2_x >= 0
		&& mlx->map.grid[(int)((int)mlx->player.y + mlx->player.hit2_y - 1)][(int)((int)mlx->player.x + mlx->player.hit2_x - 1)] != '1')
		{
			mlx->player.hit2_x = x - sqrt((((seg_y + i) / cos(angle_b)) * ((seg_y + i) / cos(angle_b))) - ((seg_y + i) * (seg_y + i)));
			mlx->player.hit2_y = 0 - i;
			i++;
		}
	}
	else if (seg_y / cos(angle_b) <= seg_x / cos(angle_a))
	{
		while (mlx->player.y + mlx->player.hit1_y >= 0 && mlx->player.x + mlx->player.hit1_x >= 0
		&& mlx->map.grid[(int)((int)mlx->player.y + mlx->player.hit1_y)][(int)((int)mlx->player.x + mlx->player.hit1_x)] != '1')
		{
			hypo = (seg_y + i) / cos(angle_b);
			mlx->player.hit1_x = x - sqrt((hypo * hypo) - ((seg_y + i) * (seg_y + i)));
			mlx->player.hit1_y = 0 - i;
			i++;
		}
		i = 0;
		while (mlx->player.y + mlx->player.hit2_y >= 0 && mlx->player.x + mlx->player.hit2_x >= 0
		&& mlx->map.grid[(int)((int)mlx->player.y + mlx->player.hit2_y - 1)][(int)((int)mlx->player.x + mlx->player.hit2_x - 1)] != '1')
		{
			mlx->player.hit2_x = 0 - i;
			mlx->player.hit2_y = y - sqrt((((seg_x + i) / cos(angle_a)) * ((seg_x + i) / cos(angle_a))) - ((seg_x + i) * (seg_x + i)));
			i++;
		}
	}
	return (hypo);
}

double	ft_ne(t_mlx *mlx, double x, double y, double angle, int square[])
{
	double	seg_x;
	double	seg_y;
	double	angle_a;
	double	angle_b;
	double	hypo;

	seg_x = 1 - x;
	seg_y = y;
	angle_a = (2 * PI) - angle;
	angle_b = (PI / 2) - angle_a;
	if (seg_x / cos(angle_a) <= seg_y / cos(angle_b))
	{
		hypo = seg_x / cos(angle_a);
		mlx->player.hit1_x = 1;
		mlx->player.hit1_y = y - sqrt((hypo * hypo) - (seg_x * seg_x));
		mlx->player.hit2_x = x + sqrt(((seg_y / cos(angle_b)) * (seg_y / cos(angle_b))) - (seg_y * seg_y));
		mlx->player.hit2_y = 0;
		mlx->player.dir = 'e';
		square[1] += 1;
	}
	else if (seg_y / cos(angle_b) <= seg_x / cos(angle_a))
	{
		hypo = seg_y / cos(angle_b);
		mlx->player.hit1_x = x + sqrt((hypo * hypo) - (seg_y * seg_y));
		mlx->player.hit1_y = 0;
		mlx->player.hit2_x = 1;
		mlx->player.hit2_y = y - sqrt(((seg_x / cos(angle_a)) * (seg_x / cos(angle_a))) - (seg_x * seg_x));
		mlx->player.dir = 'n';
		square[0] -= 1;
	}
	return (hypo);
}
