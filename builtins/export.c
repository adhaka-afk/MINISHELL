/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:45:39 by eweiberl          #+#    #+#             */
/*   Updated: 2023/12/04 09:58:26 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	print_export(t_env *env_list);
static int	check_name(char *str);

/// @brief adds a variable to the env list or overwrites existing variable
/// @param split the arguments
/// @param env_list the env list
/// @return 0 on success, 1 on fail
int	builtin_export(char **split, t_env *env_list)
{
	char	*name;
	int		i;

	if (split[0] == NULL)
		return (1);
	if (split[1] == NULL)
		return (print_export(env_list), 0);
	if (check_name(split[1]) != 0)
		return (0);
	i = 0;
	while (split[1][i] != '=')
		i++;
	name = ft_calloc(i + 2, sizeof(char));
	if (name == NULL)
		return (ft_fprintf(2, "Malloc fail in builtin export\n"), 1);
	ft_strlcpy(name, split[1], i + 2);
	if (replace_env_var(name, split[1] + i + 1, env_list) == 1)
		return (free(name), 1);
	if (split[2] != NULL)
	{
		ft_putstr_fd("Export: too many args, input after ", 2);
		ft_putstr_fd(split[2], 2);
		ft_putstr_fd(" will be ignored\n", 2);
	}
	return (free(name), 0);
}

static void	print_export(t_env *env_list)
{
	t_env	*current;

	current = env_list;
	if (current == NULL)
		ft_fprintf(2, "Env list empty\n");
	else
	{
		while (current != NULL)
		{
			printf("declare -x ");
			printf("%s\n", current->var);
			current = current->next;
		}
	}
}

/// @brief Checks if the variable name is valid
/// @param str
/// @return 0 for correct input, 2 if theres nothing to do, 1 to give an error
static int	check_name(char *str)
{
	int	i;

	i = 1;
	if (ft_isalpha(str[0]) == 0 && str[0] != '_')
		return (ft_fprintf(2, "'%s': Not a valid identifier\n", str), 1);
	while (str[i] != '=' && str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
			return (ft_fprintf(2, "'%s': Not a valid identifier\n", str), 1);
		i++;
	}
	if (str[i] != '=')
		return (2);
	return (0);
}
