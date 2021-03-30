/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:24:46 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/30 17:35:42 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_init(void)
{
	g_check.r = 0;
	g_check.no = 0;
	g_check.so = 0;
	g_check.we = 0;
	g_check.ea = 0;
	g_check.s = 0;
	g_check.f = 0;
	g_check.c = 0;
	g_check.mp = 0;	
}

void	ref_init(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	g_p.reference[0] = ' ';
	g_p.reference[1] = '0';
	g_p.reference[2] = '1';
	g_p.reference[3] = '2';
	g_p.reference[4] = 'N';
	g_p.reference[5] = 'S';
	g_p.reference[6] = 'E';
	g_p.reference[7] = 'W';
	g_p.map_h = -1;
	g_p.spawn = 0;
}

void	struct_init(void)
{
	g_p.res_w = 0;
	g_p.res_h = 0;
	g_p.n_wall[0] = -1;
	g_p.n_wall[1] = -1;
	g_p.n_wall[2] = -1;
	g_p.s_wall[0] = -1;
	g_p.s_wall[1] = -1;
	g_p.s_wall[2] = -1;
	g_p.w_wall[0] = -1;
	g_p.w_wall[1] = -1;
	g_p.w_wall[2] = -1;
	g_p.e_wall[0] = -1;
	g_p.e_wall[1] = -1;
	g_p.e_wall[2] = -1;
	g_p.sky[0] = -1;
	g_p.sky[1] = -1;
	g_p.sky[2] = -1;
	g_p.floor[0] = -1;
	g_p.floor[1] = -1;
	g_p.floor[2] = -1;
	g_p.ceiling[0] = -1;
	g_p.ceiling[1] = -1;
	g_p.ceiling[2] = -1;
	ref_init();
	check_init();
}

int	main(int argc, char **argv)
{
	char	*line;
	int		fd_map;
	int		ret;

	if (argc != 2 && argc != 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	fd_map = open(argv[1], O_RDONLY);
	struct_init();
	while ((ret = get_next_line(fd_map, &line)) == 1)
	{
		if (parse_line(line) == -1 || ret == -1)
			return (-1);
	}

	return (0);
}