#include <iostream>
using namespace std;

template <typename T>
struct No{
    T info;
    No <T> *elo;
};

template <typename T>
struct Lue{
    No <T> *comeco, *fim;
};

template <typename T>
void inicializar(Lue <T> &lista){
    lista.comeco = NULL;
    lista.fim = NULL;
}

template <typename T>
bool vazio(Lue <T> lista){
    return (lista.comeco == NULL) ? true : false;
}

template <typename T>
bool inserirFinal(Lue <T> &lista, T valor){
    No <T> *novo = new No<T>;
    if( novo == NULL ) return false;
    novo->info = valor;
    novo->elo = NULL;

    if( lista.comeco == NULL ){ // Caso A
        lista.comeco = novo;
        lista.fim = novo;
    }
    else{ // Caso C
        lista.fim->elo = novo;
        lista.fim = novo;
    }
    return true;
}

template <typename T>
bool inserir(Lue <T> &lista, T valor){
    No <T> *novo = new No<T>;
    if( novo == NULL ) return false;
    novo->info = valor;
    novo->elo = NULL;

    if( lista.comeco == NULL ){ // Caso A
        lista.comeco = novo;
        lista.fim = novo;
    }
    else if( valor < lista.comeco->info ){ // Caso B
        novo->elo = lista.comeco;
        lista.comeco = novo;
    }
    else if( valor > lista.fim->info ) { // Caso C
        lista.fim->elo = novo;
        lista.fim = novo;
    }
    else{ // Caso D
        No <T> *ant = lista.comeco;
        while( ant != NULL ){
            No <T> *prox = ant->elo;
            if( ant->info < valor && valor < prox->info ){
                ant->elo = novo;
                novo->elo = prox;
                break;
            }
            ant = ant->elo;
        }
    }
    return true;
}

template <typename T>
bool pesquisar(Lue <T> lista, T valor){
    No <T> *aux = lista.comeco;
    while( aux != NULL ){
        if( valor == aux->info ) return true;
        aux = aux->elo;
    }
    return false;
}

template <typename T>
void mostrar(Lue <T> lista){
    No <T> *aux = lista.comeco;
    while( aux != NULL ){
        cout << aux->info << " ";
        aux = aux->elo;
    }
}

template <typename T>
void liberar(Lue <T> &lista){
    No <T> *aux = lista.comeco, *aux2;
    while( aux != NULL ){
        aux2 = aux;
        aux = aux->elo;
        delete aux2;
    }
    lista.comeco = NULL;
    lista.fim = NULL;
}















