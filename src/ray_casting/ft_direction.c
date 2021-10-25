#include "../../cub3D.h"

double	ft_se(t_mlx *mlx, double x, double y, double angle)
{
	int	i;
	double	seg_x;
	double	seg_y;
	double	angle_a;
	double	angle_b;
	double	hypo;

	i = 0;
	seg_x = 1 - x;
	seg_y = 1 - y;
	angle_a = angle;
	angle_b = (PI / 2) - angle_a;
	if (seg_x / cos(angle_a) <= seg_y / cos(angle_b))
	{
		while (mlx->player.hit1_y <= 10 && mlx->player.hit1_x <= 10
		&& ft_check_hit(mlx, 'e' ,mlx->player.hit1_x, mlx->player.hit1_y) != '1')
		{
			hypo = (seg_x + i) / cos(angle_a);
			mlx->player.hit1_x = (int)mlx->player.x + i + 1;
			mlx->player.hit1_y = (int)mlx->player. y + y + sqrt((hypo * hypo) - ((seg_x + i) * (seg_x + i)));
			i++;
		}
		printf("i = %d\n", i);
		i = 0;
		while (mlx->player.hit2_y <= 10 && mlx->player.hit2_x <= 10
		&& ft_check_hit(mlx, 's' ,mlx->player.hit2_x, mlx->player.hit2_y) != '1')
		{
			mlx->player.hit2_x = (int)mlx->player.x + x + sqrt((((seg_y + i) / cos(angle_b)) * ((seg_y + i) / cos(angle_b))) - ((seg_y + i) * (seg_y + i)));
			mlx->player.hit2_y = (int)mlx->player.y + i + 1;
			i++;
		}

	}
	else if (seg_y / cos(angle_b) <= seg_x / cos(angle_a))
	{
		while (mlx->player.hit1_y <= 10 && mlx->player.hit1_x <= 10
		&& ft_check_hit(mlx, 's' ,mlx->player.hit1_x, mlx->player.hit1_y) != '1')
		{
			hypo = (seg_y + i) / cos(angle_b);
			mlx->player.hit1_x = (int)mlx->player.x + x + sqrt((hypo * hypo) - ((seg_y + i) * (seg_y + i)));
			mlx->player.hit1_y = (int)mlx->player.y + i + 1;;
			i++;
		}
		i = 0;
		while (mlx->player.hit2_y <= 10 && mlx->player.hit2_x <= 10
		&& ft_check_hit(mlx, 'e' ,mlx->player.hit2_x, mlx->player.hit2_y) != '1')		
		{
			mlx->player.hit2_x = (int)mlx->player.x + i + 1;
			mlx->player.hit2_y = (int)mlx->player.y + y + sqrt((((seg_x + i) / cos(angle_a)) * ((seg_x + i) / cos(angle_a))) - ((seg_x + i) * (seg_x + i)));
			i++;
		}
	}
	return (hypo);

}

