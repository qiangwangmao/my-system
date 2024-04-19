#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXBUFSIZE 256

char hostname[MAXBUFSIZE + 1] = "qiang"; // HOSTNAME VARIABLE

int changehost() {

    int validHostname = 0;

    while (!validHostname) { // keep asking for hostname until a valid one is entered
        printf("hostname: ");
        fgets(hostname, MAXBUFSIZE, stdin); // hostname input field
        hostname[strcspn(hostname, "\n")] = 0; // remove new line characters

        // check if hostname has no spaces
        int i;
        for (i = 0; hostname[i] != '\0'; i++) {
            if (isspace(hostname[i])) { // If a space is found
                printf("Hostname mustn't use spaces.\n");
                break; // Exit the loop to prompt for hostname again
            }
        }

        // additional checks for hostname validity
        if (hostname[i] == '\0' && strlen(hostname) <= 63 && hostname[0] != '-' && hostname[strlen(hostname) - 1] != '-') {
            validHostname = 1;
        } else {
            printf("Invalid hostname. Please try again.\n");
        }
    }

    printf("Changes were made succesfully: %s\n", hostname);
    return 0; // return 0 for success, or consider returning the hostname or a status code
}