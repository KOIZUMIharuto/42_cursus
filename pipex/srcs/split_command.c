/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxx <xxxx@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:14:34 by xxxx              #+#    #+#             */
/*   Updated: 2024/06/25 13:33:02 by xxxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**recursive_split(char *str, char *del, t_esc *esc, int str_count);
static bool	is_split(char c, char *del, t_esc *esc);
static bool	format_commands(char **commands);

char	**split_command(char *command)
{
	char	**commands;
	t_esc	esc;
	int		index;

	esc = (t_esc){false, false, false};
	commands = recursive_split(command, "\n\t\v\f\r ", &esc, 0);
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


static char	**recursive_split(char *str, char *del, t_esc *esc, int str_count)
{
	int		len;
	// char	*command;
	char	**commands;

	while (*str && is_split(*str, del, esc))
		str++;
	len = 1;
	while (*str && str[len] && !is_split(str[len], del, esc))
		len++;
	// command = NULL;
	if (*str)
		commands = recursive_split(str + len, del, esc, str_count + 1);
	else
		commands = (char **)malloc((str_count + 1) * sizeof(char *));
	if (!commands)
		return (NULL);
	if (*str)
	{
		commands[str_count] = ft_substr(str, 0, len);
		if (!commands[str_count])
			return (NULL);
	}
	else
		commands[str_count] = NULL;
	return (commands);
}

bool	is_split(char c, char *del, t_esc *esc)
{
	if (ft_strchr(del, c) && !(esc->single_q || esc->double_q || esc->bacl_s))
		return (true);
	if (c == '\\')
		esc->bacl_s = !(esc->bacl_s);
	else
	{
		if (c == '\'')
			esc->single_q = !(esc->single_q || esc->double_q || esc->bacl_s);
		else if (c == '\"')
			if (!esc->bacl_s)
				esc->double_q = !(esc->double_q || esc->single_q);
		esc->bacl_s = false;
	}
	return (false);
}

static bool	format_commands(char **commands)
{
	t_esc	esc;
	t_esc	esc_tmp;
	int		index;

	while (*commands)
	{
		esc = (t_esc){false, false, false};
		index = 0;
		while ((*commands)[index])
		{
			esc_tmp = esc;
			(void)is_split((*commands)[index], "", &esc);
			if (esc.bacl_s || esc_tmp.single_q != esc.single_q
				|| esc_tmp.double_q != esc.double_q)
				ft_memmove(&((*commands)[index]), &((*commands)[index + 1]),
					ft_strlen(&((*commands)[index])));
			else
				index++;
		}
		if (esc.bacl_s || esc.single_q || esc.double_q)
			return (false);
		commands++;
	}
	return (true);
}
