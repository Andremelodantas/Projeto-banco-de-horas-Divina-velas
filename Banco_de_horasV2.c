#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
/*
Banco de horas para empresa Divina velas;
Feito por André Melo Dantas Filho;
Data final:28/05/2021;
*/
struct lista{
    char nome[50];
    int saldo;
};
struct lista funcionarios[20];
FILE *saldos;
int qtdfuncionarios=1;

void todosfuncionarios();

void registrarhoras();

void diretosaldo();

void alterarfuncionarios();

void versaldo();

void lersaldos();

void armazenarsaldos();

int main(){
    printf(
           "==================================================\n"
           "==========BANCO DE HORAS DIVINA VELAS=============\n"
           "==================================================\n"
           );
    setlocale(LC_ALL,"");

    strcpy(funcionarios[qtdfuncionarios].nome,"Alisson Junior");
    qtdfuncionarios++;
    strcpy(funcionarios[qtdfuncionarios].nome,"Osnir");
    qtdfuncionarios++;
    strcpy(funcionarios[qtdfuncionarios].nome,"Edjane");
    qtdfuncionarios++;
    strcpy(funcionarios[qtdfuncionarios].nome,"Janaina");
    qtdfuncionarios++;
    strcpy(funcionarios[qtdfuncionarios].nome,"Althanir");
    qtdfuncionarios++;
    strcpy(funcionarios[qtdfuncionarios].nome,"Tiago");
    qtdfuncionarios++;
    strcpy(funcionarios[qtdfuncionarios].nome,"Elisama");
    qtdfuncionarios++;
    strcpy(funcionarios[qtdfuncionarios].nome,"Willian");
    qtdfuncionarios++;
    strcpy(funcionarios[qtdfuncionarios].nome,"Djackson");
    qtdfuncionarios++;
    strcpy(funcionarios[qtdfuncionarios].nome,"D.Izabel");
    qtdfuncionarios++;
    strcpy(funcionarios[qtdfuncionarios].nome,"Michel");
    qtdfuncionarios++;
    strcpy(funcionarios[qtdfuncionarios].nome,"Leandro");
    qtdfuncionarios++;
    strcpy(funcionarios[qtdfuncionarios].nome,"Leandro da silva(Léo)");
    qtdfuncionarios++;
    strcpy(funcionarios[qtdfuncionarios].nome,"Fabio");
    qtdfuncionarios++;
    strcpy(funcionarios[qtdfuncionarios].nome,"Lucas");
    qtdfuncionarios++;
    strcpy(funcionarios[qtdfuncionarios].nome,"Jocaff");
    qtdfuncionarios++;
    strcpy(funcionarios[qtdfuncionarios].nome,"Alexandre");
    qtdfuncionarios++;


    lersaldos(qtdfuncionarios);//função para ler saldos em arquivos

    int opcao=0;
    while (opcao!=4){
        system("pause");
        system("cls");
        printf(
                "\n1-Registrar horas\n"
                "2-Adicionar ou remover horas diretamente ao saldo\n"
                "3-Ver saldo funcionários\n"
                "4-Armazenar dados e Encerrar programa\n"
                "\nEscolha uma opção:"
               );
        scanf(" %d",&opcao);

        if (opcao>4 || opcao<1){
            printf("\nOpção inexistente\n");
            continue;
            //scanf(" %d",&opcao);
        }
        else if(opcao==1){
            todosfuncionarios();
            registrarhoras();
            //funcao registrar horas

        }
        else if(opcao==2){
                todosfuncionarios(qtdfuncionarios);
                diretosaldo(qtdfuncionarios);
            //funcao adicionar ou remover horas do saldo diretamente

        }
        else if(opcao==3){
            todosfuncionarios(qtdfuncionarios);
            versaldo(qtdfuncionarios);
            //funcao para ver saldo de horas funcionarios
        }
    }
    armazenarsaldos(qtdfuncionarios);//função para armazenar os saldos em arquivos.


    return 0;
}

