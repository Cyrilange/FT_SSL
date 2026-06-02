#ifndef FT_SSL_H
# define FT_SSL_H

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>


#define FT_PI 3.14159265358979323846

//macros to manipulate bits
#define F(X, Y, Z) ((X & Y) | (~X & Z))
#define G(X, Y, Z) ((X & Z) | (Y & ~Z))
#define H(X, Y, Z) (X ^ Y ^ Z)
#define I(X, Y, Z) (Y ^ (X | ~Z))
#define LEFT_ROTATE(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

typedef struct s_flags {
    int   p; // -p : echo STDIN to STDOUT and append checksum
    int   q; // -q : quiet mode
    int   r; // -r : reverse the format of the output
    int   s; // -s : print the sum of the given string
    char  *s_arg; // Stocke char that follow   -s
} t_flags;



/*
---------UTILS
*/

void ft_error(char *str);
size_t ft_strlen(char *str);
int ft_strcmp(const char *s1, const char *s2);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_calloc(size_t count, size_t size);
double ft_fabs(double x);
double ft_sin(double x);

/*
--------md5
*/

void ft_md5_algo(const unsigned char *message, size_t len, unsigned char *digest);

#endif