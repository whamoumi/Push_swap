/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_functions9.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:53:54 by whamoumi          #+#    #+#             */
/*   Updated: 2021/07/23 16:48:21 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_word(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	*copy_word(const char *str, char c)
{
	int		i;
	char	*copy;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	copy = malloc(sizeof(char) * (i + 1));
	if (!(copy))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		y;
	int		i;

	res = malloc(sizeof(char *) * count_word(s, c) + 1);
	if (!(res))
		return (NULL);
	i = 0;
	y = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			res[y] = copy_word((&s[i]), c);
			y++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	res[y] = 0;
	return (res);
}

int	check_error_two(char *tab, t_pile *pile)
{
	char	**tabn;
	int		i;
	int		j;

	tabn = ft_split(tab, ' ');
	i = -1;
	while (tabn[++i])
	{
		j = -1;
		while (tabn[i][++j])
		{
			if (conditions(tabn[i][j]) == 0)
				return (0);
			if ((ft_strcmp(tabn[i], "-") == 0)
				|| (ft_strcmp(tabn[i], "+") == 0))
				return (0);
		}
	}
	if (check_doublonss(tabn) == 0)
		return (0);
	fill_pile(tabn, pile);
	if (pile->check == 0)
		return (0);
	return (1);
}

void	fill_pile(char **tabn, t_pile *pile)
{
	int		i;

	i = 0;
	while (tabn[i])
		i++;
	i--;
	while (i >= 0)
	{
		empiler(pile, ft_atoi(tabn[i], pile));
		free(tabn[i]);
		i--;
	}
	free(tabn);
}
