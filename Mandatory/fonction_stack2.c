/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_stack2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:03:23 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/14 20:14:29 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_2first(t_stack *stack, int (*cmp)(int, int))
{
	int	temp1;
	int	temp2;

	if (stack->size < 2)
		return (0);
	temp1 = stack->top(stack);
	stack->pop(stack);
	temp2 = stack->top(stack);
	stack->pop(stack);
	if (cmp(temp1, temp2) != 0)
	{
		stack->push(stack, temp1);
		stack->push(stack, temp2);
		return (1);
	}
	stack->push(stack, temp2);
	stack->push(stack, temp1);
	return (0);
}

void	pushin_this(t_stack *this, t_stack *from)
{
	if (from->size == 0)
		return ;
	this->push(this, from->top(from));
	from->pop(from);
}

void	r_rotate_up(t_stack *stack, char a_or_b, int if_pr)
{
	t_Node	*current;
	t_Node	*temp;

	if (stack->size < 2)
		return ;
	temp = new_node(stack->top(stack));
	stack->pop(stack);
	current = stack->head;
	while (current->next)
	{
		current = current->next;
	}
	current->next = temp;
	stack->size++;
	if (if_pr)
	{
		write(1, "r", 1);
		write(1, &a_or_b, 1);
		write(1, "\n", 1);
	}
}

void	rr_rotate_down(t_stack *stack, char a_or_b, int if_pr)
{
	int		temp;
	t_Node	*current;

	if (stack->size < 2)
		return ;
	current = stack->head;
	while (current->next->next)
	{
		current = current->next;
	}
	temp = current->next->data;
	free(current->next);
	current->next = NULL;
	stack->size--;
	stack->push(stack, temp);
	if (if_pr)
	{
		write(1, "rr", 2);
		write(1, &a_or_b, 1);
		write(1, "\n", 1);
	}
}

void	insialise(t_stack *stack)
{
	stack->head = NULL;
	stack->size = 0;
	stack->push = push_stack;
	stack->pop = pop_stack;
	stack->top = top;
	stack->destroy_satack = destroy_satack;
	stack->swap_2first = swap_2first;
	stack->pushin_this = pushin_this;
	stack->r_rotate_up = r_rotate_up;
	stack->rr_rotate_down = rr_rotate_down;
}
