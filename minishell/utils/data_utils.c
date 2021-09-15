/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:01:23 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/15 18:02:18 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*ft_malloc_data(int size_env, int size_content)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->env = malloc(size_env + 1);
	if (data->env == NULL)
	{
		free(data);
		return (NULL);
	}
	data->content = malloc(size_content + 1);
	if (data->content == NULL)
	{
		free(data->env);
		free(data);
		return (NULL);
	}
	return (data);
}

t_list	*ft_new_datalist(const char *env, const char *content, int id)
{
	t_data	*data;
	t_list	*list;
	int		len_env;
	int		len_content;

	if (content == NULL)
		len_content = 0;
	else
		len_content = ft_strlen(content);
	len_env = ft_strlen(env);
	data = ft_malloc_data(len_env, len_content);
	if (data == NULL)
		return (NULL);
	ft_strlcpy(data->env, env, len_env + 1);
	ft_strlcpy(data->content, content, len_content + 1);
	data->id = id;
	list = ft_lstnew(data);
	if (list == NULL)
		ft_free_data(data);
	return (list);
}

int	ft_data_lst_size(t_list *data_list, int id)
{
	t_data	*data;
	int		ret;

	ret = 0;
	while (data_list)
	{
		data = data_list->content;
		if (data->id == id || id == 2)
			ret++;
		data_list = data_list->next;
	}
	return (ret);
}
