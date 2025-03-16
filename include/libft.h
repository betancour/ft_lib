#ifndef FT_LIB_H
#define FT_LIB_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif
#ifndef MAX_FD
#define MAX_FD 4096
#endif
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <stdarg.h>

typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

// 1. Character Checking Functions
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c);

// 2. String Manipulation Functions
size_t ft_strlen(const char *s);
size_t ft_strnlen(const char *s, size_t maxlen);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strrchr(const char *s, int c);
char *ft_strchr(const char *s, int c);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strstr(const char *haystack, const char *needle);
char *ft_strcpy(char *dst, const char *src);
char *ft_strncpy(char *dst, const char *src, size_t len);
char *ft_strcat(char *s1, const char *s2);
char *ft_strncat(char *s1, const char *s2, size_t n);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
char *ft_substr(const char *s1, unsigned int start, size_t len);
char *ft_strjoin(const char *s1, const char *s2);
char *ft_strtrim(const char *s1, const char *set);
char **ft_split(const char *s, char c);
char *ft_strdup(const char *s1);
char *ft_itoa(int n);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void ft_striteri(char *s, void (*f)(unsigned int, char *));

// 3. Memory Functions
void *ft_memset(void *b, int c, size_t len);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dst, const void *src, size_t n);
void *ft_memmove(void *dst, const void *src, size_t len);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void *ft_calloc(size_t count, size_t len);
void *ft_memccpy(void *dst, const void *src, int c, size_t n);

// 4. List Functions (t_listbased)
t_list *ft_lstnew(void *content);
void ft_lstadd_front(t_list **alst, t_list *new);
int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **alst, t_list *new);
void ft_lstdelone(t_list *lst, void (*del)(void *));
void ft_lstclear(t_list **lst, void (*del)(void *));
void ft_lstiter(t_list *lst, void (*f)(void *));
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// 5. I/O Functions
void ft_putchar(char c);
void ft_putstr(char *str);
void ft_putnbr(int nbr);
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *str, int fd);
void ft_putendl_fd(char *str, int fd);
void ft_putnbr_fd(int n, int fd);

// 6. Utility and Conversion Functions
int ft_atoi(const char *str);
int ft_strisdigit(char *s);
long ft_atol(const char *s);
int ft_pow(int nb, int power);

#endif
