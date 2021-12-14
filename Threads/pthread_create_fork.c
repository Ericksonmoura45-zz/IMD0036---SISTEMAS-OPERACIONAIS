#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#DEFINE NTHREADS 2
pid_t pid; // criamos um probcesso

void* hello_world(void *tid){
    //sleep(2);
    printf("Hello World. Esta é a Thread %d\n", (int)(size_t)tid);
    //sleep(((int)(size_t)tid+1)*2);
    pthread_exit(NULL);
}

int main (int argc, char *argv[]){

    pthread_t threads[NTHREADS];
    int status, i, returno;
    void *thread_return;

    pid = fork(); // criamos um processo filho

    for(i = 0; i<NTHREADS; i++){
        //getpid: id do processo
        printf("Processo [%d] criando thread #%d\n", getpid(), i);
        status = pthread_create(&threads[i], NULL, hello_world, (void *)(size_t) i);
        //if(!i)
        // pid = fork();

        if(status!=0){
            printf("Erro na Criação da Thread. Código de Erro: %d\n", status);
            return 1;
        }
    }
    
    for(i = 0; i < NTHREADS; i++){
        printf("Processo[%d]: Esperando Thread %d finalizar.....\n", getpid(), i);
        returno = pthread_join(threads[i], &thread_return);
        printf("Processo[%d]: Thread %d finalizada. Retorno: %d\n", getpid(), i);
    }
    printf("Processo %d vai finalizar\n", getpid());

    return 1;
}