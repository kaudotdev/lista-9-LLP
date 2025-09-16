#ifndef MYCOMPUTING_H
#define MYCOMPUTING_H

#include "mystructs.h"

float calcularDistancia(Ponto a, Ponto b);



void ordenarAlunosNome(Aluno *a, int n);
void ordenarAlunosIdade(Aluno *a, int n);
void ordenarAlunosNota(Aluno *a, int n);

void calcularMediasDisciplinas(Disciplina *d, int n);

void contarEstados(PessoaEstado *p, int qtd);

#endif