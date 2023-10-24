#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//VARIAVEIS DO SISTEMA DE ADM
char *login;
char *senha;
int resp_menu;
void menu_adm();
void sys_obras();

//VARIAVEIS DO SISTEMA DE VENDA DE INGRESSO
int opcao;
int qtd_ingresso = 50;
char ingressos[9]; // Cada string pode ter até 8 caracteres + o caractere nulo

//VARIAVEIS DO SISTEMA DE OBRAS DE ARTE E QUIZ
int resposta = 0;
int acertos = 0;

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    login_adm();

    return 0;
}

//FUNÇÃO DE LOGIN
void login_adm(){

    char login[5];
    char senha[5];
    char loginAdm[] = "adm";
    char senhaAdm[] = "adm";

    system("cls");
    printf("Login: ");
    scanf("%s", login);
    printf("Senha: ");
    scanf("%s", senha);

    if (strcmp(login, loginAdm) == 0 && strcmp(senha, senhaAdm) == 0)
    {
        //LOGIN SUCESSO
        menu_adm();
    }
    else
    {
        //FALHA NO LOGIN
        system("cls"); //Limpa a tela
        printf ("\nCredenciais incorretas\n\n\n");
        system("pause");
        login_adm();
    }
}
// MENU ADMINISTRADOR
void menu_adm()
{

    system("cls"); //Limpa a tela
    printf ("\nQual sistema deseja entrar ? \n\n");
    printf ("1 - Venda de ingresso.\n");
    printf ("2 - Validacao de ingresso.\n");
    printf ("3 - Obras de arte.\n\n");
    scanf("%d", &resp_menu);

    switch(resp_menu)
    {
    case 1:
        //printf ("\n venda\n");
        system("cls");
        verifica_quantidade();
        break;
    case 2:
        system("cls");
        printf ("\n Sistema de validacao de ingressos em construcao\n\n\n");
        system("pause");
        menu_adm();
        break;
    case 3:
        //printf ("\n arte\n");
        sys_obras();
        break;
    default:
        menu_adm();
        //exit(0);
    }
}

//FUNÇÃO SISTEMA DE OBRA DE ARTE
void sys_obras()
{

    system("cls"); //Limpa a tela
    acertos = 0;
    printf ("\nQuer saber mais sobre qual evento ? \n\n");
    printf ("1 - 100 anos de arte moderna.\n");
    printf ("2 - 150 anos de Santos Dumont.\n");
    printf ("3 - Jogos olimpicos de Paris 2024.\n");
    printf ("4 - Realidade virtual e aumentada.\n\n");
    scanf("%d", &resp_menu);

    switch(resp_menu)
    {
    case 1:
        //printf ("100 anos de arte moderna.\n");
        arte_moderna();
        questoes_arte();
        system("cls");
        printf("\n\nAcertos: %d\n", acertos);
        system("pause");

        sys_obras();
        break;
    case 2:
        //printf ("150 anos de Santos Dumont.\n");
        dumont();
        questoes_dumont();
        system("cls");
        printf("\n\nAcertos: %d\n", acertos);
        system("pause");

        sys_obras();
        break;
    case 3:
        printf ("Jogos olimpicos de Paris 2024.\n");
        paris();
        questoes_paris();
        system("cls");
        printf("\n\nAcertos: %d\n", acertos);
        system("pause");

        sys_obras();
        break;
    case 4:
        realidade_virtual();
        questoes_rv();
        system("cls");
        printf("\n\nAcertos: %d\n", acertos);
        system("pause");

        sys_obras();
        break;
    default:
        sys_obras();
        break;
        //exit(0);
    }
}

