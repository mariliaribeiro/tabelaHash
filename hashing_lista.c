#include <stdio.h>
#include <stdlib.h>


#define LIVRE 0
#define OCUPADO 1
#define REMOVIDO 2


const int tam=8;
typedef struct hash Hash;
struct hash{
    int chave;
    Hash* prox;
};

int funcao_hashing(int num){
    return num % tam;
}

void mostrar_hash(Hash *tabela[]){
    Hash *aux;
    int i;
    for(i=0; i < tam; i++){
        aux = tabela[i];
        while(aux != NULL){
            printf("\nEntrada %d: %d", i, aux->chave);
            aux = aux->prox;
        }
    }
}

void inserir(Hash *tabela[], int n){
    int pos = funcao_hashing(n);
    Hash * novo = (Hash*) malloc(sizeof(Hash));
    novo->chave = n;
    novo->prox = tabela[pos];
    tabela[pos] = novo;
}

void remover(Hash *tabela[], int n){
    int pos= funcao_hashing(n);
    
    Hash *aux;
    
    if(tabela[pos] != NULL){
        if(tabela[pos]->chave == n){
            aux = tabela[pos];
            tabela[pos] = tabela[pos]->prox;
            //delete aux; 
            free(aux);
        }
        else{
            aux = tabela[pos]->prox;
            Hash* ant = tabela[pos];
            
            while(aux != NULL && aux->chave != n){
                ant = aux;
                aux = aux->prox;
            }
            
            if(aux != NULL){
                ant->prox = aux->prox;
                //delete aux;
                free(aux);
            }
            else{
                printf("\nNúmero não encontrado");
            }
        }
    }
    else
        printf("\nNúmero não encontrado");
}

int main(){
    Hash *tabela[tam];
    int num, i;
    
    //identificação da tabela
    for(i = 0; i < tam; i++)
        tabela[i] = NULL; // 'L'
        
        
    num = 5;
    inserir(tabela, num);
    mostrar_hash(tabela);
    remover(tabela, num);
    
    return 0;
}
