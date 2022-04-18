/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sealvare <sealvare@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:18:41 by sealvare          #+#    #+#             */
/*   Updated: 2022/03/17 18:48:31 by sealvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

void	reiniciar(int rec, int arr[])
{
	while (rec >= 0)
	{
		if (arr[rec] < 9)
		{
			arr[rec]++;
			rec = -1;
		}
		else
		{
			arr[rec] = 0;
			rec--;
		}
	}
}

bool	comprobar_si_cumple(int arr[], int n)
{
	int		i;
	bool	cumple;

	cumple = false;
	i = n - 1;
	while (i > 0)
	{
		if (arr[i] > arr[i - 1])
		{
			cumple = true;
		}
		else
		{
			cumple = false;
			i = 0;
		}
		i--;
	}
	return (cumple);
}

void	escribir_array(int arr[], int n)
{
	bool	cumple;
	int		i;
	char	x;

	i = 0;
	cumple = comprobar_si_cumple(arr, n);
	if (cumple)
	{
		while (i < n)
		{
			x = arr[i] + '0';
			write(1, &x, 1);
			i++;
		}
		if (arr[0] != 10 - n)
		{
			write(1, ", ", 2);
		}
	}
}

void	pintar(int n)
{
	int	arr[10];
	int	i;
	int	num;
	int	rec;

	i = n - 1;
	num = 0;
	rec = n - 1;
	while (arr[0] < 9)
	{
		rec = n - 2;
		num = 0;
		while (num < 10)
		{
			arr[n - 1] = num;
			escribir_array(arr, n);
			num++;
		}
		arr[n - 1] = 0;
		reiniciar(rec, arr);
		i--;
	}
}

void	ft_print_combn(int n)
{
	if (n == 1)
	{
		write(1, "0, 1, 2, 3, 4, 5, 6, 7, 8, 9", 28);
	}
	else if (n > 1 && n < 10)
	{
		pintar(n);
	}
}
