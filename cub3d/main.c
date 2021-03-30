/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:24:46 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/30 19:45:02 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_init(void)
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

void	ft_ref_init(void)
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

void	ft_struct_init(void)
{
	g_p.res_w = 0;
	g_p.res_h = 0;
	g_p.sky[0] = -1;
	g_p.sky[1] = -1;
	g_p.sky[2] = -1;
	g_p.floor[0] = -1;
	g_p.floor[1] = -1;
	g_p.floor[2] = -1;
	g_p.ceiling[0] = -1;
	g_p.ceiling[1] = -1;
	g_p.ceiling[2] = -1;
	g_p.sprite = 0;
	ft_ref_init();
	ft_check_init();
}

int	main(int argc, char **argv)
{
	char	*line;
	int		fd_map;
	int		ret = 0;

	if (argc != 2 && argc != 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	fd_map = open(argv[1], O_RDONLY);
	ft_struct_init();
	while ((ret = get_next_line(fd_map, &line)) == 1)
	{
		if (ft_parse_line(line) == -1 || ret == -1)
			{
				puts("Fuck yea");
				return (-1);
			}
	}
	free(line);
	printf("|W : %d|\n|H : %d|\n", g_p.res_w, g_p.res_h);
	printf("|NO : |%s|\n|SO : |%s|\n|WE : |%s|\n|EA : |%s|\n|S : |%s|\n", g_p.wall[0], g_p.wall[1], g_p.wall[2], g_p.wall[3], g_p.sprite);
	return (0);
}