/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:26:07 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/23 20:24:05 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stddef.h>

# define MY_UINT_MAX 4294967295
# define ERROR 1

enum					e_error_type
{
	NO_ERROR,
	MEM_ERR,
	INT_OVERFLOW,
	DUPLICATED_ELEMENT,
	SYNTAX_ERR,
	UNKNOWN_INSTRUCTION,
	IS_ERROR,
};

enum					e_path_type
{
	CONFLICT,
	COMMON_ROTATE,
	COMMON_R_ROTATE,
};

enum					e_rotation_type
{
	STANDARD,
	REVERSE,
};

typedef enum e_stack
{
	STACK_A,
	STACK_B,
}						t_stack;

typedef struct s_lst
{
	struct s_lst		*prev;
	struct s_lst		*next;
	int					value;
}						t_lst;

typedef struct s_move
{
	struct s_lst		*target;
	struct s_lst		*match;
	enum e_path_type	type;
}						t_move;

struct					s_stacks
{
	struct s_lst		*a;
	struct s_lst		*b;
};

char					**get_arguments(int argc, char **argv);
t_lst					*extract_elements(char **elements);
int						ft_safe_atoi(char *arg, int *error);

void					ft_lstclear(t_lst *head);
void					ft_lstadd_back(t_lst **head, t_lst *new);
t_lst					*ft_lst_new(t_lst *head);
size_t					ft_lst_size(t_lst *head);

int						error_manager(enum e_error_type type);

void					action_swap(t_lst **head);
void					action_push(t_lst **head_src, t_lst **head_dst);
void					action_rotate(t_lst **head);
void					action_reverse_rotate(t_lst **head);

void					sa(t_lst **head_stack_a);
void					pa(struct s_stacks *stacks);
void					ra(t_lst **head_stack_a);
void					rra(t_lst **head_stack_a);
void					sb(t_lst **head_stack_b);
void					pb(struct s_stacks *stacks);
void					rb(t_lst **head_stack_b);
void					rrb(t_lst **head_stack_b);
void					ss(struct s_stacks *stacks);
void					rr(struct s_stacks *stacks);
void					rrr(struct s_stacks *stacks);

void					sort_elements(struct s_stacks stacks);
void					sort_three_elements(t_lst **stack_a);

size_t					get_difference(int a, int b);
size_t					get_max(size_t a, size_t b);

size_t					get_position(t_lst *head, t_lst *to_find);
t_lst					*find_greatest(t_lst *head);
t_lst					*find_lowest(t_lst *head);
void					set_moves_to_top_count(t_lst *head, t_lst *target,
							size_t moves_count[2]);

void					move_element_to_top(t_lst **stack, t_lst *target,
							t_stack stack_type);
void					do_move(struct s_stacks *stacks, t_move best_move);
t_move					create_move(struct s_stacks stacks, t_lst *to_move);

t_lst					*find_nearest_low(t_lst *head, int reference_value);
t_lst					*find_nearest_high(t_lst *head, int reference_value);

size_t					get_score(struct s_stacks stacks, t_lst *target);
enum e_path_type		get_best_path(struct s_stacks stacks, t_lst *target,
							t_lst *match);

bool					check_for_empty_arg(char **argv);

void					clear_tab(char **s);
char					*get_next_line(int fd);

#endif
