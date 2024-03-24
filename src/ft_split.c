#include "libft.h"
#include <stdlib.h>

static size_t ft_count_words(const char *s, char c)
{
    size_t count = 0;
    size_t i = 0;

    while (s[i])
    {
        if (s[i] != c)
        {
            count++;
            while (s[i] && s[i] != c)
                i++;
        }
        else
            i++;
    }
    return count;
}

static size_t ft_get_word_len(const char *s, char c)
{
    size_t len = 0;
    while (s[len] && s[len] != c)
        len++;
    return len;
}

static void ft_free_array(size_t i, char **array)
{
    while (i > 0)
    {
        i--;
        free(array[i]);
    }
    free(array);
}

char **ft_split(const char *s, char c)
{
    if (!s)
        return NULL;

    size_t words = ft_count_words(s, c);
    char **array = (char **)malloc(sizeof(char *) * (words + 1));
    if (!array)
        return NULL;

    size_t i = 0;
    size_t j = 0;
    while (i < words)
    {
        while (s[j] && s[j] == c)
            j++;
        size_t word_len = ft_get_word_len(&s[j], c);
        array[i] = ft_substr(s, j, word_len);
        if (!array[i])
        {
            ft_free_array(i, array);
            return NULL;
        }
        j += word_len;
        i++;
    }
    array[i] = NULL;
    return array;
}

