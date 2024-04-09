#include "listas.h"

int LISTA_POS = 0;
Usuario *lista;
int tamanho = 5;

void init(){
    lista = malloc(5 * sizeof(Usuario));
    if(!lista){
        printf("Erro de alocacao de memoria\n");

        exit(EXIT_FAILURE);
    }
}

void destroy(){
    free(lista);
}

bool listaCheia()
{
    return LISTA_POS == tamanho;
}
bool listaVazia()
{
    return LISTA_POS == 0;
}

bool indexValido(int index)
{
    return !(index < 0 || index >= LISTA_POS);
}

bool add(Usuario novo)
{

    if(listaCheia()){
        expand();
    }

    lista[LISTA_POS] = novo;
    LISTA_POS++;
    return true;
}

bool delete(char cpf[20])
{
    int index = -1;
    searchByCPF(cpf, &index);
    if(!indexValido(index))
    {
        return false;
    }

    for(int i = index+1; i < LISTA_POS;i++)
    {
        lista[i-1] = lista[i];
    }
    LISTA_POS--;
    return true;
}


bool set(char cpf[20], Usuario atualizado)
{
    int index = -1;
    searchByCPF(cpf, &index);
    if(!indexValido(index))
    {
        return false;
    }

    lista[index] = atualizado;

    return true;
}


bool searchByCPF(char cpf[20], int *index)
{
    if(listaVazia())
    {

        return false;
    }

    for(int i = 0; i < LISTA_POS; i++)
    {
        if(!strcmp(lista[i].cpf, cpf)){
            *index = i;

            return true;
        }
    }


    return false;
}

bool sort()
{
    Usuario aux;

    if(listaVazia())
    {
        return false;
    }

    for(int i = 0; i < LISTA_POS - 1; i++)
    {
        for(int k = i+1; k < LISTA_POS; k++)
        {
            if(strcmp(lista[k].nome, lista[i].nome) < 0)
            {
                aux = lista[i];
                lista[i] = lista[k];
                lista[k] = aux;
            }
        }
    }

    return true;
}

void imprimir(char cpf[20])
{
    int index;
    if(!searchByCPF(cpf, &index))
    {
        printf("CPF não cadastrado !!");
        return;
    }

    printf("| Nome: %s \n| cpf: %s \n| Telefone: %s \n| Endereco: %s \n| Email: %s \n", lista[index].nome,
           lista[index].cpf, lista[index].telefone, lista[index].endereco, lista[index].email);
}

void expand(){
    Usuario *aux;
    int novoTamanho;

    novoTamanho = tamanho + 3;

    printf("Expandindo");

    aux = malloc(novoTamanho * sizeof(Usuario));
    if(!aux)
    {
        printf("Erro na alocacao de memoria");
        exit(EXIT_FAILURE);
    }
    for(int i = 0 ; i < tamanho;i++)
    {
        aux[i] = lista[i];
    }

    free(lista);
    lista = aux;
}

void novoUsuario()
{
    int placeholder;
    int choice;

    char cpf[20];
    char nome[50];
    char endereco[80];
    char telefone[20];
    char email[50];

    fflush(stdin);
    printf("Digite o CPF: ");

    fgets(cpf, 20, stdin);

    if(searchByCPF(cpf, &placeholder))
    {
        printf("CPF ja Cadastrado!! Digite 0 para tentar novamente: ");
        scanf("%d", &choice);

        if(!choice)
        {
            novoUsuario();
            return;
        }
        return;
    }

    printf("Digite o seu nome: ");
    fgets(nome, 50, stdin);
    printf("Digite o seu endereco: ");
    fgets(endereco, 80, stdin);
    printf("Digite o seu telefone: ");
    fgets(telefone, 20, stdin);
    printf("Digite o seu email: ");
    fgets(email, 50, stdin);

    Usuario novo;

    strcpy(novo.cpf, cpf);
    strcpy(novo.nome, nome);
    strcpy(novo.endereco, endereco);
    strcpy(novo.telefone, telefone);
    strcpy(novo.email, email);

    add(novo);
    fflush(stdin);
}

void atualizar()
{
    int index;
    int choice;

    char cpf[20];
    char nome[50];
    char endereco[80];
    char telefone[20];
    char email[50];

    fflush(stdin);
    printf("Digite o CPF: ");
    fgets(cpf, 20, stdin);

    if(!searchByCPF(cpf, &index))
    {
        printf("CPF nao cadastrado!! Digite 0 para tentar novamente: ");
        scanf("%d", &choice);

        if(!choice)
        {
            atualizar();
            return;
        }
        return;
    }

    printf("Digite o nome (nao digite nada para nao mudar): ");
    fgets(nome, 50, stdin);
    printf("Digite o endereco (nao digite nada para nao mudar): ");
    fgets(endereco, 80, stdin);
    printf("Digite o telefone (nao digite nada para nao mudar): ");
    fgets(telefone, 20, stdin);
    printf("Digite o email (nao digite nada para nao mudar): ");
    fgets(email, 50, stdin);

    Usuario novo;

    strcpy(novo.cpf, lista[index].cpf);
    strcpy(novo.nome, lista[index].nome);
    strcpy(novo.endereco, lista[index].endereco);
    strcpy(novo.telefone, lista[index].telefone);
    strcpy(novo.email, lista[index].email);

    if(strcmp(nome, "\n") != 0){
        strcpy(novo.nome, nome);
    }
    if(strcmp(endereco, "\n") != 0){
        strcpy(novo.endereco, endereco);
    }
    if(strcmp(telefone, "\n") != 0){
        strcpy(novo.telefone, telefone);
    }
    if(strcmp(email, "\n") != 0){
        strcpy(novo.email, email);
    }

    set(cpf, novo);
    fflush(stdin);
}

void imprimirTudo()
{
    for(int index = 0; index < LISTA_POS; index++)
    {
        printf("| Nome: %s | cpf: %s | Telefone: %s | Endereco: %s | Email: %s |\n", lista[index].nome,
               lista[index].cpf, lista[index].telefone, lista[index].endereco, lista[index].email);
    }
}