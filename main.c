#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

typedef struct Usuario {
char nome[100];
char email[100];
char senha[50];
char telefone[50];
char experiencia[1000];
char cidade[50];
char estado[50];
char idade[50];
char nomeart[50];
char ritmo[50];
char tipo[100];
char deletado;
} usuarios;
FILE *arq;
usuarios max[10000];

typedef struct Funcionario {
char nome[50];
char cpf[50];
char cargo[50];
char funcao[100];
char deletado;
} funcionarios;
FILE *arq;
funcionarios maximum[100];

typedef struct Relatorio {
char nome[50];
char texto[1000];
char data[15];
char deletado;
} relatorios;
FILE *arq;
relatorios maxi[1000];

typedef struct Estabelecimento {
char nome[50];
char localizacao[100];
char fone[20];
char email[50];
char cidade[50];
char estado[50];
char tipo[100];
char senha[50];
char deletado;
}estabelecimentos;
FILE *arq;
estabelecimentos maximo [1000];

void loginAdm(void);
void menuAdministrador(void);
void clientesAdministrador(void);
void estabelecimentosAdministrador(void);
void gerenciarCores(int opcao);
void montarMenuPrincipal(void);
void gerenciarMenuPrincipal(int opcao);
void sair(void);

void montarMenuCliente(void);
void gerenciarMenuCliente(int opcao);
void cadastroCliente(void);
void loginCliente(void);
void menuCliente(void);
void alterarCliente(void);
void consultarCliente(void);
void listarCliente(void);
void excluirCliente(void);

void montarMenuEstabelecimento(void);
void gerenciarMenuEstabelecimento(int opcao);
void cadastroEstabelecimento(void);
void loginEstabelecimento(void);
void menuEstabelecimento(void);
void listarEstabelecimento(void);
void alterarEstabelecimento(void);
void consultarEstabelecimento(void);
void excluirEstabelecimento(void);

void montarMenuFuncionarios(void);
void gerenciarFuncionarios(int opcao);
void cadastrarFuncionarios(void);
void alterarFuncionarios(void);
void consultarFuncionarios(void);
void excluirFuncionarios(void);

void montarMenuRelatorios(void);
void gerenciarRelatorios(int opcao);
void cadastrarRelatorios(void);
void alterarRelatorios(void);
void consultarRelatorios(void);
void excluirRelatorios(void);

void sair(void);

