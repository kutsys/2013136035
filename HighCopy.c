#include <stdio.h>
int main(){
    int i,a;

    FILE *file_in,*file_out;
    char buffer[1024];
    a = 0;
    file_in = fopen("sampleTxT","r");
    file_out = fopen("file_high","w");

    while (fread(buffer,1,1,file_in) != 0 ) {
        for(i = 0; i<a; i++){
           sleep(1);
            printf(" ");
           }
        a++;
        printf("*\n");
        fwrite(buffer,1,1,file_out);
    }

    fclose(file_in);
    fclose(file_out);
}
                                           
