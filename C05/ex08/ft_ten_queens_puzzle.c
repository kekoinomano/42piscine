/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: sealvare <sealvare@student.42malaga.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/03/24 23:07:46 by sealvare          #+#    #+#             */
/*   Updated: 2022/03/24 23:07:46 by sealvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	g_queen[10];
int	g_col[10];
int	g_diag_l[19];
int	g_diag_r[19];
int	g_n;

void	print_result(void)
{
	int		i;
	char	c;

	i = 0;
	while (i < 9)
	{
		c = g_queen[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	set_params(int the_column, int the_queen, int value)
{
	g_diag_l[the_column + the_queen] = value;
	g_diag_r[the_queen - the_column + 9] = value;
	g_col[the_column] = value;
}

void	try(int the_queen)
{
	int	the_column;

	if (the_queen == 10)
	{
		print_result();
		g_n++;
	}
	the_column = 0;
	while (the_column < 10)
	{
		if (!g_col[the_column] && !g_diag_l[the_column + the_queen]
			&& !g_diag_r[the_queen - the_column + 9])
		{
			set_params(the_column, the_queen, 1);
			g_queen[the_queen] = the_column;
			try(the_queen + 1);
			set_params(the_column, the_queen, 0);
		}
		the_column++;
	}
}

int	ft_ten_queens_puzle(void)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		g_queen[i] = 0;
		g_col[i] = 0;
		i++;
	}
	i = 0;
	while (i < 19)
	{
		g_diag_l[i] = 0;
		g_diag_r[i] = 0;
		i++;
	}
	g_n = 0;
	try(0);
	return (g_n);
}
