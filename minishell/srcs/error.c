#include "minishell.h"

static int	ft_error_20(int id)
{
	if (id == 15)
		ft_putstr_fd("#: argv and argc error\n", 2);
	if (id == 16)
		ft_putstr_fd("#: fail to create env's list\n", 2);
	if (id == 17)
		ft_putstr_fd("#: error with history file\n", 2);
	return (-1);
}

static int	ft_error_15(int id, char *str)
{
	if (id == 10)
	{
		ft_putstr_fd("#: syntax error near unexpected token `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("'\n", 2);
	}
	return (-1);
}

static int	ft_error_10(int id, char *str)
{
	if (id == 5)
	{
		ft_putstr_fd("#: cd: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if (id == 6)
	{
		ft_putstr_fd("#: export: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(" : not a valid identifier\n", 2);
	}
	else if (id == 7)
		ft_putstr_fd("#: cd: OLDPWD not set\n", 2);
	else if (id == 8)
		ft_putstr_fd("#: cd: HOME not set\n", 2);
	return (-1);
}

static int	ft_error_5(int id, char c)
{
	if (id == 1)
	{
		ft_putstr_fd("#: syntax error near unexpected token `", 2);
		ft_putchar_fd(c, 2);
		ft_putstr_fd("'\n", 2);
	}
	else if (id == 2)
	{
		ft_putstr_fd("#: ", 2);
		ft_putchar_fd(c, 2);
		ft_putstr_fd(": Is a directory\n", 2);
	}
	else if (id == 3)
		ft_putstr_fd("#: syntax error near unexpected token `newline'\n", 2);
	return (-1);
}

int	ft_error(int id, char c, char *str)
{
	int	num;

	num = 0;
	if (id < 5)
		num = ft_error_5(id, c);
	if (id >= 5 && id < 10)
		num = ft_error_10(id, str);
	if (id >= 10 && id < 15)
		num = ft_error_15(id, str);
	if (id >= 15 && id < 20)
		num = ft_error_20(id);
	return (num);
}
