#include <stdio.h>
#include <string.h>
#include <math.h>
#include "mycomputing.h"

/*
* Aluno: Kauan Souza
* Problema: Projeto lista 9, enunciados em cada questão do questoes.c
*/

float calcularDistancia(Ponto a, Ponto b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrtf(dx * dx + dy * dy);
}



void ordenarAlunosNome(Aluno *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int k = 0;

            while (a[i].nome[k] == a[j].nome[k] && a[i].nome[k] != 0 && a[j].nome[k] != 0) {
                k++;
            }


            if (a[i].nome[k] > a[j].nome[k]) {
                Aluno temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void ordenarAlunosIdade(Aluno *a, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i].idade > a[j].idade) {
                Aluno temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}


void ordenarAlunosNota(Aluno *a, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i].nota < a[j].nota) {
                Aluno temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}


void calcularMediasDisciplinas(Disciplina *d, int n) {
    for (int i = 0; i < n; i++) {
        float soma = 0;
        for (int j = 0; j < 3; j++) soma += d[i].notas[j];
        d[i].media = soma / 3.0f;
        if (d[i].media >= 7.0)
            d[i].situacao = 0;
        else if (d[i].media >= 5.0)
            d[i].situacao = 1;
        else
            d[i].situacao = 2;
    }
}


void mostrarIdades(PessoaData *p, int qtd, int diaA, int mesA, int anoA) {
    printf("Nome\tData Nasc.\tIdade\n");
    for (int i = 0; i < qtd; i++) {
        int idade = anoA - p[i].data_nascimento.ano;
        if (mesA < p[i].data_nascimento.mes || (mesA == p[i].data_nascimento.mes && diaA < p[i].data_nascimento.dia))
            idade--;
        printf("%s\t%02d/%02d/%04d\t%d anos\n", p[i].nome, p[i].data_nascimento.dia, p[i].data_nascimento.mes, p[i].data_nascimento.ano, idade);
    }
}


void mostrarProdutosAbaixoMedia(Produto *produtos, int n) {
    float soma_menores = 0;
    float menores[30];
    for (int i = 0; i < n; i++) {
        float menor = produtos[i].cotacoes[0];
        if (produtos[i].cotacoes[1] < menor) menor = produtos[i].cotacoes[1];
        if (produtos[i].cotacoes[2] < menor) menor = produtos[i].cotacoes[2];
        menores[i] = menor;
        soma_menores += menor;
    }
    float media_menores = n > 0 ? soma_menores / n : 0;
    printf("Produtos com média das cotações menor que a média dos menores preços:\n");
    for (int i = 0; i < n; i++) {
        float media = (produtos[i].cotacoes[0] + produtos[i].cotacoes[1] + produtos[i].cotacoes[2]) / 3.0f;
        if (media < media_menores) {
            printf("%s - cotações: %.2f %.2f %.2f - média: %.2f\n", produtos[i].nome, produtos[i].cotacoes[0],
                   produtos[i].cotacoes[1], produtos[i].cotacoes[2], media);
        }
    }
}

void listarPessoasEstado(PessoaEstado *p, int qtd) {
    printf("Pessoas cadastradas:\n");
    for (int i = 0; i < qtd; i++) {
        printf("%s (%s)\n", p[i].nome, p[i].estado);
    }
}


void contarEstados(PessoaEstado *p, int qtd) {
    char estados[300][3];
    int cont[300] = {0};
    int estados_qtd = 0;
    for (int i = 0; i < qtd; i++) {
        int found = 0;
        for (int j = 0; j < estados_qtd; j++) {
            if (strcmp(estados[j], p[i].estado) == 0) {
                cont[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(estados[estados_qtd], p[i].estado);
            cont[estados_qtd] = 1;
            estados_qtd++;
        }
    }
    printf("Quantidade de pessoas por estado:\n");
    for (int i = 0; i < estados_qtd; i++) {
        printf("%s: %d\n", estados[i], cont[i]);
    }
}
