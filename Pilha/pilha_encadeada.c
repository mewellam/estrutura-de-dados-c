// Pilha sequencial
// objetivo: empilhar e desempilhar containers
// programador: Miguel Moraes


// Bibliotecas
#include <stdio.h>
#include <stdlib.h>

// Definicoes de tipo

typedef struct container{
    int id;
    float peso_tonelada;
    char empresa[30];
} container;

typedef struct pilha{
    container itens;
    struct pilha *prox;               // Topo da pilha
} pilha;

// Declaracao de funcoes

void entrada_dados( container *novo );
void esvazia_pilha( pilha **p );
void push( pilha **p );
void pop( pilha **p );
void imprime_pilha( pilha *p );

// Main

int main(){
    int op = 1; // Opcao
    pilha *p;
    // Inicia a pilha
    p = NULL;

    cria_pilha( &p ); // Apenas uma garantia.

    system( "cls" );  // cls para nao mostrar a mensagem.

    while(op != 0){

        printf("/-----------------------/\n");
        printf("/------ 1 Esvaziar -----/\n");
        printf("/------- 2 Push --------/\n");
        printf("/-------- 3 pop --------/\n");
        printf("/-- 4 Imprimir pilha ---/\n");
        printf("/-----------------------/\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &op);

        switch (op)
        {
        case 1:
            esvazia_pilha(&p);
            break;
        
        case 2:
            push(&p);
            break;

        case 3:
            pop(&p);
            break;

        case 4:
            imprime_pilha(p);
            break;

        case 0:
            printf("\nSaindo do programa...");
            break;
        }

        if(op != 0){

            printf("\nPressione enter para continuar"); 
            getchar();                                  // Garante que a tela sera pausada (Absorve o espaco)
            getchar();                                  // Pausa a tela
            system( "cls" );                            // Limpa a tela

        }
    }    
}

// Funcoes

void esvazia_pilha( pilha **p){

    pilha *a;

    // Esvazia pilha
    while(*p != NULL){
        a = *p;
        *p = (*p)->prox;
        free(a);
    }
    
    printf("\nPilha criada!\n");

}

void push( pilha **p ){

    pilha *novo = (pilha*) malloc (sizeof(pilha));

    // Verificar se pilha cheia
    if( novo == NULL ){
        printf("\nPilha cheia!\n");
    }
    else{ // Caso tenha espaco, pede dados e insere container.
        entrada_dados( &novo->itens ); 
        novo->prox = *p;
        *p = novo;
        printf("\nContainer adicionado\n");
    }
}

void entrada_dados( container *novo ){
    
    printf("\nDigite o ID do container: ");
    scanf("%d", &novo->id);
    printf("\nPeso em toneladas: ");
    scanf("%f", &novo->peso_tonelada);
    printf("\nEmpresa a qual pertence: ");
    scanf(" %30[^\n]", novo->empresa);

}

void pop( pilha **p){

    pilha *aux;
    // Verifica pilha vazia
    if( *p == NULL ){
        printf("\nPilha vazia!\n");
    }
    else{
        aux = *p;
        *p = (*p)->prox;
        free(aux);
        printf("\nContainer removido!\n");
    }
    
}

void imprime_pilha( pilha *p ){

    int po = 1;

    // Verificar se lista vazia
    if( p == NULL){
        printf("\nPilha vazia!\n");
        return;
    }

    // Loop para mostrar na tela
    while( p != NULL){

        printf("\nEndereco de memoria: %p", p);
        printf("\nPosicao na pilha: %d", po);
        printf("\nContainer ID: %d", p->itens.id);
        printf("\nPeso: %.2f", p->itens.peso_tonelada);
        printf("\nEmpresa: %s", p->itens.empresa);

        p = p->prox;
        po++;
        printf("\n");
    }
}