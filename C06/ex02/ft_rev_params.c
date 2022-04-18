/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: sealvare <sealvare@student.42malaga.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/03/28 18:36:48 by sealvare          #+#    #+#             */
/*   Updated: 2022/03/28 18:36:48 by sealvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int n, char **arg)
{
	int	i;
	int	j;

	j = n - 1;
	while (j > 0)
	{
		i = 0;
		while (arg[j][i] != '\0')
		{
			write(1, &arg[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		j--;
	}
	return (0);
}
