/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: sealvare <sealvare@student.42malaga.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/03/28 18:38:05 by sealvare          #+#    #+#             */
/*   Updated: 2022/03/28 18:38:05 by sealvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	sort(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	print_params(int n, char **arg)
{
	int	j;
	int	i;

	i = 1;
	while (i < n)
	{
		j = 0;
		while (arg[i][j] != '\0')
		{
			write(1, &arg[i][j], 1);
			j++;
		}
		arg[i][j] = '\0';
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

int	main(int n, char **arg)
{
	char	*swap;
	int		i;

	i = 1;
	while (i < n - 1)
	{
		if (sort(arg[i], arg[i + 1]) > 0)
		{
			swap = arg[i];
			arg[i] = arg[i + 1];
			arg[i + 1] = swap;
			i = 1;
		}
		else
			i++;
	}
	print_params(n, arg);
	return (0);
}
