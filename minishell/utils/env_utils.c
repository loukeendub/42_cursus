/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:01:27 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/15 18:02:18 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_add_env(t_list *var, char *dst, char *src, int id)
{
	if (ft_find_env(var, dst, ft_strlen(dst)) == NULL)
	{
		if (ft_create_env(var, dst, src, id) == -1)
			return (-1);
	}
	else
	{
		if (ft_change_env(var, dst, src) == -1)
			return (-1);
	}
	return (1);
}

int	ft_change_env(t_list *list, char *dst, char *src)
{
	t_data	*temp;
	char	*data;
	int		len;
	int		flag;

	flag = 0;
	while (list && flag == 0)
	{
		temp = (t_data *)(list->content);
		if (ft_strncmp(dst, temp->env, ft_strlen(temp->env) + 1) == 0)
		{
			len = ft_strlen(src);
			data = malloc(len + 1);
			if (data == NULL)
				return (-1);
			ft_strlcpy(data, src, len + 1);
			free(temp->content);
			temp->content = data;
			flag = 1;
		}
		list = list->next;
	}
	return (1);
}

char	*ft_find_env(t_list *list, char *env, int len)
{
	char	*temp;

	while (list)
	{
		temp = ((t_data *)(list->content))->env;
		if (ft_strncmp(temp, env, len + 1) == 0)
			return (((t_data *)(list->content))->content);
		list = list->next;
	}
	return (NULL);
}

void	ft_free_listenv(t_list *env)
{
	while (env)
	{
		free(((t_data *)(env->content))->content);
		free(((t_data *)(env->content))->env);
		free(env->content);
		env = env->next;
	}
}

int	ft_create_env(t_list *list, const char *env, const char *content, int id)
{
	t_list	*l;

	l = ft_new_datalist(env, content, id);
	if (l == NULL)
		return (-1);
	ft_lstadd_back(&list, l);
	ft_setprev(&list);
	return (1);
}
