/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_stack_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:13:06 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/15 12:30:58 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_Node	*new_node(int data)
{
	t_Node	*node;

	node = malloc(sizeof(t_Node));
	if (node == NULL)
		exit(1);
	node->next = NULL;
	node->data = data;
	return (node);
}

void	push_stack(t_stack *stack, int data)
{
	t_Node	*temp;

	stack->size++;
	if (!stack->head)
	{
		stack->head = new_node(data);
		return ;
	}
	temp = stack->head;
	stack->head = new_node(data);
	stack->head->next = temp;
}

void	pop_stack(t_stack *stack)
{
	t_Node	*temp;

	if (stack->size == 0)
		return ;
	stack->size--;
	temp = stack->head->next;
	free(stack->head);
	stack->head = temp;
}

void	destroy_satack(t_stack *stack)
{
	t_Node	*temp;

	while (stack->head)
	{
		temp = stack->head;
		stack->head = stack->head->next;
		free(temp);
	}
	stack->size = 0;
	stack->head = NULL;
}

int	top(t_stack *stack)
{
	if (stack->size == 0)
		return (0);
	return (stack->head->data);
}
