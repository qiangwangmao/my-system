#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "write.h"
#include "help.h"
#include "hostname.h"

#define MAXBUFSIZE 512

extern char hostname[MAXBUFSIZE + 1];

int main() {
    reboot:

    system("clear"); // clear terminal :^
    char username[MAXBUFSIZE + 1]; // USERNAME VARIABLE
    char password[MAXBUFSIZE + 1]; // PASSWORD VARIABLE

    FILE *hostfile = fopen("hostname.txt", "r"); // open hostname.txt
    fgets(hostname, MAXBUFSIZE, hostfile); // fetch hostname from text file
    fclose(hostfile); // close hostname.txt

    puts(">> welcome to your system\n");

    int validLogin = 0; // 0 = logged out, 1 = log in
    login:
    validLogin = 0;

    while (!validLogin) {
        printf("username: ");
        fgets(username, MAXBUFSIZE, stdin); // user input for username
        username[strcspn(username, "\n")] = 0; // removes new line from fgets
        printf("password: ");
        fgets(password, MAXBUFSIZE, stdin); // user input for password
        password[strcspn(password, "\n")] = 0; // removes new line from fgets
        char credentials[MAXBUFSIZE + 1];
        FILE *creds = fopen("login.txt", "r"); // open login.txt in read mode
        fgets(credentials, MAXBUFSIZE, creds); // gets credentials from login.txt
        fclose(creds); // close file
        char *userInputCreds;
        asprintf(&userInputCreds, "%s:%s", username, password);
        if (strcmp(credentials, userInputCreds) == 0 ) { // compares login.txt credentials with user input credentials
            validLogin = 1;
            system("clear"); // Clear console
        } else {
            printf("Invalid credentials. Please try again.\n");
        }
    }
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
            system("clear");
            goto login;
        }

        else if (strcmp(userInput, "reboot") == 0) { // logout command
            goto reboot;
        }

        else if (strcmp(userInput, "hostname") == 0) {
            changehost();
            system("clear");
        }

        else if (strcmp(userInput, "clear") == 0){
            system("clear");
        }

        else if (strcmp(userInput, "username") == 0){
            int validUsername = 0; // flag to check if a valid user is entered, 1 = valid
        do {
            while (!validUsername) { // keep asking for user until a valid one is entered

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
                FILE * creds = fopen("login.txt", "w"); // open login.txt in write mode
                fprintf(creds, "%s:%s", username, password); // prints login to file
                fclose(creds);
              }
            }
          } while (!validUsername); // this cannot be right
        }

        else if (strcmp(userInput, "password") == 0) {
            printf("password: ");
            fgets(password, MAXBUFSIZE, stdin); // username input field
            password[strcspn(password, "\n")] = 0; // remove new line characters          
            FILE * creds = fopen("login.txt", "w"); // open login.txt in write mode
            fprintf(creds, "%s:%s", username, password); // prints login to file
            fclose(creds);
              }

        else {
            puts("This command doesn't exist. Check 'help' for a list of all available commands.");
        }
    }

    return 0;
}