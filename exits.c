#include <stddef.h>
char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;
	char *s = dest;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
	dest[i] = src[i];
	}
	for (; i < n; i++)
	{
	dest[i] = '\0';
	}
	return (s);
}
char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = 0;
	char *s = dest;

	while (dest[dest_len] != '\0')
	{
	dest_len++;
	}

	for (size_t i = 0; i < n && src[i] != '\0'; i++)
	{
	dest[dest_len + i] = src[i];
	}
	dest[dest_len + n] = '\0';
	
	return (s);
}
char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
		
	{
	return (char *)s;
	}
		s++;
	}

	return (NULL);
}
