/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkory <hkory@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:15:00 by hkory             #+#    #+#             */
/*   Updated: 2022/03/26 16:15:00 by hkory            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_atoi(const char *str)
{
	long int	res;
	int			sign;

	sign = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			do_error();
		res = (res * 10) + ((*str - '0') * sign);
		if (res < -2147483648 || res > 2147483647)
			do_error();
		str++;
	}
	return ((int)(res));
}

int	ft_issort(char**s, int d)
{
	int	i;
	int	j;
	int	f;

	f = 0;
	i = 1;
	if (d == 2)
		ft_atoi(s[1]);
	while (i < d)
	{
		j = i + 1;
		while (j < d)
		{
			if (ft_atoi(s[i]) > ft_atoi(s[j]))
				f = 1;
			if (ft_atoi(s[i]) == ft_atoi(s[j]))
				do_error();
			j++;
		}
		i++;
	}
	return (f);
}

static int	ft_isnum(char *str)
{
	while (*str != '\0')
	{
		if ((*str == '+' || *str == '-')
			&& ft_isdigit(*str++) && !ft_isspace(*str))
			str++;
		else if (!ft_isdigit(*str))
			do_error();
		str++;
	}
	return (1);
}

int	ft_inputcheck(char **s, int d)
{
	int	*tmp;
	int	i;
	int	j;

	tmp = malloc(sizeof(int) * (d - 1));
	i = 0;
	while (++i < d)
	{
		if (!ft_isnum(s[i]))
			do_error();
		tmp[i] = ft_atoi(s[i]);
	}
	i = 0;
	if (!ft_issort(s, d))
		exit(EXIT_FAILURE);
	free(tmp);
	return (1);
}
