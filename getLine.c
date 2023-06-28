#include <stddef.h>
#include <unistd.h>
#define READ_BUF_SIZE 1024
ssize_t input_buf(char **buf, size_t *len)
{
ssize_t r = 0;
size_t len_p = 0;

if (!*len) {
free(*buf);
*buf = NULL;
r = getline(buf, &len_p, stdin);
if (r > 0) {
if ((*buf)[r - 1] == '\n') {
(*buf)[r - 1] = '\0';
r--;
}
*len = r;
}
}
return (r);
}
ssize_t get_input(char **buf)
{
static size_t i, j, len;
ssize_t r = 0;
char **buf_p = buf, *p;
_putchar(BUF_FLUSH);
r = input_buf(buf, &len);
if (r == -1)
return -1;
if (len) {
j = i;
p = *buf + i;
while (j < len) {
if (is_chain(*buf, &j))
break;
j++;
}
i = j + 1;
if (i >= len) {
i = len = 0;
info->cmd_buf_type = CMD_NORM;
}
*buf_p = p;
return j - i;
}
*buf_p = *buf;
return (r);
}
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
ssize_t r = 0;
if (*i)
return (0);
r = read(info->readfd, buf, READ_BUF_SIZE);
if (r >= 0)
*i = r;
return (r);
}
int _getline(info_t *info, char **ptr, size_t *length)
{
static char buf[READ_BUF_SIZE];
static size_t i, len;
size_t k;
ssize_t r = 0, s = 0;
char *p = NULL, *new_p = NULL, *c;

p = *ptr;
if (p && length)
s = *length;
if (i == len)
i = len = 0;

r = read_buf(info, buf, &len);
if (r == -1 || (r == 0 && len == 0))
return (-1);

c = strchr(buf + i, '\n');
k = c ? 1 + (unsigned int)(c - buf) : len;
new_p = realloc(p, s ? s + k : k + 1);
if (!new_p)
return p ? (free(p), -1) : -1;

if (s)
strncat(new_p, buf + i, k - i);
else
strncpy(new_p, buf + i, k - i + 1);

s += k - i;
i = k;
p = new_p;

if (length)
*length = s;
*ptr = p;
return (s);
}
void sigintHandler(int sig_num)
{
_puts("\n");
_puts("$ ");
_putchar(BUF_FLUSH);
}

