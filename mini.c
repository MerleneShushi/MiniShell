/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:29:15 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/07/13 11:29:17 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit;

int	ft_strcmp(char *s1, char *s2)
{
	int	a;

	a = 0;
	while (s1[a] != '\0' && s2[a] != '\0')
	{
		if (s1[a] != s2[a])
		{
			return (s1[a] - s2[a]);
		}
		a++;
	}
	return (s1[a] - s2[a]);
}


void	ft_inputuser(t_shell *myshell, char *input)
{
	input = getcwd(input, 2000);
	input = ft_strjoin(input, "$> ");
	myshell->minput = readline(input);
	if (myshell->minput[0] != '\0')
		add_history(myshell->minput);
    free(input);
}

char    *ft_echo(t_shell *myshell, char *input)
{
    char    *echo;
    int     i;
    int     j;

    i = 0;
    j = 0;
    //printf("input: %s\n", input);
    echo = ft_calloc(sizeof(char), ft_strlen(input) + 1);
    while (input[i] != '\0')
    {
        if (input[i] == '\"' || input[i] == '\'')
            i++;
        else
        {
            echo[j] = input[i];
            i++;
            j++;
        }
    }
    //printf("echo: %s\n", echo);
    return (echo);
}

int	ft_exec(t_shell *myshell)
{
	if (ft_strcmp(myshell->minput, "exit") == 0)
		return (1);
	else if (ft_strcmp(myshell->minput, "pwd") == 0)
	{
		if (getcwd(myshell->pwd, 2000) != NULL)
			printf("%s\n", myshell->pwd);
		else
			printf("Failed to get current working directory\n");
	}
	else if (ft_strcmp(myshell->minput, "cd") == 0)
	{
		if (myshell->home != NULL)
			chdir(myshell->home);
		else
			printf("Home directory not found\n");
	}
	else if (ft_strncmp(myshell->minput, "cd ", 3) == 0)
    {  // Extract the path from the input
        myshell->path = myshell->minput + 3;
		if (chdir(myshell->path) != 0) 
        printf("Failed to change directory\n");
	}
    else if (ft_strncmp(myshell->minput, "echo", 4) == 0)
    {
        myshell->myecho = ft_echo(myshell, myshell->minput + 5);
        if (ft_strlen(myshell->minput) == 4)
            printf("\n");
        else if (ft_strncmp(myshell->minput, "echo -n ", 8) == 0)
        {
            myshell->myecho = ft_echo(myshell, myshell->minput + 8);
            ft_printf("%s", myshell->myecho);
        }
        else if ((ft_strncmp(myshell->minput, "echo ", 5) != 0))
            printf("%s: Command not found\n", myshell->minput);
        else 
            ft_printf("%s\n", myshell->myecho);
        free(myshell->myecho);
    }
	else
		printf("%s: Command not found\n", myshell->minput);
	return (0);
}

int main() 
{
	t_shell myshell;
	char* input;

	input = NULL;
	myshell.pwd = getcwd(NULL, 2000);
	myshell.home = getenv("HOME");
	while(1)
	{
		ft_inputuser(&myshell, input);
		if (myshell.minput == NULL) // Handle EOF or error condition
            break;
		if (ft_exec(&myshell) == 1)
            break;
        free(myshell.minput);
	}
    free(myshell.minput);
	free(myshell.pwd);
/*
        if (strcmp(input, "ls") == 0) {
            // If the input is "ls", execute the ls command within the Minishell program
            pid_t pid = fork();  // Create a child process

            if (pid < 0) {
                // Error occurred while forking
                fprintf(stderr, "Failed to create a child process\n");
            } else if (pid == 0) {
                // Child process
                char* args[] = {"ls", NULL};
                execv("/bin/ls", args);  // Execute the ls command
                // If execv returns, an error occurred
                fprintf(stderr, "Failed to execute ls command\n");
                exit(1);
            } else {
                // Parent process
                wait(NULL);  // Wait for the child process to complete
            }
        }
            /*char* token;
            char* path = getenv("PATH");

            // Split the input command by spaces to extract the program and arguments
            char* args[64];
            int argCount = 0;

            token = strtok(input, " ");
            while (token != NULL) {
                args[argCount++] = token;
                token = strtok(NULL, " ");
            }
            args[argCount] = NULL;

            // Check if the program path is absolute or relative
            if (args[0][0] == '/') {
                // Absolute path
                execv(args[0], args);
            } else {
                // Relative path or search in PATH
                char fullPath[MAX_PATH_LENGTH];
                token = strtok(path, ":");
                while (token != NULL) {
                    snprintf(fullPath, sizeof(fullPath), "%s/%s", token, args[0]);
                    execv(fullPath, args);
                    token = strtok(NULL, ":");
                }

                // If the program is not found in PATH or is not executable
                printf("Command not found: %s\n", args[0]);
            }*/
				//}

        /*HIST_ENTRY** history_entries = history_list();
        if (history_entries != NULL) {
            for (int i = 0; history_entries[i] != NULL; i++) {
                printf("%d: %s\n", i + 1, history_entries[i]->line);
            }
        }*/
        
       /* free(input); // Free retrieved input
    }

    return 0;*/
}

/*int main()
{
    printf("%d", ft_strcmp("exit", "exit"));
    return (0);
}*/
