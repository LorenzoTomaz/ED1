#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./cofo.h"

void main(void){
    Aluno *a;
    Cofo *c;
    char nome[100];
    char curso[50];
    int matricula;
    int ativo;
    float coefRend;
    int status;
    int qtdAlunos;
    int i;
    int opcoes;
    printf("Digite a quantidade de alunos: \n");
    scanf("%d", &qtdAlunos);
    c = cCreate(qtdAlunos);
    printf("oi");
    if (c != NULL){
        for (i=0;i<qtdAlunos;i++){
            printf("Digite o nome do Aluno: \n");
            scanf("%s", nome);
            printf("Digite o curso do Aluno: \n");
            scanf("%s", curso);
            printf("Digite a matricula do Aluno: \n");
            scanf("%d", &matricula);
            printf("Aluno ativo ou inativo? 1 para Ativo, 2 para Inativo: \n");
            scanf("%d", &ativo);
            printf("Digite o coeficiente de rendimento do Aluno: \n");
            scanf("%f", &coefRend);
            printf("%f", coefRend);
            a = (Aluno *)malloc(sizeof(Aluno));
            strcpy(a->nome, nome);
            strcpy(a->curso, curso);
            a->matricula = matricula;
            a->ativo = ativo;
            a->coefRend = coefRend;
            status = cInsert(c, (void *)a);
            printf("Dados Adicionados \n");
            if (status != true){
                 printf ("Erro ao inserir dados no Cofo"); 
                 exit (1); 
                
            }
        }
        printf("Digite uma opção abaixo: \n");
        scanf("%d", &opcoes);
        printf("Faça uma busca: \n");
        while(true) {
                switch (opcoes)
                {
                case 1:
                    printf("Digita o numero da matricula de algum aluno \n");
                    scanf("%d", &matricula);
                    a = (Aluno *)cQuery(c, (void *)&matricula, comparaMatricula);
                    if (a != NULL){
                        printf("Aluno Encontrado! \n");
                        printf("o nome do aluno é %s, o seu curso é %s e seu CR é %f \n", a->nome, a->curso, a->coefRend);
                    }
                    else{
                        printf("Aluno não encontrado \n");
                    }
                    break;
                
                default:
                    printf("valor default \n");
                    break;
                }
            }
    }
    
}
