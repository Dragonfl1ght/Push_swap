/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkory <hkory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:14:58 by hkory             #+#    #+#             */
/*   Updated: 2022/03/31 13:11:19 by hkory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

t_list	*ft_list_create(int d, char **s);
t_list	*ft_init(int a);
t_list	*ft_addelem(t_list *lst, int number);
t_list	*ft_get_last(t_list *stack);
void	do_error(void);
void	mas_index(char **s, int d, int *mas);
void	massort(int *mas, int d);
void	ft_reverse_rotate(t_list **stack, char *c);
void	ft_rotate(t_list **stack, char *c);
void	ft_push(t_list **stack_a, t_list **stack_b, char *c);
void	ft_swap(t_list **stack, char *c);
void	sort_for_3(t_list **l1);
void	sort_for_5(t_list **l1, t_list **l2, int argc);
void	sort_for_100(t_list **a, t_list **b, int argc);
void	sort_for_500(t_list **a, t_list **b, int argc);
void	ft_go_to_sort(t_list **list_a, t_list **list_b, int argc);
int		ft_atoi(const char *str);
int		ft_inputcheck(char**s, int d);
int		ft_isspace(const char ch);
int		ft_isdigit(int c);
int		ft_issort(char**s, int d);
#endif