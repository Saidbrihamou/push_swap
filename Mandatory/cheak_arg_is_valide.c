/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheak_arg_is_valide.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:52:37 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/15 18:06:01 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cheakis_sorted(t_stack	stack)
{
	int		temp;
	t_Node	*curr;

	curr = stack.head;
	temp = curr->data;
	while (curr)
	{
		if (curr->data < temp)
			return (0);
		temp = curr->data;
		curr = curr->next;
	}
	return (1);
}

int	len_int(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		count++;
	}
	return (count);
}

int	is_not_digits(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	cheak_is_all_is_integer(char **numbers, int count, int isallocat)
{
	long long	result;
	int			i;

	i = 0;
	while (i < count)
	{
		result = ft_atolong(numbers[i]);
		if (result > INT_MAX || result < INT_MIN || len_int(numbers[i]) > 10 \
									|| is_not_digits(numbers[i]))
		{
			ft_putstr_fd("Error\n", 2);
			if (isallocat)
				free_tab(numbers);
			exit(1);
		}
		i++;
	}
}
