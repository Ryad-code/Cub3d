#include "../cub3D.h"

double	ft_se(t_mlx *mlx, double x, double y, double angle)
{
	double seg_x;
	double seg_y;
	double angle_a;
	double angle_b;
	double hypo;

	seg_x = 1 -x;
	seg_y = 1 - y;
	angle_a = angle;
	angle_b = (PI / 2) - angle_a;
	if (seg_x / cos(angle_a) <= seg_y / cos(angle_b))
	{
		hypo = seg_x / cos(angle_a);
		mlx->player.hit1_x = 1;
		mlx->player.hit1_y = y + sqrt((hypo * hypo) - (seg_x * seg_x));
		mlx->player.hit2_x = x + sqrt(((seg_y / cos(angle_b)) * (seg_y / cos(angle_b))) - (seg_y * seg_y));
		mlx->player.hit2_y = 1;
		mlx->player.dir = 'e';
	}
	else if (seg_y / cos(angle_b) <= seg_x / cos(angle_a))
	{
		hypo = seg_y / cos(angle_b);
		mlx->player.hit1_x = x + sqrt((hypo * hypo) - (seg_y * seg_y));
		mlx->player.hit1_y = 1;
		mlx->player.hit2_x = 1;
		mlx->player.hit2_y = y + sqrt(((seg_x / cos(angle_a)) * (seg_x / cos(angle_a))) - (seg_x * seg_x));
		mlx->player.dir = 's';
	}
	return (hypo);

}

double	ft_sw(t_mlx *mlx, double x, double y, double angle)
{
	double	seg_x;
	double	seg_y;
	double angle_a;
	double angle_b;
	double hypo;

	seg_x = x;
	seg_y = 1 - y;
	angle_a = angle - (PI / 2);
	angle_b = (PI / 2) - angle_a;
	if (seg_x / cos(angle_b) <= seg_y / cos(angle_a))
	{
		hypo = seg_x / cos(angle_b);
		mlx->player.hit1_x = 0;
		mlx->player.hit1_y = y + sqrt((hypo * hypo) - (seg_x * seg_x));
		mlx->player.hit2_x = x - sqrt(((seg_y / cos(angle_a)) * (seg_y / cos(angle_a))) - (seg_y * seg_y));
		mlx->player.hit2_y = 1;
		mlx->player.dir = 'w';
	}
	else if (seg_y / cos(angle_a) <= seg_x / cos(angle_b))
	{
		hypo = seg_y / cos(angle_a);
		mlx->player.hit1_x = x - sqrt((hypo * hypo) - (seg_y * seg_y));
		mlx->player.hit1_y = 1;
		mlx->player.hit2_x = 0;
		mlx->player.hit2_y = y + sqrt(((seg_x / cos(angle_b)) * (seg_x / cos(angle_b))) - (seg_x * seg_x));
		mlx->player.dir = 's';
	}
	return (hypo);
}

double	ft_nw(t_mlx *mlx, double x, double y, double angle)
{
	double	seg_x;
	double	seg_y;
	double	angle_a;
	double	angle_b;
	double	hypo;

	seg_x = x;
	seg_y = y;
	angle_a = angle - PI;
	angle_b = (PI / 2) - angle_a;
	if (seg_x / cos(angle_a) <= seg_y / cos(angle_b))
	{
		hypo = seg_x / cos(angle_a);
		mlx->player.hit1_x = 0;
		mlx->player.hit1_y = y - sqrt((hypo * hypo) - (seg_x * seg_x));
		mlx->player.hit2_x = x - sqrt(((seg_y / cos(angle_b)) * (seg_y / cos(angle_b))) - (seg_y * seg_y));
		mlx->player.hit2_y = 0;
		mlx->player.dir = 'w';
	}
	else if (seg_y / cos(angle_b) <= seg_x / cos(angle_a))
	{
		hypo = seg_y / cos(angle_b);
		mlx->player.hit1_x = x - sqrt((hypo * hypo) - (seg_y * seg_y));
		mlx->player.hit1_y = 0;
		mlx->player.hit2_x = 0;
		mlx->player.hit2_y = y - sqrt(((seg_x / cos(angle_a)) * (seg_x / cos(angle_a))) - (seg_x * seg_x));
		mlx->player.dir = 'n';
	}
	return (hypo);
}

double	ft_ne(t_mlx *mlx, double x, double y, double angle)
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
	}
	else if (seg_y / cos(angle_b) <= seg_x / cos(angle_a))
	{
		hypo = seg_y / cos(angle_b);
		mlx->player.hit1_x = x + sqrt((hypo * hypo) - (seg_y * seg_y));
		mlx->player.hit1_y = 0;
		mlx->player.hit2_x = 1;
		mlx->player.hit2_y = y - sqrt(((seg_x / cos(angle_a)) * (seg_x / cos(angle_a))) - (seg_x * seg_x));
		mlx->player.dir = 'n';
	}
	return (hypo);
}
