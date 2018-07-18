//for compilation; cc -std=c99 -Wall $filename -o $exe_name
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define VERSION "0.0.1"

static char input[2048];
//input[strcspn(input, "\n")] = 0;
const char* quit = "quit";

int diceroll(int sides) {
    return ((rand() % sides) + 1);
}

void parse_token(char* token) {
    switch(strcmp(token, quit)) {
        case 0:
            exit(0);
            break;
    }
    /*int compared = strcmp(token, quit);
    if (compared == 0) {
        exit(0);
    }*/
}

void get_user_input(void) {
    fputs("> ", stdout);
    fgets(input, 2048, stdin);
    //drop trailing newline
    input[strcspn(input, "\n")] = 0;
}

int main(int argc, char** argv) {
    printf("Dialup Punk v%s\n", VERSION);
    printf("For the FloppyJam\n");

    //Main Loop

    while (1) {
        get_user_input();
        //tokenize
        char *token = strtok(input, " ");
        while (token) {
            parse_token(token);
            //this bit here makes strtok move on to the next token in the usr string
            token = strtok(NULL, " ");
        }
    }
    return 0;
}
