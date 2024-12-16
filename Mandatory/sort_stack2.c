/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:17:50 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/15 17:48:29 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->r_rotate_up(stack_a, 'a', 0);
	stack_b->r_rotate_up(stack_b, 'b', 0);
	write(1, "rr\n", 3);
}

void	decrement(int *a, int *b)
{
	*a = *a - 1;
	*b = *b - 1;
}

void	if_rrr_move(t_stack *stack_a, t_stack *stack_b, t_data_push var)
{
	if (var.p_on_push.n_rotate > 0 && var.p_to_push.n_rotate > 0)
		rrr(stack_a, stack_b);
	else if (var.p_on_push.n_rotate > 0)
		stack_a->rr_rotate_down(stack_a, 'a', 1);
	else
		stack_b->rr_rotate_down(stack_b, 'b', 1);
}

int	to_top_a_and_b(t_stack *stack_a, t_stack *stack_b, t_data_push var)
{
	while (var.p_on_push.n_rotate > 0 || var.p_to_push.n_rotate > 0)
	{
		if (var.p_on_push.index > stack_a->size / 2 && \
						var.p_to_push.index > stack_b->size / 2)
			if_rrr_move(stack_a, stack_b, var);
		else if (var.p_on_push.index <= stack_a->size / 2 && \
						var.p_to_push.index <= stack_b->size / 2)
		{
			if (var.p_on_push.n_rotate > 0 && var.p_to_push.n_rotate > 0)
				rr(stack_a, stack_b);
			else if (var.p_on_push.n_rotate > 0)
				stack_a->r_rotate_up(stack_a, 'a', 1);
			else
				stack_b->r_rotate_up(stack_b, 'b', 1);
		}
		else
			return (0);
		decrement(&var.p_on_push.n_rotate, &var.p_to_push.n_rotate);
	}
	return (1);
}

void	push_the_shep(t_stack *stack_a, t_stack *stack_b)
{
	t_data_push	var;

	var = get_the_shepin_b(stack_a, stack_b);
	if (to_top_a_and_b(stack_a, stack_b, var) == 0)
	{
		to_top(var.on_push, stack_a, 'a', 1);
		to_top(var.to_push, stack_b, 'b', 1);
	}
	stack_a->pushin_this(stack_a, stack_b);
	write(1, "pa\n", 3);
}
