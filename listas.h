#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*TODO

 * - Fazer El Menu
 * */



//struct
typedef struct {
    char cpf[20];
    char nome[50];
    char endereco[80];
    char telefone[20];
    char email[50];
}Usuario;




//Variaveis
extern Usuario *lista;
extern int LISTA_POS;
extern int tamanho;

void init();
void destroy();

void novoUsuario();
void atualizar();

bool add(Usuario novo);
bool delete(char cpf[20]);
bool set(char cpf[20], Usuario atualizado);

bool listaCheia();
bool listaVazia();
bool indexValido(int index);

bool searchByCPF(char cpf[20], int *index);

bool sort();

void imprimir(char cpf[20]);
void imprimirTudo();

void expand();