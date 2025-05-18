#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void help();
void shfont(char *name);

//fc-list | grep Jet | awk -F':' '{print $2}' | sort -u
int main(int argc, char *argv[]){
    if (argc == 1){
        help();
        return EXIT_FAILURE;
    }
    char *help_pmt = "--help";
    int val = strcmp(argv[1],help_pmt );

    if (val == 0){
        help();
        return  EXIT_SUCCESS;
    }
    shfont(argv[1]);
    return 0;
}
    //fc-list | grep Jet | awk -F':' '{print $2}' | sort -u
void shfont(char *name){
    char *command = malloc(100 * sizeof(char));

    sprintf(command, "fc-list | grep %s | awk -F':' '{print $2}' | sort -u | awk -F',' '{print $1}' | sort -u ",name);
    // printf("%s",command);

    system(command);
}
void help(){
    printf("Enter The name of the font\n");
    printf("shfont [OPTIONS] [ARG]\n");
    printf("--help for this memu\n");
}
