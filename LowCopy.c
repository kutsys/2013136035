#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
int main() {
    char block[1024];
    int i,a,in, out;
    int nread=1;
    a=0;
    in = open("sampleTxT", O_RDONLY);
    out = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    while(nread = read(in,block,1) > 0){
        write(out,block,nread);
        sleep(1);
        for(i=0;i<a;i++){
            printf(" ");
         }
        printf("*\n");
        a++;
    }
    printf("done!");
}
