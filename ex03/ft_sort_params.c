/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:16:53 by ydumaine          #+#    #+#             */
/*   Updated: 2022/01/30 13:04:40 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strncmp(char *s1, char *s2)
{
	int unsigned	i;
	int				c;
	int				a;
	int				b;

	i = 0;
	c = 0;
	while ((s1[i] || s2[i]))
	{
		a = s1[i];
		b = s2[i];
		if (s1[i] < 0)
		a = 128 - s1[i];
		if (s2[i] < 0)
		b = 128 - s1[i];
		if (a > b)
			c = 1;
		else if (a < b)
			c = -1;
		if (c != 0)
			break ;
	i++;
	}
	return (c);
}

void	ft_print(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		write(1, &argv[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_tri(int	*classe, int argc, char **argv)
{
	int	i;
	int	j;
	int	x;

	i = 1;
	while (i <= argc - 2)
	{
		x = classe[i];
		j = i;
		while (j > 0 && (ft_strncmp(argv[j], argv[x]) == 1))
		{
				classe[j] = classe[j - 1];
				j = j - 1;
		}
		classe[j] = x;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	classe[1000];
	int	i;

	i = 1;
	while (i <= argc - 1)
	{
		classe[i - 1] = i;
		i++;
	}
	i = 1;
	ft_tri(classe, argc, argv);
	i = 0;
	while (i <= argc - 2)
	{
		ft_print(argv[classe[i]]);
		i++;
	}
}