void retornarMensagem(const char* mensagem)
{
    printf(mensagem);
    return;
}
void sair()
{
    printf("\tObrigado por acessar nosso programa em C criado para apresentação do PIM!\n\n\n");
    printf("\t\t\t\t             OOOOOOOOOOO               \n");
    printf("\t\t\t\t         OOOOOOOOOOOOOOOOOOO           \n");
    printf("\t\t\t\t      OOOOOO  OOOOOOOOO  OOOOOO        \n");
    printf("\t\t\t\t    OOOOOO      OOOOO      OOOOOO      \n");
    printf("\t\t\t\t  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
    printf("\t\t\t\t OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
    printf("\t\t\t\tOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
    printf("\t\t\t\tOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
    printf("\t\t\t\tOOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
    printf("\t\t\t\t OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
    printf("\t\t\t\t  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
    printf("\t\t\t\t    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
    printf("\t\t\t\t      OOOOOO   OOOOOOOOO   OOOOOO      \n");
    printf("\t\t\t\t         OOOOOO         OOOOOO         \n");
    printf("\t\t\t\t             OOOOOOOOOOOO              \n\n");
    exit(1);
}
void configurarTela()
{
    int opcao = 0;
    printf("A primeira cor corresponde ao fundo, e a segunda aos caracteres.\n\n");
    printf("1. Cinza/Amarelo\n");
    printf("2. Branco/Roxo\n");
    printf("3. Verde-água/Azul-escuro\n");
    printf("4. Preto/Branco-brilhante\n");
    printf("5. Voltar ao Menu Principal\n");
    system("pause>nul");
    scanf("%i", &opcao);
    system("cls || clear");
    gerenciarCores(opcao);
}
void gerenciarCores(int opcao)
{
    switch(opcao)
    {
        case 1:
            system("color 8E");
            montarMenuPrincipal();
            break;

        case 2:
            system("color F5");
            montarMenuPrincipal();
            break;

        case 3:
            system("color B1");
            montarMenuPrincipal();
            break;

        case 4:
            system("color 0F");
            montarMenuPrincipal();
            break;
        case 5:
            montarMenuPrincipal();
            break;
        default:
            printf("Digite uma opção válida!\n");
            configurarTela();
    }
}
void sobre()
{
    printf("\t\t\tPIM\n\n");
    printf("\tAnálise e Desenvolvimento de Sistemas\n\tProjeto Integrado Multidisciplinar\n\tUNIP - Universidade Paulista\n");
    printf("\t2º Semestre - 2022\n");
    printf("\n\tUNIMUSIC - Plataforma de contratação de musicos.\n\n");
    printf("\tIntegrantes:\n\tRaul Sanches Pedrosa\n\tRonny Fabiano Dantas\n\tSavio Emanuel B Gonçalves\n\tVinicius Bezerra Pimentel\n\n\n");
    printf("\tNesse presente projeto tivemos a ideia de criar uma palataforma de musicos, onde no mesma existe a\n");
    printf("\tpossibilidade de cadastro de clientes e contratantes, onde os dois poderão se consultar e conseguir informações \n");
    printf("\tde contato para fins trabalhistas.\n\n\n");
    getch();
    system("cls || clear");
    montarMenuPrincipal();
}

void loginAdm()
{
    int continuar = 0;

    printf("\n\t\t\t\t| ACESSO ADMINISTRADOR |\n\n\n");
    printf("\tDigite o login e a senha para ter acesso às funções de administrador.\n\n\n");

    char login[15] = "adm";
    char login1[15];
    char senha[15] = "adm";
    char senha1[15];

    printf("Digite o Login: ");
    scanf("%s", login1);

    printf("\nDigite a Senha: ");
    scanf("%s", senha1);

    if (strcmp(login, login1) == 0 && strcmp(senha, senha1) == 0) {

        system ("cls || clear");
        printf("\n\t\t\t\tLOGADO!\n\n");
        printf("1. Entrar\n");
        printf("2. Voltar\n");
        scanf("%d", &continuar);
        system ("cls || clear");

        switch(continuar)
        {
            case 1:
                menuAdministrador();
            case 2:
                montarMenuPrincipal();
            default:
                printf("Digite uma opção valida!\n");
                loginAdm();
        }

                } else

                system("cls||clear");
                printf("\n\n\t\t\t\tDADOS INVÁLIDOS!\n");
                printf("\nDados de administrador não constam.\n\n");
                printf("1. Para inserir os dados novamente.\n");
                printf("2. Para voltar  ao menu principal.\n");
                scanf("%i", &continuar);
                system("cls||clear");

                switch(continuar)
                {
                    case 1:
                        return loginAdm();
                    case 2:
                        montarMenuPrincipal();
                    default:
                        printf("Digite uma opção válida!\n");
                        loginAdm();
                }
}
void menuAdministrador()
{
    int continuar = 0;

    printf("\n\tMenu de Administrador\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Gerenciar Funcionários\n");
    printf("2. Gerenciar Relatorios\n");
    printf("3. Gerenciar Clientes\n");
    printf("4. Gerenciar Estabelecimentos\n");
    printf("5. Voltar ao Menu Principal\n");
    printf("6. Sair do Programa\n");

    scanf("%d", &continuar);
    system("cls || clear");

    switch(continuar)
    {
        case 1:
            montarMenuFuncionarios();
            break;
        case 2:
            montarMenuRelatorios();
            break;
        case 3:
            clientesAdministrador();
            break;
        case 4:
            estabelecimentosAdministrador();
            break;
        case 5:
            montarMenuPrincipal();
            break;
        case 6:
            sair();
        default:
            printf("Digite uma opção válida!\n");
            menuAdministrador();
    }
}
void clientesAdministrador()
{
    int continuar = 0;

    printf("\n\tMenu de Clientes\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Cadastrar Cliente\n");
    printf("2. Alterar Clientes\n");
    printf("3. Consultar Clientes\n");
    printf("4. Excluir Clientes\n");
    printf("5. Voltar ao Menu Administrador\n");

    scanf("%i", &continuar);
    system("cls || clear");

    switch(continuar)
    {
        case 1:
            cadastroCliente();
            break;
        case 2:
            alterarCliente();
            break;
        case 3:
            consultarCliente();
            break;
        case 4:
            excluirCliente();
            break;
        case 5:
            menuAdministrador();
            break;
        default:
            printf("Digite uma opção válida!\n");
            clientesAdministrador();
    }
}
void estabelecimentosAdministrador()
{
    int continuar = 0;

    printf("\n\tMenu de Estabelecimentos\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Cadastrar Estabelecimento\n");
    printf("2. Alterar Estabelecimento\n");
    printf("3. Consultar Estabelecimento\n");
    printf("4. Excluir Estabelecimento\n");
    printf("5. Voltar ao Menu Administrador\n");

    scanf("%i", &continuar);
    system("cls || clear");

    switch(continuar)
    {
        case 1:
            cadastroEstabelecimento();
            break;
        case 2:
            alterarEstabelecimento();
            break;
        case 3:
            consultarEstabelecimento();
            break;
        case 4:
            excluirEstabelecimento();
            break;
        case 5:
            menuAdministrador();
            break;
        default:
            printf("Digite uma opção válida!\n");
            estabelecimentosAdministrador();
    }
}
void montarMenuFuncionarios()
{
    int opcao = 0;
    printf("\n\tMenu de Funcionários\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Cadastrar Funcionários\n");
    printf("2. Alterar Funcionários\n");
    printf("3. Consultar Funcionários\n");
    printf("4. Excluir Funcionários\n");
    printf("5. Voltar ao Menu Administrador\n");
    system("pause>nul");
    scanf("%i", &opcao);
    system("cls || clear");
    gerenciarFuncionarios(opcao);
}
void gerenciarFuncionarios(int opcao)
{
    switch(opcao)
    {
        case 1:
            cadastrarFuncionarios();
            break;
        case 2:
            alterarFuncionarios();
            break;
        case 3:
            consultarFuncionarios();
            break;
        case 4:
            excluirFuncionarios();
            break;
        case 5:
            menuAdministrador();
            break;
        default:
            printf("Digite uma opcão válida\n");
            montarMenuFuncionarios();
    }
}
void cadastrarFuncionarios()
{
    struct Funcionario funcionarios;
    int retorno;
    arq = fopen("funcionarios.pro", "a");
    if (arq == NULL)
    {
        retornarMensagem("\nErro ao abrir arquivo");
        return;
    }
    printf("\n\t\t\t\|SISTEMA DE CADASTRO DE FUNCIONÁRIO|\n");
    printf("\nDigite o nome: ");
    scanf("%s", &funcionarios.nome);
    printf("Digite o CPF: ");
    scanf("%s", &funcionarios.cpf);
    printf("Digite o cargo: ");
    fflush(stdin);
    gets(funcionarios.cargo);
    printf("Digite a função: ");
    scanf("%s", &funcionarios.funcao);
    retorno = fwrite (&funcionarios, sizeof(funcionarios), 1, arq);
    if (retorno == 1)
    {
        fclose (arq);
        retornarMensagem("\nDados do funcionário incluídos com sucesso!");
        system("pause>nul");
        system("cls || clear");
        montarMenuFuncionarios();
    }
    else
    {
        fclose (arq);
        retornarMensagem("\n Falha ao gravar dados do funcionário.");
        system("pause>nul");
        system("cls || clear");
        montarMenuFuncionarios();
    }
}
void alterarFuncionarios()
{
    arq = fopen("funcionarios.pro", "r+b");
    if (arq == NULL)
    {
        retornarMensagem("\nArquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenuFuncionarios();
    }

    struct Funcionario funcionarios;
    char nome[50];
    int encontrado = 0;
    printf ("\nDigite o nome que procura: ");
    scanf ("%s", &nome);

    while (fread (&funcionarios, sizeof(funcionarios), 1, arq))
    {
        if ((funcionarios.nome[0] == nome[0]) && (funcionarios.deletado != '*'))
        {
            printf("\nNome do funcionário: %s\nCPF: %s\nCargo: %s\nFunção: %s\n",funcionarios.nome, funcionarios.cpf, funcionarios.cargo, funcionarios.funcao);
            encontrado = 1;

            fseek(arq,sizeof(struct Funcionario)*-1, SEEK_CUR);
            printf("\nDigite o novo cargo: ");
            fflush(stdin);
            gets(funcionarios.cargo);
            printf("Digite a nova função: ");
            scanf("%s", &funcionarios.funcao);

            fwrite(&funcionarios, sizeof(funcionarios), 1, arq);
            fseek(arq, sizeof(funcionarios)* 0, SEEK_END);

            retornarMensagem("\n\t\t\t|Dados do funcionário alterados com sucesso!|");
            system("pause>nul");
            system("cls || clear");
            montarMenuFuncionarios();
        }
    }
    if (!encontrado)
    {
        retornarMensagem("\n\t\t\tNome não cadastrado!\n");
        system("pause>nul");
        system("cls || clear");
        montarMenuFuncionarios();
    }
    fclose(arq);
}
void consultarFuncionarios()
{
    arq = fopen("funcionarios.pro", "rb");
    if (arq == NULL)
    {
        retornarMensagem("\nArquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenuFuncionarios();
    }
    struct Funcionario funcionarios;
    char nome[50];
    int encontrado = 0;
    printf ("\nDigite o nome que procura: ");
    scanf ("%s", &nome);

    while (fread (&funcionarios, sizeof(funcionarios), 1, arq))
    {
        if ((funcionarios.nome[0] == nome[0]) && (funcionarios.deletado != '*'))
        {
            printf("\nNome do funcionário: %s\nCPF: %s\nCargo: %s\nFunção: %s\n",funcionarios.nome, funcionarios.cpf, funcionarios.cargo, funcionarios.funcao);
            encontrado = 1;
            system("pause>nul");
            system("cls || clear");
            montarMenuFuncionarios();
        }
    }
    if (!encontrado)
    {
        retornarMensagem("\nFuncionário não cadastrado!\n");
        system("pause>nul");
        system("cls || clear");
        montarMenuFuncionarios();
    }
    fclose(arq);
}
void excluirFuncionarios()
{
    char excluir;
    printf("\t\t\t\t\t|AVISO|\n");
    printf("TODOS OS FUNCIONÁRIOS SERÃO APAGADOS!\n");
    printf("NÃO É POSSÍVEL RECUPERAR!");
    printf("\n\n");
    printf("Deseja realmente apagar todos os funcionários? [S/N} \n");
    scanf("%s", &excluir);
    printf("\n");

    while (excluir != 's' || excluir != 'S')
    {
        if (excluir == 's' || excluir == 'S')
        {
            arq = fopen("funcionarios.pro", "w++");

            fclose(arq);
            printf("\nFuncionários excluídos como solicitado.");
            getch();
            system("clear||cls");
            montarMenuFuncionarios();

        }
        if (excluir == 'n' || excluir == 'N')
        {
            printf("\nNenhum funcionário foi apagado!\n\n\n\n");
            system("clear||cls");
            montarMenuFuncionarios();
        }
    }
}
void montarMenuRelatorios()
{
    int opcao = 0;
    printf("\n\tMenu de Relatórios\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Cadastrar Relatórios\n");
    printf("2. Alterar Relatórios\n");
    printf("3. Consultar Relatórios\n");
    printf("4. Excluir Relatórios\n");
    printf("5. Voltar ao Menu Administrador\n");
    system("pause>nul");
    scanf("%i", &opcao);
    system("cls || clear");
    gerenciarRelatorios(opcao);
}
void gerenciarRelatorios(int opcao)
{
    switch(opcao)
    {
        case 1:
            cadastrarRelatorios();
            break;
        case 2:
            alterarRelatorios();
            break;
        case 3:
            consultarRelatorios();
            break;
        case 4:
            excluirRelatorios();
            break;
        case 5:
            menuAdministrador();
            break;
        default:
            printf("Digite uma opção válida!\n");
            montarMenuRelatorios();
    }
}
void cadastrarRelatorios()
{
    struct Relatorio relatorios;
    int retorno;
    arq = fopen("relatorios.pro", "a");
    if (arq == NULL)
    {
        retornarMensagem("Erro ao abrir arquivo");
        return;
    }
    printf("\n\t\t\t\|SISTEMA DE CADASTRO DE RELATÓRIO|\n");
    printf("\nDigite o título do relátório: ");
    scanf("%s", &relatorios.nome);
    printf("Digite o relatório: ");
    fflush(stdin);
    gets(relatorios.texto);
    printf("Digite a data: ");
    scanf("%s", &relatorios.data);
    retorno = fwrite (&relatorios, sizeof(relatorios), 1, arq);
    if (retorno == 1)
    {
        fclose (arq);
        retornarMensagem("\nRelatório cadastrado com sucesso!");
        system("pause>nul");
        system("cls || clear");
        montarMenuRelatorios();
    }
    else
    {
        fclose (arq);
        retornarMensagem("\n Falha ao cadastrar relatório.");
        system("pause>nul");
        system("cls || clear");
        montarMenuRelatorios();
    }
}
void alterarRelatorios()
{
    {
        arq = fopen("relatorios.pro", "r+b");
        if (arq == NULL)
        {
            retornarMensagem("\nArquivo inexistente!");
            system("pause>nul");
            system("cls || clear");
            montarMenuRelatorios();
        }

        struct Relatorio relatorios;
        char nome[50];
        int encontrado = 0;
        printf ("\nDigite o nome que procura: ");
        scanf ("%s", &nome);

        while (fread (&relatorios, sizeof(relatorios), 1, arq))
        {
            if ((relatorios.nome[0] == nome[0]) && (relatorios.deletado != '*'))
            {
                printf("\nNome do relatório: %s\nTexto: %s\nData:  %s\n",relatorios.nome, relatorios.texto, relatorios.data);
                encontrado = 1;

                fseek(arq,sizeof(struct Relatorio)*-1, SEEK_CUR);
                printf("\nDigite o novo texto: ");
                fflush(stdin);
                gets(relatorios.texto);
                printf("Digite a nova data: ");
                scanf("%s", &relatorios.data);

                fwrite(&relatorios, sizeof(relatorios), 1, arq);
                fseek(arq, sizeof(relatorios)* 0, SEEK_END);

                retornarMensagem("\n\t\t\t|Dados do relatório alterados com sucesso!|");
                system("pause>nul");
                system("cls || clear");
                montarMenuRelatorios();
            }
        }
        if (!encontrado)
        {
            retornarMensagem("\n\t\t\tNome não cadastrado!\n");
            system("pause>nul");
            system("cls || clear");
            montarMenuRelatorios();
        }
        fclose(arq);
    }

}
void consultarRelatorios()
{
    {
        arq = fopen("relatorios.pro", "rb");
        if (arq == NULL)
        {
            retornarMensagem("\nArquivo inexistente!");
            system("pause>nul");
            system("cls || clear");
            montarMenuRelatorios();
        }
        struct  Relatorio relatorios;
        char nome[50];
        int encontrado = 0;
        printf ("\nDigite o relatório que procura: ");
        scanf ("%s", &nome);

        while (fread (&relatorios, sizeof(relatorios), 1, arq))
        {
            if ((relatorios.nome[0] == nome[0]) && (relatorios.deletado != '*'))
            {
                printf("\nNome do relatório: %s\nTexto: %s\nData: %s\n",relatorios.nome, relatorios.texto, relatorios.data);
                encontrado = 1;
                system("pause>nul");
                system("cls || clear");
                montarMenuRelatorios();
            }
        }
        if (!encontrado)
        {
            retornarMensagem("\nRelatório não cadastrado!\n");
            system("pause>nul");
            system("cls || clear");
            montarMenuRelatorios();
        }
        fclose(arq);
    }
}
void excluirRelatorios()
{
    char excluir;
    printf("\t\t\t\t\t|AVISO|\n");
    printf("TODOS OS RELATÓRIOS SERÃO APAGADOS!\n");
    printf("NÃO É POSSÍVEL RECUPERAR!");
    printf("\n\n");
    printf("Deseja realmente apagar todos os relatórios? [S/N} \n");
    scanf("%s", &excluir);
    printf("\n");

    while (excluir != 's' || excluir != 'S')
    {
        if (excluir == 's' || excluir == 'S')
        {
            arq = fopen("relatorios.pro", "w++");

            fclose(arq);
            printf("\nRelatórios excluídos como solicitado.");
            getch();
            system("clear||cls");
            montarMenuRelatorios();

        }
        if (excluir == 'n' || excluir == 'N')
        {
            printf("\nNenhum relatório foi excluído!\n\n\n\n");
            system("clear||cls");
            montarMenuRelatorios();
        }
    }
}
void montarMenuCliente()
{
    int opcao = 0;
    printf("\n\tMenu Cliente\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Caso já tenha cadastro e deseja se logar.\n");
    printf("2. Caso não tenha cadastro e deseja criar um.\n");
    printf("3. Voltar ao menu principal.\n");
    system("pause>nul");
    scanf("%i", &opcao);
    system("cls || clear");
    gerenciarMenuCliente(opcao);
}
void gerenciarMenuCliente(int opcao)
{
    switch(opcao)
    {
        case 1:
            loginCliente();
            break;
        case 2:
            cadastroCliente();
            break;
        case 3:
            montarMenuPrincipal();
            break;
        default:
            printf("Digite uma opção válida!\n");
            montarMenuCliente();
    }
}
void cadastroCliente()
{
    printf("\n\t\t\t\|SISTEMA DE CADASTRO DE CLIENTE|\n");
    arq = fopen("clientes.pro", "ab");
    struct Usuario usuarios;
    int cont, i = 0;
    int voltar;
    int adicionar;
    int opcao = 0;

    printf("\nDigite seu nome: ");
    scanf("%s", &usuarios.nome);
    printf("Digite seu nome artístico: ");
    scanf("%s", &usuarios.nomeart);
    printf("Digite sua idade: ");
    scanf("%s", &usuarios.idade);
    printf("Digite o telefone: ");
    scanf("%s", &usuarios.telefone);
    printf("Digite seu ritmo musical: ");
    scanf("%s", &usuarios.ritmo);
    printf("Digite sua profissão: ");
    scanf("%s", &usuarios.tipo);
    printf("Digite sua experiência profissional: ");
    scanf("%s", &usuarios.experiencia);
    printf("Digite sua cidade: ");
    scanf("%s", &usuarios.cidade);
    printf("Digite seu estado: ");
    scanf("%s", &usuarios.estado);
    printf("Digite o email: ");
    scanf("%s", &usuarios.email);
    printf("Crie uma senha: ");
    scanf("%s", &usuarios.senha);
    voltar = fwrite(&usuarios, sizeof(usuarios), 1, arq);
    fclose(arq);
    if (voltar == 1){
        printf("\n\nCadastro realizado com sucesso!\n");
        getch();
        system("clear || cls");
        loginCliente();
}
    else
        {
        printf("\nHouve erro ao cadastrar, favor tente novamente.\n\n");
        cadastroCliente();
    }
}
void loginCliente()
{
    int i = 0, valor = 1, cont = 0;
    char email[50];
    char senha[50];

    arq = fopen("clientes.pro", "rb");
    printf("\n\t\t\t\t|SISTEMA DE LOGIN DE CLIENTE|\n");
    printf("\nDigite o seu e-mail: ");
    scanf("%s", &email);
    printf("\nDigite a senha: ");
    scanf("%s", &senha);
    valor = fread(&max[i], sizeof(usuarios), 1, arq);
    printf("%d", valor);
    while (valor ==1)
    {
        if (strcmp(email, max[i].email)==0)
        {
           if (strcmp(senha, max[i].senha)==0)
            {
                fclose(arq);
                system("clear || cls");
                menuCliente();
                cont++;
            }
        }
        i++;
        valor = fread(&max[i], sizeof(usuarios), 1, arq);
    }
    if (cont ==0)
    {
        fclose(arq);
        system("cls || clear");
        printf("\nLogin ou senha incorretos! Digite novamente.\n");
        loginCliente();
    }
    getch();
    system("cls || clear");
}

void alterarCliente()
{
    {
        arq = fopen("clientes.pro", "r+b");
        if (arq == NULL)
        {
            retornarMensagem("\nArquivo inexistente!");
            system("pause>nul");
            system("cls || clear");
            montarMenuCliente();
        }

        struct Usuario usuarios;
        char nome[50];
        int encontrado = 0;
        printf ("\nDigite o nome que procura: ");
        scanf ("%s", &nome);

        while (fread (&usuarios, sizeof(usuarios), 1, arq))
        {
            if ((usuarios.nome[0] == nome[0]) && (usuarios.deletado != '*'))
            {
                printf("\nNome do cliente: %s", usuarios.nome);
                printf("\nNome artístico: %s", usuarios.nomeart);
                printf("\nIdade: %s", usuarios.idade);
                printf("\nTelefone: %s", usuarios.telefone);
                printf("\nRitmo musical: %s", usuarios.ritmo);
                printf("\nProfissão: %s", usuarios.tipo);
                printf("\nExperiência Profisional: %s", usuarios.experiencia);
                printf("\nCidade: %s", usuarios.cidade);
                printf("\nEstado: %s", usuarios.estado);
                printf("\nE-mail: %s", usuarios.email);
                encontrado = 1;

                fseek(arq,sizeof(struct Usuario)*-1, SEEK_CUR);
                printf("\n\nDigite o novo nome: ");
                fflush(stdin);
                gets(usuarios.nome);
                printf("Digite o novo nome artístico: ");
                scanf("%s", &usuarios.nomeart);
                printf("Digite a nova idade: ");
                scanf("%s", &usuarios.idade);
                printf("Digite o novo telefone: ");
                scanf("%s", &usuarios.telefone);
                printf("Digite o novo ritmo musical: ");
                scanf("%s", &usuarios.ritmo);
                printf("Digite a nova profissão: ");
                scanf("%s", &usuarios.tipo);
                printf("Digite a nova experiência profissional: ");
                scanf("%s", &usuarios.experiencia);
                printf("Digite a nova cidade: ");
                scanf("%s", &usuarios.cidade);
                printf("Digite o novo estado: ");
                scanf("%s", &usuarios.estado);
                printf("Digite a senha: ");
                scanf("%s", &usuarios.email);

                fwrite(&usuarios, sizeof(usuarios), 1, arq);
                fseek(arq, sizeof(usuarios)* 0, SEEK_END);

                retornarMensagem("\n\t\t\t|Dados do cliente alterados com sucesso!|");
                system("pause>nul");
                system("cls || clear");
                clientesAdministrador();
            }
        }
        if (!encontrado)
        {
            retornarMensagem("\n\t\t\t|Nome não cadastrado!|\n");
            system("pause>nul");
            system("cls || clear");
            clientesAdministrador();
        }
        fclose(arq);
    }

}

void consultarCliente()
{
    {
        arq = fopen("clientes.pro", "rb");
        if (arq == NULL)
        {
            retornarMensagem("\nArquivo inexistente!");
            system("pause>nul");
            system("cls || clear");
            montarMenuCliente();
        }
        struct  Usuario usuarios;
        char nome[50];
        int encontrado = 0;
        printf ("\nDigite o cliente que procura: ");
        scanf ("%s", &nome);

        while (fread (&usuarios, sizeof(usuarios), 1, arq))
        {
            if ((usuarios.nome[0] == nome[0]) && (usuarios.deletado != '*'))
            {
                printf("\nNome do cliente: %s", usuarios.nome);
                printf("\nNome artístico: %s", usuarios.nomeart);
                printf("\nIdade: %s", usuarios.idade);
                printf("\nTelefone: %s", usuarios.telefone);
                printf("\nRitmo musical: %s", usuarios.ritmo);
                printf("\nProfissão: %s", usuarios.tipo);
                printf("\nExperiência Profisional: %s", usuarios.experiencia);
                printf("\nCidade: %s", usuarios.cidade);
                printf("\nEstado: %s", usuarios.estado);
                printf("\nE-mail: %s", usuarios.email);
                encontrado = 1;
                system("pause>nul");
                system("cls || clear");
                clientesAdministrador();
            }
        }
        if (!encontrado)
        {
            retornarMensagem("\nCliente não cadastrado!\n");
            system("pause>nul");
            system("cls || clear");
            clientesAdministrador();
        }
        fclose(arq);
    }
}

void excluirCliente(void)
{
    char excluir;
    printf("\t\t\t\t\tAVISO\n");
    printf("TODOS OS CLIENTES SERÃO APAGADOS!\n");
    printf("NÃO É POSSÍVEL RECUPERAR!");
    printf("\n\n");
    printf("Deseja realmente apagar todos os clientes? [S/N} \n");
    scanf("%s", &excluir);
    printf("\n");

    while (excluir != 's' || excluir != 'S')
    {
        if (excluir == 's' || excluir == 'S')
        {
            arq = fopen("clientes.pro", "w++");

            fclose(arq);
            printf("Clientes excluídos como solicitado.");
            getch();
            system("clear||cls");
            montarMenuPrincipal();

        }
        if (excluir == 'n' || excluir == 'N')
        {
            printf("Nenhum cliente foi apagado!\n\n\n\n");
            system("clear||cls");
            menuCliente();
        }
    }
}
void listarCliente()
{
    int i = 0, retorno;

    arq = fopen("clientes.pro", "a+b");
    if (arq == NULL){
       printf ("\nErro!\nO arquivo da lista não pode ser aberto!\n");
       getch();
       exit(1);
    }
    retorno = fread(&max[i], sizeof(usuarios), 1, arq);
    while (retorno == 1){
      printf("\nNome: %s",max[i].nome);
      printf("\nNome artístico: %s",max[i].nomeart);
      printf("\nIdade: %s",max[i].idade);
      printf("\nTelefone: %s",max[i].telefone);
      printf("\nRitmo musical: %s",max[i].ritmo);
      printf("\nProfissão: %s",max[i].tipo);
      printf("\nExperiência Profissional: %s",max[i].experiencia);
      printf("\nCidade: %s",max[i].cidade);
      printf("\nEstado: %s",max[i].estado);
      printf("\nE-mail: %s\n",max[i].email);
      i++;
      retorno = fread(&max[i], sizeof(usuarios), 1, arq);
    }
    printf(" \n\n %d Contatos salvos!\n ", i);
    getch();
    fclose(arq);
    system("cls || clear");
    menuEstabelecimento();
}
void menuCliente()
{
    int continuar = 0;

    printf("\n\tMenu do Cliente\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Alterar Cadastro\n");
    printf("2. Excluir Cadastro\n");
    printf("3. Listar Estabelecimentos\n");
    printf("4. Voltar ao Menu Principal\n");
    printf("5. Sair do Programa\n");

    scanf("%i", &continuar);
    system("cls || clear");

    switch(continuar)
    {
        case 1:
            alterarCliente();
            break;
        case 2:
            excluirCliente();
            break;
        case 3:
            listarEstabelecimento();
            break;
        case 4:
            montarMenuPrincipal();
        case 5:
            sair();
            break;
        default:
            printf("Digite uma opção válida!\n");
            menuCliente();
    }
}
void montarMenuEstabelecimento()
{
    int opcao = 0;
    printf("\n\tMenu de Estabelecimento\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Caso já tenha cadastro e deseja se logar.\n");
    printf("2. Caso não tenha cadastro e deseja criar um.\n");
    printf("3. Voltar ao menu principal.\n");
    system("pause>nul");
    scanf("%i", &opcao);
    system("cls || clear");
    gerenciarMenuEstabelecimento(opcao);
}
void gerenciarMenuEstabelecimento(int opcao)
{
    switch(opcao)
    {
        case 1:
            loginEstabelecimento();
            break;
        case 2:
            cadastroEstabelecimento();
            break;
        case 3:
            montarMenuPrincipal();
        default:
            printf("Digite uma opção válida!\n");
            montarMenuEstabelecimento();
    }
}
void menuEstabelecimento()
{
    int continuar = 0;

    printf("\n\tMenu do Estabelecimento\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Alterar Cadastro\n");
    printf("2. Excluir Cadastro\n");
    printf("3. Listar Clientes\n");
    printf("4. Voltar ao Menu Principal\n");
    printf("5. Sair do Programa\n");

    scanf("%i", &continuar);
    system("cls || clear");

    switch(continuar)
    {
        case 1:
            alterarEstabelecimento();
            break;
        case 2:
            excluirEstabelecimento();
            break;
        case 3:
            listarCliente();
            break;
        case 4:
            montarMenuPrincipal();
        case 5:
            sair();
            break;
        default:
            printf("Digite uma opção válida!\n");
            menuEstabelecimento();
    }
}
void cadastroEstabelecimento()
{
    printf("\n\t\t\t|SISTEMA DE CADASTRO DE ESTABELECIMENTO|\n");
    arq = fopen("estabelecimento.pro", "ab");
    struct Estabelecimento estabelecimentos;
    int cont, i = 0;
    int voltar;
    int adicionar;
    int opcao = 0;

    printf("\nQual o nome do estabelecimento: ");
    scanf("%s", &estabelecimentos.nome);
    printf("Telefone do estabelecimento: ");
    scanf("%s", &estabelecimentos.fone);
    printf("Qual o estado: ");
    scanf("%s", &estabelecimentos.estado);
    printf("Qual a cidade: ");
    scanf("%s", &estabelecimentos.cidade);
    printf("Endereço do estabelecimento: ");
    scanf("%s", &estabelecimentos.localizacao);
    printf("Qual o tipo do estabelecimento (ex:casa de show, bar, produtora, empresário): ");
    scanf("%s", &estabelecimentos.tipo);
    printf("Qual o e-mail do estabelecimento: ");
    scanf("%s", &estabelecimentos.email);
    printf("Crie uma senha: ");
    scanf("%s", &estabelecimentos.senha);

    voltar = fwrite(&estabelecimentos, sizeof(estabelecimentos), 1, arq);
    fclose(arq);
    if (voltar == 1){
        printf("\nCadastro realizado com sucesso!\n");
        getch();
        system("clear || cls");
        loginEstabelecimento();
}
    else
        {
        printf("\nHouve erro ao cadastrar, favor tente novamente.\n");
        cadastroEstabelecimento();
    }
}
void loginEstabelecimento()
{
    int i = 0, valor = 1, cont = 0;
    char email[50];
    char senha[50];

    arq = fopen("estabelecimento.pro", "rb");
    printf("\n\t\t\t\t|SISTEMA DE LOGIN DE ESTABELECIMENTO|\n");
    printf("\nDigite o seu e-mail: ");
    scanf("%s", &email);
    printf("\nDigite a senha: ");
    scanf("%s", &senha);
    valor = fread(&maximo[i], sizeof(estabelecimentos), 1, arq);
    printf("%d", valor);
    while (valor ==1)
    {
        if (strcmp(email, maximo[i].email)==0)
        {
           if (strcmp(senha, maximo[i].senha)==0)
            {
                fclose(arq);
                system("clear || cls");
                menuEstabelecimento();
                cont++;
            }
        }
        i++;
        valor = fread(&maximo[i], sizeof(estabelecimentos), 1, arq);
    }
    if (cont ==0)
    {
        fclose(arq);
        system("cls || clear");
        printf("\nLogin ou senha incorreto! Digite novamente.\n");
        loginEstabelecimento();
    }
    getch();
    system("cls || clear");
}

void alterarEstabelecimento()
{
arq = fopen("estabelecimento.pro", "r+b");

    if (arq == NULL)

    {
        retornarMensagem("\nArquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        estabelecimentosAdministrador();
    }

    struct Estabelecimento estabelecimentos;
    char nome[50];
    int encontrado = 0;
    int valor;
    printf ("\nDigite o nome que procura: ");
    scanf ("%s", &nome);
    while (fread (&estabelecimentos, sizeof(estabelecimentos), 1, arq))
    {
        if ((estabelecimentos.nome[0] == nome[0]) && (estabelecimentos.deletado != '*'))
        {
            printf("\nNome do estabelecimento: %s",estabelecimentos.nome);
            printf("\nTelefone do estabelecimento: %s",estabelecimentos.fone);
            printf("\nEstado: %s",estabelecimentos.estado);
            printf("\nCidade: %s",estabelecimentos.cidade);
            printf("\nEndereço do estabelecimento: %s",estabelecimentos.localizacao);
            printf("\nTipo do estabelecimento: %s",estabelecimentos.tipo);
            printf("\nE-mail do estabelecimento: %s",estabelecimentos.email);

            encontrado = 1;

            fseek(arq,sizeof(struct Estabelecimento)*-1, SEEK_CUR);

            printf("\n\nDigite o novo nome: ");
            fflush(stdin);
            gets(estabelecimentos.nome);
            printf("Digite o novo telefone: ");
            scanf(" %s", &estabelecimentos.fone);
            printf("Digite o novo estado: ");
            scanf(" %s", &estabelecimentos.estado);
            printf("Digite a nova cidade: ");
            scanf(" %s", &estabelecimentos.cidade);
            printf("Digite o novo endereço: ");
            scanf(" %s", &estabelecimentos.localizacao);
            printf("Digite a nova senha: ");
            scanf(" %s", &estabelecimentos.senha);


            fwrite(&estabelecimentos, sizeof(estabelecimentos), 1, arq);
            fseek(arq, sizeof(estabelecimentos)* 0, SEEK_END);

            retornarMensagem("\n\t\t\t|Dados do funcionário alterados com sucesso!|");
            system("pause>nul");
            system("cls || clear");
            estabelecimentosAdministrador();
        }
    }
    if (!encontrado)
    {
        retornarMensagem("\nNome não cadastrado!\n");
        system("pause>nul");
        system("cls || clear");
        estabelecimentosAdministrador();
    }
    fclose(arq);
}

void consultarEstabelecimento()
{
    {
        arq = fopen("estabelecimento.pro", "rb");
        if (arq == NULL)
        {
            retornarMensagem("\nArquivo inexistente!");
            system("pause>nul");
            system("cls || clear");
            montarMenuEstabelecimento();
        }
        struct  Estabelecimento estabelecimentos;
        char nome[50];
        int encontrado = 0;
        printf ("\nDigite o estabelecimento que procura: ");
        scanf ("%s", &nome);

        while (fread (&estabelecimentos, sizeof(estabelecimentos), 1, arq))
        {
            if ((estabelecimentos.nome[0] == nome[0]) && (estabelecimentos.deletado != '*'))
            {
                printf("\nNome do estabelecimento: %s",estabelecimentos.nome);
                printf("\nTelefone do estabelecimento: %s",estabelecimentos.fone);
                printf("\nEstado: %s",estabelecimentos.estado);
                printf("\nCidade:  %s",estabelecimentos.cidade);
                printf("\nEndereço do estabelecimento:  %s",estabelecimentos.localizacao);
                printf("\nTipo do estabelecimento: %s",estabelecimentos.tipo);
                printf("\nE-mail do estabelecimento:  %s",estabelecimentos.email);
                encontrado = 1;
                system("pause>nul");
                system("cls || clear");
                estabelecimentosAdministrador();
            }
        }
        if (!encontrado)
        {
            retornarMensagem("\nEstabelecimento não cadastrado!\n");
            system("pause>nul");
            system("cls || clear");
            estabelecimentosAdministrador();
        }
        fclose(arq);
    }
}

void excluirEstabelecimento()
{
    char excluir;
    printf("\t\t\t\t\t|AVISO|\n");
    printf("TODOS OS ESTABELECIMENTOS SERÃO APAGADOS!\n");
    printf("NÃO É POSSÍVEL RECUPERAR!");
    printf("\n\n");
    printf("Deseja realmente apagar todos os estabelecimentos? [S/N} \n");
    scanf("%s", &excluir);
    printf("\n");

    while (excluir != 's' || excluir != 'S')
    {
        if (excluir == 's' || excluir == 'S')
        {
            arq = fopen("estabelecimento.pro", "w++");
            fclose(arq);
            printf("Todos os estabelecimentos foram excluídos com sucesso.");
            getch();
            system("clear||cls");
            montarMenuPrincipal();

        }
        if (excluir == 'n' || excluir == 'N')
        {
            printf("Nenhum estabelecimento foi excluído!\n\n\n\n");
            system("clear||cls");
            menuEstabelecimento();
        }
    }
}

void listarEstabelecimento()
{
    int i = 0, retorno;

    arq = fopen("estabelecimento.pro", "a+b");
    if (arq == NULL){
       printf ("\nErro!\nO arquivo da lista não pode ser aberto!\n");
       getch();
       montarMenuEstabelecimento();
    }
    retorno = fread(&maximo[i], sizeof(estabelecimentos), 1, arq);
    while (retorno == 1){
      printf("\n Nome: %s",maximo[i].nome);
      printf("\n Endereço: %s",maximo[i].localizacao);
      printf("\n Estado: %s",maximo[i].estado);
      printf("\n Cidade: %s",maximo[i].cidade);
      printf("\n Telefone: %s",maximo[i].fone);
      printf("\n Tipo Estabelecimento: %s",maximo[i].tipo);
      printf("\n E-mail: %s\n",maximo[i].email);
      i++;
      retorno = fread(&maximo[i], sizeof(estabelecimentos), 1, arq);
    }
    printf(" \n\n %d Contatos salvos!\n ", i);
    getch();
    fclose(arq);
    system("cls || clear");
    menuCliente();
}

void montarMenuPrincipal()
{
    int opcao = 0;
    printf("\n\tMenu Principal\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Menu Administrador\n");
    printf("2. Menu Cliente\n");
    printf("3. Menu Estabelecimento\n");
    printf("4. Configurar Cores\n");
    printf("5. Sobre\n");
    printf("6. Sair\n");
    system("pause>nul");
    scanf("%i", &opcao);
    system("cls || clear");
    gerenciarMenuPrincipal(opcao);
}
void gerenciarMenuPrincipal(int opcao)
{
    switch(opcao)
    {
        case 1:
            loginAdm();
            break;
        case 2:
            montarMenuCliente();
            break;
        case 3:
            montarMenuEstabelecimento();
            break;
        case 4:
            configurarTela();
            break;
        case 5:
            sobre();
        case 6:
            sair();
        default:
            printf("Digite uma opção válida!\n");
            montarMenuPrincipal();
    }
}
int main()
{
    int var;
    system("title PIM - UNIMUSIC");
    system("color F0");
    setlocale(LC_ALL, "Portuguese");
    printf("\n\n\t\tUNIMUSIC - PLATAFORMA DO RAMO MUSICAL\n\n");
    printf("\tVeja todas as funções disponiveis no menu.\n");
    printf("\tUse os numeros para selecionar a opção desejada.\n");
    printf("\tPressione qualquer tecla para continuar ou espaço para sair do programa agora.\n");
    printf("\n\n");
    printf("\t\t          P  /_\\  P                              \n");
    printf("\t\t         /_\\_|_|_/_\\                            \n");
    printf("\t\t     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("\t\t     |_|_|nnnn nnnn|_|_|        nosso programa!   \n");
    printf("\t\t    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("\t\t    |_____| ' _ ' |_____|                         \n");
    printf("\t\t          \\__|_|__/                              \n");
    printf("\n\n");
    var=getch();
    if(var == 32){ exit(0);}
    system("cls || clear");
    montarMenuPrincipal();
    system("pause");
}
