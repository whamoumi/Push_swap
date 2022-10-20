/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_functions6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:57:55 by whamoumi          #+#    #+#             */
/*   Updated: 2021/07/23 14:16:23 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_element_tree(t_pile *pile, t_pile *pile_b)
{
	push_a(pile_b, pile);
	if (pile_b->first->nb < pile_b->first->next->nb)
		swap_b(pile_b);
	push_a(pile_b, pile);
	push_a(pile_b, pile);
}

void	sort_three_element_treee(t_pile *pile, t_pile *pile_b)
{
	swap_b(pile_b);
	push_a(pile_b, pile);
	if (pile_b->first->nb < pile_b->first->next->nb)
		swap_b(pile_b);
	push_a(pile_b, pile);
	push_a(pile_b, pile);
}

void	sort_three_element_treeee(t_pile *pile, t_pile *pile_b)
{
	rotate_b(pile_b);
	swap_b(pile_b);
	push_a(pile_b, pile);
	rotate_reverse_b(pile_b);
	if (pile_b->first->nb < pile_b->first->next->nb)
		swap_b(pile_b);
	push_a(pile_b, pile);
	push_a(pile_b, pile);
}

void	sort_tree_element(t_pile *pile, t_pile *pile_b, int nb)
{
	if (nb == 3)
	{
		if ((pile_b->first->nb > pile_b->first->next->nb)
			&& pile_b->first->nb > pile_b->first->next->next->nb)
			sort_three_element_tree(pile, pile_b);
		else if ((pile_b->first->nb < pile_b->first->next->nb)
			&& (pile_b->first->next->nb > pile_b->first->next->next->nb))
			sort_three_element_treee(pile, pile_b);
		else if ((pile_b->first->nb < pile_b->first->next->next->nb)
			&& (pile_b->first->next->nb < pile_b->first->next->next->nb))
			sort_three_element_treeee(pile, pile_b);
	}
	else if (nb == 2)
	{
		if (pile_b->first->nb < pile_b->first->next->nb)
			swap_b(pile_b);
		push_a(pile_b, pile);
		push_a(pile_b, pile);
	}
	else if (nb == 1)
		push_a(pile_b, pile);
}
