#include "minishell.h"

/*t_list  ft_exp(char **envp)
{
    t_list  *head;
    t_list  *temp;
    int     i;
    
    i = 0;
    head = NULL;
    ft_lstadd_back(&head, ft_lstnew(create_env_node(envp[i])));
    temp = head;
    while (envp[++i])
    {
        temp->next = ft_lstnew(create_env_node(envp[i]));
        temp = temp->next;
    }
    return (head);
}*/