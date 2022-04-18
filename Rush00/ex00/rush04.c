/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sealvare <sealvare@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:55:16 by sealvare          #+#    #+#             */
/*   Updated: 2022/03/20 17:08:12 by sealvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	inicial(int x)
{
	int	col;

	col = 0;
	while (col < x)
	{
		if (col == 0)
		{
			ft_putchar('A');
		}
		else if (col == x - 1)
		{
			ft_putchar('C');
		}
		else
		{
			ft_putchar('B');
		}
		col++;
	}
}

void	final(int x)
{
	int	col;

	col = 0;
	while (col < x)
	{
		if (col == 0)
		{
			ft_putchar('C');
		}
		else if (col == x - 1)
		{
			ft_putchar('A');
		}
		else
		{
			ft_putchar('B');
		}
		col++;
	}
}

void	intermedio(int x)
{
	int	col;

	col = 0;
	while (col < x)
	{
		if (col == 0 || col == x - 1)
		{
			ft_putchar('B');
		}
		else
		{
			ft_putchar(' ');
		}
		col++;
	}
}

void	rush(int x, int y)
{
	int		fil;

	fil = 0;
	while (fil < y)
	{
		if (fil == 0)
		{
			inicial(x);
		}
		else if (fil == y - 1)
		{
			final(x);
		}
		else
		{
			intermedio(x);
		}
		ft_putchar('\n');
		fil++;
	}
}
