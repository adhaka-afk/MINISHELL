/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:57:07 by eweiberl          #+#    #+#             */
/*   Updated: 2023/12/04 09:55:06 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	add_env_var(char *name, char *value, t_env *env_list);

/// @brief Like getenv for the t_env struct
/// @param name the variable to look for (without the =)
/// @param env_list the list to look in
/// @return A pointer to the variable if existent (DO NOT FREE), NULL
char	*get_env_var(char *name, t_env *env_list)
{
	t_env	*current;
	char	*full_name;
	size_t	name_len;

	current = env_list;
	full_name = ft_strjoin(name, "=");
	if (full_name == NULL)
		return (ft_fprintf(2, "Malloc fail in get_env_var\n"), NULL);
	name_len = ft_strlen(full_name);
	while (current != NULL)
	{
		if (ft_strncmp(full_name, current->var, name_len) == 0)
			return (free(full_name), current->var + name_len);
		current = current->next;
	}
	free(full_name);
	return (NULL);
}

/// @brief Replaces the value of a variable
/// @param name the name of the variable to replace (WITH =)
/// @param value the new value
/// @param env_list the list of variables
/// @return 0 on succes, 1 on malloc fail
int	replace_env_var(char *name, char *value, t_env *env_list)
{
	t_env	*current;
	size_t	name_len;

	name_len = ft_strlen(name);
	current = env_list;
	while (current != NULL)
	{
		if (ft_strncmp(name, current->var, name_len) == 0)
		{
			free(current->var);
			current->var = ft_strjoin(name, value);
			if (current->var == NULL)
				return (ft_fprintf(2, "Malloc fail in replace_env\n"), 1);
			return (0);
		}
		current = current->next;
	}
	if (add_env_var(name, value, env_list) == 1)
		return (1);
	return (0);
}

/// @brief Adds the variable to the end of the env list
/// @param name the name of the variable (with =)
/// @param value the content of the var
/// @param env_list the list to add to
/// @return 1 on malloc fail, otherwise 0
static int	add_env_var(char *name, char *value, t_env *env_list)
{
	t_env	*current;
	t_env	*new_env;

	new_env = ft_calloc(1, sizeof(t_env));
	if (new_env == NULL)
		return (ft_fprintf(2, "Malloc fail in add_env\n"), 1);
	new_env->next = NULL;
	new_env->var = ft_strjoin(name, value);
	if (new_env->var == NULL)
		return (free(new_env), ft_fprintf(2, "Malloc fail in add_env\n"), 1);
	current = env_list;
	while (current->next != NULL)
		current = current->next;
	current->next = new_env;
	return (0);
}

/// @brief removes an element from the env list
/// @param name the name of the variable to remove
/// @param env_list the list to remove from
/// @return 0 on succesfull remove, 1 on element not found
int	rem_env_var(char *name, t_env **env_list)
{
	t_env	*current;
	t_env	*free_me;
	size_t	name_len;

	name_len = ft_strlen(name);
	current = *env_list;
	if (ft_strncmp(name, current->var, name_len) == 0)
	{
		*env_list = current->next;
		return (free(current->var), free(current), 0);
	}
	while (current->next != NULL)
	{
		if (ft_strncmp(name, current->next->var, name_len) == 0)
		{
			free_me = current->next;
			current->next = free_me->next;
			return (free(free_me->var), free(free_me), 0);
		}
		current = current->next;
	}
	return (1);
}
