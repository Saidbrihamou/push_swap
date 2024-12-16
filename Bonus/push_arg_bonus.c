/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_arg_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:17:29 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/15 20:55:03 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	isexist(t_stack *stack, int n)
{
	t_Node	*curr;

	curr = stack->head;
	while (curr)
	{
		if (curr->data == n)
			return (1);
		curr = curr->next;
	}
	return (0);
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

void	push_all_in_stack(char **numbers, int count_numbers, \
								int isallocat, t_stack *stack)
{
	int	i;
	int	number;

	i = 0;
	cheak_is_all_is_integer(numbers, count_numbers, isallocat);
	count_numbers--;
	while (count_numbers >= 0)
	{
		number = ft_atolong(numbers[count_numbers]);
		if (isexist(stack, number))
		{
			ft_putstr_fd("Error\n", 2);
			if (isallocat)
				free_tab(numbers);
			stack->destroy_satack(stack);
			exit(1);
		}
		stack->push(stack, number);
		count_numbers--;
	}
	if (isallocat)
		free_tab(numbers);
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
