#include <iostream>
using namespace std;

template <typename T>
struct No{
    T info;
    No <T> *elop;
    No <T> *eloa;
};

template <typename T>
struct Lde{
    No <T> *comeco, *fim;
};

template <typename T>
void inicializar(Lde <T> &lista){
    lista.comeco = NULL;
    lista.fim = NULL;
}

template <typename T>
bool vazio(Lde <T> lista){
    return (lista.comeco == NULL) ? true : false;
}

template <typename T>
bool inserirFinal(Lde <T> &lista, T valor){
    No <T> *novo = new No<T>;
    if( novo == NULL ) return false;
    novo->info = valor;
    novo->elop = NULL;
    novo->eloa = NULL;

    if( lista.comeco == NULL ){ // Caso A
        lista.comeco = novo;
        lista.fim = novo;
    }
    else{ // Caso C
        lista.fim->elop = novo;
        novo->eloa = lista.fim;
        lista.fim = novo;
    }
    return true;
}

template <typename T>
bool inserir(Lde <T> &lista, T valor){
    No <T> *novo = new No<T>;
    if( novo == NULL ) return false;
    novo->info = valor;
    novo->elop = NULL;
    novo->eloa = NULL;

    if( lista.comeco == NULL ){ // Caso A
        lista.comeco = novo;
        lista.fim = novo;
    }
    else if( valor < lista.comeco->info ){ // Caso B
        lista.comeco->eloa = novo;
        novo->elop = lista.comeco;
        lista.comeco = novo;
    }
    else if( valor > lista.fim->info ) { // Caso C
        lista.fim->elop = novo;
        novo->eloa = lista.fim;
        lista.fim = novo;
    }
    else{ // Caso D
        No <T> *ant = lista.comeco;
        while( ant != NULL ){
            No <T> *prox = ant->elop;
            if( ant->info < valor && valor < prox->info ){
                ant->elop = novo;
                novo->elop = prox;
                prox->eloa = novo;
                novo->eloa = ant;
                break;
            }
            ant = ant->elop;
        }
    }
    return true;
}

template <typename T>
bool pesquisar(Lde <T> &lista, T valor){
    No <T> *aux = lista.comeco;
    while( aux != NULL ){
        if( valor == aux->info ) return true;
        aux = aux->elop;
    }
    return false;
}

template <typename T>
void mostrar(Lde <T> &lista){
    No <T> *aux = lista.comeco;
    while( aux != NULL ){
        cout << aux->info << " ";
        aux = aux->elop;
    }
}

template <typename T>
void paraCada(Lde <T> &lista, void (*func)(No<T>)){
    if(lista.comeco == NULL) return;
    No <T> *aux = lista.comeco;
    while(aux != NULL){
        func(*aux);
        aux = aux->elop;
    }
}

template <typename T>
void trocar(Lde <T> &lista, No <T> * primeiro, No <T> * segundo){
    cout << "trocando " << primeiro->info.nome << " por " << segundo->info.nome << endl;
    
    T auxPrimeiro = primeiro->info;
    primeiro->info = segundo->info;
    segundo->info = auxPrimeiro;

}

template <typename T>
void sort(Lde <T> &lista, int (*index)(No<T>*), void (*pc)(No<T>)){
    No<T> * aux;
    bool trocou = true;
    while(trocou){
        trocou = false;
        aux = lista.comeco;
        while(aux->elop != NULL){
            cout << index(aux) << "<" << index(aux->elop) << endl;
            if(index(aux) < index(aux->elop)){
                trocar(lista, aux, aux->elop);
                trocou = true;
            }
            aux = aux->elop;
            paraCada(lista, pc);
        }
    }
}

template <typename T>
void liberar(Lde <T> &lista){
    No <T> *aux = lista.comeco, *aux2;
    while( aux != NULL ){
        aux2 = aux;
        aux = aux->elop;
        delete aux2;
    }
    lista.comeco = NULL;
    lista.fim = NULL;
}















