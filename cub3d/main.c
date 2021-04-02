/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:24:46 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/02 12:50:10 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)// 29 lines
{
	t_all	all;
	char	*line;
	int		fd_map;
	int		ret = 0;

	if (argc != 2 && argc != 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	fd_map = open(argv[1], O_RDONLY);

	//fd_map = open("map.cub", O_RDONLY);

	ft_str_all_init(&all);
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd_map, &line);
		if (ft_parse_line(line, fd_map, &all) == -1 || ret == -1)
		{
			//puts("Fuck yea");
			write(1, "Error\n", 6);
			return (-1);
		}
	}
	if (!check_val(&all))
		{
			//puts("invalid number");
			write(1, "Error\n", 6);
		}

	free(line);
	/*---DEBUG---*/
	//printf("ERR : %d\n", all.chr->no);
	printf("|W : %d|\n|H : %d|\n", all.par->res_w, all.par->res_h);
	printf("|NO : |%s|\n|SO : |%s|\n|WE : |%s|\n|EA : |%s|\n|S : |%s|\n", all.par->wall[0], all.par->wall[1], all.par->wall[2], all.par->wall[3], all.par->sprite);
	//int i = 0;
	printf("|C : |%d| |%d| |%d|\n", all.par->ceiling[0], all.par->ceiling[1], all.par->ceiling[2]);
	printf("|F : |%d| |%d| |%d|\n", all.par->floor[0], all.par->floor[1], all.par->floor[2]);
	//while (all.par->map[i])
	//	puts(all.par->map[i++]);
	/*---end of debug---*/
	return (0);
}