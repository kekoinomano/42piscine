/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sealvare <sealvare@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:41:50 by sealvare          #+#    #+#             */
/*   Updated: 2022/04/06 12:41:01 by sealvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
		{
			return (1);
		}
		i++;
	}
	if (c == '\0')
	{
		return (1);
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (!(separator(str[i], charset)) && separator(str[i + 1], charset))
		{
			words++;
		}
		i++;
	}
	return (words);
}

void	write_word(char *dest, char *str, int i, char *charset)
{
	int	j;

	j = 0;
	while (!separator(str[i], charset))
	{
		dest[j] = str[i];
		i++;
		j++;
	}
	dest[j] = '\0';
}

void	write_split(char **split, char *str, char *charset)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (separator(str[i], charset))
		{
			i++;
		}
		else
		{
			j = 0;
			while (!(separator(str[i + j], charset)))
			{
				j++;
			}
			split[word] = malloc(sizeof(char) * (j + 1));
			write_word(split[word], str, i, charset);
			i = i + j;
			word++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		words;

	words = count_words(str, charset);
	split = malloc(sizeof(char *) * (words + 1));
	split[words] = NULL;
	write_split(split, str, charset);
	return (split);
}

// #include <stdio.h>

// int main()
// {
// 	char	**split;
// 	int		words;
// 	char *str;
// 	char *charset;

// 	str = "hola, pepe, que, hay";
// 	charset = ", ";
// 	words = count_words(str, charset);
// 	printf("%d\n", words);
// 	split = malloc(sizeof(char *) * (words + 1));
// 	split = ft_split(str, charset);
// 	for(int i = 0;i<words;i++)
// 		printf("%s\n", split[i]);
// }