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
    char name[50];
    int matricula;
    int *mat;
    int ativo;
    float coefRend;
    int status;
    int qtdAlunos;
    int i;
    int opcoes;
    bool boolean;
    boolean = true;
    Aluno *remove;
    printf("Digite a quantidade de alunos: \n");
    scanf("%d", &qtdAlunos);
    c = cCreate(qtdAlunos);
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
            a = (Aluno *)malloc(sizeof(Aluno));
            if (a != NULL){
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
            else
            {
                printf ("Erro ao criar estrutura Aluno"); 
                exit (1);
            }
            
        }
        while(boolean) {
                printf("Digite uma opção abaixo: \n");
                printf("1 - Buscar usuário por número de matrícula: \n");
                printf("2 - Buscar usuário por nome: \n");
                printf("3 - Listar alunos: \n");
                printf("4 - Remover um aluno por matricula: \n");
                printf("5 - Remover um aluno por nome: \n");
                printf("6 - Remover todos os alunos: \n");
                scanf("%d", &opcoes);
                printf("Faça uma busca: \n");
                switch (opcoes)
                {
                case 1:
                    printf("[x] Buscar usuário por número de matrícula \n");
                    printf("Digite o numero da matricula de algum aluno: \n");
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
                case 2:
                    printf("[x] Buscar usuário por nome \n");
                    printf("Digite o nome de algum aluno: \n");
                    scanf("%s", name);
                    a = (Aluno *)cQuery(c, (void *)name, comparaNome);
                    if (a != NULL){
                        printf("Aluno Encontrado! \n");
                        printf("A matrícula do aluno é %d, o seu curso é %s e seu CR é %f \n", a->matricula, a->curso, a->coefRend);
                    }
                    else{
                        printf("Aluno não encontrado! \n");
                    }
                    break;
                case 3:
                    printf("[x] Listar alunos: \n");
                    int status;
                    status = listaAluno(c);
                    if (status == false){
                        printf("Não há dados em sua busca! \n");
                    }
                    break;
                case 4:
                    printf("[x] Remover um aluno por matricula \n");
                    printf("Digite o numero da matricula de algum aluno: \n");
                    scanf("%d", &matricula);
                    a = (Aluno *)cRemove(c, (void *)&matricula, comparaMatricula);
                    if (a != NULL){
                        printf("O aluno com nome %s e com matricula %d foi deletado com sucesso! \n", a->nome, a->matricula);
                    }
                    else{
                        printf("Não foi possível deletar aluno com o número de matricula informado. \n");
                    }
                    break;
                case 5:
                    printf("[x] Remover um aluno por nome \n");
                    printf("Digite o nome de algum aluno: \n");
                    scanf("%s", nome);
                    a = (Aluno *)cRemove(c, (void *)nome, comparaNome);
                    if (a != NULL){
                        printf("O aluno do curso %s com matricula %d foi deletado com sucesso! \n", a->curso, a->matricula);
                    }
                    else{
                        printf("Não foi possível deletar aluno com o nome informado. \n");
                    }
                    break;
                
                
                case 6:
                    printf("[x] Remover todos os alunos \n");
                    a = (Aluno *)cGetFirst(c);
                    int iterator;
                    iterator = 0;
                    while (iterator < qtdAlunos && a != NULL){
                            remove = cRemove(c, (void *)&(a->matricula), comparaMatricula);
                            if (remove != NULL){
                                printf("O aluno com nome %s e com matricula %d foi deletado com sucesso! \n", remove->nome, remove->matricula);
                                a = (Aluno *)cGetFirst(c);
                                if (a == NULL){
                                    break;           
                                } 
                            }
                            
                        
                        iterator++;
                    }
                    free(c);
                    printf("Todos os usuarios foram deletados \n");
                    printf("Saindo do programa! \n");
                    boolean = false;
                    break;
                    
                default:
                    printf("valor default \n");
                    break;
                }
            }
    }
    
}


int comparaMatricula(void *a, void *b){
     Aluno *pa;
     int *pb;
     int mat;
     int key;
     pb = (int *)b;
     pa = (Aluno *)a;
     mat = pa->matricula;
     key = *pb;
     if (mat == key){
         return true;
     }else {
         return false;
     }
 }


int comparaNome(void *a, void *b){
     Aluno *pa;
     char *pb;
     char *key;
     char *nome;
     pb = (char *)b;
     pa = (Aluno *)a;
     key = pb;
     nome = pa->nome;
     if (strcmp(nome,key) == 0){
         return true;
     }
     else{
         return false;
     }
 }



int listaAluno(Cofo *c){
    if (c != NULL){
        if (c->nElms > 0){
            int i = 0;
            Aluno *aluno;
            for (i=0; i < c->nElms; i++){
                aluno = (Aluno *)c->elms[i];
                printf("Nome: %s \n", aluno->nome);
                printf("Curso: %s \n", aluno->curso);
                printf("Matrícula: %d \n", aluno->matricula);
                printf("Ativo: %d \n", aluno->ativo);
                printf("CR: %f \n", aluno->coefRend);    
            }
            return true;
        }
    }
    return false;
}