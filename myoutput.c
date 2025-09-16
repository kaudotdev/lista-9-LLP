#include <stdio.h>
#include "myoutput.h"

/*
* Aluno: Kauan Souza
* Problema: Projeto lista 9, enunciados em cada questão do questoes.c
*/

void exibirDistancia(float d) {
    printf("Distância entre os pontos: %.2f\n", d);
}

void exibirPessoa(const Pessoa *p) {
    printf("%s - %.2f m - %02d/%02d/%04d\n", p->nome, p->altura, p->data_nascimento.dia, p->data_nascimento.mes, p->data_nascimento.ano);
}

void listarCompromissos(const Compromisso *c, int qtd) {
    const char *situacoes[] = {"Agendado", "Cancelado", "Concluído"};
    printf("Compromissos agendados:\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d. [%s] %02d/%02d/%04d %02d:%02d - %s\n",
               i + 1,
               situacoes[c[i].situacao],
               c[i].data.dia, c[i].data.mes, c[i].data.ano,
               c[i].horario.hora, c[i].horario.minuto,
               c[i].texto);
    }
}

void listarPessoasPorMes(Pessoa *pessoas, int qtd, int mes) {
    printf("Pessoas nascidas no mês %d:\n", mes);
    for (int i = 0; i < qtd; i++) {
        if (pessoas[i].data_nascimento.mes == mes) {
            printf("%s - %.2f m - %02d/%02d/%04d\n", pessoas[i].nome, pessoas[i].altura, pessoas[i].data_nascimento.dia, pessoas[i].data_nascimento.mes,
                   pessoas[i].data_nascimento.ano);
        }
    }
}

void listarPessoasAbaixoMediaAltura(Pessoa *pessoas, int qtd) {
    float soma = 0;
    for (int i = 0; i < qtd; i++) soma += pessoas[i].altura;
    float media = qtd > 0 ? soma / qtd : 0;
    printf("Média de altura: %.2f\nPessoas abaixo da média:\n", media);
    for (int i = 0; i < qtd; i++) {
        if (pessoas[i].altura < media) {
            printf("%s - %.2f m - %02d/%02d/%04d\n", pessoas[i].nome, pessoas[i].altura, pessoas[i].data_nascimento.dia, pessoas[i].data_nascimento.mes,
                   pessoas[i].data_nascimento.ano);
        }
    }
}

void exibirCompromisso(const Compromisso *c) {
    printf("[%s] %02d/%02d/%04d %02d:%02d - %s\n",
        c->situacao == 0 ? "Agendado" :
        c->situacao == 1 ? "Cancelado" : "Concluído",
        c->data.dia, c->data.mes, c->data.ano, c->horario.hora, c->horario.minuto, c->texto);
}

void exibirAluno(const Aluno *a) {
    printf("%s - Idade: %d - Nota: %.2f\n", a->nome, a->idade, a->nota);
}

void exibirDisciplina(const Disciplina *d) {
    printf("Disciplina: %s\n", d->nome);
    printf("Notas: %.2f %.2f %.2f\n", d->notas[0], d->notas[1], d->notas[2]);
    printf("Média: %.2f - Situação: ", d->media);
    if(d->situacao == 0) printf("Aprovado\n");
    else if(d->situacao == 1) printf("Prova Final\n");
    else printf("Reprovado\n");
}

void exibirPessoaData(const PessoaData *p, int idade) {
    printf("%s - %02d/%02d/%04d - Idade: %d\n", p->nome, p->data_nascimento.dia, p->data_nascimento.mes, p->data_nascimento.ano, idade);
}

void exibirProduto(const Produto *prod) {
    printf("%s - Cotações: %.2f %.2f %.2f\n", prod->nome, prod->cotacoes[0], prod->cotacoes[1], prod->cotacoes[2]);
}

void exibirPessoaEstado(const PessoaEstado *p, int qtd) {
    for(int i=0; i<qtd; i++) {
        printf("%s (%s)\n", p[i].nome, p[i].estado);
    }
}

void exibirAlunos(const Aluno *a, int n) {
    for(int i=0; i<n; i++) {
        exibirAluno(&a[i]);
    }
}

void exibirDisciplinas(const Disciplina *d, int n) {
    for(int i=0; i<n; i++) {
        exibirDisciplina(&d[i]);
    }
}