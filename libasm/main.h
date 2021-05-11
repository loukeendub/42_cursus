/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:16:12 by lmarzano          #+#    #+#             */
/*   Updated: 2021/05/11 10:48:40 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# define BLK "\e[0;30m"
# define RED "\e[1;31m"
# define GRN "\e[0;32m"
# define YEL "\e[1;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"
# define NRM "\e[0;0m"

void		simple_test(char *str);
void		test_read(void);
void		test_write(char *str);
void		test_strdup(char *str);
void		test_strcpy(char *str);
void		test_strcmp(char *str);
void		test_strlen(char *str);

#endif
