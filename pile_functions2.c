/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:44:31 by whamoumi          #+#    #+#             */
/*   Updated: 2021/07/23 16:25:13 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	give_push_element(int *tab, int size, int mediane)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < size)
	{
		if (tab[i] <= mediane)
			count++;
		i++;
	}
	return (count);
}

int	give_push_elementt(int *tab, int size, int mediane)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < size)
	{
		if (tab[i] >= mediane)
			count++;
		i++;
	}
	return (count);
}

void	up_id(t_pile *pile_b, int median)
{
	t_element	*actuell;

	actuell = pile_b->first;
	if (pile_b == NULL)
		exit (0);
	while (actuell != NULL)
	{
		if (actuell->nb <= median)
			actuell->id++;
		actuell = actuell->next;
	}
}

void	up_idd(t_pile *pile_b, int median)
{
	t_element	*actuell;

	actuell = pile_b->first;
	if (pile_b == NULL)
		exit(0);
	while (actuell != NULL)
	{
		if (actuell->nb < median)
			actuell->id++;
		actuell = actuell->next;
	}
}

void	sort_tree_two_elems(t_pile *pile)
{
	if (give_size_of_pile(pile) == 3)
	{
		while (sort_tab(pile) == 0)
		{
			if (pile->first->nb > pile->first->next->nb)
				swap_a(pile);
			else
				rotate_reverse_a(pile);
		}
	}
	else if (give_size_of_pile(pile) == 2)
	{
		if (pile->first->nb > pile->first->next->nb)
			swap_a(pile);
	}
}
