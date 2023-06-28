#include "shell.h"
list_t *add_node(list_t **head, const char *str, int num)
{
    list_t *new_head;

    if (!head)
        return NULL;
    new_head = malloc(sizeof(list_t));
    if (!new_head)
        return NULL;
    memset(new_head, 0, sizeof(list_t));
    new_head->num = num;
    if (str)
    {
        new_head->str = strdup(str);
        if (!new_head->str)
        {
            free(new_head);
            return (NULL);
        }
    }
    new_head->next = *head;
    *head = new_head;
    return new_head;
}
list_t *add_node_end(list_t **head, const char *str, int num)
{
    list_t *new_node, *node;

    if (!head)
        return (NULL);
}
    node = *head;
    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return NULL;
    memset(new_node, 0, sizeof(list_t));
    new_node->num = num;
    if (str)
    {
        new_node->str = strdup(str);
        if (!new_node->str)
        {
            free(new_node);
            return (NULL);
        }
    }
    if (node)
    {
        while (node->next)
            node = node->next;
        node->next = new_node;
    }
    else
        *head = new_node;
    return (new_node);
}
size_t print_list_str(const list_t *h)
{
    size_t i = 0;

    while (h)
    {
        _puts(h->str ? h->str : "(nil)");
        _puts("\n");
    }
