/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:23:00 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/12/08 13:30:18 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "ft_printf.h"
#include <limits.h>

unsigned int	reg_to_int(char *reg)
{
	unsigned int	value;
	unsigned int	i;
	unsigned int	tmp;

	i = 0;
	value = 0;
	while (i < REG_SIZE * 2)
	{
		if (reg[i] >= 'A')
			tmp = reg[i] - 'A' + 10;
		else
			tmp = reg[i] - '0';
		tmp = tmp * ft_power(16, REG_SIZE * 2 - i - 1);
		value += tmp;
		i++;
	}
	return (value);
}

char			*int_to_reg(unsigned int value)
{
	char			*tmp;
	unsigned int	tmp2;
	unsigned int	i;

	tmp2 = 0;
	tmp = (char *)malloc(sizeof(char) * (REG_SIZE * 2));
	ft_memset(tmp, '0', REG_SIZE * 2);
	i = 0;
	while (value >= 16)
	{
		tmp2 = value % 16;
		value /= 16;
		if (tmp2 >= 10)
			tmp[REG_SIZE * 2 - i - 1] = tmp2 + 'A' - 10;
		else
			tmp[REG_SIZE * 2 - i - 1] = '0' + tmp2;
		i++;
	}
	if (value < 10)
		tmp[REG_SIZE * 2 - i - 1] = '0' + value;
	else
		tmp[REG_SIZE * 2 - i - 1] = 'A' + value - 10;
	return (tmp);
}

int				memory_4_bytes_to_int(t_env *env, unsigned int value, \
	int num_player, int modulo)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	value = position_2_bytes(env, value, num_player, modulo);
	i = 0;
	tmp = (char *)malloc(sizeof(char) * REG_SIZE * 2);
	ft_memset(tmp, '0', REG_SIZE * 2);
	tmp2 = (char*)malloc(sizeof(char) * 2);
	while (i < REG_SIZE)
	{
		get_tmp_from_memory(env, tmp2, value, i);
		ft_memcpy(&tmp[2 * i], tmp2, 2);
		i++;
	}
	return (reg_to_int(tmp));
}

int				memory_2_bytes_to_int(t_env *env, unsigned int value, \
	int num_player, int modulo)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	value = position_2_bytes(env, value, num_player, modulo);
	tmp = (char *)malloc(sizeof(char) * REG_SIZE * 2);
	ft_memset(tmp, '0', REG_SIZE * 2);
	tmp2 = (char*)malloc(sizeof(char) * 2);
	if (!modulo && env->memory[value] >= 0x80)
		ft_memset(tmp, 'F', REG_SIZE);
	while (i < REG_SIZE / 2)
	{
		get_tmp_from_memory(env, tmp2, value, i);
		ft_memcpy(&tmp[2 * i + REG_SIZE], tmp2, 2);
		i++;
	}
	return (reg_to_int(tmp));
}

unsigned char	*int_to_ind(unsigned int value)
{
	unsigned char	*tmp;
	int				tmp2;
	int				i;

	tmp2 = 0;
	tmp = (unsigned char *)malloc(sizeof(unsigned char) * (REG_SIZE));
	ft_memset(tmp, 0, REG_SIZE);
	i = 0;
	while (value >= 256)
	{
		tmp2 = value % 256;
		value /= 256;
		tmp[REG_SIZE - i - 1] = tmp2;
		i++;
	}
	tmp[REG_SIZE - i - 1] = value;
	return (tmp);
}
