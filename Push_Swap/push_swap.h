/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:47:24 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/06/02 15:05:26 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 42
# define MAXINT 2147483647

typedef struct s_stack
{
	int				content;
	int				lenght;
	int				index;
	int				pre_index;
	int				mark;
	int				pair;
	int				flag;
	int				instruc;
	struct s_stack	*next;
}	t_stack;

void	ft_putchar_fd(char c);
char	**ft_split(char const *s);
void	ft_lstadd_back(t_stack **alst, t_stack *new);
t_stack	*ft_lstnew(int content);
int		checking_pars(int ac, char **av);
size_t	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s);
int		ft_isdigit(int c);
void	print_node(t_stack *node_a);
void	creat_stack(t_stack **node, char **av);
int		ft_strcmp(const char *s1, const char *s2);
int		numcompare(int a, int b);
void	swap_a(t_stack **node);
void	swap_b(t_stack **node);
void	ss(t_stack **node_a, t_stack **node_b);
void	push_b(t_stack **node_a, t_stack **node_b);
void	push_a(t_stack **node_a, t_stack **node_b);
t_stack	*ft_lstlast(t_stack	*lst);
void	rotate_a(t_stack **node, int a);
void	rotate_b(t_stack **node, int a);
void	rr(t_stack **node_a, t_stack **node_b);
void	reverse_rotate_a(t_stack **node, int a);
void	ft_lstadd_front(t_stack **alst, t_stack *new);
void	reverse_rotate_b(t_stack **node, int a);
void	rrr(t_stack **node_a, t_stack **node_b);
int		ft_lstsize(t_stack *lst);
int		*init_tab(int i);
int		find_lentab(t_stack *node);
t_stack	*update_len(t_stack *node);
t_stack	*get_len(t_stack *stack);
t_stack	*find_element(t_stack *stack, int index);
void	index_stack(t_stack *stack);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	check_for_min_elem(t_stack *stack_a, t_stack *stack_b);
void	re_index_stack(t_stack *stack_a, t_stack *stack_b);
void	top_element_a(t_stack **stack, t_stack *node);
void	top_element_b(t_stack **stack, t_stack *node);
t_stack	*find_min_head(t_stack *stack);
void	print_rra(void);
void	print_rrb(void);
void	print_ra(void);
void	print_rb(void);
void	print_rrr(void);
void	print_rr(void);
void	clr_list(t_stack **head);
void	check_in(int ac, char **av, t_stack **a);
void	sort4_5(t_stack **stack_a, t_stack **stack_b, int size);
void	sort2(t_stack **stack_a);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*get_line(char **data);
char	*get_final_line(char **data);
int		ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2);
void	ft_exit(t_stack **a);
char	*ft_strdup(char *s1);
void	push_to_b(t_stack **stack_a, t_stack **stack_b, int len);
void	double_rotate_dec(t_stack **a, t_stack **b, t_stack *n_a, t_stack *n_b);
void	move_best_element(t_stack **stack_a, t_stack **stack_b, t_stack *n_b);
void	ft_sorting(t_stack **stack_a, t_stack **stack_b);
t_stack	*find_min_head(t_stack *stack);
void	double_r(t_stack **a, t_stack **b, t_stack *node_a, t_stack *node_b);
void	double_rr(t_stack **a, t_stack **b, t_stack *node_a, t_stack *node_b);
void	double_ra_rrb(t_stack **a, t_stack **b, t_stack *n_a, t_stack *n_b);
void	double_rb_rra(t_stack **a, t_stack **b, t_stack *n_a, t_stack *n_b);
void	config_instruc_b(t_stack *b, int l_b, int l_a);
t_stack	*best_element(t_stack *stack);
void	index_instruc(t_stack *stack_a, t_stack *stack_b);
int		ft_markup(t_stack *stack, t_stack *node);
int		sorted(t_stack *a);

int		ft_putchar(char c);
#endif