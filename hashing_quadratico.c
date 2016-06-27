#include <stdio.h>
#include <stdlib.h>


#define LIVRE 0
#define OCUPADO 1
#define REMOVIDO 2


const int tam=8;
typedef struct hash Hash;
struct hash{
    int chave;
    int livre; // L = 0, O = 1, R = 2
    //char livre; //L = livre, O = ocupado, R = removido
};

int funcao_hashing(int num){
    return num % tam;
}

void mostrar_hash(Hash tabela[]){
    int i;
    for(i=0; i < tam; i++){
        if(tabela[i].livre == OCUPADO ) //'O'
            printf("\nEntrada %d: %d", i, tabela[i].chave);
    }
}

void inserir(Hash tabela[], int n){
    int pos = funcao_hashing(n);
    int i = 1;
    
    while(i <= tam && tabela[pos].livre != LIVRE && tabela[pos].livre != REMOVIDO){ //'L', 'R'
        pos = (pos + i)%tam;
        i = i + 1;
    }
    if (i <= tam){
        tabela[pos].chave = n;
        tabela[pos].chave = OCUPADO; //'O'
    }
    else
        printf("\n Tabela cheia ou em loop!");
}

int buscar(Hash tabela[], int n){
    int i =0;
    int pos = funcao_hashing(n);
    
    while(i <= tam && tabela[pos].livre != LIVRE && tabela[pos].chave != n){ //'L'
        pos = (pos+i)%tam;
        i = i +1;
    }
    
    if(tabela[pos].chave == n && tabela[pos].livre != REMOVIDO) // 'R'
        return pos;
    else
        return tam; // não encontrado
}

void remover(Hash tabela[], int n){
    int posicao = buscar(tabela, n);
    
    if(posicao < tam)
        tabela[posicao].livre = REMOVIDO; //'R'
    else
       printf("\n Elemento não está presente.");
}

int main(){
    Hash tabela[tam];
    
    int num, i;
    
    //identificação da tabela
    for(i = 0; i < tam; i++)
        tabela[i].livre = LIVRE; // 'L'
        
        
    num = 5;
    inserir(tabela, num);
    mostrar_hash(tabela);
    remover(tabela, num);
    
    return 0;
}
