#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    pid_t pid;
    int retorno;
    pid = fork();
    if(pid < 0){
        printf("Erro ao criar processo\n");
        return 1;
    }
    else if(pid == 0){
        printf("Esta é a execução do Filho PID=%d , cujo pai tem PID=%d)\n", getpid(), getppid());
        printf("Esperando...\n");
        sleep(10);
        printf("Voltou!");
        execlp("/bin/ls", "ls", "-l", NULL);
        printf("execpl executado!\n");
        exit(0);
    }
    //getpid() - PID do filho, getppid() - PID do pai
    else{
        retorno = wait(NULL);//entrega o valor do PID do filho que acabou sua execução primeiro
        //pai esperará algum filho terminar para finalizar o processo
        printf("Processo-filho finalizado e seu PID era: %d\n", retorno);
    }
    return 0;
}