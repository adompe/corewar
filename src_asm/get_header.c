/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <adompe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:11:33 by adompe            #+#    #+#             */
/*   Updated: 2017/02/10 17:19:13 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	ft_check_blank(char *str)
{
	while (*str == ' ' || *str == '\t' || *str == ',')
		str++;
	if (!(*str))
		return (TRUE);
	if (*str == ',')
		return (TRUE);
	else
		return (FALSE);
}

void	ft_set_sting_newline(char *str, char *line, int max_size)
{
	if ((int)ft_strlen(str) + (int)ft_strlen(line) + 1 < max_size)
	{
		ft_strcat(str, line);
		ft_strcat(str, "\n");
	}
	else if ((int)ft_strlen(line) + 1 > max_size)
		ft_error("Error: program name or comment size\n");
}

void	ft_get_end_quote(char *str, char *line, int fd, int max_size)
{
	int	i;

	ft_set_sting_newline(str, line, max_size);
	while (get_next_line(fd, &line) && i < max_size)
	{
		i = 0;
		while (line[i] && line[i] != '\"')
			i++;
		if (line[i] && (int)ft_strlen(str) + i < max_size)
		{
			ft_strncat(str, line, i);
			if (line[i + 1])
				if (!ft_check_blank(&(line[i + 1])))
					ft_error("Error: invalid header\n");
			return ;
		}
		else if ((int)ft_strlen(str) > max_size)
			ft_error("Error: program name or comment size\n");
		ft_set_sting_newline(str, line, max_size);
	}
}

void	ft_get_quote_value(char *str, char *line, int fd, int max_size)
{
	int		i;

	i = 0;
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line != '\"')
		ft_error("Error: invalid header\n");
	line++;
	while (line[i] && line[i] != '\"')
		i++;
	if (line[i] && i < max_size)
	{
		ft_strncat(str, line, i);
		if (line[i + 1])
			ft_error("Error: invalid header\n");
	}
	else if (i > max_size)
		ft_error("Error: program name or comment size\n");
	else
		ft_get_end_quote(str, line, fd, max_size);
}

void	ft_get_header(t_asm *data, int fd)
{
	char *line;

	while (get_next_line(fd, &line))
	{
		if (line == NULL)
			ft_error("Error: bad file\n");
		while (*line == ' ' || *line == '\t')
			line++;
		if (*line == '#' || !(*line))
			continue ;
		else if (!(*data->header->prog_name) && !ft_strncmp(line, ".name", 5))
		{
			line += 5;
			ft_get_quote_value(data->header->prog_name,
				line, fd, PROG_NAME_LENGTH);
		}
		else if (!(*data->header->comment) && !ft_strncmp(line, ".comment", 8))
		{
			line += 8;
			ft_get_quote_value(data->header->comment, line, fd, COMMENT_LENGTH);
			break ;
		}
		else
			ft_error("Error: no name or comment\n");
	}
}