void todosfuncionarios(){
    int i;
    for (i=1;i<qtdfuncionarios;i++){
        //printf("%s #%d\n",funcionarios[i].nome,i);
        printf("%d-%s\n",i,funcionarios[i].nome);
    }

}

void registrarhoras(){

        int codigo_funcionario,saldo=0,confirma;
        int h_inicial,h_final,h_intervalo;
        printf("\nDeseja registrar horas de qual funcionario, insira o codigo:\n");
        scanf(" %d",&codigo_funcionario);
        printf("\n%s\n",funcionarios[codigo_funcionario].nome);
        printf("Horario inicial:");
        scanf(" %d",&h_inicial);
        printf("Horario final:");
        scanf(" %d",&h_final);
        printf("Hora(s) de intervalo:");
        scanf(" %d",&h_intervalo);
        saldo=(h_final-h_inicial-h_intervalo)-8;

        printf("Funcionario %s entrou na empresa de %d horas e saiu de %d horas, gerando um saldo de %d horas\n",funcionarios[codigo_funcionario].nome,h_inicial,h_final,saldo);
        printf("Confirma essa informação para adicionar ao sistema?(1.Sim | 2.Não)\n");
        scanf(" %d",&confirma);
        if (confirma==1){
            funcionarios[codigo_funcionario].saldo+=saldo;
            printf("Saldo adicionado no sistema com sucesso!!\n");
        }
        else if(confirma==2){
            printf("Saldo esquecido.\n");
            return 0;
        }
}

void diretosaldo(){
    int saldodireto,codigo_funcionario;
    printf("Deseja adicionar ou remover saldo de qual funcionario:");
    printf("Para aplicar em todos, digite 0.\n");
    scanf(" %d",&codigo_funcionario);
    if (codigo_funcionario==0){
        printf("Quantas horas deseja adicionar/remover de todos:\n");
    }else{
        printf("Quantas horas deseja adicionar/remover de %s:\n",funcionarios[codigo_funcionario].nome);
    }

    scanf(" %d",&saldodireto);
    int i;
    if (codigo_funcionario==0){
        if (saldodireto>0){
                printf("Será adicionado %d horas de todos funcionarios que estão devendo a Divina velas\n",saldodireto);
            }
            else if(saldodireto<0){
                printf("Será removido %d horas de todos funcionarios que estão devendo a Divina velas\n",saldodireto);
            }

        for (i=1;i<qtdfuncionarios;i++){
            funcionarios[i].saldo+=saldodireto;
        }
    }
    else{
        funcionarios[codigo_funcionario].saldo+=saldodireto;
        if (saldodireto>0){
            printf("Será adicionado %d horas ao saldo da(o) funcionaria(o) %s.\n",saldodireto,funcionarios[codigo_funcionario].nome);
        }
        else if(saldodireto<0){
            printf("Será removido %d horas do saldo da(o) funcionaria(o) %s.\n",saldodireto,funcionarios[codigo_funcionario].nome);
        }
    }



}

void versaldo(){

    int codigo_funcionario,i;
    printf("Deseja ver saldo de qual funcionario?\n");
    printf("Para ver de todos, digite 0.\n");
    scanf(" %d",&codigo_funcionario);
    if (codigo_funcionario==0){
            for (i=1;i<qtdfuncionarios;i++){
                printf("%s:%d horas\n",funcionarios[i].nome,funcionarios[i].saldo);
            }
    }else{
        printf("%s tem saldo de %d horas\n",funcionarios[codigo_funcionario].nome,funcionarios[codigo_funcionario].saldo);
    }

}

void lersaldos(){
    int i=1;
    saldos = fopen("Banco_de_horas.txt","rt");
    for (i=1;i<qtdfuncionarios;i++){
        fscanf(saldos,"%d",&funcionarios[i].saldo);
    }
    fclose(saldos);
}

void armazenarsaldos(){
    int i=1;
    saldos = fopen("Banco_de_horas.txt","w");
    for (i=1;i<qtdfuncionarios;i++){
        fprintf(saldos,"%d\n",funcionarios[i].saldo);
    }
    fclose(saldos);

}
