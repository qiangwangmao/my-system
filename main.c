#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "write.h"

#define MAXBUFSIZE 256

int main () {
  char username[MAXBUFSIZE + 1];
  puts("Welcome to your system\n");
  puts("Type your username\n");
  fgets(username, MAXBUFSIZE, stdin);
  system("clear"); // Clear console
  printf("Welcome to your system, much needed %s", username);
  
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
      char userInput[MAXBUFSIZE + 1];
      fgets(userInput, MAXBUFSIZE, stdin);
      userInput[strcspn(userInput, "\n")] = 0;
    
      if (strcmp(userInput, "write") == 0) {   // check if user wrote "write"
      write_file(); // Call the write_file function
  }
  };

   



  return 0;
}
