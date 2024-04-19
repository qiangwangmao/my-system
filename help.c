#include <stdio.h>

int help() {
    puts("Available commands:");
    puts("  help (Lists all available commands)");
    puts("  clear (Clears the terminal)");
    puts("  write   (Writes data to a file)");
    puts("  hostname (Change your hostname)");
    puts("  username (Change your username)");
    puts("  password (Change your password)");
    puts("  logout");
    puts("  reboot");
    puts("  shutdown");

    return 0;
}