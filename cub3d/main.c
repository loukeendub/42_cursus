/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:24:46 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/01 10:58:03 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)// 29 lines
{
	t_all	all;
	char	*line;
	int		fd_map;
	int		ret = 0;

	//if (argc != 2 && argc != 3)
	//{
	//	write(1, "Error\n", 6);
	//	return (0);
	//}
	fd_map = open("map.cub", O_RDONLY);
	ft_str_all_init(&all);
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd_map, &line);
		if (ft_parse_line(line, fd_map, &all) == -1 || ret == -1)
		{
			puts("Fuck yea");
			return (-1);
		}
	}
	if (all.chr->r != 1 || all.chr->no != 1 || all.chr->so != 1 || all.chr->we != 1\
	|| all.chr->ea != 1 || all.chr->s != 1 || all.chr->f != 1 || all.chr->c != 1 || all.chr->mp != 1) 
	{
		puts("manca qualcosa stronzo");
		return (0);
	}
	free(line);
	/*---DEBUG---*/
	printf("ERR : %d\n", all.chr->no);
	printf("|W : %d|\n|H : %d|\n", all.par->res_w, all.par->res_h);
	printf("|NO : |%s|\n|SO : |%s|\n|WE : |%s|\n|EA : |%s|\n|S : |%s|\n", all.par->wall[0], all.par->wall[1], all.par->wall[2], all.par->wall[3], all.par->sprite);
	/*---end of debug---*/
	return (0);
}