#ifndef MYINPUT_H
#define MYINPUT_H

#include "mystructs.h"

void lerPonto(Ponto *p, const char* label);
int cadastrarPessoas(Pessoa *pessoas, int max);
void adicionarCompromisso(Compromisso *c, int *qtd, int max);
void cancelarCompromisso(Compromisso *c, int qtd);
void lerAlunos(Aluno *alunos, int n);
void lerDisciplinas(Disciplina *d, int n);
int lerPessoasData(PessoaData *p, int max);
void lerProdutos(Produto *produtos, int n);
void incluirPessoaEstado(PessoaEstado *p, int *qtd, int max);

int menuPrincipal();
int menuListagemPessoas();
int menuCompromissos();
int menuOrdemAlunos();
int menuPessoasEstado();

void gerenciarMenuPrincipal();
void gerenciarMenuPessoas(Pessoa *pessoas, int qtd);
void gerenciarMenuCompromissos(Compromisso *c, int *qtd, int max);
void gerenciarMenuAlunos(Aluno *alunos, int n);
void gerenciarMenuPessoasEstado(PessoaEstado *p, int *qtd, int max);

#endif