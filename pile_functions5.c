/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_functions5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:41:20 by whamoumi          #+#    #+#             */
/*   Updated: 2021/07/23 16:19:03 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(char **argv, int argc, t_pile *d)
{
	int	i;
	int	j;
	int	*tab;

	j = 1;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		return (check_error_two(argv[1], d));
	else
	{
		if (pre_condition(argv, argc) == 0)
			return (0);
		tab = fill_tab(argv, argc, d);
		i = 0;
		while (i < argc - 1)
			empiler(d, tab[i++]);
		if (check_doublons(tab, argc) == 0)
			return (0);
		if (d->check == 0)
			return (0);
		free(tab);
		return (1);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i + 1 < size)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int	*pile_in_tab(t_pile *pile)
{
	t_element	*actuel;
	int			i;
	int			*tab;

	tab = malloc(sizeof(int) * give_size_of_pile(pile));
	i = 0;
	actuel = pile->first;
	while (actuel != NULL)
	{
		tab[i] = actuel->nb;
		actuel = actuel->next;
		i++;
	}
	return (tab);
}

int	sort_tab(t_pile *pile)
{
	t_element	*actuel;
	int			i;
	int			*tab;

	tab = malloc(sizeof(int) * give_size_of_pile(pile));
	i = 0;
	actuel = pile->first;
	while (actuel != NULL)
	{
		tab[i] = actuel->nb;
		i++;
		actuel = actuel->next;
	}
	i = 0;
	while (i + 1 < give_size_of_pile(pile))
	{
		if (tab[i + 1] < tab[i])
		{	
			free(tab);
			return (0);
		}
		i++;
	}
	free(tab);
	return (1);
}

int	sort_tab_2(t_pile *pile)
{
	t_element	*actuel;
	int			i;
	int			*tab;

	tab = malloc(sizeof(int) * give_size_of_pile(pile));
	i = 0;
	actuel = pile->first;
	while (actuel != NULL)
	{
		tab[i] = actuel->nb;
		i++;
		actuel = actuel->next;
	}
	i--;
	while (i - 1 >= 0 )
	{
		if (tab[i - 1] < tab[i])
		{
			free(tab);
			return (0);
		}
		i--;
	}
	free(tab);
	return (1);
}
