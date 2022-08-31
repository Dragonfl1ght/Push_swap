/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkory <hkory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:15:23 by hkory             #+#    #+#             */
/*   Updated: 2022/03/31 14:00:04 by hkory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_get_prelast(t_list *stack)
{
	t_list	*tmp;

	while (stack->next)
	{
		stack = stack->next;
		if (stack->next)
			tmp = stack;
	}
	return (tmp);
}

void	ft_swap(t_list **stack, char*c)
{
	int	tmp;
	int	itr;

	tmp = (*stack)->value;
	itr = (*stack)->index;
	(*stack)->value = (*stack)->next->value;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->value = tmp;
	(*stack)->next->index = itr;
	write(1, "s", 1);
	write(1, c, 2);
}

void	ft_push(t_list **stack_l, t_list **stack_r, char*c)
{
	t_list	*tmp;

	tmp = *stack_l;
	*stack_l = (*stack_l)->next;
	tmp->next = *stack_r;
	*stack_r = tmp;
	write(1, "p", 1);
	write(1, c, 2);
}

void	ft_rotate(t_list **stack, char*c)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stack;
	last = ft_get_last(*stack);
	*stack = (*stack)->next;
	last->next = tmp;
	last->next->next = NULL;
	write(1, "r", 1);
	write(1, c, 2);
}

void	ft_reverse_rotate(t_list **stack, char*c)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*prelast;

	tmp = *stack;
	prelast = ft_get_prelast(*stack);
	last = prelast->next;
	last->next = *stack;
	*stack = last;
	prelast->next = NULL;
	write(1, "rr", 2);
	write(1, c, 2);
}
