#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "write.h"
#include "help.h"
#include "hostname.h"

#define MAXBUFSIZE 256

extern char hostname[MAXBUFSIZE + 1];

int main() {
    system("clear"); // clear terminal :^

    char username[MAXBUFSIZE + 1]; // USERNAME VARIABLE

    char loginTxt[MAXBUFSIZE + 1]; // LOGIN.TXT CONTENTS
    char password[MAXBUFSIZE + 1]; // PASSWORD VARIABLE

    int validUsername = 0; // flag to check if a valid user is entered, 1 = valid
    int validHostname = 0; // flag to check if a valid hostname is entered
    login:
    puts(">> welcome to your system\n");

    do {
        while (!validUsername) { // keep asking for user until a valid one is entered
            FILE * file = fopen("login.txt", "w"); // open login.txt in write mode
            printf("username: ");
            fgets(username, MAXBUFSIZE, stdin); // username input field
            username[strcspn(username, "\n")] = 0; // remove new line characters

            // check if username has
            int i;
            for (i = 0; username[i] != '\0'; i++) {
                if (isspace(username[i])) { // if a space is found
                    printf("Username mustn't use spaces.\n");
                    break; // exit the loop to prompt for username again
                }
            }

            if (username[i] == '\0') {
                validUsername = 1;
            }
        }
    } while (!validUsername); // this cannot be right

    printf("password: ");
    FILE * file = fopen("login.txt", "w"); // open login.txt in write mode
    fgets(password, MAXBUFSIZE, stdin); // user input for password
    password[strcspn(password, "\n")]; // remove new line
    fprintf(file, "%s:%s", username, password); // prints login to file
    fclose(file); // close the file

    // do {
    //     while (!validHostname) { // keep asking for hostname until a valid one is entered
    //         printf("hostname: ");
    //         fgets(hostname, MAXBUFSIZE, stdin); // hostname input field
    //         hostname[strcspn(hostname, "\n")] = 0; // remove new line characters

            // check if hostname has
    //         int i;
    //         for (i = 0; hostname[i] != '\0'; i++) {
    //             if (isspace(hostname[i])) { // if a space is found
    //                 printf("Hostname mustn't use spaces.\n");
    //                 break; // exit the loop to prompt for hostname again
    //             }
    //         }

    //         if (hostname[i] == '\0') {
    //             validHostname = 1;
    //         }
    //     }
    // } while (!validHostname); // this cannot be right

    // succesful login
    system("clear"); // Clear console
    printf("Welcome to your system, much needed %s\n", username);

    // Get the current time
    time_t currentTime; // declares a variable to hold the current time.
    time( & currentTime); // gets the current time and stores it in currentTime

    // Convert to local time
    struct tm * localTime = localtime( & currentTime); // converts the current time to local time and stores it in localTime.

    // Print the date and time
    printf("Current date and time: %02d/%02d/%04d, %02d:%02d.\n",
        localTime -> tm_mday, localTime -> tm_mon + 1, localTime -> tm_year + 1900,
        localTime -> tm_hour, localTime -> tm_min);

    puts("Run 'help' to see the available commands.");

    // user input starts here
    while (1) {
        printf("[%s@%s]$ ", username, hostname);
        char userInput[MAXBUFSIZE + 1];
        fgets(userInput, MAXBUFSIZE, stdin);
        userInput[strcspn(userInput, "\n")] = 0;

        if (strcmp(userInput, "write") == 0) { // check if user wrote "write"
            write_file(); // Call the write_file function
        }

        else if (strcmp(userInput, "help") == 0) { // help command
            help(); // Call the help function
        }

        else if (strcmp(userInput, "shutdown") == 0) { // shutdown command
            system("clear");
            return 0; // shutdown the program
        }

        else if (strcmp(userInput, "logout") == 0) { // logout command
            goto login;
        }

        else if (strcmp(userInput, "hostname") == 0) {
            changehost();
            system("clear");
        }

        else if (strcmp(userInput, "clear") == 0){
            system("clear");
        }

        else {
            puts("This command doesn't exist. Check 'help' for a list of all available commands.");
        }
    };

    return 0;
}