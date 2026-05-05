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
Lde <T> inicializar(T listaNormal[], size_t tamanho){
    Lde <T> Lista;
    inicializar(Lista);
    for(int i = 0; i < tamanho; i++){
        inserirFinal(Lista, listaNormal[i]);
    }
    return Lista;
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
void paraCada(Lde <T> &lista, void (*func)(T)){
    if(lista.comeco == NULL) return;
    No <T> *aux = lista.comeco;
    while(aux != NULL){
        func(aux->info);
        aux = aux->elop;
    }
}

template <typename T>
void trocar(Lde <T> &lista, No <T> * primeiro, No <T> * segundo){
    
    T auxPrimeiro = primeiro->info;
    primeiro->info = segundo->info;
    segundo->info = auxPrimeiro;

}

template <typename T>
bool _comparacaoSimples(T valor1, T valor2){
    return valor1 > valor2;
}

template <typename T>
void sort(Lde <T> &lista, bool (*comparar)(T, T)){
    No<T> * aux;
    bool trocou = true;
    while(trocou){
        trocou = false;
        aux = lista.comeco;
        while(aux->elop != NULL){
            if(!comparar(aux->info, aux->elop->info)){
                trocar(lista, aux, aux->elop);
                trocou = true;
            }
            aux = aux->elop;
        }
    }
}

template <typename T>
void sort(Lde <T> &lista){
    sort(lista, _comparacaoSimples);
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
template <typename T>
Lde <T> uniao(Lde <T> &v1, Lde <T> &v2){
    Lde <T> retorno;
    inicializar(retorno);

    No <T> * aux = v1.comeco;
    while (aux != nullptr)
    {
        if (!pesquisar(v2, aux->info)){
            inserir(retorno, aux->info);
        }
        aux = aux->elop;
    }
    aux = v2.comeco;
    while (aux != nullptr){
        inserir(retorno, aux->info);
        aux = aux->elop;
    }

    return retorno;
}

template <typename T>
Lde <T> interseccao(Lde <T> &v1, Lde <T> &v2){
    Lde <T> retorno;
    inicializar(retorno);

    No <T> * aux = v1.comeco;
    while (aux != nullptr)
    {
        if (pesquisar(v2, aux->info)){
            inserir(retorno, aux->info);
        }
        aux = aux->elop;
    }

    return retorno;
}

template <typename T>
Lde <T> diferenca(Lde <T> &v1, Lde <T> &v2){
    Lde <T> retorno;
    inicializar(retorno);

    No <T> * aux = v1.comeco;
    while (aux != nullptr)
    {
        if (!pesquisar(v2, aux->info)){
            inserir(retorno, aux->info);
        }
        aux = aux->elop;
    }

    return retorno;
}

template <typename T>
bool pertence(Lde <T> &v1, Lde <T> &v2){

    bool Pertence = true;

    No <T> * aux = v1.comeco;
    while (aux != nullptr)
    {
        if (!pesquisar(v2, aux->info)){
            Pertence = false;
        }
        aux = aux->elop;
    }

    return Pertence;
}

template <typename T>
Lde <T> substituirVetores(T * vetorMatriz, size_t tamanhoMatriz, T * vetorNovo, size_t tamanhoNovo, Lde <T> &lista){
    Lde <T> retorno;
    inicializar(retorno);

    Lde <T> novoLde = inicializar(vetorNovo, tamanhoNovo-1);

    No <T> * aux = lista.comeco;

    while (aux != nullptr)
    {
        cout << aux->info;
        if(aux->info == vetorMatriz[0] && aux->elop != nullptr){
                cout << " teste3 ";
            int index = 0;
                cout << " teste4 ";
            No <T> * possivelTroca = aux;
                cout << " teste5 ";
            while (index < (tamanhoMatriz) && aux->elop != nullptr){
                index++;
                aux = aux->elop;
                    cout << " . ";
                if(index < (tamanhoMatriz) && aux->info != vetorMatriz[index]){
                    cout << aux->info << " != " << vetorMatriz[index] << " ";
                    possivelTroca = nullptr;
                }
            }
            if (possivelTroca != nullptr){
                cout << "ant - possivelTroca - fim - pos" << endl;
                No <T> * fim = aux;
                cout << " ant.elop = novoLde.comeco " << endl;
                possivelTroca->eloa->elop = novoLde.comeco;
                if (fim->elop != nullptr){
                    cout << " novoLde.fim.elop = pos " << endl;
                    novoLde.fim->elop = fim->elop;
                    cout << " pos.eloa = novoLde.fim " << endl;
                    fim->elop->eloa = novoLde.fim;
                    cout << " aux = pos" << endl;
                    aux = fim->elop;
                    cout << " fim.elop = nullptr " << endl;
                    fim->elop = nullptr;
                }
                cout << " delete NovoLde " << endl;
                delete (&novoLde); // apenas deleta o Lde, os Nós continuam
                cout << " testefim " << aux->info << ":" << endl;
                possivelTroca = nullptr;
            }
        }
        aux = aux->elop;
    }
    
}









