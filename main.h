#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define BUFSIZE 1024
#define T_MINUS 1
#define T_PLUS 2
#define T_ZERO 4
#define T_HASH 8
#define T_SPACE 16
#define SLONG 2
#define SSHORT 1

/**
 * struct fmt - Struct op
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 * @fmt: The format
 * @fmt: The function associated.
 */
typedef struct fmt fmtt;

int _printf(const char *format, ...);
int print(const char *fmt, int *ind,
va_list list, char buffer[], int flag, int width, int precision, int size);


int printchars(va_list type, char buffer[],
	int flag, int width, int precision, int size);
int printstring(va_list type, char buffer[],
	int flag, int width, int precision, int size);
int printpercent(va_list type, char buffer[],
	int flag, int width, int precision, int size);
int printint(va_list type, char buffer[],
	int flag, int width, int precision, int size);
int printbinary(va_list type, char buffer[],
	int flag, int width, int precision, int size);
int printunsigned(va_list type, char buffer[],
	int flag, int width, int precision, int size);
int printoctal(va_list type, char buffer[],
	int flag, int width, int precision, int size);
int printhexadecimal(va_list type, char buffer[],
	int flag, int width, int precision, int size);
int printhexaupper(va_list type, char buffer[],
	int flag, int width, int precision, int size);

int printhexa(va_list type, char mapto[],
char buffer[], int flag, char flagch, int width, int precision, int size);
int printnonprintable(va_list type, char buffer[],
	int flag, int width, int precision, int size);

int printpointer(va_list type, char buffer[],
	int flag, int width, int precision, int size);

int getflag(const char *format, int *i);
int getwidth(const char *format, int *i, va_list list);
int getprecision(const char *format, int *i, va_list list);
int getsize(const char *format, int *i);

int printreverse(va_list type, char buffer[],
	int flag, int width, int precision, int size);

int printrot13string(va_list type, char buffer[],
	int flag, int width, int precision, int size);

int writechar(char c, char buffer[],
	int flag, int width, int precision, int size);
int writenumber(int ispositive, int ind, char buffer[],
	int flag, int width, int precision, int size);
int writenum(int ind, char bff[], int flags, int width, int precision,
	int length, char pat, char extrac);
int writepointer(char buffer[], int ind, int length,
	int width, int flag, char pat, char extrac, int patstart);

int writeunsgnd(int isnegative, int ind,
char buffer[],
	int flag, int width, int precision, int size);

int isprintable(char);
int appendhexacode(char, char[], int);
int is_digit(char);

long int convertsizenumber(long int num, int size);
long int convertsizeunsgnd(unsigned long int num, int size);

#endif
