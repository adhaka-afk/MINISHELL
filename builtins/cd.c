/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:46:10 by eweiberl          #+#    #+#             */
/*   Updated: 2023/12/04 09:55:31 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	set_oldpwd(t_env *env_list);

/// @brief Changes the directory and updates OLDPWD and PWD
/// @param cmds the arguments to cd
/// @param env_list the environment list
/// @throw Could segfault if PWD doesnt exist
/// @return 0 on succes, 1 on malloc fail or wrong command
int	builtin_cd(char **cmds, t_env *env_list)
{
	char	*path;
	char	*new_pwd;

	if (cmds[0] == NULL)
		return (1);
	if (cmds[1] == NULL || ft_strncmp(cmds[1], "~", 2) == 0)
		path = get_env_var("HOME", env_list);
	else if (cmds[2] == NULL)
		path = cmds[1];
	else
		return (ft_fprintf(2, "cd: too many args\n"), 1);
	if (set_oldpwd(env_list) == 1)
		return (1);
	chdir(path);
	if (get_env_var("PWD", env_list) == NULL)
		return (0);
	new_pwd = getcwd(NULL, 0);
	if (new_pwd == NULL)
		return (ft_fprintf(2, "cd: getcwd fail\n"), 1);
	if (replace_env_var("PWD=", new_pwd, env_list) == 1)
		return (free(new_pwd), 1);
	free(new_pwd);
	return (0);
}

static int	set_oldpwd(t_env *env_list)
{
	char	*pwd_str;

	if (get_env_var("OLDPWD", env_list) == NULL)
		return (0);
	pwd_str = getcwd(NULL, 0);
	if (pwd_str == NULL)
		return (ft_fprintf(2, "cd: set_oldpwd: getcwd fail\n"), 1);
	if (replace_env_var("OLDPWD=", pwd_str, env_list) == 1)
		return (free(pwd_str), 1);
	free(pwd_str);
	return (0);
}
