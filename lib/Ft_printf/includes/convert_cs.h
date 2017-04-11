/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_cs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:35:20 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/04/05 15:04:32 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_CS_H
# define CONVERT_CS_H

# include "libft.h"
# include "struct.h"
# include <wchar.h>
# include <unistd.h>

int		ft_write_char_1(unsigned char o[5], wint_t c);
int		ft_write_char_2(unsigned int mask[3], unsigned int v, \
	unsigned char o[5]);
int		ft_write_char_3(unsigned int mask[3], unsigned int v, \
	unsigned char o[5]);
int		ft_write_char_4(unsigned int mask[3], unsigned int v, \
	unsigned char o[5]);
void	suite_string_wchar(t_print param, int *i, int *nb_written);
void	suite_string_wchar2(t_print param, wchar_t *str, int *nb_written, \
	int i);
int		ft_putnstr_wchar(wchar_t *str, int n);
int		ft_putstr_wchar(wchar_t *str);
int		ft_print_string_normal(char *str, t_print param);
int		ft_print_string_wchar(wchar_t *str, t_print param);
int		ft_p_char_wint(wint_t c);
int		ft_print_char_normal(char c, t_print param);
int		ft_print_char_wint(wint_t c, t_print param);
void	size_bin(wint_t c, int *size);

#endif
