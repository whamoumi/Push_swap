/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:25:10 by whamoumi          #+#    #+#             */
/*   Updated: 2021/07/23 16:58:34 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_element
{
	int					nb;
	int					id;
	struct s_element	*next;
}				t_element;

typedef struct s_pile
{
	t_element	*first;
	int			check;
}				t_pile;

typedef struct s_data
{
	int	mediane;
	int	countpush;
	int	countrotate;
	int	i;
	int	push;
	int	count;
	int	id;
	int	*tab;
	int	number;
	int	mediano;
}				t_data;
void	rr(t_pile *mapile, t_pile *mapile_b);
void	rrr(t_pile *mapile, t_pile *mapile_b);
void	ss(t_pile *mapile, t_pile *mapile_b);
void	first_bis(t_pile *mapile, t_pile *mapile_b, t_data *data);
void	second_bis_bis(t_pile *mapile, t_pile *mapile_b, t_data *data);
void	second_bis(t_pile *mapile_b, t_pile *mapile, t_data *data);
void	second_step_of_sort(t_pile *mapile, t_pile *mapile_b, t_data *data);
void	first_steps(int argc, char **argv, t_pile *mapile, t_pile *mapile_b);
void	fill_pile(char **tabn, t_pile *pile);
void	sort_tree_elementttt(t_pile *pile);
void	sort_tree_elementtttt(t_pile *pile);
void	sort_tree_elementttttt(t_pile *pile);
void	sort_tree_elementtt(t_pile *pile, int count);
void	sort_tree_element(t_pile *pile, t_pile *pile_b, int nb);
void	sort_three_element_treeee(t_pile *pile, t_pile *pile_b);
void	sort_three_element_treee(t_pile *pile, t_pile *pile_b);
void	sort_three_element_tree(t_pile *pile, t_pile *pile_b);
void	ft_sort_int_tab(int *tab, int size);
void	empiler(t_pile *pile, int nbv);
void	supp_debut(t_pile *liste);
void	push_a(t_pile *pile_a, t_pile *pile_b);
void	rotate_b(t_pile *pile);
void	rotate_a(t_pile *pile);
void	swap_b(t_pile *pile_b);
void	swap_a(t_pile *pile_a);
void	push_b(t_pile *pile_a, t_pile *pile_b);
void	rotate_reverse_a(t_pile *pile);
void	rotate_reverse_b(t_pile *pile);
void	sort_tree_two_elems(t_pile *pile);
void	up_idd(t_pile *pile_b, int median);
void	up_id(t_pile *pile_b, int median);
int		give_push_elementt(int *tab, int size, int mediane);
int		give_push_element(int *tab, int size, int mediane);
int		*fill_tab_id(t_pile *pile, int size);
int		count_element(t_pile *pile);
int		check_doublons(int *tab, int argc);
int		*fill_tab(char **argv, int argc, t_pile *d);
int		*fill_tabb(char *argv, int argc, t_pile *d);
int		give_size_of_pile(t_pile *pile);
int		ft_strcmp(char *s1, char *s2);
int		conditions(char c);
int		*give_rotate_tab(int *tab, int size);
int		ft_atoi(char *str, t_pile *d);
int		*give_tab(int *tab, int size);
int		check_error(char **argv, int argc, t_pile *d);
int		check_error_two(char *tab, t_pile *pile);
char	**ft_split(char const *s, char c);
char	*copy_word(const char *str, char c);
int		check_doublonss(char **tab);
int		count_word(const char *str, char c);
int		is_space(char *str);
int		pre_condition(char **argv, int argc);
int		sort_tab_2(t_pile *pile);
int		sort_tab(t_pile	*pile);
int		*pile_in_tab(t_pile *pile);
int		sort_tab_2(t_pile *pile);
#endif