void verifica_quantidade()
{
    if(qtd_ingresso>=1)
    {
        sys_venda();
    }
    else
    {
        system("cls");
        printf("Ingressos esgotados\n");
        system("pause");
        return 0;
    }
}
void sys_venda()
{
    system("cls");
    printf("\nOpcoes de ingresso:\n");
    printf("1. Meia entrada\n");
    printf("2. Inteira\n");
    printf("3. Isencao\n");

    printf("Escolha o tipo do ingresso: ");
    scanf("%d", &opcao);
    switch(opcao)
    {
    case 1:
        system("cls");

        printf("Meia entrada\n");
        gerador_ingressos(1);
        system("pause");
        qtd_ingresso--;

        verifica_quantidade();
        break;

    case 2:
        system("cls");

        printf("Ingresso inteiro\n");
        gerador_ingressos(1);
        system("pause");
        qtd_ingresso--;

        verifica_quantidade();
        break;
    case 3:
        system("cls");

        printf("Isencao de ingresso\n");
        gerador_ingressos(1);
        system("pause");
        qtd_ingresso--;

        verifica_quantidade();
        break;
    case 404:
        menu_adm();
        break;
    default :
        verifica_quantidade();
        break;
    }
}
void gerador_ingressos(int quantidade)
{
    // Inicialize o gerador de números aleatórios com uma semente diferente a cada execução
    srand(time(NULL));

    char cod_ingresso[9]; // 8 caracteres + caractere nulo
    for (int i = 0; i < quantidade; i++)
    {

        for (int i = 0; i < 8; i++)
        {
            int escolha = rand() % 2; // Gere um número aleatório de 0 a 2 para escolher entre letras maiúsculas, minúsculas ou números

            switch (escolha)
            {
            case 0:
                cod_ingresso[i] = 'A' + (rand() % 26); // Letra maiúscula
                break;
            case 1:
                cod_ingresso[i] = '0' + (rand() % 10); // Número
                break;
            }
        }

        cod_ingresso[8] = '\0'; // Adicione o caractere nulo para torná-lo uma string

        printf("Codigo do ingresso: %s\n\n",cod_ingresso);
    }

}

//FUNCOES DE OBRAS DE ARTE E QUIZ

void questoes_arte()
{
    questao1_arte();
    questao2_arte();
    questao3_arte();
}
void questoes_dumont()
{
    questao1_dumont();
    questao2_dumont();
    questao3_dumont();
}
void questoes_paris()
{
    questao1_paris();
    questao2_paris();
    questao3_paris();
}
void questoes_rv()
{
    questao1_rv();
    questao2_rv();
    questao3_rv();
}
void questao1_arte()
{
    system("cls");
    printf("Qual e o maior planeta do sistema solar?\n");
    printf("1) Terra\n2) Marte\n3) Jupiter\n");

    printf("\nDigite a resposta:\n");
    scanf("%d", &resposta);

    if(resposta == 3)
    {
        acertos++;
        resposta = 0;
    }
}

void questao2_arte()
{
    system("cls");
    printf("Qual foi o primeiro aviao?\n");
    printf("1) Airbus A320\n2) 14 Bis\n3) Boeing 737\n");


    printf("\nDigite a resposta:\n");
    scanf("%d", &resposta);

    if(resposta == 2)
    {
        acertos++;
        resposta = 0;
    }
}

void questao3_arte()
{
    system("cls");
    printf("Qual seria a obra de Tarscila do amaral?\n");
    printf("1) Abapouru\n2) Monalisa\n3) Ceu estrelado\n");

    printf("\nDigite a resposta:\n");
    scanf("%d", &resposta);

    if(resposta == 1)
    {
        acertos++;
        resposta = 0;
    }
}
//QUESTOES DUMONT
void questao1_dumont()
{
    system("cls");
    printf("Qual e o maior planeta do sistema solar?\n");
    printf("1) Terra\n2) Marte\n3) Jupiter\n");

    printf("\nDigite a resposta:\n");
    scanf("%d", &resposta);

    if(resposta == 3)
    {
        acertos++;
        resposta = 0;
    }
}

void questao2_dumont()
{
    system("cls");
    printf("Qual foi o primeiro aviao?\n");
    printf("1) Airbus A320\n2) 14 Bis\n3) Boeing 737\n");


    printf("\nDigite a resposta:\n");
    scanf("%d", &resposta);

    if(resposta == 2)
    {
        acertos++;
        resposta = 0;
    }
}

void questao3_dumont()
{
    system("cls");
    printf("Qual seria a obra de Tarscila do amaral?\n");
    printf("1) Abapouru\n2) Monalisa\n3) Ceu estrelado\n");

    printf("\nDigite a resposta:\n");
    scanf("%d", &resposta);

    if(resposta == 1)
    {
        acertos++;
        resposta = 0;
    }
}
//QUESTOES PARIS 2024
void questao1_paris()
{
    system("cls");
    printf("Qual e o maior planeta do sistema solar?\n");
    printf("1) Terra\n2) Marte\n3) Jupiter\n");

    printf("\nDigite a resposta:\n");
    scanf("%d", &resposta);

    if(resposta == 3)
    {
        acertos++;
        resposta = 0;
    }
}

