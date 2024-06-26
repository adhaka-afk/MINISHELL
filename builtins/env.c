/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:23:40 by eweiberl          #+#    #+#             */
/*   Updated: 2023/12/04 09:55:50 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/// @brief Prints the entire env list
/// @param env_list the list to print
/// @return 0 on success, 1 if list is empty
int	builtin_env(t_env *env_list)
{
	t_env	*current;

	current = env_list;
	if (current == NULL)
		return (ft_fprintf(2, "env list empty\n"), 1);
	while (current != NULL)
	{
		printf("%s\n", current->var);
		current = current->next;
	}
	return (0);
}
