#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int a = 0;
void implementacao_filho(int *a){
    *a = *a + 1;
    printf("executando filho 1 = %d\n", getpid());
}
void implementacao_filho2(int *a){
    *a = *a + 1;
    printf("executando filho 2 = %d\n", getpid());
}
int main(){
    int filho1,filho2,pid,status;
    printf("Pai comecou (PID=%d)\n", getpid());

    filho1 = fork();
    if(!filho1){ //se for o filho
    implementacao_filho(&a);
    printf("PID=%d - Valor de a=%d\n",getpid(), a);
    exit(0);
    }
    wait(NULL);
    if(filho1 > 0){
        filho2 = fork();
        if(!filho2){//se for filho
        implementacao_filho2(&a);
        printf("PID=%d - Valor de a=%d\n",getpid(), a);
        exit(0);
        }
    }
    pid = wait(NULL);
    printf("(PID=%d) o PID do processo finalizado é: %d\n", getpid(), a);
    printf("Valor final de a=%d\n", a);

    exit(0);
    printf("Pai terminou\n");

    return 0;

}