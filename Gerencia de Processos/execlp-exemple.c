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
        execlp("/bin/ls","ls","-l", NULL);
        /* função usada para sobreescrever o texto do processo filho
        pelo código ls e informar os parâmetros de entrada(ls e -1) */
       }
       else{ /* processo pai */
       }
}
