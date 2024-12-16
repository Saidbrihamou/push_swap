/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrihamo <sbrihamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:18:40 by sbrihamo          #+#    #+#             */
/*   Updated: 2024/12/16 10:45:21 by sbrihamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_and_free(const char *buffer, ssize_t	len_buffer, \
										char *temp, size_t *num_line_read);
char	*create_result(char *temp, char **buff_static, size_t *line_read, \
													ssize_t num_read);
void	ft_update_rest_and_temp(char *temp, char *buff_static, \
													size_t *num_line_read);
size_t	count_newline(const char *str);
void	ft_cat(char *dst, const char *src, size_t len_src);
int		my_free(char **p);

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
	int		(*swap_2first)(struct s_stack *stack);
	void	(*pushin_this)(struct s_stack *, struct s_stack *);
	void	(*r_rotate_up)(struct s_stack *stack, char, int);
	void	(*rr_rotate_down)(struct s_stack *stack, char, int);
}	t_stack;

void	insialise(t_stack *stack);
void	push_stack(t_stack *stack, int data);
void	pop_stack(t_stack *stack);
void	destroy_satack(t_stack *stack);
int		top(t_stack *stack);
t_Node	*new_node(int data);

char	**ft_split(char const *s, char c);
long	ft_atolong(const char *str);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	push_all_in_stack(char **numbers, int count_numbers, \
								int isallocat, t_stack *stack);
void	cheak_is_all_is_integer(char **numbers, int count, int isallocat);
void	sort_management(t_stack *stack_a, t_stack *stack_b);
void	free_tab(char **tab);
#endif