/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:41:53 by lduthill          #+#    #+#             */
/*   Updated: 2023/03/29 14:49:21 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		main(void)
{
	t_vars	vars;

	size_of_map(&vars);
	print_map(&vars);
	if (size_of_map(&vars) == 0)
		return (ft_printf("[SO - LONG] Error: Invalid map size"));
	if (check_map(&vars) == 0)
		return (ft_printf("[SO - LONG] Error: Invalid map"));
	if (check_arround(&vars) == 0)
		return (ft_printf("[SO - LONG] Error: Invalid patern of map"));
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.height * 64, vars.width * 64, "So Long !");
	mlx_loop(vars.mlx);
}