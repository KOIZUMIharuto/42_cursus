/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:14:34 by xxxx              #+#    #+#             */
/*   Updated: 2024/07/03 15:48:58 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**recursive_split(char *str, char *del, t_esc *esc, int cmd_count);
static bool	is_split(char c, char *del, t_esc *esc);
static bool	format_commands(char **commands);

char	**split_command(char *command)
{
	char	**commands;
	t_esc	esc;

	esc = (t_esc){false, false, false};
	commands = recursive_split(command, "\n\t\v\f\r ", &esc, 0);
	if (!commands)
		return (NULL);
	if (!format_commands(commands))
		return (free_commands(commands, 0));
	return (commands);
}


static char	**recursive_split(char *str, char *del, t_esc *esc, int cmd_count)
{
	int		len;
	char	**commands;

	while (*str && is_split(*str, del, esc))
		str++;
	len = 1;
	while (*str && str[len] && !is_split(str[len], del, esc))
		len++;
	if (*str)
		commands = recursive_split(str + len, del, esc, cmd_count + 1);
	else
		commands = (char **)ft_calloc((cmd_count + 1),  sizeof(char *));
	if (!commands)
		return (NULL);
	if (*str)
	{
		commands[cmd_count] = ft_substr(str, 0, len);
		if (!commands[cmd_count])
			return (free_commands(commands, cmd_count + 1));
	}
	else
		commands[cmd_count] = NULL;
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
