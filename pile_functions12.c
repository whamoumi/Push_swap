/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_functions12.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 16:54:02 by whamoumi          #+#    #+#             */
/*   Updated: 2021/07/23 16:59:14 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_pile *mapile, t_pile *mapile_b)
{
	rotate_a(mapile);
	rotate_b(mapile_b);
	write(1, "rr\n", 3);
}

void	rrr(t_pile *mapile, t_pile *mapile_b)
{
	rotate_reverse_a(mapile);
	rotate_reverse_b(mapile_b);
	write(1, "rrr\n", 4);
}

void	ss(t_pile *mapile, t_pile *mapile_b)
{
	swap_a(mapile);
	swap_b(mapile_b);
	write(1, "ss\n", 3);
}
