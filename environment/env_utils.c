/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:00:56 by eweiberl          #+#    #+#             */
/*   Updated: 2023/12/04 09:55:14 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/// @brief Frees env list and malloced vars
/// @param env_list the list to free
/// @todo put together with free_tokens
/// @see lexer.c void free_tokens
void	free_env_struct(t_env **env_list)
{
	t_env	*cur_env;
	t_env	*next_env;

	if (*env_list == NULL)
		return ;
	cur_env = *env_list;
	while (cur_env != NULL)
	{
		next_env = cur_env->next;
		if (cur_env->var != NULL)
			free(cur_env->var);
		free(cur_env);
		cur_env = next_env;
	}
	*env_list = NULL;
}

/// @brief Prints the t_env struct
/// @param environment_list the struct to print
void	t_print_env_struct(t_env *environment_list)
{
	t_env	*current;

	current = environment_list;
	if (current == NULL)
	{
		ft_fprintf(2, "environment struct empty\n");
		return ;
	}
	while (current != NULL)
	{
		printf("%s\n", current->var);
		current = current->next;
	}
}

/// @brief Returns the elements in the linked list
/// @param env_list the list
/// @throw a listsize > INT_MAX returns incorrect sizes
/// @return the amount of elements in the list
int	env_size(t_env *env_list)
{
	int		size;
	t_env	*current;

	current = env_list;
	size = 0;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}
