/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sealvare <sealvare@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:04:03 by sealvare          #+#    #+#             */
/*   Updated: 2022/03/27 23:04:03 by sealvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	dif;
	int	*tab;

	dif = max - min;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	tab = malloc(dif * sizeof(int));
	if (!tab)
	{
		*range = 0;
		return (-1);
	}
	i = 0;
	*range = tab;
	while (i < dif)
		tab[i++] = min++;
	return (i);
}

// #include <stdio.h>
// int main()
// {
// 	int *range[1];
// 	range[0][0]=0;
// 	range[0][1]=0;
// 	range[0][2]=0;
// 	range[0][3]=0;
// 	ft_ultimate_range(range, 1, 5);
// 	for (int i = 0;i < 4;i++)
// 		printf("%d ",range[0][i]);
// }