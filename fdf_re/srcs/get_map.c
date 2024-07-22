/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkoizumi <hkoizumi@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:13:30 by hkoizumi          #+#    #+#             */
/*   Updated: 2024/06/05 13:54:54 by hkoizumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	split_row(void *xyc);
static bool	get_col(char *row, unsigned int *color);

void	get_map(t_list *map, int fd)
{
	char	*row;
	int		row_count;
	t_xyc	*xyc_tmp;
	t_list	*row_tmp;


	row_count = -1;
	while (1)
	{
		row = get_next_line(fd);
		if (!row)
			break ;
		xyc_tmp = (t_xyc *)ft_calloc(1, sizeof(t_xyc));
		if (xyc_tmp)
			return (ft_lstclear(&map, &free_xyc));
		*xyc_tmp = (t_xyc){row_count, -1, (void *)row};
		row_tmp = ft_lstnew((void *)&xyc_tmp);
		if (!row_tmp)
			return (ft_lstclear(&map, &free_xyc));
		ft_lstadd_back(&map, row_tmp);
	}
	ft_lstiter(map, split_row);
}

static void	split_row(void *xyc)
{
	char	**words;
	int		index;
	t_dot	*dot;
	t_list	*dots_tmp;
	t_list	*row;

	if (xyc)
		words = ft_split((const char *)((t_xyc *)xyc)->content, " ");
	if (!xyc || !words)
		return ;
	index = -1;
	while (words[++index])
	{
		dot = (t_dot *)ft_calloc(1, sizeof(t_dot));
		set_value(dot, ((t_xyc *)xyc)->y, index, words[index]);
		dots_tmp = ft_lstnew((void *)&dot);
		free (words[index]);
		if (!dots_tmp)
		{
			while (words[++index])
				free (words[index]);
			free (words);
			return (ft_lstclear(&row, &free_xyc));
		}
		ft_lstadd_back(&row, dots_tmp);
	}
	free (words);
	free_xyc(xyc);
	xyc = (void *)row;
}

static void	set_value(t_dot *dot, int y, int x, char *word)
{

}

static bool	get_col(char *row, unsigned int *color)
{
	int	i;

	if (!row)
		*color = 0xFFFFFF;
	else
	{
		row++;
		*color = 0;
		while (*row && (ft_strchr(UPPER_HEX_LIST, *row)
				|| ft_strchr(LOWER_HEX_LIST, *row)))
		{
			i = 0;
			while (UPPER_HEX_LIST[i] != *row && LOWER_HEX_LIST[i] != *row)
				i++;
			if (*color > ((unsigned int)0xFFFFFF - i) / 16)
				return (false);
			*color = 16 * *color + i;
			row++;
		}
		if (row)
			return (false);
	}
	return (true);
}
