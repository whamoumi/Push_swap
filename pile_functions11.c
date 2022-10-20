/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_functions11.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 12:09:40 by whamoumi          #+#    #+#             */
/*   Updated: 2021/07/23 16:23:10 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	second_bis_bis(t_pile *mapile, t_pile *mapile_b, t_data *data)
{
	data->tab = fill_tab_id(mapile_b, data->count);
	ft_sort_int_tab(data->tab, data->count);
	data->mediane = data->tab[data->count / 2];
	data->push = give_push_elementt(data->tab, data->count, data->mediane);
	free(data->tab);
	data->countrotate = 0;
	data->countpush = 0;
	data->id = mapile_b->first->id;
	second_bis(mapile_b, mapile, data);
}

void	second_step_of_sort(t_pile *mapile, t_pile *mapile_b, t_data *data)
{
	while (1)
	{
		if (sort_tab_2(mapile) == 0 && give_size_of_pile(mapile_b) == 0)
			break ;
		data->id = mapile_b->first->id;
		data->count = count_element(mapile_b);
		data->tab = fill_tab_id(mapile_b, data->count);
		ft_sort_int_tab(data->tab, data->count);
		data->mediane = data->tab[data->count / 2];
		free(data->tab);
		if (data->count <= 3)
		{
			sort_tree_element(mapile, mapile_b, data->count);
			up_id(mapile_b, data->mediane);
		}
		else
			second_bis_bis(mapile, mapile_b, data);
	}
}

void	second_bis(t_pile *mapile_b, t_pile *mapile, t_data *data)
{
	data->i = 0;
	while (data->i < data->push)
	{
		if (mapile_b->first->nb >= data->mediane)
		{
			data->countpush++;
			push_a(mapile_b, mapile);
			data->i++;
		}
		else
		{
			data->countrotate++;
			rotate_b(mapile_b);
		}
	}
	up_idd(mapile_b, data->mediane);
	while (data->countrotate-- > 0 && give_size_of_pile(mapile_b) != 1)
		rotate_reverse_b(mapile_b);
	if (data->countpush > 3)
		while (data->countpush-- > 0)
			push_b(mapile, mapile_b);
	else if (data->countpush <= 3)
		sort_tree_elementtt(mapile, data->countpush);
}
