/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:03:39 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/08 16:20:09 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



long long	ft_atoi(const char *str)
{
	long long int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == ' '
		|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (str[i])
	{
		while (str[i] >= '0' && str[i] <= '9' && str[i])
			res = res * 10 + (str[i++] - '0');
		if (str[i])
			return 2147483650;
	}
	return (res * sign);
}
