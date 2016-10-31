#include <stdlib.h>
#include <stdio.h>
extern char **environ;
int main() {

    char **env = environ;

    if(!setenv("TEST_ENV","1234",1)) {
       printf("\nTEST_ENV : %s\n\n",getenv("TEST_ENV"));
    }
}
