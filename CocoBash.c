
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h> 
#include <stdbool.h>
#include <signal.h>


void run_command(char *args[]) {

    pid_t processId = fork();

    if (processId == 0) {  
        execvp(args[0], args); 
        //color for error stream
        fprintf(stderr, "\033[0;31m");

        perror("execvp failed"); 
        fprintf(stderr, "\033[0m");  // Reset color for `stderr`
        exit(1);
    } 

    else if (processId > 0)
        wait(NULL); 

    else 
        perror("fork failed");
}

int main(int argc, char *argv[]) {

    char userInput[100]; 
    char *arguments[100]; 


    if (argc > 2 && strcmp(argv[1], "timeout") == 0) 
    {
        pid_t pid1 = fork();
        int status;
        
        if (pid1 == 0) 
        {
            execvp(argv[3], &argv[3]);
            fprintf(stderr, "\033[1;31m");
            perror("execvp failed");
            fprintf(stderr, "\033[0m"); 
            exit(1);
        }
        else 
        {
            pid_t pid2 = fork();
            if (pid2 == 0) 
            {
                int n = atoi(argv[2]); 
                sleep(n);
                kill(pid1, SIGKILL);
                exit(0);
            } 
            else 
            {
                wait(&status);
            }
        }
        return 0;
    }
    
    if (argc > 1) 
    {
        for (int i = 0; i < argc - 1; i++) 
        {
            arguments[i] = argv[i + 1];  //skipping first argument (./a.out etc)
        }
        arguments[argc - 1] = NULL;
        run_command(arguments);
        return 0; 
    }



    while (true) { 
        
    
        char currentDirectory[1000];
        getcwd(currentDirectory, sizeof(currentDirectory)); //keep showing the current directory

        printf("\033[1;32;32mCoconut's Shell: \033[0m");
        printf("\033[1;33m %s\033[0m", currentDirectory);
        printf("\033[1;33m > $ \033[0m");
        
        printf("\033[0m");
        printf("\033[1;34m");

        if (!fgets(userInput, sizeof(userInput), stdin)) 
        {
            break;  
        }

        userInput[strcspn(userInput, "\n")] = 0; //strcspn returns index of first occurence of \n in input

        char *token = strtok(userInput, " ");
        if (token == NULL) continue; 

        char command[40];  
        strcpy(command, token); //pehla token is command
        arguments[0] = command;

        int i = 1; 
        while ((token = strtok(NULL, " ")) != NULL) 
        {
            arguments[i++] = token;
        }
        arguments[i] = NULL;

        if (strcmp(command, "exit") == 0) {

            printf("\033[0m");
            printf("\033[1;32m");
            printf("Exiting Coconut's shell > ... $\n");
            break;
        }

        if (strcmp(command, "cd") == 0) 
        {
            if (arguments[1] == NULL) {
                fprintf(stderr, "\033[1;31m");
                fprintf(stderr, "cd: missing argument\n");
                fprintf(stderr, "\033[0m");  
                
            } else {
                if (chdir(arguments[1]) != 0) {
                    fprintf(stderr, "\033[1;31m");
                    perror("cd failed");
                    fprintf(stderr, "\033[0m");
                    
                }
            }
            continue;
        }

        run_command(arguments);

        printf("\033[0m");
    }

    return 0;
}
