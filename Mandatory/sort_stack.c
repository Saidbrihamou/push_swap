/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:12:45 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/14 21:18:02 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data_to_top	get_pris_totop(t_stack *stack, int var)
{
	t_Node			*curr;
	t_data_to_top	data;

	curr = stack->head;
	data.index = 0;
	while (curr)
	{
		if (curr->data == var)
			break ;
		data.index++;
		curr = curr->next;
	}
	if (data.index > stack->size / 2)
		data.n_rotate = stack->size - data.index;
	else
		data.n_rotate = data.index;
	return (data);
}

int	get_on_push(t_stack *stack, int to_push)
{
	t_Node	*curr;
	int		on_push;

	curr = stack->head;
	on_push = get_max_in_stackint(stack);
	while (curr)
	{
		if (on_push > curr->data && curr->data > to_push)
			on_push = curr->data;
		curr = curr->next;
	}
	if (to_push > on_push)
		return (get_min_in_stack(stack));
	return (on_push);
}

t_data_push	get_the_shepin_b(t_stack *stack_a, t_stack *stack_b)
{
	t_data_push	data;
	t_data_push	temp;
	t_Node		*curr;

	curr = stack_b->head;
	data.to_push = stack_b->head->data;
	data.on_push = get_on_push(stack_a, data.to_push);
	data.p_on_push = get_pris_totop(stack_a, data.on_push);
	data.p_to_push = get_pris_totop(stack_b, data.to_push);
	data.pris = data.p_on_push.n_rotate + data.p_to_push.n_rotate;
	while (curr)
	{
		temp.to_push = curr->data;
		temp.on_push = get_on_push(stack_a, temp.to_push);
		temp.p_on_push = get_pris_totop(stack_a, temp.on_push);
		temp.p_to_push = get_pris_totop(stack_b, temp.to_push);
		temp.pris = temp.p_on_push.n_rotate + temp.p_to_push.n_rotate;
		if (temp.pris < data.pris)
			data = temp;
		curr = curr->next;
	}
	return (data);
}

void	to_top(int moveto_top, t_stack *stack, char a_or_b, int if_pr)
{
	int		index;
	t_Node	*curr;
	int		n_rotate;

	curr = stack->head;
	index = 0;
	while (curr)
	{
		if (moveto_top == curr->data)
			break ;
		index++;
		curr = curr->next;
	}
	if (index > stack->size / 2)
		n_rotate = stack->size - index;
	else
		n_rotate = index;
	while (n_rotate > 0)
	{
		if (index > stack->size / 2)
			stack->rr_rotate_down(stack, a_or_b, if_pr);
		else
			stack->r_rotate_up(stack, a_or_b, if_pr);
		n_rotate--;
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->rr_rotate_down(stack_a, 'a', 0);
	stack_b->rr_rotate_down(stack_b, 'b', 0);
	write(1, "rrr\n", 4);
}
