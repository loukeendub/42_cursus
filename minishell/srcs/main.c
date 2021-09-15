#include "minishell.h"

static int	ft_create_list_env(char *env[], t_list	**var)
{
	int		i;
	char	**matrix;
	t_list	*list;

	i = 0;
	while (env[i])
	{
		matrix = ft_split(env[i], '=');
		if (matrix == NULL)
			return (-1);
		list = ft_new_datalist(matrix[0], matrix[1], 0);
		if (list == 0)
		{
			ft_free_listenv(list);
			return (-1);
		}
		ft_lstadd_back(var, list);
		ft_free_matrix(matrix);
		i++;
	}
	ft_setprev(var);
	return (1);
}

int	ft_execute(t_parse *parse, t_list *list, t_list *var)
{
	int	num;

	if (parse == NULL)
		return (1);
	if (ft_strncmp(parse->command, "echo", 5) == 0)
		num = ft_check_echo(parse);
	else if (ft_strncmp(parse->command, "pwd", 4) == 0)
		num = ft_check_pwd(parse, var);
	else if (ft_strncmp(parse->command, "cd", 3) == 0)
		num = ft_check_cd(parse, var);
	else if (ft_strncmp(parse->command, "exit", 5) == 0)
		num = ft_check_exit(parse, list, var);
	else if (ft_strncmp(parse->command, "export", 7) == 0)
		num = ft_check_export(parse, var);
	else if (ft_strncmp(parse->command, "env", 4) == 0)
		num = ft_check_env(parse, var);
	else if (ft_strncmp(parse->command, "unset", 4) == 0)
		num = ft_check_unset(parse, var);
	else
		num = ft_execute_command(parse, var);
	return (num);
}

static int	ft_go(t_list *parse_list, t_list *history, t_list *var)
{
	int		num;
	int		fd[2];
	t_parse	*data;

	num = 0;
	if (parse_list && parse_list->next)
	{
		data = ((t_parse *)(parse_list->next)->content);
		num = ft_exec_pipe(parse_list->content, data, history, var);
		if (num == -1)
			return (num);
		return (ft_go(parse_list->next, history, var));
	}
	else if (parse_list)
	{
		if (parse_list->content == NULL || \
		ft_open_red(((t_parse *)(parse_list->content))->output, \
		&fd[0], &fd[1], history) == -1)
			return (258);
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		num = ft_execute(parse_list->content, history, var);
	}
	return (num);
}

static int	ft_run(char *line, t_list *history, t_list *var)
{
	t_list	*parse_list;
	int		num;
	char	*c_num;
	int		fd[2];

	num = 0;
	line = ft_expand(line, var);
	parse_list = ft_list_parse(line);
	free(line);
	ft_save_fd(&fd[0], &fd[1]);
	num = ft_go(parse_list, history, var);
	c_num = ft_itoa(num);
	ft_add_env(var, "?", c_num, 1);
	ft_restore_fd(fd);
	ft_free_parse_list(parse_list);
	free(c_num);
	return (num);
}

int	main(int argc, char *argv[], char *env[])
{
	char			*line;
	t_list			*var;
	t_list			*list;
	struct termios	origin;

	signal(SIGINT, ft_aspetta);
	signal(SIGQUIT, ft_aspetta);
	tcgetattr(STDIN_FILENO, &origin);
	list = NULL;
	if (argc < 0 || argv == NULL)
		ft_error(15, 0, NULL);
	var = NULL;
	if (ft_create_list_env(env, &var) == -1)
		ft_error(16, 0, NULL);
	if (ft_file_history(&list, var) == -1)
		ft_error(17, 0, NULL);
	while (1)
	{
		line = ft_prompt("#mini_hell: ", &list, &origin);
		ft_run(line, list, var);
	}
}
