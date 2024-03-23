#include "libft.h"

static size_t ft_count_words(char const *s, char c)
{
	size_t count;
	size_t i;

	count = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			count++;
			while (*(s + i) && *(s + i) != c)
				i++;
		}
		else if (*(s + i) == c)
			i++;
	}
	return (count);
}

static size_t ft_get_word_len(char const *s, char c)
{
	size_t i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

static void ft_free_array(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(*(array + i));
	}
	free(array);
}

static char **ft_split(char const *c, char c, char **array, size_t words_count)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(array + i) = ft_substr(s, j, ft_get_word_len(&*(s + j), c));
		if (!*(array + i))
		{
			ft_free_array(i, array);
			return (NULL);
		}
		while (*(s + j) && *(s + j) != c)
			j++;
		i++;
	}
	*(array + i) = NULL;
	return (array);
}

char **ft_split(char const *s, char c)
{
	char **array;
	size_t words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array = ft_split(s, c, array, words);
	return (array);
}
