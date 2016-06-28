#include <stdio.h>
#include <stdlib.h>


#define LIVRE 0
#define OCUPADO 1
#define REMOVIDO 2


const int tam=10;
typedef struct hash Hash;
struct hash{
    int chave;
    int livre;
};

int funcao_hashing(int num, int i){
    return (num % tam) + i;
}

void mostrar_hash(Hash tabela[]){
    int i;
    for(i=0; i < tam; i++){
        if(tabela[i].livre == OCUPADO)
            printf("\nEntrada %d: %d", i, tabela[i].chave);
        else
            printf("\nEntrada %d: NULL", i);
    }
}

void inserir(Hash tabela[], int n){ 
    int i = 0;   
    int pos = funcao_hashing(n, i);
    
    // tratar colisão
    while(i < tam && tabela[pos].livre == OCUPADO){
        i += 1;
        pos = funcao_hashing(n, i);
    } 
  
    tabela[pos].chave = n;
    tabela[pos].livre = OCUPADO; 
  
    //printf("\n Tabela cheia!");
}


int buscar(Hash tabela[], int n){
    int i = 0;
    int pos = funcao_hashing(n, i);
    
    // tratar colisão
    while(i < tam && tabela[pos].livre == OCUPADO && tabela[pos].chave != n){
        i += 1;
        pos = funcao_hashing(n, i);
    } 
    
    if(tabela[pos].chave == n && tabela[pos].livre != REMOVIDO)
        return pos;
    else
        return tam;
}

void remover(Hash tabela[], int n){
    int pos = buscar(tabela, n);
    
    if(pos < tam){
        printf("\n[%d] = %d - tag: %d", pos, tabela[pos].chave, tabela[pos].livre);
        tabela[pos].livre = REMOVIDO;
        printf("\n[%d] = %d - tag: %d", pos, tabela[pos].chave, tabela[pos].livre);
        tabela[pos].chave = NULL;
        tabela[pos].livre = LIVRE;
        printf("\n[%d] = %d - tag: %d", pos, tabela[pos].chave, tabela[pos].livre);
    }
    else
       printf("\n Elemento não está presente.");
}

/*Hash* criaHash(int tam){
    Hash* ha = (Hash*)malloc(sizeof(Hash));
    
    int i;

    for(i=0; i < tam; i++){
        ha[i].chave = NULL;
        ha[i].livre = LIVRE;
    }

    return ha;    
}*/

int main(){
    Hash tabela[tam]; 
    
    //identificação da tabela
    int i;
    for(i = 0; i < tam; i++)
        tabela[i].livre = LIVRE; // 'L'
        
    //Hash* tabela = criaHash(tam);
    
    inserir(tabela, 371);
    inserir(tabela, 121);
    inserir(tabela, 173);
    inserir(tabela, 203);
    inserir(tabela, 11);
    inserir(tabela, 24);
    mostrar_hash(tabela);
    
    remover(tabela, 121);
    
    return 0;
}
