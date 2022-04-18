/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sealvare <sealvare@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:11:01 by sealvare          #+#    #+#             */
/*   Updated: 2022/03/23 14:52:29 by sealvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	the_checks(int i, char *str)
{
	while (str[i] != '\0' && ((str[i] == '\t' || str[i] == '\v'
				|| str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
				|| str[i] == ' ' )))
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	menos;
	int	numero;

	i = 0;
	menos = 0;
	numero = 0;
	i = the_checks(i, str);
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			menos++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		numero = numero * 10 + str[i] - 48;
		i++;
	}
	if ((menos % 2) == 0)
		return (numero);
	else
		return (-numero);
}
