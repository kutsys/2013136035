#include <stdlib.h>
#include <stdio.h>

int main() {

    printf("            HOME env :  %s\n", getenv("HOME"));
    printf("            PS1 env  :  %s\n", getenv("PS1"));
    printf("            PATH env :  %s\n", getenv("PATH"));
    printf(" LD_LIBRARY_PATH env :  %s\n", getenv("LD_LIBRARY_PATH"));
}
