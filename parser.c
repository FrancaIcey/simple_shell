#include "shell.h"
int is_cmd(info_t *info, char *path)
{
struct stat st;

if (!path || stat(path, &st) != 0)
return (0);
}
return (S_ISREG(st.st_mode) ? 1 : 0);
}
char *dup_chars(char *pathstr, int start, int stop)
{
static char buf[1024];
int k = 0;

for (int i = start; i < stop; i++)
{
if (pathstr[i] != ':')
buf[k++] = pathstr[i];
}
buf[k] = '\0';

return (buf);
}
char *find_path(info_t *info, char *pathstr, char *cmd)
{
if (!pathstr)
return (NULL);

if (_strlen(cmd) > 2 && starts_with(cmd, "./"))
{
if (is_cmd(info, cmd))
return (cmd);
}

int i = 0, curr_pos = 0;
char *path = NULL;

while (1)
{
if (!pathstr[i] || pathstr[i] == ':')
{
path = dup_chars(pathstr, curr_pos, i);
if (!*path)
_strcat(path, cmd);
else
{
_strcat(path, "/");
_strcat(path, cmd);
}

if (is_cmd(info, path))
return (path);

if (!pathstr[i])
break;

curr_pos = i;
}
i++;
}

return (NULL);
}

