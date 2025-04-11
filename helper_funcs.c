#include "so_long.h"

void exit_error(char *error_message)
{
    perror(error_message);
    //use another error funct
    exit(2);
}