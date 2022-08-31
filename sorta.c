/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkory <hkory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:14:56 by hkory             #+#    #+#             */
/*   Updated: 2022/03/31 14:20:52 by hkory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

static int	search_max(t_list **b, int i)
{
	t_list	*tmp;
	int		n;

	n = 0;
	tmp = *b;
	while (tmp)
	{
		if (tmp->index == i)
			break ;
		tmp = tmp->next;
		n++;
	}
	return (n);
}

static void	sort_b(t_list **a, t_list **b, int argc)
{
	int	max_i;
	int	half;
	int	place;

	max_i = argc - 2;
	while (*b)
	{
		half = (max_i + 1) / 2;
		place = search_max(b, max_i);
		if ((*b)->index == max_i)
		{
			ft_push(b, a, "a\n");
			max_i--;
		}
		else if (place <= half && (*b)->index != max_i)
			ft_rotate(b, "b\n");
		else if (place > half && (*b)->index != max_i)
			ft_reverse_rotate(b, "b\n");
	}
}

void	sort_for_100(t_list **a, t_list **b, int argc)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i && i > 1)
		{
			ft_push(a, b, "b\n");
			ft_rotate(b, "b\n");
			i++;
		}
		else if ((*a)->index <= (i + 15))
		{
			ft_push(a, b, "b\n");
			i++;
		}
		else if ((*a)->index >= i)
			ft_rotate(a, "a\n");
	}
	sort_b(a, b, argc);
}

void	sort_for_500(t_list **a, t_list **b, int argc)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i && i > 1)
		{
			ft_push(a, b, "b\n");
			ft_rotate(b, "b\n");
			i++;
		}
		else if ((*a)->index <= (i + 30))
		{
			ft_push(a, b, "b\n");
			i++;
		}
		else if ((*a)->index >= i)
			ft_rotate(a, "a\n");
	}
	sort_b(a, b, argc);
}