void questao2_paris()
{
    system("cls");
    printf("Qual foi o primeiro aviao?\n");
    printf("1) Airbus A320\n2) 14 Bis\n3) Boeing 737\n");


    printf("\nDigite a resposta:\n");
    scanf("%d", &resposta);

    if(resposta == 2)
    {
        acertos++;
        resposta = 0;
    }
}

void questao3_paris()
{
    system("cls");
    printf("Qual seria a obra de Tarscila do amaral?\n");
    printf("1) Abapouru\n2) Monalisa\n3) Ceu estrelado\n");

    printf("\nDigite a resposta:\n");
    scanf("%d", &resposta);

    if(resposta == 1)
    {
        acertos++;
        resposta = 0;
    }
}
//QUESTOES REALIDADE VIRTUAL
void questao1_rv()
{
    system("cls");
    printf("Qual e o maior planeta do sistema solar?\n");
    printf("1) Terra\n2) Marte\n3) Jupiter\n");

    printf("\nDigite a resposta:\n");
    scanf("%d", &resposta);

    if(resposta == 3)
    {
        acertos++;
        resposta = 0;
    }
}

void questao2_rv()
{
    system("cls");
    printf("Qual foi o primeiro aviao?\n");
    printf("1) Airbus A320\n2) 14 Bis\n3) Boeing 737\n");


    printf("\nDigite a resposta:\n");
    scanf("%d", &resposta);

    if(resposta == 2)
    {
        acertos++;
        resposta = 0;
    }
}

void questao3_rv()
{
    system("cls");
    printf("Qual seria a obra de Tarscila do amaral?\n");
    printf("1) Abapouru\n2) Monalisa\n3) Ceu estrelado\n");

    printf("\nDigite a resposta:\n");
    scanf("%d", &resposta);

    if(resposta == 1)
    {
        acertos++;
        resposta = 0;
    }
}
// BLOCOS DE TEXTO SOBRE AS OBRAS
void dumont()
{
    //BLOCO 1
    system("cls");
    printf("Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n Phasellus euismod ex ac nulla malesuada mollis.\n\n");
    system("pause");

    //BLOCO 2
    system("cls");
    printf("Curabitur egestas eleifend tellus, non rhoncus velit. \nPhasellus maximus lacus ut nibh cursus, mauris tristique. \n\n");
    system("pause");

    //BLOCO 3
    system("cls");
    printf("Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n Phasellus euismod ex ac nulla malesuada mollis.\n\n");
    system("pause");
}
void arte_moderna()
{
    //BLOCO 1
    system("cls");
    printf("Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n Phasellus euismod ex ac nulla malesuada mollis.\n\n");
    system("pause");

    //BLOCO 2
    system("cls");
    printf("Curabitur egestas eleifend tellus, non rhoncus velit. \nPhasellus maximus lacus ut nibh cursus, mauris tristique. \n\n");
    system("pause");

    //BLOCO 3
    system("cls");
    printf("Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n Phasellus euismod ex ac nulla malesuada mollis.\n\n");
    system("pause");
}
void paris()
{
    //BLOCO 1
    system("cls");
    printf("Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n Phasellus euismod ex ac nulla malesuada mollis.\n\n");
    system("pause");

    //BLOCO 2
    system("cls");
    printf("Curabitur egestas eleifend tellus, non rhoncus velit. \nPhasellus maximus lacus ut nibh cursus, mauris tristique. \n\n");
    system("pause");

    //BLOCO 3
    system("cls");
    printf("Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n Phasellus euismod ex ac nulla malesuada mollis.\n\n");
    system("pause");
}
void realidade_virtual()
{
    //BLOCO 1
    system("cls");
    printf("Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n Phasellus euismod ex ac nulla malesuada mollis.\n\n");
    system("pause");

    //BLOCO 2
    system("cls");
    printf("Curabitur egestas eleifend tellus, non rhoncus velit. \nPhasellus maximus lacus ut nibh cursus, mauris tristique. \n\n");
    system("pause");

    //BLOCO 3
    system("cls");
    printf("Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n Phasellus euismod ex ac nulla malesuada mollis.\n\n");
    system("pause");
}
