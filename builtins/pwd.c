/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:35:08 by eweiberl          #+#    #+#             */
/*   Updated: 2023/12/04 09:58:42 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/// @brief Prints the current working directory
/// @param env_list the environment list
/// @return 0 on success, 1 if PWD doesnt exist
int	builtin_pwd(t_env *env_list)
{
	char	*pwd_str;

	(void)env_list;
	pwd_str = getcwd(NULL, 0);
	if (pwd_str == NULL)
		return (ft_fprintf(2, "pwd: getcwd fail\n"), 1);
	printf("%s\n", pwd_str);
	free(pwd_str);
	return (0);
}
