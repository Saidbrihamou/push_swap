/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_management_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:59:05 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/16 17:23:24 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	handle_part2(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(line, "rr\n", 4) == 0)
	{
		stack_a->r_rotate_up(stack_a, 'a', 0);
		stack_b->r_rotate_up(stack_b, 'b', 0);
	}
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
	{
		stack_a->rr_rotate_down(stack_a, 'a', 0);
		stack_a->rr_rotate_down(stack_b, 'b', 0);
	}
	else if (ft_strncmp(line, "ss\n", 4) == 0)
	{
		stack_a->swap_2first(stack_a);
		stack_b->swap_2first(stack_b);
	}
	else
	{
		stack_a->destroy_satack(stack_a);
		free(line);
		ft_putstr_fd("Error\n", 2);
		stack_a->destroy_satack(stack_a);
		stack_b->destroy_satack(stack_b);
		exit(1);
	}
}

void	handle_instraction(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(line, "pa\n", 4) == 0)
		stack_a->pushin_this(stack_a, stack_b);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		stack_b->pushin_this(stack_b, stack_a);
	else if (ft_strncmp(line, "sa\n", 4) == 0)
		stack_a->swap_2first(stack_a);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		stack_b->swap_2first(stack_b);
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		stack_a->r_rotate_up(stack_a, 'a', 0);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		stack_b->r_rotate_up(stack_b, 'b', 0);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		stack_a->rr_rotate_down(stack_a, 'a', 0);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		stack_b->rr_rotate_down(stack_b, 'b', 0);
	else
		handle_part2(line, stack_a, stack_b);
}

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

void	sort_management(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		handle_instraction(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
	if (stack_b->size == 0 && cheakis_sorted(*stack_a) == 1)
	{
		write(1, "OK\n", 3);
	}
	else
		write(1, "KO\n", 3);
	stack_a->destroy_satack(stack_a);
	stack_b->destroy_satack(stack_b);
}
