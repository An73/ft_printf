/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:36:45 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/12 13:36:47 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		procent(char **p, va_list ap)
{
	int		width;
	char	flg;
	int		i;

	width = 0;
	flg = 0;
	if (*(++(*p)) == '%')
	{
		write(1, "%", 1);
		(*p)++;
		return (1);
	}
	while (*(*p) == '-' || *(*p) == '+'\
	|| *(*p) == ' ' || *(*p) == '#' || *(*p) == '0')
	{
		flags((*p), &flg);
		(*p)++;
	}
	while (*(*p) >= '0' && *(*p) <= '9')
	{
		width = width * 10 + *(*p) - '0';
		(*p)++;
	}
	i = mod_conv(width, flg, p, ap);
	return (i);
}
