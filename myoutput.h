#ifndef MYOUTPUT_H
#define MYOUTPUT_H

#include "mystructs.h"

void exibirDistancia(float d);
void exibirPessoa(const Pessoa *p);
void listarPessoasPorMes(Pessoa *pessoas, int qtd, int mes);
void listarPessoasAbaixoMediaAltura(Pessoa *pessoas, int qtd);
void listarCompromissos(const Compromisso *c, int qtd);
void exibirCompromisso(const Compromisso *c);
void exibirAluno(const Aluno *a);
void exibirDisciplina(const Disciplina *d);
void exibirPessoaData(const PessoaData *p, int idade);
void mostrarIdades(PessoaData *p, int qtd, int diaA, int mesA, int anoA);
void mostrarProdutosAbaixoMedia(Produto *produtos, int n);
void listarPessoasEstado(PessoaEstado *p, int qtd);
void exibirProduto(const Produto *prod);
void exibirPessoaEstado(const PessoaEstado *p, int qtd);
void exibirAlunos(const Aluno *a, int n);
void exibirDisciplinas(const Disciplina *d, int n);

#endif