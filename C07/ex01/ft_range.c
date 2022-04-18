/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sealvare <sealvare@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:42:39 by sealvare          #+#    #+#             */
/*   Updated: 2022/03/27 22:42:39 by sealvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*ptr;
	int	temp;

	temp = min;
	if (min >= max)
		return (0);
	ptr = (int *)malloc(sizeof(int) * (max - min));
	if (!ptr)
		return (0);
	i = 0;
	while (i < (max - min))
	{
		ptr[i++] = temp;
		temp++;
	}
	return (ptr);
}

// int main()
// {
// 	int min = 1, max = 4;
// 	int *p;
// 	p = (int *)malloc(sizeof(int) * (min - max));
// 	p = ft_range(1,4);
// 	for (int i = 0; i<(max-min);i++)
// 		printf("%d", p[i]);
// }