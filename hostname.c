#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXBUFSIZE 256

char hostname[MAXBUFSIZE + 1]; // HOSTNAME VARIABLE

int changehost() {
    FILE *hostfile = fopen("hostname.txt", "r");
    fgets(hostname, MAXBUFSIZE, hostfile);
    fclose(hostfile);

    int validHostname = 0;

    while (!validHostname) { // keep asking for hostname until a valid one is entered
        printf("Your new hostname: ");
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

    FILE *file = fopen("hostname.txt", "w");
    fprintf(file, "%s", hostname);
    fclose(file);

    return 0; // return 0 for success, or consider returning the hostname or a status code
}