
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//primeira estrutura dos n�s
   typedef struct no{

    int valor;
    struct no *proximo; //ponteiro para outro n�

   }No; //esta estrutura � do tipo n�

   //segunda estrutura
   typedef struct{

    No *topo;   //ponteiro do tipo n�
    int tam;

   }Pilha;  //esta estrutura � do tipo pilha

   //opera��o push (empilhar)
   void empilhar(Pilha *p, int elemento){

    No *no = malloc(sizeof(No)); //pegando um endere�o de mem�ria din�mico e guardando no ponteiro do tipo No
    no->valor = elemento;
    no->proximo = p->topo;  //O pr�ximo elemento sempre ser� o topo da nossa pilha
    p->topo = no;   //E o topo da nossa pilha sempre virar� um novo n� at� acabar a inser��o de elementos
    p->tam++;   //contagem do tamanho da nossa pilha

   }

   //opera��o pop (desempilhar)
   No* desempilhar(Pilha *p){
    No *no = NULL;  //ponteiro do tipo n� que ser� nulo

    if(p->topo != NULL){    //verificando se o nosso topo da pilha tem elementos
        no = p->topo;   //se tiver, o nosso n� receber� o ponteiro que aponta para o topo da nossa pilha
        p->topo = no->proximo; //o topo receber� o proximo n�
        p->tam--;  //e o tamanho da pilha diminui conforme vai desempilhando
    }
    return no;  //Retorna o n�
    free(no);
   }


   //opera��o imprimir
   void imprimir(No *no){
        if(no){ //se o nosso n� for diferente de nulo
            printf("%d\n", no->valor);  //imprime o valor que est� no nosso ponteiro n�
            imprimir(no->proximo);  //reutilizando a fun��o para percorrer a nossa pilha e imprimir o pr�ximo valor
        }
   }

int main(){

    //Variaveis
    No *no;
    int op, valor;
    Pilha p;
    p.tam = 0;
    p.topo = NULL;


    do{
        //menu de op��es
        printf("Menu de opcoes:\n 01 - sair\n 02 - empilhar\n 03 - desempilhar\n 04 - imprimir\n");
        scanf("%d", &op);

        //escolhendo as op��es
        switch(op){

        case 1:
            printf("\nVoce escolheu sair.");
            break;

        case 2:
            printf("\nDigite um valor para a pilha: \n");
            scanf("%d", &valor);

            empilhar(&p, valor);
            break;

        case 3:
            printf("\n voce escolheu desempilhar: \n");
            no = desempilhar(&p);

            if(no){
                printf("\nDesempilhando: %d\n", no->valor);
            }
            break;

        case 4:
            printf("\n Imprimindo a pilha: \n");
            printf("-----------------------------PILHA---------------------------------\n");

            imprimir(p.topo);

            printf("-----------------------------PILHA---------------------------------\n");

        default:
            printf("Opcao invalida\n");
        }


    }while(op != 1);



    return 0;
}

