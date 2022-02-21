#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* script; //Pointer to hold file
char line[100]; //Pointer to first line
char* cmd; //Pointer to hold the last word with '/'
char exec[100]; //Pointer to hold the string to execute

int main(int argc,char** argv){
    if(argc != 2)              //Check if parameter was given
        return 1;

    script = fopen(argv[1],"r"); //Load script file

    fgets(line,100,script);    //Get first line
    if(line[0] == '#' and  line[1] == '!'){ //Check if "#!" exists
        cmd = strrchr(line,'/');  //Get last "/WORD"
        sprintf(exec,"%s %s",strtok(cmd,"\n/"),argv[1]); //Join all together
        system(exec); //Execute
        return 0;
    }
    return 1;
}
