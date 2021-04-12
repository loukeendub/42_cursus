/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:18:01 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/12 11:18:05 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCUB_BONUS_H
# define LIBCUB_BONUS_H
# include "../libcub.h"

/*
**Minimap
*/

void			minimap_img(t_data *img, t_window *window, t_player *player,
					int min_fract);
void			mouse_rot(t_window *window);
void			player_movement_b(t_keys *keys, t_player *player, char **map);

#endif
