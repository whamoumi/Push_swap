/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_functions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:54:45 by whamoumi          #+#    #+#             */
/*   Updated: 2021/07/23 16:45:16 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empiler(t_pile *pile, int nbv)
{
	t_element	*nouveau;

	nouveau = malloc(sizeof(*nouveau));
	if (pile == NULL || nouveau == NULL)
		exit (0);
	nouveau->nb = nbv;
	nouveau->id = 0;
	nouveau->next = pile->first;
	pile->first = nouveau;
}

void	supp_debut(t_pile *liste)
{
	t_element	*supp_element;

	supp_element = liste->first;
	free(supp_element);
	liste->first = liste->first->next;
}

int	give_size_of_pile(t_pile *pile)
{
	int			i;
	t_element	*tmp;

	i = 0;
	tmp = pile->first;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	*fill_tab(char **argv, int argc, t_pile *d)
{
	int	i;
	int	j;
	int	*tab;

	tab = malloc(sizeof(int) * (argc - 1));
	j = argc - 1;
	i = 0;
	while (i < argc - 1)
	{
		tab[i] = ft_atoi(argv[j], d);
		i++;
		j--;
	}
	return (tab);
}

int	*fill_tabb(char *argv, int argc, t_pile *d)
{
	int		i;
	int		j;
	int		*tab;
	char	**argvv;

	argvv = ft_split(argv, ' ');
	tab = malloc(sizeof(int) * (argc));
	j = argc - 1;
	i = 0;
	while (i < argc)
	{
		tab[i] = ft_atoi(argvv[j], d);
		free(argvv[j]);
		i++;
		j--;
	}
	free(argvv);
	return (tab);
}
