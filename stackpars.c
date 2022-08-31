/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackpars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkory <hkory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:14:50 by hkory             #+#    #+#             */
/*   Updated: 2022/04/01 14:49:01 by hkory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_init(int a)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	lst->value = a;
	lst->next = NULL;
	return (lst);
}

t_list	*ft_addelem(t_list *lst, int number)
{
	t_list	*tmp;
	t_list	*p;

	tmp = (t_list *)malloc(sizeof(t_list));
	p = lst->next;
	lst->next = tmp;
	tmp->value = number;
	tmp->next = p;
	return (tmp);
}

t_list	*ft_list_create(int d, char **s)
{
	int		i;
	t_list	*tmp;

	i = d;
	tmp = ft_init(ft_atoi(s[1]));
	while (i > 1)
	{
		ft_addelem(tmp, ft_atoi(s[i]));
		i--;
	}
	return (tmp);
}

void	stack_index(t_list *stack, int *mas)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == mas[i])
		{
			stack->index = i;
			stack = stack->next;
			i = -1;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	int		*p;

	i = 0;
	p = malloc(sizeof(int) * (argc - 1));
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (!ft_inputcheck(argv, argc))
		do_error();
	stack_a = ft_list_create((argc - 1), argv);
	mas_index(argv, argc - 1, p);
	stack_index(stack_a, p);
	i = 0;
	stack_b = NULL;
	ft_go_to_sort(&stack_a, &stack_b, argc);
	free(p);
	exit(EXIT_SUCCESS);
}
