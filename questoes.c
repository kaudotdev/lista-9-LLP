#include "questoes.h"
#include "myinput.h"
#include "mycomputing.h"
#include "myoutput.h"
#include "mystructs.h"

/*
* Aluno: Kauan Souza
* Problema: Projeto questão 9, enunciados em cada questão do questoes.c
*/


void questao1() {
    /*
    * Aluno: Kauan Souza
    * Problema: 1. A distância entre dois pontos A e B no plano cartesiano é a medida do segmento de reta
        que liga esses dois pontos. Essa distância pode ser calculada pela expressão:
        d . Desenvolver um programa que receba coordenadas de
        AB = x
        B − x
        A
        ( )
        2
        + y
        B − y
        A
        ( )
        2

        dois pontos quaisquer e exiba a distância entre eles. Deve-se utilizar um registro na
        representação das coordenadas (x,y) de um ponto no plano cartesiano.
    */
    Ponto a, b;
    float dist;
    lerPonto(&a, "Coordenadas do ponto A:");
    lerPonto(&b, "Coordenadas do ponto B:");
    dist = calcularDistancia(a, b);
    exibirDistancia(dist);
}

void questao2() {
    /*
    * Aluno: Kauan Souza
    * Problema: 2. Desenvolver um programa que permita armazenar o nome, a altura e a data de nascimento
        de até trinta pessoas. Cada pessoa, bem como a data de nascimento, deve ser
        representada pela estrutura de registro. O programa deve questionar quantas pessoas
        serão cadastradas, e durante preenchimento, a data de nascimento pode ser gerada
        aleatoriamente, por exemplo: mês = 1 + (rand() % 12), ano = 1950 + (rand() % 49), dia = 1 +
        (rand() % 30). Após cadastramento, o programa deve:
        a) Listar pessoas (nome,altura,data de nascimento) nascidas em um determinado mês
        escolhido pelo usuário.
        b) Listar pessoas (nome,altura,data de nascimento) com estatura abaixo da média da
        altura.
        Opcionalmente, pode-se utilizar um menu com as opções de listagem permitindo ao
        usuário encerrar a qualquer momento.
    */
    Pessoa pessoas[30];
    int qtd;
    qtd = cadastrarPessoas(pessoas, 30);
    gerenciarMenuPessoas(pessoas, qtd);
}

void questao3() {
    /*
    * Aluno: Kauan Souza
    * Problema:3. Desenvolver um programa para trabalhar os compromissos de uma pessoa. Um
        compromisso possui um texto (string de até 200 caracteres), situação do compromisso
        Agendado, Cancelado, Concluído), uma data e um horário. Uma data deve possuir dia, mês
        e ano, que são números inteiros. Um horário deve possuir hora, minuto, todos também
        números inteiros. O programa deve permitir até cem compromissos utilizando o seguinte
        menu de ações:
        1) Adicionar compromisso
        2) Cancelar compromisso
        3) Listar compromissos agendados
        9) Encerrar programa
    */
    Compromisso compromissos[100];
    int qtd = 0;
    gerenciarMenuCompromissos(compromissos, &qtd, 100);
}

void questao4() {
    /*
    * Aluno: Kauan Souza
    * Problema: 4. Desenvolver um programa que receba nome, idade e nota de três pessoas. Com esses
        dados, o programa deve exibir nome,idade e nota das pessoas a partir do seguinte menu:
        1) Ordenar por nome(crescente)
        2) Ordenar por idade(crescente)
        3) Ordenar por nota(decrescente)
        9) Encerrar programa
    */
    Aluno alunos[3];
    lerAlunos(alunos, 3);
    gerenciarMenuAlunos(alunos, 3);
}

void questao5() {
    /*
    * Aluno: Kauan Souza
    * Problema: 5. Estudantes do IFBA cursam até dez disciplinas por semestre. Em cada disciplina o
        estudante realiza três atividades avaliativas com pontuação de 0 à 10. Desenvolver um
        programa que receba nomes das disciplinas cursadas e as notas das atividades. Ao final, o
        programa deve exibir relação das disciplinas, média da disciplina (média simples das notas
        das atividades) e situação: Aprovado (média ≥ 7. 0), Prova final (2. 5 ≤ média < 7. 0), e
        Reprovado (média < 2. 5).
    */
    Disciplina disciplinas[2];
    lerDisciplinas(disciplinas, 2);
    calcularMediasDisciplinas(disciplinas, 2);
    exibirDisciplinas(disciplinas, 2);
}

void questao6() {
    /*
    * Aluno: Kauan Souza
    * Problema: 6. Desenvolver um programa que receba nome e data de nascimento (dia,mês,ano) de trinta
        pessoas. A partir desses dados, o programa deve mostrar nome, data de nascimento
        (dia/mês/ano), e a idade em quantidade de dias considerando a data atual como referência
        para cálculo dos dias.
    */
    PessoaData pessoas[30];
    int qtd = lerPessoasData(pessoas, 30);
    mostrarIdades(pessoas, qtd, 15, 9, 2025);
}

void questao7() {
    /*
    * Aluno: Kauan Souza
    * Problema: 7. Dado uma relação de nomes de trinta produtos e três cotações de preços para cada um
        deles deve-se desenvolver um programa que mostre nomes e cotações daqueles produtos
        nos quais a média das três cotações seja menor que a média dos menores preços de cada
        produto.
    */
    Produto produtos[30];
    lerProdutos(produtos, 30);
    mostrarProdutosAbaixoMedia(produtos, 30);
}

void questao8() {
    /*
    * Aluno: Kauan Souza
    * Problema: 8. Desenvolver um programa usando registros que receba nome e sigla do estado de até
        trezentas pessoas. O programa deverá apresentar um menu com as opções: a) Incluir; b;
        Listar; c) Estados; d) Encerrar. Na opção “incluir”, o programa permite inserir um novo
        registro assegurando que não haja nomes duplicados e que o limite de capacidade do
        cadastro não seja ultrapassado. Na opção “listar”, deve-se exibir a relação dos dados
        cadastrados. Na opção “estado”, deve mostrar o estado e a quantidade de pessoas
        cadastradas para aquele estado.
    */
    PessoaEstado pessoas[300];
    int qtd = 0;
    gerenciarMenuPessoasEstado(pessoas, &qtd, 300);
}

