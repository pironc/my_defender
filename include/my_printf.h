/*
** EPITECH PROJECT, 2020
** project_base
** File description:
** my_printf
*/

#ifndef _MY_PRINTF_H_
#define _MY_PRINTF_H_

#include <stdarg.h>

/* MY_PRINTF STRUCT */

typedef struct pad_t {
    unsigned int zero_pad;
    unsigned int sp_pad_left;
    unsigned int sp_pad_right;
}pad_s;

/* MY_PRINTF LIB FUNCTIONS */

int my_printf(const char *format, ...);
void special_flags_check(const char *format, int *i, va_list ap, pad_s **pad);
int basic_flags_check(const char *format, int i, va_list ap, pad_s **pad);

/* Basic flags */
int f_c2(const char *format, int i, va_list ap, pad_s **pad);
int f_di(const char *format, int i, va_list ap, pad_s **pad);
int f_s2(const char *format, int i, va_list ap, pad_s **pad);
int f_b(const char *format, int i, va_list ap, pad_s **pad);
int f_o(const char *format, int i, va_list ap, pad_s **pad);
int f_u(const char *format, int i, va_list ap, pad_s **pad);
int f_x(const char *format, int i, va_list ap, pad_s **pad);
int f_x_cap(const char *format, int i, va_list ap, pad_s **pad);
int f_p(const char *format, int i, va_list ap, pad_s **pad);

/* Base nested loops */
void f_b_nested_loop(char *binary, pad_s **pad);
void f_o_nested_loop(char *octal, pad_s **pad);
void f_x_nested_loop(char *hexa, pad_s **pad);
void f_x_cap_nested_loop(char *hexa, pad_s **pad);
void f_p_nested_loop(char *str, pad_s **pad);

/* Basic nested loops */
void f_c2_nested_loop(pad_s **pad, va_list ap);
void f_di_nested_loop(pad_s **pad, va_list ap, int arg_len);
void f_s2_nested_loop(pad_s **pad, char *str);
void f_u_nested_loop(pad_s **pad, va_list ap, int arg_len);

/* Special flags */
void f_hashtag(const char *format, int *i, va_list ap);
void f_space(const char *format, int *i, va_list ap);
void f_zero(const char *format, int *i, pad_s **pad);
void f_dash(const char *format, int *i, pad_s **pad);
void f_number(const char *format, int *i, pad_s **pad);

/* Double modulo */
int modulo_check(const char *format, int i);

#endif /* !_MY_PRINTF_H_ */
