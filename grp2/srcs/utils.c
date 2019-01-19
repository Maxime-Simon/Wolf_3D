#include "../include/wolf.h"

int ft_exit(int i)
{
  	if (i == 1)
  	{
  		ft_putstr("Invalid Map\n");
  		exit(0);
  	}
  	if (i == 2)
  	{
  		ft_putstr("usage : ./Wolf3D <filename>\n");
  		exit(0);
  	}
  	if (i == 3)
  	{
  		ft_putstr("Esc Pressed\n");
  		exit(0);
  	}
  	if (i == 4)
  	{
  		ft_putstr("Invalid Fd\n");
  		exit(0);
  	}
    if (i == 5)
  	{
  		ft_putstr("Texture error\n");
  		exit(0);
  	}
    else
      ft_putstr("Texture Failed\n");
      exit(0);
}

int  ft_click_exit(void)
{
  ft_putstr("Red Cross\n");
  exit(0);
}

void  ft_pixel_to_image(t_env *e, int x, int y, int color)
{
	int			color1;
	int			color2;
	int			color3;
	int			bit_pix;
	double		img_size;

	img_size = e->win_x * e->win_y * e->bpp / 8;
	if (x < 0 || y < 0 || y * e->size_line + x * e->bpp / 8 > \
		img_size
		|| x >= e->size_line / (e->bpp / 8) || y >= img_size / \
		e->size_line)
		return ;
	color1 = color;
	color2 = color >> 8;
	color3 = color >> 16;
	bit_pix = e->bpp / 8;
	e->addr[y * e->size_line + x * bit_pix] = color1;
	e->addr[y * e->size_line + x * bit_pix + 1] = color2;
	e->addr[y * e->size_line + x * bit_pix + 2] = color3;
}

int		rgb_to_hexa(int r, int g, int b)
{
	return ((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF);
}
