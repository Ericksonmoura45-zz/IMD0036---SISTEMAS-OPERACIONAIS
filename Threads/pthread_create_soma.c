#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NTHREADS 5

 void* hello_world(void *tid){
     printf("Esta é a thread %d\n", (int)(size_t)tid);
     sleep(((int)(size_t)tid+1)*2);
     pthread_exit(NULL); 
 }

 int main (int argc, char* argv[]){

     pthread_t threads[NTHREADS]; //vetor com número de threads 5
     int status, i;
     void *thread_return;

     for(i = 0; i < NTHREADS; i++){
         printf("Processo principal criando threads #%d\n", i);
         status = pthread_create(&threads[i], NULL, hello_world, (void*)(size_t) i);
         //pthread_create: escreve o id da thread, função e parâmetro 
         
         if(status!=0){
             printf("Erro na criação da thread. Código de Erro: %d\n", status);
         }
     }
     for(i = 0; i < NTHREADS; i++){
         printf("Esperando a thread %d finalizar...", i);
         pthread_join(threads[i], &thread_return);
         //pthread_join: esperando o endereço de um thread para escrever o resultado numa outra variável, passando o endereço
         printf("Thread %d finalizou\n", i);
     }
     printf("Processo vai finalizar!\n");

     return 0;

 }