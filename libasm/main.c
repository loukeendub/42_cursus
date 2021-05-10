/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:06:19 by lmarzano          #+#    #+#             */
/*   Updated: 2021/05/10 14:31:07 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "main.h"

void		test_strdup(char *str)
{
	char	*str2;

	printf(YEL"\n#------ ft_strdup ------#\n\n");
	printf(GRN"I mean, strdup was used in every test here, so...\n");
	printf("Anyway, here's another test:\n\n"WHT);
	str2 = ft_strdup(str);
	printf(RED"Original string:\t"WHT"%s (len: %zu)\n", str, ft_strlen(str));
	printf(RED"Strdup string:\t\t"WHT"%s (len: %zu)\n", str2, ft_strlen(str2));
	printf("\n");
	free(str2);
}

void		test_strcpy(char *str)
{
	char *str2;

	if (!(str2 = (char *)malloc(ft_strlen(str))))
	{
		printf("Oops! Something went wrong during allocation! Try again!");
		exit(EXIT_FAILURE);
	}
	str2 = ft_strcpy(str2, str);
	printf(YEL"\n#------ ft_strcpy ------#\n\n");
	printf(RED"Original string:\t"WHT"%s (len: %zu)\n", str, ft_strlen(str));
	printf(RED"String copy:\t\t"WHT"%s (len: %zu)\n", str2, ft_strlen(str2));
	printf(GRN"\n#------ comparing ------#\n\n");
	printf(CYN"str1: %s; str2: %s\n compare: %d\n", str,
								str2, strcmp(str, str2));
	printf(MAG"str1: %s; str2: %s\n compare: %d\n\n", str,
								str2, ft_strcmp(str, str2));
}

void		test_strcmp(char *str)
{
	char	*str2;
	int		i;

	i = 0;
	str2 = NULL;
	printf(YEL"\n#------ ft_strcmp ------#\n\n");
	while (i < 3)
	{
		if (i == 0)
			str2 = ft_strdup("");
		else if (i == 1)
			str2 = ft_strdup(str);
		else
			str2 = ft_strdup("THE CAKE IS A LIE!");
		printf(CYN"str1: %s; str2: %s\ncompare: %d\n", str,
									str2, strcmp(str, str2));
		printf(MAG"str1: %s; str2: %s\ncompare: %d\n\n", str,
									str2, ft_strcmp(str, str2));
		free(str2);
		str2 = NULL;
		i++;
	}
}

void		test_strlen(char *str)
{
	printf(YEL"\n#------ ft_strlen ------#\n\n");
	printf(CYN"len of %s: %zu\n", str, strlen(str));
	printf(MAG"len of %s: %zu\n\n", str, ft_strlen(str));
}

int			main(int argc, char **argv)
{
	printf(WHT"TESTER FOR DUMMIES:\nNo args: test premade strings\n");
	printf("1 arg: test with argument\n");
	printf("2 args: test of specified function with specified argument\n");
	printf("COLOR CODING:\n"CYN"ORIGINAL FUNCTION\n"MAG"FT FUNCTION\n");
	if (argc == 1)
		simple_test(NULL);
	else if (argc == 2 && !ft_strcmp(argv[1], "read"))
		test_read();
	else if (argc == 2)
		simple_test(argv[1]);
	else if (argc == 3 && !ft_strcmp(argv[1], "strlen"))
		test_strlen(argv[2]);
	else if (argc == 3 && !ft_strcmp(argv[1], "strcmp"))
		test_strcmp(argv[2]);
	else if (argc == 3 && !ft_strcmp(argv[1], "strcpy"))
		test_strcpy(argv[2]);
	else if (argc == 3 && !ft_strcmp(argv[1], "write"))
		test_write(argv[2]);
	else if (argc == 3 && !ft_strcmp(argv[1], "strdup"))
		test_strdup(argv[2]);
	else
		printf(WHT"What?\n");
	return (0);
}
