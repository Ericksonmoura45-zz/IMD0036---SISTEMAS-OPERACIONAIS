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
     int vetor[argc];
     int status;
     void *thread_return;

     for(int i = argc; i =! 0; i==){     
     pthread_t thread; // criamos a thread
     printf("Processo principal criando thread\n");
     status = pthread_create(&thread, NULL, hello_world, 0);
     //crio a thread e passo o endereço da variavel threado como parametro
     //e defino qual será sua função(hello_world)
     vetor[i] = &thread;
     printf('Thread de numero %d adicionada ao vetor', &i);
     if(status!=0){//erro na criação da thread 
         printf("Erro na criação da thread. Código de erro: %d\n", status);
         return 1;
     }
     printf("Esperando thread finalizar....\n");
     pthread_join(thread, &thread_return);
     };
     return 0;
 }