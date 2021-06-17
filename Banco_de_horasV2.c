#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
/*
Banco de horas para empresa Divina velas;
Feito por André Melo Dantas Filho;
Data final:17/06/2021;
*/
struct lista{
    char nome[50];
    int saldo;
};
struct lista funcionarios[30];
FILE *saldos;
FILE *funcionario;

int qtdfuncionarios=1;

void todosfuncionarios();

void registrarhoras();

void diretosaldo();

void alterarfuncionarios();

void versaldo();

void lersaldos();

void armazenarsaldos();

int verificavariavel();

int lerfuncionarios();



int main(){
    printf(
           "==================================================\n"
           "==========BANCO DE HORAS DIVINA VELAS=============\n"
           "==================================================\n"
           );
    setlocale(LC_ALL,"");





    int opcao=0;
    while (opcao!=5){
        qtdfuncionarios=lerfuncionarios();//função para ler funcionários em arquivos
        lersaldos(qtdfuncionarios);//função para ler saldos em arquivos
        system("pause");
        system("cls");
        printf(
                "\n1-Registrar horas\n"
                "2-Adicionar ou remover horas diretamente ao saldo\n"
                "3-Ver saldo funcionários\n"
                "4-Armazenar dados\n"
                "5-Encerrar programa\n"
                "\nEscolha uma opção:"
               );

        opcao=verificavariavel();

        if (opcao>5 || opcao<1){
            printf("\nOpção inexistente\n");
            continue;

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
        else if(opcao==4){
            armazenarsaldos(qtdfuncionarios);//função para armazenar os saldos em arquivos.
            printf("Dados armazenados com sucesso!\n");
        }
    }


    printf("\nPrograma encerrado!\n");
    return 0;
}

int verificavariavel(){//Função feita para scanf só aceitar numeros inteiros.
    char variavel[50];
    bool a=false,invalido=false;
    int i=0,retorno;
    while(a==false){
        invalido=false;
        scanf(" %[^\n]s",variavel);
        for (i=0;i<strlen(variavel);i++){
            if (variavel[i]>='0' && variavel[i]<='9'){


            }else invalido=true;
        }
        if (invalido==true){
            printf("Só é permitido digitar números\nDigite novamente:\n");
        }else if (invalido==false){
            retorno = atoi(variavel);
            a=true;
        }
    }
    return retorno;

}

void todosfuncionarios(){
    int i;
    for (i=1;i<qtdfuncionarios;i++){

        printf("%d-%s\n",i,funcionarios[i].nome);
    }

}

void registrarhoras(){

        int codigo_funcionario,saldo=0,confirma;
        int h_inicial,h_final,h_intervalo;
        printf("\nDeseja registrar horas de qual funcionario, insira o codigo:\n");
        codigo_funcionario=verificavariavel();
        printf("\n%s\n",funcionarios[codigo_funcionario].nome);
        printf("Horario inicial:");
        h_inicial=verificavariavel();
        printf("Horario final:");
        h_final=verificavariavel();
        printf("Hora(s) de intervalo:");
        h_intervalo=verificavariavel();
        saldo=(h_final-h_inicial-h_intervalo)-8;

        printf("Funcionario %s entrou na empresa de %d horas e saiu de %d horas, gerando um saldo de %d horas\n",funcionarios[codigo_funcionario].nome,h_inicial,h_final,saldo);
        printf("Confirma essa informação para adicionar ao sistema?(1.Sim | 2.Não)\n");

        confirma=verificavariavel();
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
    codigo_funcionario=verificavariavel();
    if (codigo_funcionario==0){
        printf("Quantas horas deseja adicionar/remover de todos:\n");
    }else{
        printf("Quantas horas deseja adicionar/remover de %s:\n",funcionarios[codigo_funcionario].nome);
    }
    saldodireto=verificavariavel();
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
    codigo_funcionario=verificavariavel();

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

int lerfuncionarios(){
    int i=1;
    funcionario = fopen("funcionarios.txt", "rt");
    if (funcionario == NULL) {
        printf("Arquivo não encontrado!\nCriando arquivo...\n");
        funcionario = fopen("funcionarios.txt", "w");
        fclose(funcionario);
        return 1;
    }
    for (i=1;i<18;i++){
        fscanf(funcionario," %[^\n]s",&funcionarios[i].nome);
        }
    qtdfuncionarios=18;

    fclose(funcionario);

    return qtdfuncionarios;

}


