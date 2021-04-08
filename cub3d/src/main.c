#include "cub3d.h"

int main(int argc, char **argv)//26 lines
{
	t_all	all;
	t_vars	vars;

	vars.time = 0;
	vars.oldTime = 0;
	if (argc != 2 && argc != 3)
	{
		write(2, "Error\n", 6);
		ft_exit(&vars, &all);
	}
	ft_bzero(&vars, sizeof(t_vars));
	ft_main_parsing(argv[1], &all, &vars);
	/*---DEBUG---*/
	//printf("no : |%d|\nso : |%d|\nwe : |%d|\nea : |%d|\nr : |%d|\ns : |%d|\nf : |%d|\nc : |%d|\nmp : |%d|\n", all->chr->no, all->chr->so, all->chr->we, all->chr->ea, all->chr->r, all->chr->s, all->chr->f, all->chr->c, all->chr->mp);
	//printf("|W : %d|\n|H : %d|\n", all->par->res_w, all->par->res_h);
	//printf("|NO : |%s|\n|SO : |%s|\n|WE : |%s|\n|EA : |%s|\n|S : |%s|\n", all->par->wall[0], all->par->wall[1], all->par->wall[2], all->par->wall[3], all->par->sfc[0]);
	//int i = 0;
	//printf("|C : |%d| |%d| |%d|\n", all->par->ceiling[0], all->par->ceiling[1], all->par->ceiling[2]);
	//printf("|F : |%d| |%d| |%d|\n", all->par->floor[0], all->par->floor[1], all->par->floor[2]);
	//while (all->par->map[i])
	//	puts(all->par->map[i++]);
	/*---end of debug---*/
	ft_init_vars(&vars, &all);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.ScreenWidth, vars.ScreenHeight, "cub3D");
	vars.moveSpeed = 0.11;
	vars.rotSpeed = 0.07;
	if (!(ft_gettextures(&vars)))
	{
		write(2, "Error\n", 6);
		ft_exit(&vars, &all);
	}
	//mlx_put_image_to_window(vars.mlx, vars.win, all.data->img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_hook(vars.win, 3, 1L<<1, ft_release, &vars);
	mlx_hook(vars.win, 17, 1L<<5, ft_exit, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	puts("entering loop");
	mlx_loop(vars.mlx);
	return (0);
}