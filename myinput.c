#include <stdio.h>
#include "myinput.h"
#include "myoutput.h"
#include "mycomputing.h"
#include "questoes.h"

/*
* Aluno: Kauan Souza
* Problema: Projeto lista 9, enunciados em cada questão do questoes.c
*/

void lerPonto(Ponto *p, const char* label) {
    printf("%s\n", label);
    printf("Digite X: ");
    scanf("%f", &p->x);
    printf("Digite Y: ");
    scanf("%f", &p->y);
}

void lerData(Data *d) {
    printf("Dia: ");
    scanf("%d", &d->dia);
    printf("Mes: ");
    scanf("%d", &d->mes);
    printf("Ano: ");
    scanf("%d", &d->ano);
}

void lerHorario(Horario *h) {
    printf("Hora: ");
    scanf("%d", &h->hora);
    printf("Minuto: ");
    scanf("%d", &h->minuto);
}

int cadastrarPessoas(Pessoa *pessoas, int max) {
    int qtd;
    printf("Quantas pessoas deseja cadastrar? ");
    scanf("%d", &qtd);
    if(qtd > max) qtd = max;
    for(int i = 0; i < qtd; i++) {
        printf("Nome: "); scanf(" %[^\n]", pessoas[i].nome);
        printf("Altura: "); scanf("%f", &pessoas[i].altura);
        printf("Data de nascimento:\n");
        lerData(&pessoas[i].data_nascimento);
    }
    return qtd;
}

void adicionarCompromisso(Compromisso *c, int *qtd, int max) {
    if(*qtd >= max) {
        printf("Limite de compromissos atingido!\n");
        return;
    }
    printf("Texto do compromisso: ");
    scanf(" %[^\n]", c[*qtd].texto);
    printf("Situacao (0=Agendado, 1=Cancelado, 2=Concluido): ");
    scanf("%d", &c[*qtd].situacao);
    printf("Data do compromisso:\n");
    lerData(&c[*qtd].data);
    printf("Horario do compromisso:\n");
    lerHorario(&c[*qtd].horario);
    (*qtd)++;
}

void cancelarCompromisso(Compromisso *c, int qtd) {
    int idx;
    printf("Informe o indice do compromisso para cancelar (1 a %d): ", qtd+1);
    scanf("%d", &idx);
    if(idx >= 0 && idx < qtd) {
        c[idx].situacao = 1;
        printf("Compromisso cancelado.\n");
    } else {
        printf("Indice invalido!\n");
    }
}

void lerAlunos(Aluno *alunos, int n) {
    for(int i=0; i < n; i++) {
        printf("Nome: "); scanf(" %[^\n]", alunos[i].nome);
        printf("Idade: "); scanf("%d", &alunos[i].idade);
        printf("Nota: "); scanf("%f", &alunos[i].nota);
    }
}

void lerDisciplinas(Disciplina *d, int n) {
    for(int i=0; i < n; i++) {
        printf("Nome da disciplina: "); scanf(" %[^\n]", d[i].nome);
        for(int j=0; j<3; j++) {
            printf("Nota %d: ", j+1);
            scanf("%f", &d[i].notas[j]);
        }
    }
}

int lerPessoasData(PessoaData *p, int max) {
    int qtd;
    printf("Quantas pessoas deseja cadastrar? ");
    scanf("%d", &qtd);
    if(qtd > max) qtd = max;
    for(int i=0; i<qtd; i++) {
        printf("Nome: "); scanf(" %[^\n]", p[i].nome);
        printf("Data de nascimento:\n");
        lerData(&p[i].data_nascimento);
    }
    return qtd;
}

void lerProdutos(Produto *produtos, int n) {
    for(int i=0; i<n; i++) {
        printf("Nome do produto: "); scanf(" %[^\n]", produtos[i].nome);
        for(int j=0; j<3; j++) {
            printf("Cotacao %d: ", j+1);
            scanf("%f", &produtos[i].cotacoes[j]);
        }
    }
}

void incluirPessoaEstado(PessoaEstado *p, int *qtd, int max) {
    if(*qtd >= max) {
        printf("Limite de pessoas atingido!\n");
        return;
    }
    printf("Nome: "); scanf(" %[^\n]", p[*qtd].nome);
    printf("Estado (sigla): "); scanf("%2s", p[*qtd].estado);
    p[*qtd].estado[2] = '\0';
    (*qtd)++;
}

int menuPrincipal() {
    int op;
    printf("\nMenu principal:\n1- Q1\n2- Q2\n3- Q3\n4- Q4\n5- Q5\n6- Q6\n7- Q7\n8- Q8\n9- Sair\nOpcao: ");
    scanf("%d", &op);
    return op;
}

int menuListagemPessoas() {
    int op;
    printf("1- Listar por mes\n2- Listar abaixo media altura\n9- Sair\nOpcao: ");
    scanf("%d", &op);
    return op;
}

int menuCompromissos() {
    int op;
    printf("1- Adicionar\n2- Cancelar\n3- Listar\n9- Sair\nOpcao: ");
    scanf("%d", &op);
    return op;
}

int menuOrdemAlunos() {
    int op;
    printf("1- Nome\n2- Idade\n3- Nota\n9- Sair\nOpcao: ");
    scanf("%d", &op);
    return op;
}

int menuPessoasEstado() {
    int op;
    printf("1- Incluir\n2- Listar\n3- Estado\n9- Sair\nOpcao: ");
    scanf("%d", &op);
    return op;
}

void gerenciarMenuPrincipal() {
    int op = menuPrincipal();
    switch (op) {
        case 1: questao1(); break;
        case 2: questao2(); break;
        case 3: questao3(); break;
        case 4: questao4(); break;
        case 5: questao5(); break;
        case 6: questao6(); break;
        case 7: questao7(); break;
        case 8: questao8(); break;
        case 9: break;
        default: break;
    }
}

void gerenciarMenuPessoas(Pessoa *pessoas, int qtd) {
    int op;
    do {
        op = menuListagemPessoas();
        if (op == 1) {
            int mes;
            printf("Mês de nascimento (1-12): ");
            scanf("%d", &mes);
            listarPessoasPorMes(pessoas, qtd, mes);
        } else if (op == 2) {
            listarPessoasAbaixoMediaAltura(pessoas, qtd);
        }
    } while (op != 9);
}

void gerenciarMenuCompromissos(Compromisso *c, int *qtd, int max) {
    int op;
    do {
        op = menuCompromissos();
        if (op == 1) adicionarCompromisso(c, qtd, max);
        else if (op == 2) cancelarCompromisso(c, *qtd);
        else if (op == 3) listarCompromissos(c, *qtd);
    } while (op != 9);
}

void gerenciarMenuAlunos(Aluno *alunos, int n) {
    int op;
    do {
        op = menuOrdemAlunos();
        if (op == 1) ordenarAlunosNome(alunos, n);
        else if (op == 2) ordenarAlunosIdade(alunos, n);
        else if (op == 3) ordenarAlunosNota(alunos, n);
        if (op != 9)
            exibirAlunos(alunos, n);
    } while (op != 9);
}

void gerenciarMenuPessoasEstado(PessoaEstado *p, int *qtd, int max) {
    int op;
    do {
        op = menuPessoasEstado();
        if (op == 1) incluirPessoaEstado(p, qtd, max);
        else if (op == 2) listarPessoasEstado(p, *qtd);
        else if (op == 3) contarEstados(p, *qtd);
    } while (op != 9);
}