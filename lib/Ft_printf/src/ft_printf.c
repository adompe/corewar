/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 13:28:22 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/05/21 16:58:45 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_suite(const char *format, t_print *param, t_norme *norme)
{
	if (format[norme->i] == '%')
	{
		va_copy(norme->ap[1], norme->ap[0]);
		ft_init(param);
		norme->i += ft_analyze(&format[norme->i + 1], param, norme);
		va_copy(norme->ap[1], norme->ap[0]);
		if (param->conversion > 1)
			norme->nb_print += ft_print_printf(*param, &(norme->current_id), \
				norme->ap[1], norme->nb_print);
	}
	else
	{
		ft_putchar(format[norme->i]);
		norme->nb_print++;
		norme->i++;
	}
}

int		ft_printf(const char *format, ...)
{
	t_norme *norme;
	t_print	*param;

	param = (t_print*)malloc(sizeof(t_print));
	norme = (t_norme*)malloc(sizeof(t_norme));
	init_norme_printf(norme);
	va_start(norme->ap[0], format);
	while (format[norme->i])
	{
		ft_printf_suite(format, param, norme);
	}
	va_end(norme->ap[0]);
	free(param);
	free(norme);
	return (norme->nb_print);
}

int		ft_analyze(const char *format, t_print *param, t_norme *norme)
{
	va_list ap_cpy;
	va_list ap_cpy2;
	int		precision[2];

	precision[0] = 0;
	precision[1] = 0;
	norme->j = 0;
	if (format[norme->j] != '\0')
	{
		va_copy(ap_cpy, norme->ap[1]);
		va_copy(ap_cpy2, norme->ap[1]);
		param->modifier = ft_strnew(2);
		while (!param->conversion)
		{
			norme->j = parse_id(format, &(param->id), norme->j);
			norme->j = parse_flags(format, param->flags, norme->j);
			norme->j = parse_field_length(format, param, norme, ap_cpy);
			norme->j = parse_precision(format, precision, norme, ap_cpy2);
			param->precision = precision[0];
			param->precision_spec = precision[1];
			norme->j = parse_modifier(format, param->modifier, norme->j);
			norme->j = parse_conversion(format, &(param->conversion), norme->j);
		}
	}
	return (norme->j + 1);
}

int		ft_print_printf(t_print param, int *current_id, va_list ap_cpy, \
		int nb_print)
{
	int	nb_char_written;

	nb_char_written = 0;
	if (param.conversion == 'd' || param.conversion == 'i' || \
	param.conversion == 'D')
		nb_char_written = ft_print_signed_int(param, current_id, ap_cpy);
	else if (param.conversion == 'b')
		nb_char_written = ft_print_unsigned_int(param, current_id, ap_cpy, 2);
	else if (param.conversion == 'o' || param.conversion == 'O')
		nb_char_written = ft_print_unsigned_int(param, current_id, ap_cpy, 8);
	else if (param.conversion == 'u' || param.conversion == 'U')
		nb_char_written = ft_print_unsigned_int(param, current_id, ap_cpy, 10);
	else if (param.conversion == 'x' || param.conversion == 'X')
		nb_char_written = ft_print_unsigned_int(param, current_id, ap_cpy, 16);
	else if (param.conversion == 's' || param.conversion == 'S')
		nb_char_written = ft_print_string(param, current_id, ap_cpy);
	else if (param.conversion == 'c' || param.conversion == 'C')
		nb_char_written = ft_print_char(param, current_id, ap_cpy);
	else if (param.conversion == 'p')
		nb_char_written = ft_print_pointer(param, current_id, ap_cpy);
	else
		nb_char_written = ft_print_bonus(param, current_id, ap_cpy, nb_print);
	return (nb_char_written);
}

int		ft_print_bonus(t_print param, int *current_id, va_list ap_cpy, \
		int nb_print)
{
	int	nb_char_written;

	nb_char_written = 0;
	if (param.conversion == 'n')
		nb_char_written = ft_print_number(param, current_id, ap_cpy, nb_print);
	else if (param.conversion == 'e' || param.conversion == 'E')
		nb_char_written = ft_print_double_scientific(param, current_id, ap_cpy);
	else if (param.conversion == 'f' || param.conversion == 'F')
		nb_char_written = ft_print_double_classic(param, current_id, ap_cpy);
	else if (param.conversion == 'g' || param.conversion == 'G')
		nb_char_written = ft_print_double_both(param, current_id, ap_cpy);
	else if (param.conversion == 'a' || param.conversion == 'A')
		nb_char_written = ft_print_double_hexa(param, current_id, ap_cpy);
	else if (param.conversion == '%')
		nb_char_written = ft_print_percent(param);
	else
		nb_char_written = ft_print_no_convert(param);
	return (nb_char_written);
}
