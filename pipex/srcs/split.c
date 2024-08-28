/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:50:17 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/08/23 23:10:09 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static char	**recursive_split(char *str, char *del, t_esc *esc, int cmd_count);
static bool	is_split(char c, char *del, t_esc *esc);
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
		return (free_cmds(cmds, 0));
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
		cmds = (char **)ft_calloc((cmd_count + 1),  sizeof(char *));
	if (!cmds)
	{
		// エラー出力
		return (NULL);
	}
	if (*str)
	{
		cmds[cmd_count] = ft_substr(str, 0, len);
		if (!cmds[cmd_count])
		{
			// エラー出力
			return (free_cmds(cmds, cmd_count + 1));
		}
	}
	else
		cmds[cmd_count] = NULL;
	return (cmds);
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
		{
			// エラー出力
			return (false);
		}
		cmds++;
	}
	return (true);
}