double	ft_sw(t_mlx *mlx, double x, double y, double angle)
{
	int	i;
	double	seg_x;
	double	seg_y;
	double angle_a;
	double angle_b;
	double hypo;
	
	i = 1;
	seg_x = x;
	seg_y = 1 - y;
	angle_a = angle - (PI / 2);
	angle_b = (PI / 2) - angle_a;
	if (seg_x / cos(angle_b) <= seg_y / cos(angle_a))
	{
		hypo = seg_x / cos(angle_b);
		mlx->player.hit1_x = (int)mlx->player.x;
		mlx->player.hit1_y = (int)mlx->player.y + y + sqrt((hypo * hypo) - (seg_x * seg_x));
		while (mlx->player.hit1_y <= 10 && mlx->player.hit1_x >= 0
		&& ft_check_hit(mlx, 'w' ,mlx->player.hit1_x, mlx->player.hit1_y) != '1')
		{
			hypo = (seg_x + i) / cos(angle_b);
			mlx->player.hit1_x = (int)mlx->player.x - i;
			mlx->player.hit1_y = (int)mlx->player.y + y + sqrt((hypo * hypo) - ((seg_x + i) * (seg_x + i)));
			i++;
		}
		i = 0;
		mlx->player.hit2_x = (int)mlx->player.x + x - sqrt(((seg_y / cos(angle_a)) * (seg_y / cos(angle_a))) - (seg_y * seg_y));
		mlx->player.hit2_y = (int)mlx->player.y + 1;
		while (mlx->player.hit2_y <= 10 && mlx->player.hit2_x >= 0
		&& ft_check_hit(mlx, 's' , mlx->player.hit2_x, mlx->player.hit2_y) != '1')
		{
			mlx->player.hit2_x = (int)mlx->player.x + x - sqrt((((seg_y + i) / cos(angle_a)) * ((seg_y + i) / cos(angle_a))) - ((seg_y + i) * (seg_y + i)));
			mlx->player.hit2_y = (int)mlx->player.y + 1 + i;
			i++;
		}
	}
	else if (seg_y / cos(angle_a) <= seg_x / cos(angle_b))
	{
		hypo = seg_y / cos(angle_a);
		mlx->player.hit1_x = (int)mlx->player.x + x - sqrt((hypo * hypo) - (seg_y * seg_y));
		mlx->player.hit1_y = (int)mlx->player.y + 1;
		while (mlx->player.hit1_y <= 10 && mlx->player.hit1_x >= 0
		&& ft_check_hit(mlx, 's' , mlx->player.hit1_x, mlx->player.hit1_y) != '1')
		{
			hypo = (seg_y + i) / cos(angle_a);
			mlx->player.hit1_x = (int)mlx->player.x + x - sqrt((hypo * hypo) - ((seg_y + i) * (seg_y + i)));
			mlx->player.hit1_y = (int)mlx->player.y + 1 + i;
			i++;
		}
		i = 0;
		mlx->player.hit2_x = (int)mlx->player.x;
		mlx->player.hit2_y = (int) mlx->player.y + y + sqrt(((seg_x / cos(angle_b)) * (seg_x / cos(angle_b))) - (seg_x * seg_x));
		while (mlx->player.hit2_y <= 10 && mlx->player.hit2_x >= 0
		&& ft_check_hit(mlx, 'w' , mlx->player.hit2_x, mlx->player.hit2_y) != '1')
		{
			mlx->player.hit2_x = (int)mlx->player.x - i;
			mlx->player.hit2_y = (int) mlx->player.y + y + sqrt((((seg_x + i) / cos(angle_b)) * ((seg_x + i) / cos(angle_b))) - ((seg_x + i) * (seg_x + i)));
			i++;
		}
	}
	return (hypo);
}
double	ft_nw(t_mlx *mlx, double x, double y, double angle)
{
	int	i;
	double	seg_x;
	double	seg_y;
	double	angle_a;
	double	angle_b;
	double	hypo;

	i = 0;
	seg_x = x;
	seg_y = y;
	angle_a = angle - PI;
	angle_b = (PI / 2) - angle_a;
	if (seg_x / cos(angle_a) <= seg_y / cos(angle_b))
	{
		hypo = seg_x / cos(angle_a);
		mlx->player.hit1_x = (int)mlx->player.x;
		mlx->player.hit1_y = (int)mlx->player.y + y - sqrt((hypo * hypo) - seg_x * (seg_x));
		while (mlx->player.hit1_y >= 0 && mlx->player.hit1_x >= 0
		&& ft_check_hit(mlx, 'w' , mlx->player.hit1_x, mlx->player.hit1_y) != '1')
		{
			hypo = (seg_x + i) / cos(angle_a);
			mlx->player.hit1_x = (int)mlx->player.x - i;
			mlx->player.hit1_y = (int)mlx->player.y + y - sqrt((hypo * hypo) - ((seg_x + i) * (seg_x + i)));
			i++;
		}
		i = 0;
		mlx->player.hit2_x = (int)mlx->player.x + x - sqrt(((seg_y / cos(angle_b)) * (seg_y / cos(angle_b))) - (seg_y * seg_y));
		mlx->player.hit2_y = (int)mlx->player.y;
		while (mlx->player.hit2_y >= 0 && mlx->player.hit2_x >= 0
		&& ft_check_hit(mlx, 'n' , mlx->player.hit2_x, mlx->player.hit2_y) != '1')
		{
			mlx->player.hit2_x = (int)mlx->player.x + x - sqrt((((seg_y + i) / cos(angle_b)) * ((seg_y + i) / cos(angle_b))) - ((seg_y + i) * (seg_y + i)));
			mlx->player.hit2_y = (int)mlx->player.y - i;
			i++;
		}
	}
	else if (seg_y / cos(angle_b) <= seg_x / cos(angle_a))
	{
		hypo = seg_y / cos(angle_b);
		mlx->player.hit1_x = (int)mlx->player.x + x - sqrt((hypo * hypo) - (seg_y * seg_y));
		mlx->player.hit1_y = (int)mlx->player.y;
		while (mlx->player.hit1_y >= 0 && mlx->player.hit1_x >= 0
		&& ft_check_hit(mlx, 'n' , mlx->player.hit1_x, mlx->player.hit1_y) != '1')
		{
			hypo = (seg_y + i) / cos(angle_b);
			mlx->player.hit1_x = (int)mlx->player.x + x - sqrt((hypo * hypo) - ((seg_y + i) * (seg_y + i)));
			mlx->player.hit1_y = (int)mlx->player.y - i;
			i++;
		}
		i = 0;
		mlx->player.hit2_x = (int)mlx->player.x;
		mlx->player.hit2_y = (int) mlx->player.y + y - sqrt(((seg_x / cos(angle_a)) * (seg_x / cos(angle_a))) - (seg_x * seg_x));
		while (mlx->player.hit2_y >= 0 && mlx->player.hit2_x >= 0
		&& ft_check_hit(mlx, 'w' , mlx->player.hit2_x, mlx->player.hit2_y) != '1')
		{
			mlx->player.hit2_x = (int)mlx->player.x - i;
			mlx->player.hit2_y = (int) mlx->player.y + y - sqrt((((seg_x + i) / cos(angle_a)) * ((seg_x + i) / cos(angle_a))) - ((seg_x + i) * (seg_x + i)));
			i++;
		}
	}
	return (hypo);
}

