/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:56:59 by kshyshki          #+#    #+#             */
/*   Updated: 2017/12/05 18:11:58 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_f		find_func(char mod)
{
	if (((C(mod)) && !IS_BIG(mod)))
		return (&parse_c);
	else if (C(mod))
		return (&parse_lc);
	else if ((S(mod)) && !IS_BIG(mod))
		return (&parse_s);
	else if (S(mod))
		return (&parse_ls);
	else if ((I(mod)) && !IS_BIG(mod))
		return (&parse_i);
	else if (I(mod))
		return (&parse_ld);
	else if ((X(mod)))
		return (&parse_x);
	else if (U(mod))
		return (&parse_u);
	else if (O(mod))
		return (&parse_o);
	else if (P(mod))
		return (&parse_p);
	else
		return (NULL);
}

t_fl	find_fl_func(char mod)
{
	if ((C(mod)) || (S(mod)))
		return (&parse_fl_s);
	else if (X(mod))
		return (&parse_fl_x);
	else if (O(mod))
		return (&parse_fl_o);
	else if (P(mod))
		return (&parse_fl_p);
	else if (U(mod))
		return (&parse_fl_unbr);
	else if (!(I(mod)) && !(P(mod)))
		return (&parse_fl_unbr);
	else if (I(mod))
		return (&parse_fl_nbr);
	else
		return (NULL);
}
