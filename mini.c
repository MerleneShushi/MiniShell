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

/*#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1024

int main() {
    char input[MAX_INPUT_SIZE];

    while (1) {
        printf("shell$ ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\n");
            break;
        }

        // Code to handle user input and execute commands

        // Example exit condition
        if (strcmp(input, "exit\n") == 0) {
            break;
        }
    }

    return 0;
}

int main() {
    char input[MAX_INPUT_SIZE];
    
    while (1) {
        printf("myshell> ");  // Displaying the prompt

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\n");
            break;
        }
    }

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/wait.h>


#define MAX_PATH_LENGTH 1024

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

int main() {
    char* input;

    while (1) {
        input = readline("myshell> ");  // Displaying the prompt and read user input

        if (input == NULL) {
            // Handle EOF or error condition
            break;
        }

        // Example exit condition
        if (ft_strcmp(input, "exit") == 0) {
            break;
        }

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

        if (ft_strcmp(input, "cd") == 0) {
            // If the input is "cd", change the directory to the home directory
            char* home_dir = getenv("HOME");
            if (home_dir != NULL) {
                chdir(home_dir);
            } else {
                fprintf(stderr, "Home directory not found\n");
            }
        } else {
            // Process and execute other commands
            // ...
        }

        if (ft_strcmp(input, "pwd") == 0) {
            // If the input is "pwd", print the current working directory
            char current_dir[MAX_PATH_LENGTH];
            if (getcwd(current_dir, sizeof(current_dir)) != NULL) {
                printf("%s\n", current_dir);
            } else {
                fprintf(stderr, "Failed to get current working directory\n");
            }
        } else {
            // Process and execute other commands
            // ...
        }


        if (input[0] != '\0') {
            add_history(input);  // Add the input to command history
            //printf("%s\n", input);  // Echo input back to user
    
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
        }

        /*HIST_ENTRY** history_entries = history_list();
        if (history_entries != NULL) {
            for (int i = 0; history_entries[i] != NULL; i++) {
                printf("%d: %s\n", i + 1, history_entries[i]->line);
            }
        }*/
        
        free(input); // Free retrieved input
    }

    return 0;
}

/*int main()
{
    printf("%d", ft_strcmp("exit", "exit"));
    return (0);
}*/
