#include "cub3d.h"

int main(int argc, char **argv)//26 lines
{
	t_all	all;
	t_vars	vars;

	vars.time = 0;
	vars.oldTime = 0;
	if (argc != 2 && argc != 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_bzero(&vars, sizeof(t_vars));
	ft_main_parsing(argv[1], &all);
	ft_init_vars(&vars, &all);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.ScreenWidth, vars.ScreenHeight, "cub3D");
	vars.moveSpeed = 0.11;
	vars.rotSpeed = 0.07;
	ft_gettextures(&vars);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_hook(vars.win, 3, 1L<<1, ft_release, &vars);
	mlx_hook(vars.win, 17, 1L<<5, ft_exit, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	puts("entering loop");
	mlx_loop(vars.mlx);
	return (0);
}