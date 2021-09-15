#include "minishell.h"

static char	*ft_add_path(char *start, char *add)
{
	char	*temp;
	char	*path;

	temp = ft_strjoin("/", add);
	if (temp == NULL)
		return (NULL);
	path = ft_strjoin(start, temp);
	if (path == NULL)
	{
		free(temp);
		return (NULL);
	}
	free(temp);
	return (path);
}

static char	*ft_sub_path(char *start)
{
	char	*temp;
	char	*path;
	int		len1;
	int		len2;

	temp = ft_strrchr(start, '/');
	if (temp == start)
		len2 = 1;
	else
	{
		len1 = ft_strlen(temp);
		len2 = ft_strlen(start) - len1;
	}
	path = malloc(len2 + 1);
	if (path == NULL)
		return (NULL);
	ft_strlcpy(path, start, len2 + 1);
	return (path);
}

char	*ft_create_path(t_list *list, char *str)
{
	char	*temp;
	char	*path;
	char	**matrix;
	int		i;

	i = 0;
	temp = ft_get_pwd();
	matrix = ft_split(str, '/');
	if (matrix == NULL)
		return (NULL);
	path = malloc(ft_strlen(temp) + 1);
	ft_strlcpy(path, temp, ft_strlen(temp) + 1);
	free(temp);
	while (path && matrix && matrix[i])
	{
		temp = path;
		if (ft_strncmp(matrix[i], "..", 3) == 0)
			path = ft_sub_path(path);
		else
			path = ft_add_path(path, matrix[i]);
		free(temp);
		i++;
	}
	ft_free_matrix(matrix);
	return (path);
}

char	*ft_create_minus_path(t_list *list)
{
	int		len;
	char	*l;
	char	*path;

	l = ft_find_env(list, "OLDPWD", 6);
	if (l == NULL)
	{
		ft_error(7, 0, NULL);
		return (NULL);
	}
	len = ft_strlen(l);
	path = malloc(len + 1);
	if (path == NULL)
		return (NULL);
	ft_strlcpy(path, ft_find_env(list, "OLDPWD", 6), len + 1);
	return (path);
}

char	*ft_create_home_path(t_list *list)
{
	int		len;
	char	*path;
	char	*home;

	home = ft_find_env(list, "HOME", 4);
	if (home == NULL)
	{
		ft_error(8, 0, "HOME");
		return (NULL);
	}
	len = ft_strlen(home);
	path = malloc(len + 1);
	if (path == NULL)
		return (NULL);
	ft_strlcpy(path, home, len + 1);
	return (path);
}
