/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_functions8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:59:30 by whamoumi          #+#    #+#             */
/*   Updated: 2021/07/23 17:06:17 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	first_bis(t_pile *mapile, t_pile *mapile_b, t_data *data)
{	
	while (data->i < give_push_element(data->tab, data->number, data->mediano))
	{
		if (mapile->first->nb <= data->mediano)
		{
			mapile->first->id++;
			data->i++;
			push_b(mapile, mapile_b);
		}
		else
			rotate_a(mapile);
	}
}

void	first_steps(int argc, char **argv, t_pile *mapile, t_pile *mapile_b)
{
	t_data	data;

	data.number = count_element(mapile);
	if (argc > 2)
		data.tab = fill_tab(argv, argc, mapile);
	else
		data.tab = fill_tabb(argv[1], data.number, mapile);
	ft_sort_int_tab(data.tab, give_size_of_pile(mapile));
	while (give_size_of_pile(mapile) > 3)
	{
		data.number = count_element(mapile);
		data.mediano = data.tab[((give_size_of_pile(mapile)) / 4)];
		up_id(mapile_b, data.mediano);
		data.i = 0;
		first_bis(mapile, mapile_b, &data);
		free(data.tab);
		data.tab = pile_in_tab(mapile);
		ft_sort_int_tab(data.tab, give_size_of_pile(mapile));
	}
	sort_tree_two_elems(mapile);
	free(data.tab);
}

int	sort_tab_3(t_pile *pile)
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
		if (tab[i - 1] > tab[i])
		{
			free(tab);
			return (0);
		}
		i--;
	}
	free(tab);
	return (1);
}

int	main(int argc, char **argv)
{
	t_pile	mapile;
	t_pile	mapile_b;
	t_data	data;

	mapile.first = NULL;
	mapile_b.first = NULL;
	mapile.check = 1;
	if (argc == 1)
		return (0);
	if (check_error(argv, argc, &mapile) == 0)
		return (write(1, "error\n", 6));
	if (sort_tab_3(&mapile) == 1)
		return (0);
	else
	{
		first_steps(argc, argv, &mapile, &mapile_b);
		second_step_of_sort(&mapile, &mapile_b, &data);
		return (0);
	}
}
