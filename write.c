#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "write.h"

int write_file() {
    char file_name[20]; // define the file name
    char text_input[100]; // define the text thts written to the output
    printf("File name and format: "); // ask user for file name
    fgets(file_name, sizeof(file_name), stdin); // user input for file name
    file_name[strcspn(file_name, "\n")] = 0;
    FILE * file = fopen(file_name, "w"); // open the file, "W" for write mode
    printf("Write: "); // ask user for the text file data
    fgets(text_input, sizeof(text_input), stdin); // user input for the text data
    text_input[strcspn(text_input, "\n")] = 0;
    fprintf(file, "%s", text_input); // i forgot
    fclose(file); // close the file
    return 0;
}