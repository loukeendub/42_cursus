#include "minishell.h"

void	ft_write_prompt(char *prompt, char *line)
{
	write(STDOUT_FILENO, "\x1b[2K", 4);
	write(STDOUT_FILENO, "\033[u", 4);
	ft_putstr_fd(prompt, STDOUT_FILENO);
	ft_putstr_fd(line, STDOUT_FILENO);
}

char	*ft_prompt(const char *prompt, t_list **list, struct termios *or_term)
{
	struct termios	new_termios;
	char			*line;

	new_termios = *or_term;
	new_termios.c_lflag &= ~(ECHO | ICANON | ISIG);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &new_termios);
	write(STDOUT_FILENO, "\033[s", 4);
	ft_putstr_fd((char *)prompt, STDOUT_FILENO);
	if (*list != NULL)
		*list = ft_lstlast(*list);
	line = ft_read(prompt, list);
	if (*list != NULL)
		*list = ft_lstfirst(*list);
	if (line && ft_strlen(line) > 0)
		ft_change_history(line, list);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, or_term);
	return (line);
}
