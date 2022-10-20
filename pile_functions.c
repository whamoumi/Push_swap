/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:18:59 by whamoumi          #+#    #+#             */
/*   Updated: 2021/07/23 16:24:56 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_pile *pile_a)
{
	int	tmp;

	tmp = pile_a->first->nb;
	pile_a->first->nb = pile_a->first->next->nb;
	pile_a->first->next->nb = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_pile *pile_b)
{
	int	tmp;

	tmp = pile_b->first->nb;
	pile_b->first->nb = pile_b->first->next->nb;
	pile_b->first->next->nb = tmp;
	write(1, "sb\n", 3);
}

void	rotate_a(t_pile *pile)
{
	t_element	*actuel;
	t_element	*element;

	element = malloc(sizeof(*element));
	actuel = pile->first;
	element->nb = pile->first->nb;
	element->id = pile->first->id;
	supp_debut(pile);
	while (actuel->next != NULL)
		actuel = actuel->next;
	actuel->next = element;
	element->next = NULL;
	write(1, "ra\n", 3);
}

void	rotate_b(t_pile *pile)
{
	t_element	*actuel;
	t_element	*element;

	element = malloc(sizeof(*element));
	actuel = pile->first;
	element->nb = pile->first->nb;
	element->id = pile->first->id;
	supp_debut(pile);
	while (actuel->next != NULL)
		actuel = actuel->next;
	actuel->next = element;
	element->next = NULL;
	write(1, "rb\n", 3);
}

void	push_a(t_pile *pile_a, t_pile *pile_b)
{
	t_element	*tmp;

	tmp = malloc(sizeof(*tmp));
	if (pile_b == NULL)
		exit (0);
	tmp->nb = pile_a->first->nb;
	tmp->id = pile_a->first->id;
	tmp->next = pile_b->first;
	pile_b->first = tmp;
	free(pile_a->first);
	pile_a->first = pile_a->first->next;
	write(1, "pa\n", 3);
}
