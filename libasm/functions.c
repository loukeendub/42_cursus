/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crossi <crossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:37:11 by crossi            #+#    #+#             */
/*   Updated: 2021/03/18 14:49:44 by crossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "main.h"

char		*rot13(char *s)
{
	char	*s1;
	int		i;

	i = 0;
	s1 = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	while (s[i])
	{
		if (s[i] >= 65 && s[i] <= 90)
		{
			if (s[i] + 13 >= 90)
				s1[i] = s[i] - 13;
			else
				s1[i] = s[i] + 13;
		}
		if (s[i] >= 97 && s[i] <= 122)
		{
			if (s1[i] + 13 >= 122)
				s1[i] = s[i] - 13;
			else
				s1[i] += 13;
		}
		i++;
	}
	s1[i] = 0;
	return (s1);
}

void		simple_test(char *str)
{
	if (!str)
		str = ft_strdup("Hey!, i'm a made up test string");
	test_strlen(str);
	test_strcmp(str);
	test_strcpy(str);
	test_write(str);
	test_read();
	test_strdup(str);
}

void		test_read(void)
{
	char	*buff;
	int		i;

	i = 0;
	if (!(buff = malloc(2 * sizeof(char))))
	{
		printf("Oops! Something went wrong during allocation! Try again!");
		exit(EXIT_FAILURE);
	}
	printf(YEL"\n#------  ft_read  ------#\n\n"GRN);
	printf("Now I'll guess what you wrote on the stdin, go on, i won't look\n");
	ft_write(1, WHT, ft_strlen(WHT));
	while ((ft_read(0, &(buff[i]), 1)) > 0)
	{
		if (buff[i] == '\n')
		{
			buff[i] = 0;
			break ;
		}
		i++;
		buff = realloc(buff, i + 1);
	}
	printf(GRN"Let's see, i think you wrote\n"WHT
					"%s\n"GRN"was i right?\n", buff);
	free(buff);
}

void		test_write(char *str)
{
	int	fd;

	printf(YEL"\n#------ ft_write ------#\n\n");
	ft_write(1, WHT, ft_strlen(WHT));
	ft_write(1, "writing with ft_write! (on stdin)\n",
						ft_strlen("writing with ft_write! (on stdin)\n"));
	ft_write(2, "writing with ft_write! (on stderr)\n",
						ft_strlen("writing with ft_write! (on stderr)\n"));
	if ((fd = open("ft_write.res", O_CREAT | O_RDWR | O_TRUNC, 0666)) < 0)
	{
		printf("Oops! Something went wrong during "
				"file opening/creating! Try again!");
		exit(EXIT_FAILURE);
	}
	write(fd, str, ft_strlen(str));
}
