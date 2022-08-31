/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   massort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkory <hkory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:14:45 by hkory             #+#    #+#             */
/*   Updated: 2022/03/26 16:23:35 by hkory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_get_last(t_list *stack)
{
	if (!stack)
		exit(1);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	massort(int *mas, int d)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < d - 1)
	{
		j = d - 1;
		while (j > i)
		{
			if (mas[j - 1] > mas[j])
			{
				tmp = mas[j - 1];
				mas[j - 1] = mas[j];
				mas[j] = tmp;
			}
			j--;
		}
		i++;
	}
}

void	mas_index(char **s, int d, int *mas)
{
	int	i;

	i = 0;
	while (i < d)
	{
		mas[i] = ft_atoi(s[i + 1]);
		i++;
	}
	massort(mas, d);
}

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

int	ft_isspace(const char ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n'
		|| ch == '\v' || ch == '\f')
		return (1);
	return (0);
}
