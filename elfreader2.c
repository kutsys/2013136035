#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUF_SIZE 1024
int main(int argc, char *argv[]){
    char buf[BUF_SIZE];
    
    char* file;
 
    file = argv[2];
   
    switch(strlen(argv[1])){
        case 2:
            if(argv[1][1]=='e'){
		sprintf(buf,"readelf -h %s",file);
		system(buf);

            }else if(argv[1][1]=='p'){
		sprintf(buf,"readelf -l %s",file);
		system(buf);

            }else{
		sprintf(buf,"readelf -s %s",file);
		system(buf);

            }
            break;
        case 3:
            if(argv[1][1]=='e' && argv[1][2]=='p'){
		sprintf(buf,"readelf -h %s",file);
		system(buf);
		sprintf(buf,"readelf -l %s",file);
		system(buf);

            }else if(argv[1][1]=='e' && argv[1][2]=='s'){
		sprintf(buf,"readelf -h %s",file);
		system(buf);
		sprintf(buf,"readelf -S %s",file);
		system(buf);

            }else if(argv[1][1]=='p' && argv[1][2]=='s'){
		sprintf(buf,"readelf -l %s",file);
		system(buf);
		sprintf(buf,"readelf -S %s",file);
		system(buf);

            }
            break;
        case 4:
		sprintf(buf,"readelf -e %s",file);
		system(buf);

            break;

    }

    return 0;
}
