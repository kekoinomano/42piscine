/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sealvare <sealvare@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:55:01 by sealvare          #+#    #+#             */
/*   Updated: 2022/03/17 10:55:22 by sealvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_is_negative(int n)
{
	char	ans;

	if (n < 0)
	{
		ans = 'N';
		write(1, &ans, 1);
	}
	else
	{
		ans = 'P';
		write(1, &ans, 1);
	}
}
