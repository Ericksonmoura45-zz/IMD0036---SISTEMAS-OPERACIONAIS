#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

 void* hello_world(void *tid){
     printf("Esta é a thread %d\n", (int) (size_t)tid);
     pthread_exit(NULL); //Função cujo a thread irá executar
 }
 //quando compilar, usar a tag -pthread
 int main (int argc, char* argv[]){
     pthread_t thread; // criamos a thread
     int status;
     void *thread_return;

     printf("Processo principal criando thread\n");
     status = pthread_create(&thread, NULL, hello_world, 0);
     //crio a thread e passo o endereço da variavel threado como parametro
     //e defino qual será sua função(hello_world)
     if(status!=0){//erro na criação da thread 
         printf("Erro na criação da thread. Código de erro: %d\n", status);
         return 1;
     }

     printf("Esperando thread finalizar....\n");
     pthread_join(thread, &thread_return);
     //mesma coisa que wait dos processos
     //pthread_join(thread que estou esperando terminar, armazena o retorno da thread(da função))
     printf("Thread finalizada\n");

     printf("Processo pai vai finalizar\n");

     return 0;
 }