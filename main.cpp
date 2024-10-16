#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main()
{
    char command[]="tasklist/FI\"IMAGENAME eq example.exe\"";
    char output[1024];

    while(1)
    {
        FILE *pipe=popen(command,"r");
        if(pipe==NULL)
        {
            fprintf(stderr,"Failed to run command\n");
            exit(1);
        }
         
        while (fgets(output,sizeof(output),pipe)!=NULL)
        {
            if(strstr(output,"example.exe")==NULL)
            {
                pclose(pipe);
                break;
            }
        }
        pclose(pipe);
        
        if (strstr(output,"example.exe")==NULL)
        {
            break;
        }
        
        sleep(5);
    }
    printf("Prosess exe has exited.\n");

    return 0;
}
    
    


     
      

