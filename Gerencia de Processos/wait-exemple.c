#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    pid_t pid;
    pid = fork();
       if(pid < 0){/* ocorrência de erro */
           fprintf(stderr,"Erro ao criar processo\n");
           exit(-1);
       }
       else if(pid == 0){/* processo filho */
       }
       else{ /* processo pai */
       wait(NULL); 
       /* faz o processo pai esperar até que pelo
       menos um filho tenha terminado */
       }
}