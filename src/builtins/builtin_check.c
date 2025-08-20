/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:48:20 by xriera-c          #+#    #+#             */
/*   Updated: 2024/06/25 15:53:29 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	run_builtin(t_sh *sh_data, char **cmd)
{
	if (!ft_strncmp(cmd[0], "export", 6) && ft_strlen(cmd[0]) == 6
		&& sh_data->processes == 1)
		return (ft_export(sh_data->env, cmd, 0));
	if (!ft_strncmp(cmd[0], "cd", 2) && ft_strlen(cmd[0]) == 2
		&& sh_data->processes == 1)
		return (ft_cd(cmd[1], sh_data->env));
	if (!ft_strncmp(cmd[0], "unset", 5) && ft_strlen(cmd[0]) == 5
		&& sh_data->processes == 1)
		return (ft_unset(sh_data->env, cmd, 0));
	if (!ft_strncmp(cmd[0], "exit", 4) && ft_strlen(cmd[0]) == 4
		&& sh_data->processes == 1) 
		{
			if (getenv("DESKTOP_SESSION") == NULL)
				ft_printf(2, RED":( "END " No exit allowed, you're trapped\n");
			else 
				return (ft_exit(sh_data, cmd));
		} 	
	return (-1);
}

int	builtin_check(char **cmd, t_env *env)
{
	if (!ft_strncmp(cmd[0], "echo", 4) && ft_strlen(cmd[0]) == 4)
		return (ft_echo(cmd));
	if (!ft_strncmp(cmd[0], "pwd", 3) && ft_strlen(cmd[0]) == 3)
		return (ft_pwd(env));
	if (!ft_strncmp(cmd[0], "env", 3) && ft_strlen(cmd[0]) == 3)
		return (ft_env(env->env_arr));
	if (!ft_strncmp(cmd[0], "export", 6) && ft_strlen(cmd[0]) == 6)
		return (ft_export(env, cmd, 0));
	if (!ft_strncmp(cmd[0], "cd", 2) && ft_strlen(cmd[0]) == 2)
		return (ft_cd(cmd[1], env));
	if (!ft_strncmp(cmd[0], "unset", 5) && ft_strlen(cmd[0]) == 5)
		return (0);
	if (!ft_strncmp(cmd[0], "exit", 4) && ft_strlen(cmd[0]) == 4)
		return (0);
	return (-1);
}
