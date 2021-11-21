#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/shm.h>

int a = 0;
void implemetacao_filho1(int *a){
    *a = *a + 1;
    printf("executando filho 1 = %d\n", getpid());
}

void implementacao_filho2(int *a){
    *a = *a + 2;
    printf("executando filho 2 = %d\n", getpid());
}

int main(){
    int filho1, filho2, pid, status;
    int *mem;
    
    int valor = shmget(IPC_PRIVATE, 20*sizeof(int), IPC_CREAT | 0666);
    mem = shmat(valor, NULL, 0);
    if(mem < 0){
        printf("Erro na Alocação");
        return 0;
    }
    *mem = 5;

    /* Criando espaço de endereçamento compartilhado(privado), tendo 20* o tamanho de um char */
    /* Recenbo o Id do endereço de memoria */

    printf("Pai começa: PID=%d", getpid());
    /* Criando processo */

    filho1 = fork(); /* Forkando processo | criando primeiro filho */
    if(filho1 == 0){ //Se for o filho
        implemetacao_filho1(&a);
        mem = shmat(seg_id, NULL, 0);
        /*compartimento de memoria criado pelo pai e compartilhado pelos filhos */
        sprintf(mem, "Escrevendo teste");
        /* escreve da região de memoria apontada por mem*/
        printf("%s no processo PID=%d\n", mem, getpid());
        shmdt(mem);
        /* free no ponteiro mem */
        exit(0);
    }
    status = wait(NULL);
    if(filho1 > 0){
        filho2 = fork(); /* Forkando processo | criando segundo filho */
        if(!filho2){//se for filho
        implementacao_filho2(&a);
        mem = shmat(seg_id, NULL, 0);
        printf("%s no processo PID=%d\n", mem, getpid());
        /* Somente ira ler o que contem no espaço apontado por mem */
        shmdt(mem);
        exit(0);
        }
    }

    status = wait(NULL);
    printf("(PID=%d) Processo sendo Finalizado!\n", getpid());
    printf("Valor final de a=%d\n", a);
    shmctl(seg_id, IPC_RMID, NULL);
    /* apagando espaço de endereçamento compartilhado */
    exit(0);
    printf("Pai terminou\n");

    return 0;

}