/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:29:45 by apelissi          #+#    #+#             */
/*   Updated: 2018/07/31 11:13:14 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		fin(char *texte)
{
	int	i;

	if (!texte)
		return (0);
	i = 0;
	while (texte[i])
	{
		if (texte[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	tri(char *texte, int taille, char **str)
{
	int		i;
	char	li[taille];

	if (!taille)
		*str = NULL;
	else
	{
		i = 0;
		while (texte[i] && texte[i] != '\n')
		{
			li[i] = texte[i];
			i++;
		}
		li[i] = '\0';
		*str = li;
	}
}

char	*str_add(char *base, char *ajout, int lu)
{
	char	*new;
	int		i;
	int		j;

	i = ft_strlen(base);
	if (!(new = (char *)malloc((1000 * 1000) * sizeof(char))))
		return (NULL);
	j = 0;
	while (j < i)
	{
		new[j] = base[j];
		j++;
	}
	j = 0;
	while (j < lu)
	{
		new[i + j] = ajout[j];
		j++;
	}
	new[i + j] = '\0';
	base = new;
	free(new);
	return (base);
}

int		get_next_line(const int fd, char **line)
{
	static char	*lectures[7168];
	char		temp[BUFF_SIZE];
	int			lu;
	int			taille;

	if (fd < 0)
		return (-1);
	while (!fin(lectures[fd]) && (lu = read(fd, temp, BUFF_SIZE)) == BUFF_SIZE)
		lectures[fd] = str_add(lectures[fd], temp, lu);
	if (lu < 0)
		return (-1);
	if ((!lectures[fd] || !lectures[fd][0]) && lu == 0)
		return (0);
	if (!fin(lectures[fd]))
		lectures[fd] = str_add(lectures[fd], temp, lu);
	taille = 0;
	while (lectures[fd][taille] && lectures[fd][taille] != '\n')
		taille++;
	tri(lectures[fd], taille, line);
	if (!lectures[fd] || ft_strlen(*line) >= ft_strlen(lectures[fd]))
		lectures[fd] = NULL;
	else
		lectures[fd] = &lectures[fd][ft_strlen(*line) + 1];
	return (1);
}
