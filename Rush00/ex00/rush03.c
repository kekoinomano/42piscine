/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sealvare <sealvare@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:55:16 by sealvare          #+#    #+#             */
/*   Updated: 2022/03/20 17:08:06 by sealvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	inicial_final( int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (i == 0)
		{
			ft_putchar('A');
		}
		else if (i == col - 1)
		{
			ft_putchar('C');
		}
		else
		{
			ft_putchar('B');
		}
		i++;
	}
}

void	intermedia( int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (i == 0 || i == col - 1)
		{
			ft_putchar('B');
		}
		else
		{
			ft_putchar(' ');
		}
		i++;
	}
}

void	rush(int x, int y)
{
	int		fil;

	fil = 0;
	while (fil < y)
	{
		if (fil == 0 || fil == y - 1)
		{
			inicial_final(x);
		}
		else
		{
			intermedia(x);
		}
		ft_putchar('\n');
		fil++;
	}
}
