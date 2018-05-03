/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:38:45 by kshyshki          #+#    #+#             */
/*   Updated: 2018/01/26 19:54:14 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "libft.h"
# include <inttypes.h>

# define UCH unsigned char
# define CCH const char

# define MAX_UNI 1114111
# define MAX_ASCII 127
# define MASK_SEC 128
# define MASK1_MAIN 192
# define MASK2_MAIN 224
# define MASK3_MAIN 240
# define MASK_SEL 63

# define TMOD "sSpdDioOuUxXcC"
# define FLAGS "#0-+ "
# define LEN "hljz"
# define ZEROX "0x"
# define ZEROLX "0X"
# define PROC "%"
# define NULL_STR "(null)"

# define ABS(x) ((x) < 0) ? -(x) : (x)
# define S(x) (x == 's' || x == 'S') ? (1) : (0)
# define C(x) (x == 'c' || x == 'C') ? (1) : (0)
# define I(x) (x == 'd' || x == 'D' || x == 'i') ? (1) : (0)
# define X(x) (x == 'x' || x == 'X') ? (1) : (0)
# define U(x) (x == 'u' || x == 'U') ? (1) : (0)
# define O(x) (x == 'o' || x == 'O') ? (1) : (0)
# define P(x) (x == 'p') ? (1) : (0)
# define IS_OLD(x) (x == 'O' || x == 'U' || x == 'D') ? (1) : (0)
# define IS_BIG(x) (x >= 'A' && x <= 'Z') ? (1) : (0)

# define ER (-1)
# ifndef OK
# 	define OK (1)
# endif
# define ER_PR (2)
# define NEXT_STEP (3)

typedef struct		s_res
{
	unsigned char	*res;
	char			*mod;
	char			*len;
	int				dbl_len;
	int				pre;
	int				width;
	unsigned char	fl_min;
	unsigned char	fl_pl;
	int				fl_nul;
	unsigned char	fl_octo;
	unsigned char	fl_sp;
	size_t			res_len;
	int				kos;
	struct s_res	*next;
}					t_res;

typedef int			(*t_f)(t_res*, va_list*);
typedef int			(*t_fl)(t_res*);

int					add_lst_str(const char *str, int *cnt, t_res *res);
int					add_lst_ap(const char *str, int *cnt, t_res *res,
								va_list *ap);
int					create_res(const char *str, t_res *res, int *cnt);
int					parse_res_ap(const char *str, t_res *res, int *cnt,
									va_list *ap);
void				free_res(t_res **res);
int					ft_printf(const char *format, ...);
t_f					find_func(char mod);
t_res				*new_res(void);

unsigned char		*pf_uchr(wchar_t chr);
unsigned char		*pf_itoabase(intmax_t value, int base);
unsigned char		*pf_uitoabase(uintmax_t value, int base);
int					pf_get_sign_arg(char *len, int dbl, va_list *ap,
									intmax_t *res);
int					pf_get_usign_arg(char *len, int dbl, va_list *ap,
									uintmax_t *res);
int					parse_c(t_res *s, va_list *ap);
int					parse_lc(t_res *s, va_list *ap);
int					parse_s(t_res *s, va_list *ap);
int					parse_ls(t_res *s, va_list *ap);
int					parse_i(t_res *s, va_list *ap);
int					parse_ld(t_res *s, va_list *ap);
int					parse_x(t_res *s, va_list *ap);
int					parse_o(t_res *s, va_list *ap);
int					parse_u(t_res *s, va_list *ap);
int					parse_p(t_res *s, va_list *ap);

int					error_handler(char **tmp);
int					error_handler_both(char **tmp, char **tmp_res);
int					add_zero_left(intmax_t len, unsigned char **tmp, t_res *s);
int					check_zero(t_res *s);
int					parse_fl_okto(t_res *s);
int					parse_fl_min(t_res *s, unsigned char *tmp);
int					parse_nul_sign(t_res *s, intmax_t len, int fl_pre);
int					parse_width_nbr(t_res *s);
int					parse_nul_uxo(intmax_t len, t_res *s);

int					parse_fl_s(t_res *s);
int					parse_fl_nbr(t_res *s);
int					parse_fl_unbr(t_res *s);
int					parse_fl_x(t_res *s);
int					parse_fl_o(t_res *s);
int					parse_fl_p(t_res *s);
t_fl				find_fl_func(char mod);

#endif
