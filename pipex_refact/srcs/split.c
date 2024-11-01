/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:50:17 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/10/30 15:03:25 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static char	**recursive_split(char *str, char *del, t_esc *esc, int cmd_count);
static bool	is_split(char c, char *del, t_esc *esc);
static bool	cut_str(char **cmds, int cmd_count, char *str, int len);
static bool	format_cmds(char **cmds);

char	**split_cmd(char *cmd)
{
	char	**cmds;
	t_esc	esc;

	esc = (t_esc){false, false, false};
	cmds = recursive_split(cmd, "\n\t\v\f\r ", &esc, 0);
	if (!cmds)
		return (NULL);
	if (!format_cmds(cmds))
	{
		free_cmds(cmds, 0);
		return (NULL);
	}
	return (cmds);
}

static char	**recursive_split(char *str, char *del, t_esc *esc, int cmd_count)
{
	int		len;
	char	**cmds;

	while (*str && is_split(*str, del, esc))
		str++;
	len = 1;
	while (*str && str[len] && !is_split(str[len], del, esc))
		len++;
	if (*str)
		cmds = recursive_split(str + len, del, esc, cmd_count + 1);
	else
		cmds = (char **)ft_calloc((cmd_count + 1), sizeof(char *));
	if (!cmds && !*str)
		return (error_return_null(strerror(errno), "malloc"));
	else if (!cmds)
		return (NULL);
	if (*str)
	{
		if (!cut_str(cmds, cmd_count, str, len))
			return (NULL);
	}
	else
		cmds[cmd_count] = NULL;
	return (cmds);
}

static bool	is_split(char c, char *del, t_esc *esc)
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

static bool	cut_str(char **cmds, int cmd_count, char *str, int len)
{
	cmds[cmd_count] = ft_substr(str, 0, len);
	if (!cmds[cmd_count])
	{
		free_cmds(cmds, cmd_count + 1);
		return (error_return_bool(strerror(errno), "malloc"));
	}
	return (true);
}

static bool	format_cmds(char **cmds)
{
	t_esc	esc;
	t_esc	esc_tmp;
	int		index;

	while (*cmds)
	{
		esc = (t_esc){false, false, false};
		index = 0;
		while ((*cmds)[index])
		{
			esc_tmp = esc;
			(void)is_split((*cmds)[index], "", &esc);
			if (esc.bacl_s || esc_tmp.single_q != esc.single_q
				|| esc_tmp.double_q != esc.double_q)
				ft_memmove(&((*cmds)[index]), &((*cmds)[index + 1]),
					ft_strlen(&((*cmds)[index])));
			else
				index++;
		}
		if (esc.bacl_s || esc.single_q || esc.double_q)
			return (error_return_bool(SEQUENCE_ERROR, NULL));
		cmds++;
	}
	return (true);
}
