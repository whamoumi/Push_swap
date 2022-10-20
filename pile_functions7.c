/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_functions7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:58:47 by whamoumi          #+#    #+#             */
/*   Updated: 2021/07/23 12:54:17 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tree_elementttt(t_pile *pile)
{
	swap_a(pile);
	rotate_a(pile);
	swap_a(pile);
	rotate_reverse_a(pile);
	if (pile->first->nb > pile->first->next->nb)
		swap_a(pile);
}

void	sort_tree_elementtttt(t_pile *pile)
{
	rotate_a(pile);
	swap_a(pile);
	rotate_reverse_a(pile);
	if (pile->first->nb > pile->first->next->nb)
		swap_a(pile);
}

void	sort_tree_elementttttt(t_pile *pile)
{
	if (pile->first->nb > pile->first->next->nb)
		swap_a(pile);
}

void	sort_tree_elementtt(t_pile *pile, int count)
{
	if (count == 3)
	{
		if ((pile->first->nb > pile->first->next->nb)
			&& pile->first->nb > pile->first->next->next->nb)
			sort_tree_elementttt(pile);
		else if ((pile->first->nb < pile->first->next->nb)
			&& pile->first->next->nb > pile->first->next->next->nb)
			sort_tree_elementtttt(pile);
		else if ((pile->first->nb < pile->first->next->next->nb)
			&& pile->first->next->nb < pile->first->next->next->nb)
			sort_tree_elementttttt(pile);
	}
	else if (count == 2)
		sort_tree_elementttttt(pile);
	else if (count == 1)
		sort_tree_elementttttt(pile);
}
