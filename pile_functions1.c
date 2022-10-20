/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_functions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:29:21 by whamoumi          #+#    #+#             */
/*   Updated: 2021/07/23 16:25:04 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_reverse_b(t_pile *pile)
{
	t_element	*actuel;
	t_element	*actuell;
	t_element	*element;

	element = malloc(sizeof(*element));
	actuel = pile->first;
	actuell = pile->first;
	while (actuel->next->next != NULL)
		actuel = actuel->next;
	element->nb = actuel->next->nb;
	element->id = actuel->next->id;
	free(actuel->next);
	actuel->next = NULL;
	element->next = actuell;
	pile->first = element;
	write(1, "rrb\n", 4);
}

void	rotate_reverse_a(t_pile *pile)
{
	t_element	*actuel;
	t_element	*actuell;
	t_element	*element;
	int			nb;
	int			id;

	element = malloc(sizeof(*element));
	actuel = pile->first;
	actuell = pile->first;
	while (actuel->next->next != NULL)
		actuel = actuel->next;
	nb = actuel->next->nb;
	id = actuel->next->id;
	free(actuel->next);
	actuel->next = NULL;
	element->nb = nb;
	element->id = id;
	element->next = actuell;
	pile->first = element;
	write(1, "rra\n", 4);
}

void	push_b(t_pile *pile_a, t_pile *pile_b)
{
	t_element	*tmp;

	tmp = malloc(sizeof(*tmp));
	if (pile_a == NULL)
		exit (0);
	tmp->nb = pile_a->first->nb;
	tmp->id = pile_a->first->id;
	tmp->next = pile_b->first;
	pile_b->first = tmp;
	free(pile_a->first);
	pile_a->first = pile_a->first->next;
	write(1, "pb\n", 3);
}

int	count_element(t_pile *pile)
{
	t_element	*actuel;
	int			i;
	int			id;

	id = pile->first->id;
	i = 0;
	actuel = pile->first;
	while (actuel != NULL && actuel->id == id)
	{
		i++;
		actuel = actuel->next;
	}
	return (i);
}

int	*fill_tab_id(t_pile *pile, int size)
{
	t_element	*actuel;
	int			*tab;
	int			i;
	int			id;

	actuel = pile->first;
	id = pile->first->id;
	tab = malloc(sizeof(int) * size);
	i = 0;
	while (actuel != NULL && actuel->id == id)
	{
		tab[i] = actuel->nb;
		i++;
		actuel = actuel->next;
	}
	return (tab);
}
