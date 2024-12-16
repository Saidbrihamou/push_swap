/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:10:48 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/16 17:25:05 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_management(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 0)
		exit(0);
	if (cheakis_sorted(*stack_a))
	{
		stack_a->destroy_satack(stack_a);
		exit(0);
	}
	if (stack_a->size < 3)
	{
		stack_a->r_rotate_up(stack_a, 'a', 1);
		stack_a->destroy_satack(stack_a);
		exit(0);
	}
	sort_stack(stack_a, stack_b);
	stack_a->destroy_satack(stack_a);
	exit(0);
}

int	main(int c, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	**numbers;
	int		count_num;

	insialise(&stack_a);
	insialise(&stack_b);
	count_num = 0;
	if (c == 2)
	{
		numbers = ft_split(av[1], ' ');
		if (!numbers)
			exit(1);
		while (numbers[count_num])
			count_num++;
		push_all_in_stack(numbers, count_num, 1, &stack_a);
	}
	else if (c > 2)
		push_all_in_stack(&av[1], c - 1, 0, &stack_a);
	else
		return (0);
	sort_management(&stack_a, &stack_b);
	exit(0);
	return (0);
}
