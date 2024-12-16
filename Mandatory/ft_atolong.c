/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:55:21 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/14 22:16:35 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	skep_and_singe(int *i, const char *str)
{
	int	singe;

	singe = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
		{
			singe = -1;
		}
		(*i)++;
	}
	return (singe);
}

long	ft_atolong(const char *str)
{
	int			singe;
	int			i;
	long long	resulat;

	resulat = 0;
	i = 0;
	singe = skep_and_singe(&i, str);
	while (str[i] >= '0' && str[i] <= '9')
	{
		resulat *= 10;
		resulat += str[i] - '0';
		i++;
	}
	return (resulat * singe);
}
