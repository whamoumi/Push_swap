/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_functions10.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 11:52:39 by whamoumi          #+#    #+#             */
/*   Updated: 2021/07/23 16:41:40 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doublons(int *tab, int argc)
{
	int	i;
	int	j;

	i = 1;
	i = 0;
	while (i < argc - 2)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	return (i);
}

int	pre_condition(char **argv, int argc)
{
	int	i;
	int	j;

	j = 1;
	while (j < argc)
	{
		i = -1;
		while (argv[j][++i])
		{
			if (conditions(argv[j][i]) == 0)
				return (0);
			if ((ft_strcmp(argv[j], "-") == 0)
				|| (ft_strcmp(argv[j], "+") == 0))
				return (0);
		}
		j++;
	}
	return (1);
}

int	check_doublonss(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (tab[i + 1])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
