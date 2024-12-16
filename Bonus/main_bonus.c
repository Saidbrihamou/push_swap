/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:26:30 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/15 20:54:49 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	return (0);
}
