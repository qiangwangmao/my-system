#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "write.h"
#include "help.h"

#define MAXBUFSIZE 256

int main () {
  system("clear"); // clear terminal :^
  char username[MAXBUFSIZE + 1]; // USERNAME VARIABLE
  int validUsername = 0; // flag to check if a valid user is entered, 1 = valid
  puts(">> welcome to your system\n");

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
      }
    }
  } while (!validUsername);
  // succesful login
  system("clear"); // Clear console
  printf("Welcome to your system, much needed %s\n", username);
  
  // Get the current time
  time_t currentTime; // declares a variable to hold the current time.
  time(&currentTime); // gets the current time and stores it in currentTime

  // Convert to local time
  struct tm *localTime = localtime(&currentTime); // converts the current time to local time and stores it in localTime.

  // Print the date and time
  printf("Current date and time: %02d/%02d/%04d, %02d:%02d.\n",
          localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900,
          localTime->tm_hour, localTime->tm_min);
  
  // user input starts here
  while (1) {
      printf("[%s@root]$ ", username);
      char userInput[MAXBUFSIZE + 1];
      fgets(userInput, MAXBUFSIZE, stdin);
      userInput[strcspn(userInput, "\n")] = 0;
    
      if (strcmp(userInput, "write") == 0) {   // check if user wrote "write"
      write_file(); // Call the write_file function
      }

      if (strcmp(userInput, "help") == 0) {   // help command
      help(); // Call the help function
  }

      if (strcmp(userInput, "shutdown") == 0) {   // shutdown command
      system("clear");
      return(1); // shutdown the program // I DONT THINK THIS IS HOW ITS DONE BUT IT WORKS
  }
  };

  return 0;
}
