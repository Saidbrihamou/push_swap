/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:56:22 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/16 10:45:25 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_Node
{
	int				data;
	struct s_Node	*next;
}	t_Node;

typedef struct s_stack
{
	int		size;
	t_Node	*head;
	void	(*push)(struct s_stack *stack, int data);
	void	(*pop)(struct s_stack *stack);
	int		(*top)(struct s_stack *stack);
	void	(*destroy_satack)(struct s_stack *stack);
	int		(*swap_2first)(struct s_stack *stack, int (*cmp)(int, int));
	void	(*pushin_this)(struct s_stack *this, struct s_stack *from);
	void	(*r_rotate_up)(struct s_stack *stack, char, int);
	void	(*rr_rotate_down)(struct s_stack *stack, char, int);
}	t_stack;

typedef struct s_data_to_top
{
	int	n_rotate;
	int	index;
}	t_data_to_top;

typedef struct s_data_push
{
	int				to_push;
	int				on_push;
	t_data_to_top	p_to_push;
	t_data_to_top	p_on_push;
	int				pris;
}	t_data_push;

void		ft_putstr_fd(char *s, int fd);
void		insialise(t_stack *stack);
size_t		ft_strlen(const char *s);
void		to_top(int moveto_top, t_stack *stack, char a_or_b, int if_pr);
void		sort_stack(t_stack *stack_a, t_stack *stack_b);
int			get_min_in_stack(t_stack *stack);
int			get_max_in_stackint(t_stack *stack);
char		**ft_split(char const *s, char c);
long		ft_atolong(const char *str);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
void		push_stack(t_stack *stack, int data);
void		pop_stack(t_stack *stack);
void		destroy_satack(t_stack *stack);
int			top(t_stack *stack);
t_Node		*new_node(int data);
t_data_push	get_the_shepin_b(t_stack *stack_a, t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);
void		push_the_shep(t_stack *stack_a, t_stack *stack_b);
void		push_in_b(t_stack *stack_a, t_stack *stack_b);
void		sort_three(t_stack *stack);
void		cheak_is_all_is_integer(char **numbers, int count, int isallocat);
int			isexist(t_stack *stack, int n);
void		free_tab(char **tab);
int			cheakis_sorted(t_stack	stack);
#endif