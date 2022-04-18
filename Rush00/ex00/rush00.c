/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sealvare <sealvare@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:55:16 by sealvare          #+#    #+#             */
/*   Updated: 2022/03/20 17:07:46 by sealvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	inicial_final( int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (i == 0 || i == col - 1)
		{
			ft_putchar('o');
		}
		else
		{
			ft_putchar('-');
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
			ft_putchar('|');
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
