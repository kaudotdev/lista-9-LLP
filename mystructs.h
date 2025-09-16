#ifndef MYSTRUCTS_H
#define MYSTRUCTS_H

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int hora;
    int minuto;
} Horario;

typedef struct {
    float x, y;
} Ponto;

typedef struct {
    char nome[60];
    float altura;
    Data data_nascimento;
} Pessoa;

typedef struct {
    char texto[201];
    int situacao;
    Data data;
    Horario horario;
} Compromisso;

typedef struct {
    char nome[60];
    int idade;
    float nota;
} Aluno;

typedef struct {
    char nome[60];
    float notas[3];
    float media;
    int situacao;
} Disciplina;

typedef struct {
    char nome[60];
    Data data_nascimento;
} PessoaData;

typedef struct {
    char nome[60];
    float cotacoes[3];
} Produto;

typedef struct {
    char nome[60];
    char estado[3];
} PessoaEstado;

#endif