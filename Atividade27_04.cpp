#include <iostream>
using namespace std;
#include "Lde.hpp"
#include <cstring>

struct Candidato{
    string nome;
    int votos;
    void printCandidato(Candidato * c){
        cout << c->nome << ": " << c->votos << endl;
    }
};

bool compararCandidato(Candidato candidato1, Candidato candidato2){
    return candidato1.votos > candidato2.votos;
}

void printCandidato(Candidato candidato){
    cout << candidato.nome << ": " << candidato.votos << " votos" << endl;
}

template <typename T>
void print(T valor){
    cout << valor << " ";
}

int main(){

    cout << "atividade 1\n\n";

    Lde <Candidato> candidatos;
    inicializar(candidatos);
    inserirFinal(candidatos, (Candidato){"Abelardo",231});
    inserirFinal(candidatos, (Candidato){"Bacanudo",467});
    inserirFinal(candidatos, (Candidato){"Carlos",867});
    inserirFinal(candidatos, (Candidato){"Daniel",536});
    inserirFinal(candidatos, (Candidato){"Estupefato",986});
    inserirFinal(candidatos, (Candidato){"Fagundes",395});
    sort(candidatos, compararCandidato);
    paraCada(candidatos, printCandidato);
    liberar(candidatos);

    cout << "\natividade 2\n\n";

    Lde <int> listaDesordenada;
    inicializar(listaDesordenada);
    inserirFinal(listaDesordenada, 97);
    inserirFinal(listaDesordenada, 110);
    inserirFinal(listaDesordenada, 122);
    inserirFinal(listaDesordenada, 11);
    sort(listaDesordenada);
    paraCada(listaDesordenada, print);
    liberar(listaDesordenada);

    cout << "\n\natividade 3\n\n";

    Lde <int> A;
    inicializar(A);
    inserirFinal(A, 1);
    inserirFinal(A, 2);
    inserirFinal(A, 3);

    Lde <int> B;
    inicializar(B);
    inserirFinal(B, 6);
    inserirFinal(B, 4);
    inserirFinal(B, 3);

    Lde <int> C;
    inicializar(C);
    inserirFinal(C, 6);
    inserirFinal(C, 4);

    Lde <int> uniaoConjunto = uniao(A, B);
    Lde <int> interseccaoConjunto = interseccao(A, B);
    Lde <int> diferencaConjunto = diferenca(A, B);
    
    cout << "A = {1, 2, 3} B = {3, 4, 6} C = {4, 6}\nuniao:" << endl;
    paraCada(uniaoConjunto, print);
    cout << "\ninterseccao:\n";
    paraCada(interseccaoConjunto, print);
    cout << "\ndiferenca:\n";
    paraCada(diferencaConjunto, print);
    cout << "\nA pertence a B?: " << (pertence(A, B)? "Sim" : "Nao") << endl;
    cout << "C pertence a B?: " << (pertence(C, B)? "Sim" : "Nao") << endl;

    liberar(A);
    liberar(B);
    liberar(C);
    liberar(uniaoConjunto);
    liberar(interseccaoConjunto);
    liberar(diferencaConjunto);

    cout << "\natividade 4:\n";


    char textoNormal[] = "hello world testando joy world dhsadhasjworldsadjashdas world";
    Lde <char> textoLde = inicializar(textoNormal, strlen(textoNormal));

    substituirVetores((char *)"world", 6, (char *)"mundo", 6, textoLde);

    paraCada(textoLde, print);

    return 0;
}