#include "../include/wolf.h"

void	ft_init_texture(t_env *e)
{
  void *parse;

  	if (!(parse = mlx_xpm_file_to_image(e->ptr, "./Textures/wall1h.xpm",
  		&e->w_tex_mur_nord, &e->h_tex_mur_nord)))
  		ft_exit(5);
    if (!(parse = mlx_xpm_file_to_image(e->ptr, "./Textures/wall2h.xpm",
    	&e->w_tex_mur_sud, &e->h_tex_mur_sud)))
    		ft_exit(5);
    if (!(parse = mlx_xpm_file_to_image(e->ptr, "./Textures/wall3h.xpm",
    	&e->w_tex_mur_est, &e->h_tex_mur_est)))
      	ft_exit(5);
    if (!(parse = mlx_xpm_file_to_image(e->ptr, "./Textures/metal.xpm",
      	&e->w_tex_mur_ouest, &e->h_tex_mur_ouest)))
      	ft_exit(5);
}
