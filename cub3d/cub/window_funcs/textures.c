/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:34:23 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/12 13:21:58 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

void	texture_filler(t_texture *texture, t_window *window, char *text_name)
{
	texture->img = mlx_xpm_file_to_image(window->mlx, text_name,
			&texture->img_w, &texture->img_h);
	texture->addr = (int *)mlx_get_data_addr(texture->img,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
}

void	textures_filler(t_window *window)
{
	t_game	*game;

	game = window->game;
	texture_filler(window->textures->n_texture, window, game->no_texture);
	texture_filler(window->textures->s_textture, window, game->so_texture);
	texture_filler(window->textures->w_texture, window, game->we_texture);
	texture_filler(window->textures->e_texture, window, game->ea_texture);
	texture_filler(window->textures->sprite_texture, window,
					game->sprite_texture);
	if (window->game->skybox)
		texture_filler(window->textures->skybox, window, game->skybox);
}
