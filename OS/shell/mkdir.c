/*
    my mkdir C source code
	
	Header Files:

	stdio.h: For input and output functions.
	stdlib.h: For general utility functions including strtol.
	sys/stat.h and sys/types.h: For data types and system calls related to file systems.
	errno.h: For handling error numbers.
	print_usage Function: This function prints the usage information for the program.

	main Function:

	Argument Check: The program checks if at least one argument (the directory name) is provided. If not, it prints the usage information and exits.
	Directory Name and Mode: The directory name is taken from the first argument. If a second argument is provided, it is interpreted as the mode (permissions) in octal format.
	mkdir System Call: The mkdir system call is used to create the directory with the specified mode. If an error occurs, the program prints an error message and exits.
	Success Message: If the directory is created successfully, a success message is printed.


	gcc -o mymkdir mymkdir.c

	./mymkdir new_directory 0755

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <directory_name> [<mode>]\n", prog_name);
    fprintf(stderr, "  <directory_name> : Name of the directory to create\n");
    fprintf(stderr, "  <mode>           : (Optional) Directory permissions in octal (e.g., 0755)\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *dir_name = argv[1];
    mode_t mode = 0755; // Default mode

    if (argc == 3) {
        mode = strtol(argv[2], NULL, 8);
    }

    if (mkdir(dir_name, mode) == -1) {
        perror("mkdir");
        exit(EXIT_FAILURE);
    }

    printf("Directory '%s' created with mode '%o'\n", dir_name, mode);
    return EXIT_SUCCESS;
}
