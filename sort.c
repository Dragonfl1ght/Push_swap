/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkory <hkory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:14:54 by hkory             #+#    #+#             */
/*   Updated: 2022/03/29 16:32:05 by hkory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_go_to_sort(t_list **list_a, t_list **list_b, int argc)
{
	if (argc == 3)
		ft_swap(list_a, "a\n");
	else if (argc == 4)
		sort_for_3(list_a);
	else if (argc <= 6)
		sort_for_5(list_a, list_b, argc);
	else if (argc >= 7 && argc <= 101)
		sort_for_100(list_a, list_b, argc);
	else
		sort_for_500(list_a, list_b, argc);
}

void	sort_for_3(t_list **l1)
{
	int	a;
	int	b;
	int	c;

	a = (*l1)->value;
	b = (*l1)->next->value;
	c = (*l1)->next->next->value;
	if (a > b && c > b && c > a)
		ft_swap(l1, "a\n");
	else if (a > b && a > c && b > c)
	{
		ft_swap(l1, "a\n");
		ft_reverse_rotate(l1, "a\n");
	}
	else if (a > b && c > b && a > c)
		ft_rotate(l1, "a\n");
	else if (a < b && a < c && b > c)
	{
		ft_swap(l1, "a\n");
		ft_rotate(l1, "a\n");
	}
	else if (a < b && a > c && b > c)
		ft_reverse_rotate(l1, "a\n");
}

int	count_n(t_list *list)
{
	int	n;

	n = 0;
	while (list)
	{
		n++;
		list = list->next;
	}
	return (n);
}

static void	five_finish(t_list **l1, t_list **l2)
{
	sort_for_3(l1);
	while (count_n(*l2) != 0)
	{
		if ((*l2)->index == 0)
			ft_push(l2, l1, "a\n");
		else
		{
			ft_push(l2, l1, "a\n");
			ft_rotate(l1, "a\n");
		}
	}
}

void	sort_for_5(t_list **l1, t_list **l2, int argc)
{
	t_list	*max_min;

	max_min = *l1;
	while (count_n(*l1) != 3)
	{
		if (max_min->index == 0)
		{
			max_min = max_min->next;
			ft_push(l1, l2, "b\n");
		}
		else if (max_min->index == argc - 2)
		{
			max_min = max_min->next;
			ft_push(l1, l2, "b\n");
		}
		else
		{
			max_min = max_min->next;
			ft_rotate(l1, "a\n");
		}
	}
	five_finish(l1, l2);
}