double	ft_ne(t_mlx *mlx, double x, double y, double angle)
{
	int	i;
	double	seg_x;
	double	seg_y;
	double	angle_a;
	double	angle_b;
	double	hypo;

	i = 0;
	seg_x = 1 - x;
	seg_y = y;
	angle_a = (2 * PI) - angle;
	angle_b = (PI / 2) - angle_a;
	if (seg_x / cos(angle_a) <= seg_y / cos(angle_b))
	{
		hypo = seg_x / cos(angle_a);
		mlx->player.hit1_x = (int)mlx->player.x + 1;
		mlx->player.hit1_y = (int)mlx->player.y + y - sqrt((hypo * hypo) - (seg_x * seg_x));
		while (mlx->player.hit1_y >= 0 && mlx->player.hit1_x <= 10
		&& ft_check_hit(mlx, 'e' , mlx->player.hit1_x, mlx->player.hit1_y) != '1')
		{
			hypo = (seg_x + i) / cos(angle_a);
			mlx->player.hit1_x = (int)mlx->player.x + 1 + i;
			mlx->player.hit1_y = (int)mlx->player.y + y - sqrt((hypo * hypo) - ((seg_x + i) * (seg_x + i)));
			i++;
		}
		i = 0;
		mlx->player.hit2_x = (int)mlx->player.x + x + sqrt(((seg_y / cos(angle_b)) * (seg_y / cos(angle_b))) - (seg_y * seg_y));
		mlx->player.hit2_y = (int)mlx->player.y;
		while (mlx->player.hit2_y >= 0 && mlx->player.hit2_x <= 10
		&& ft_check_hit(mlx, 'n' , mlx->player.hit2_x, mlx->player.hit2_y) != '1')
		{
			mlx->player.hit2_x = (int)mlx->player.x + x + sqrt((((seg_y + i) / cos(angle_b)) * ((seg_y + i) / cos(angle_b))) - ((seg_y + i) * (seg_y + i)));
			mlx->player.hit2_y = (int)mlx->player.y - i;
			i++;
		}
	}
	else if (seg_y / cos(angle_b) <= seg_x / cos(angle_a))
	{
		hypo = seg_y / cos(angle_b);
		mlx->player.hit1_x = (int)mlx->player.x + x + sqrt((hypo * hypo) - (seg_y * seg_y));
		mlx->player.hit1_y = (int)mlx->player.y;
		while (mlx->player.hit1_y >= 0 && mlx->player.hit1_x <= 10
		&& ft_check_hit(mlx, 'n' , mlx->player.hit1_x, mlx->player.hit1_y) != '1')
		{
			hypo = (seg_y + i) / cos(angle_b);
			mlx->player.hit1_x = (int)mlx->player.x + x + sqrt((hypo * hypo) - ((seg_y + i) * (seg_y + i)));
			mlx->player.hit1_y = (int)mlx->player.y - i;
			i++;
		}
		i = 0;
		mlx->player.hit2_x = (int)mlx->player.x + 1;
		mlx->player.hit2_y = (int)mlx->player.y + y - sqrt(((seg_x / cos(angle_a)) * (seg_x / cos(angle_a))) - (seg_x * seg_x));
		while (mlx->player.hit2_y >= 0 && mlx->player.hit2_x <= 10
		&& ft_check_hit(mlx, 'e' , mlx->player.hit2_x, mlx->player.hit2_y) != '1')
		{
			mlx->player.hit2_x = (int)mlx->player.x + 1 + i;
			mlx->player.hit2_y = (int)mlx->player.y + y - sqrt((((seg_x + i) / cos(angle_a)) * ((seg_x + i) / cos(angle_a))) - ((seg_x + i) * (seg_x + i)));
			i++;
		}
	}
	return (hypo);
}

char	ft_check_hit(t_mlx *mlx, char hit, double x, double y)
{
	if (hit == 'e')
		return (mlx->map.grid[(unsigned int)y][(unsigned int)x]);
	else if (hit == 's')
		return (mlx->map.grid[(unsigned int)y][(unsigned int)x]);
	else if (hit == 'w')
		return (mlx->map.grid[(unsigned int)y][(unsigned int)(x - 1)]);
	else if (hit == 'n')
		return (mlx->map.grid[(unsigned int)(y - 1)][(unsigned int)x]);
	return ('1');
}	
