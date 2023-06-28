#include "shell.h"
char *_memset(char *s, char b, unsigned int n)
{
for (unsigned int i = 0; i < n; i++)
s[i] = b;

return (s);
}
void ffree(char **pp)
{
if (!pp)
return;

for (char **a = pp; *pp; free(*pp++))
;

free(a);
}
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
if (!ptr)
return (malloc(new_size));
}
if (!new_size)
{
free(ptr);
return (NULL);
}

if (new_size == old_size)
return (ptr);
}
char *p = malloc(new_size);
if (!p)
return (NULL);
}
unsigned int size = old_size < new_size ? old_size : new_size;
while (size--)
p[size] = ((char *)ptr)[size];

free(ptr);
return (p);
}
