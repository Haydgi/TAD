#include <stdio.h>
#include <stdlib.h>
typedef struct aluno{
    int matri;
    char nome [80];
    float nota;
    struct aluno *proximo;
}Aluno;

typedef struct{
    Aluno *inicio;
    int tam;
}Lista;



void criar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}



void inserir_ordenado(Lista *lista, int num){
    Aluno *aux, *novo = malloc(sizeof(Aluno));

    if(novo){
        novo->A1.matri = num;
        if(lista->inicio == NULL){
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else if(novo->A1.matri < lista->inicio->A1.matri){
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }
        else{
            aux = lista->inicio;
            while(aux->proximo && novo->A1.matri > aux->proximo->A1.matri)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

Aluno* remover(Lista *lista, int num){
    Aluno *aux, *remover = NULL;

    if(lista->inicio){
        if(lista->inicio->A1.matri == num){
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->tam--;
        }
        else{
            aux = lista->inicio;
            while(aux->proximo && aux->proximo->A1.matri != num)
                aux = aux->proximo;
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                lista->tam--;
            }
        }
    }

    return remover;
}


void imprimir(Lista lista){
    Aluno *aluno = lista.inicio;
    printf("\n\tLista tam %d: ", lista.tam);
    while(aluno){
        printf("Matricula %d \t Nome X \t Nota Y \n", aluno->matri);
        aluno = aluno->proximo;
    }
    printf("\n\n");
}

int main(){
    int i=0; //numero do aluno
    int opcao, matri, anterior;
    //Aluno *lista = NULL;
    Lista lista;
    
    Aluno A1;

    criar_lista(&lista);

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir ordenado\n\t2 - Remover\n\t3 - Imprimir\n\t4 - \n\t5 - \n\t6 - \n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Digite um numero de matricula: ");
            scanf("%d", A1.matri);
            printf("Digite o nome do aluno: ");
            scanf("%c", A1.nome);
            printf("Insira a nota de %c: ",A1.nome);
            scanf("%f", A1.nota);
            inserir_ordenado(&lista, A1);
            i++;
            break;
        case 2:
           printf("Digite uma matricula a ser removida: ");
            scanf("%d", &matri);
            removido = remover(&lista, matri);
            if(removido){
                printf("Elemento removido: %d\n", removido->matri);
                free(removido);
            }
            else
                printf("elemento inexistente!\n");
                
                i++;
            break;
        case 3:
            imprimir(lista);
            i++;
            break;
        case 4:
            //
        case 5:
           //
        case 6:
           //
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}
