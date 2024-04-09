#include <stdio.h>

#include "listas.h"

enum {
    OP_NAO_SELECIONADA = 0,
    OP_ADICIONAR,
    OP_DELETAR,
    OP_UPDATE,
    OP_IMPRIMIR,
    OP_IMPRIMIR_TODOS,
    OP_AJEITAR,
    OP_SAIR,
};

int menu();

int main() {
    int opcao = OP_NAO_SELECIONADA;
    char cpf[20];
    init();

    while (opcao != OP_SAIR)
    {
        menu();
        fflush(stdin);
        scanf("%d", &opcao);
        switch (opcao) {
            case OP_ADICIONAR:
                novoUsuario();
                break;
            case OP_DELETAR:
                fflush(stdin);
                printf("Digite o cpf a ser deletado: ");
                fgets(cpf, 20, stdin);
                if(delete(cpf)){
                    printf("Valor deletado!!\n");
                }else
                {
                    printf("Valor nao deletado. CPF nao cadastrado!!\n");
                }
                fflush(stdin);
                break;
            case OP_UPDATE:
                atualizar();
                break;
            case OP_IMPRIMIR:
                fflush(stdin);
                printf("Digite o cpf: ");
                fgets(cpf, 20, stdin);
                imprimir(cpf);
                fflush(stdin);
                break;
            case OP_IMPRIMIR_TODOS:
                imprimirTudo();
                break;
            case OP_AJEITAR:
                if(sort())
                {
                    printf("Lista organizada com Sucesso!!!!\n");
                }else
                {
                    printf("Lista vazia!!\n");
                }
                break;
            case OP_SAIR:
                printf("Bye bye\n");
                break;
            default:
                printf("Opcao Invalida!!");
        }
    }

    destroy();
    exit(EXIT_SUCCESS);
}

int menu()
{
    printf("Menu:\n\n");
    printf("%d - Adicionar Usuario\n", OP_ADICIONAR);
    printf("%d - Deletar Usuario\n", OP_DELETAR);
    printf("%d - Atualizar Usuario\n", OP_UPDATE);
    printf("%d - Imprimir Um\n", OP_IMPRIMIR);
    printf("%d - Imprimir Todos\n", OP_IMPRIMIR_TODOS);
    printf("%d - Ordenar\n", OP_AJEITAR);
    printf("%d - Sair\n\n", OP_SAIR);
    printf("Digite sua opcao: ");
}