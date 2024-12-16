/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:46:20 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/14 21:48:42 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_in_stackint(t_stack *stack)
{
	int		max;
	t_Node	*curr;

	curr = stack->head;
	max = curr->data;
	while (curr)
	{
		if (max < curr->data)
			max = curr->data;
		curr = curr->next;
	}
	return (max);
}

int	get_min_in_stack(t_stack *stack)
{
	int		min;
	t_Node	*curr;

	curr = stack->head;
	min = curr->data;
	while (curr)
	{
		if (min > curr->data)
			min = curr->data;
		curr = curr->next;
	}
	return (min);
}

void	rotate_to_sort(t_stack *stack)
{
	int	min;

	min = get_min_in_stack(stack);
	to_top(min, stack, 'a', 1);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	push_in_b(stack_a, stack_b);
	sort_three(stack_a);
	while (stack_b->size > 0)
	{
		push_the_shep(stack_a, stack_b);
	}
	rotate_to_sort(stack_a);
}
