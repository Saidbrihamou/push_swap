/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:40:39 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/15 17:12:12 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_tab(t_stack *stack)
{
	int		*tab;
	t_Node	*curr;
	int		i;

	i = 0;
	tab = malloc(stack->size * sizeof(int));
	if (!tab)
		exit(1);
	i = 0;
	curr = stack->head;
	while (curr)
	{
		tab[i++] = curr->data;
		curr = curr->next;
	}
	return (tab);
}

int	get_center(t_stack *stack)
{
	int		temp;
	int		i;
	int		j;
	int		*tab;

	tab = get_tab(stack);
	i = 0;
	while (i < stack->size - 1)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	i = tab[stack->size / 2];
	free(tab);
	return (i);
}

void	push_in_b(t_stack *stack_a, t_stack *stack_b)
{
	int		center;

	center = get_center(stack_a);
	while (stack_a->size > 3 && cheakis_sorted(*stack_a) == 0)
	{
		stack_b->pushin_this(stack_b, stack_a);
		write(1, "pb\n", 3);
		if (stack_b->top(stack_b) < center && stack_b->size > 1)
			stack_b->r_rotate_up(stack_b, 'b', 1);
	}
}

int	cmp_small_to_top(int a, int b)
{
	return (a > b);
}

void	sort_three(t_stack *stack)
{
	if (stack->head->data > stack->head->next->data && \
			stack->head->data > stack->head->next->next->data)
		stack->r_rotate_up(stack, 'a', 1);
	else if (stack->head->data < stack->head->next->data && \
			stack->head->next->next->data < stack->head->next->data)
		stack->rr_rotate_down(stack, 'a', 1);
	if (stack->swap_2first(stack, cmp_small_to_top))
		write(1, "sa\n", 3);
}
