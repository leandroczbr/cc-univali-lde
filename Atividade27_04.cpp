#include <iostream>
using namespace std;
#include "Lde.hpp"

struct Candidato{
    string nome;
    int votos;
};

void pc(No <Candidato> candidato){
    cout << candidato.info.nome << " " << candidato.info.votos << endl;
}

int candidatoToInt(No <Candidato> * candidato){
    return candidato->info.votos;
}

int main(){
    Lde <Candidato> candidatos;
    inicializar(candidatos);
    inserirFinal(candidatos, (Candidato){"A",231});
    inserirFinal(candidatos, (Candidato){"B",467});
    inserirFinal(candidatos, (Candidato){"C",867});
    inserirFinal(candidatos, (Candidato){"D",536});
    inserirFinal(candidatos, (Candidato){"E",986});
    inserirFinal(candidatos, (Candidato){"F",395});
    sort(candidatos, candidatoToInt, pc);
    cout << candidatos.comeco->info.nome << " ini - fim " << candidatos.fim->info.nome <<endl;
    return 0;
}