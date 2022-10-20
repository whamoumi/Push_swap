/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_functions4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:03:11 by whamoumi          #+#    #+#             */
/*   Updated: 2021/07/23 16:17:41 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*give_tab(int *tab, int size)
{
	int	*tabn;
	int	i;
	int	j;
	int	nb;

	nb = tab[size - 1];
	j = 1;
	i = 0;
	tabn = malloc(sizeof(int) * size);
	while (i < size - 1)
	{
		tabn[j] = tab[i];
		j++;
		i++;
	}
	tabn[0] = nb;
	return (tabn);
}

int	ft_atoi(char *str, t_pile *d)
{
	int			i;
	int			signe;
	long int	resultat;

	i = 0;
	signe = 1;
	resultat = 0;
	i += is_space(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + ((str[i] - 48));
		if (resultat < INT_MIN || resultat > INT_MAX)
			d->check = 0;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9') && str[i])
		d->check = 0;
	return (signe * resultat);
}

int	*give_rotate_tab(int *tab, int size)
{
	int	*tabn;
	int	i;
	int	j;
	int	nb;

	nb = tab[0];
	j = 0;
	i = 1;
	tabn = malloc(sizeof(int) * size);
	while (i < size)
	{
		tabn[j] = tab[i];
		j++;
		i++;
	}
	tabn[j] = nb;
	return (tabn);
}

int	conditions(char c)
{
	if (!((c >= '0' && c <= '9')
			|| (c == '-' || c == '+')
			|| (c == ' ' || c == '\t'
				|| c == '\f' || c == '\n'
				|| c == '\r' || c == '\v')))
		return (0);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	else
		return (0);
}
