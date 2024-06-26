/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:02:45 by eweiberl          #+#    #+#             */
/*   Updated: 2023/12/04 09:53:50 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/// @brief Takes the token list and expands all cmds
/// @param envp
/// @param tokens the token list
/// @return 1 if the expander fails (malloc) otherwise 0
int	expand_tokens(t_env *env_list, t_token *tokens)
{
	t_token	*current;

	current = tokens;
	while (current != NULL)
	{
		current->cmd = expander(current->cmd, env_list, 0, false);
		if (current->cmd == NULL)
			return (1);
		current = current->next;
	}
	return (0);
}

/// @brief Prints the token list
/// @param tokens the list to print
void	t_print_tokens(t_token *tokens)
{
	t_token	*current;

	current = tokens;
	while (current != NULL)
	{
		printf("Command: .%s. ID: %d\n", current->cmd, current->operation);
		current = current->next;
	}
}
