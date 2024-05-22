/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:14:34 by xxxx              #+#    #+#             */
/*   Updated: 2024/05/21 22:08:49 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**recursive_split(char *str, char *delimiter, t_esc_seq *esc_seq, int str_count);
static bool	is_split(char c, char *delimiter, t_esc_seq *esc_seq);
static bool	format_commands(char **commands);

char	**split_command(char *command)
{
	char		**commands;
	t_esc_seq	esc_seq;
	int			index;

	esc_seq = (t_esc_seq){false, false, false};
	commands = recursive_split(command, "\n\t\v\f\r ", &esc_seq, 0);
	if (!commands)
		return (NULL);
	if (!format_commands(commands))
	{
		index = 0;
		while (commands[index])
			free(commands[index++]);
		free(commands);
		return (NULL);
	}
	return (commands);
}


static char	**recursive_split(char *str, char *delimiter, t_esc_seq *esc_seq, int str_count)
{
	int			len;
	char		*command;
	char		**commands;

	while (*str && is_split(*str, delimiter, esc_seq))
		str++;
	len = 1;
	while (*str && str[len] && !is_split(str[len], delimiter, esc_seq))
		len++;
	if (*str)
	{
		command = ft_substr(str, 0, len);
		if (!command)
			return (NULL);
		commands = recursive_split(str + len, delimiter, esc_seq, str_count + 1);
		if (!commands)
		{
			free(command);
			return (NULL);
		}
		commands[str_count] = command;
	}
	else
	{
		commands = (char **)malloc((str_count + 1) * sizeof(char *));
		if (!commands)
			return (NULL);
		commands[str_count] = NULL;
	}
	return (commands);
}

bool	is_split(char c, char *delimiter, t_esc_seq *esc_seq)
{
	if (ft_strchr(delimiter, c) && !(esc_seq->single_quote) && !(esc_seq->double_quote) && !(esc_seq->backslash))
		return (true);
	if (c == '\\')
		esc_seq->backslash = !(esc_seq->backslash);
	else 
	{
		if (c == '\'')
		{
			if (esc_seq->single_quote)
				esc_seq->single_quote = false;
			else
				if (!(esc_seq->double_quote) && !(esc_seq->backslash))
					esc_seq->single_quote = true;
		}
		else if (c == '\"')
		{
			if (!(esc_seq->backslash))
			{
				if (esc_seq->double_quote)
					esc_seq->double_quote = false;
				else
					if (!(esc_seq->single_quote))
						esc_seq->double_quote = true;
			}
		}
		esc_seq->backslash = false;
	}
	return (false);
}

static bool	format_commands(char **commands)
{
	t_esc_seq	esc_seq;
	t_esc_seq	esc_seq_tmp;
	char		*command;
	int			index;	

	while (*commands)
	{
		esc_seq = (t_esc_seq){false, false, false};
		index = 0;
		while ((*commands)[index])
		{
			esc_seq_tmp = esc_seq;
			(void)is_split((*commands)[index], "", &esc_seq);
			if (esc_seq.backslash
				|| esc_seq_tmp.single_quote != esc_seq.single_quote
				|| esc_seq_tmp.double_quote != esc_seq.double_quote)
				ft_memmove(*commands + index, *commands + index + 1, ft_strlen(*commands + index));
			else
				index++;
		}
		command = ft_strdup(*commands);
		if (!command)
			return (false);
		free(*commands);
		*commands = command;
		if (esc_seq.backslash || esc_seq.single_quote || esc_seq.double_quote)
			return (false);
		commands++;
	}
	return (true);
}
