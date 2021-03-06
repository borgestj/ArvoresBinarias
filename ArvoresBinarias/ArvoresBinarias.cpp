#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


struct no
{
	int n;
	struct no *d, *e;
};

struct no *raiz;
char menu();
void pausa();
void titulo(char *);
void inserir();
struct no * inserir_no_interativa(int);
struct no * inserir_no_recursiva(int);
void vincular_no(struct no *, struct no *);


void main()
{
	char op;
	raiz = NULL;
	do {
		op = menu();
	} while (op != '0');
}

char menu()
{
	char op;
	titulo("MENU");
	printf("0 - Encerrar\n");
	printf("1 - inserir\n");
	printf("Escolha a opcao: ");
	op = _getche();
	switch (op)
	{
		case '0': break;
		case '1': inserir(); break;
		default: printf("\nOpcao invalida!"); pausa(); break;
	}
	return op;
}

void titulo(char *texto)
{
	system("cls");
	printf("---------------------\n");
	printf("%s\n", texto);
	printf("---------------------\n");
}

void pausa()
{
	printf("\nTecle algo...");
	_getch();
}

void inserir()
{
	struct no * aux;
	int n;
	char op;
	titulo("INSERIR");
	printf("1 - Interativa\n");
	printf("2 - Recursiva\n");
	op = _getch();
	if (op == '1')
		titulo("INSERIR INTERATIVA");
	else
		titulo("INSERIR RECURSIVA");
	printf("Informe o numero: ");
	scanf_s("%d", &n);
	if (op == '1')
		aux = inserir_no_interativa(n);
	else
		aux = inserir_no_recursiva(n);
	if (aux != NULL)
		printf("Inserido com sucesso no endereco: %p", aux);
	else
		printf("erro na insercao!");
}

struct no * inserir_no_interativa(int n)
{
	struct no *novo, *aux;
	novo = (struct no *)malloc(sizeof(struct no));
	if (novo != NULL)
	{
		novo->n = n;
		novo->d = novo->e = NULL;
		if (raiz == NULL)
			novo = raiz;
		else
		{
			aux = raiz;
			while (aux != NULL)
			{
				if (novo->n >= aux->n)
				{
					if (aux->d == NULL)
					{
						aux->d = novo;
						aux = NULL;
					}
					else
						aux = aux->d;
				}
				else
				{
					if (aux->e == NULL)
					{
						aux->e = novo;
						aux = NULL;
					}
					else
						aux = aux->e;
				}
			}
		}
		return novo;
	}

};

struct no * inserir_no_recursiva(int n)
{
	struct no * novo;
	novo = (struct no *)malloc(sizeof(struct no));
	if (novo != NULL)
	{
		novo->n = n;
		novo->d = novo->e = NULL;
		if (raiz == NULL)
			raiz = novo;
		else
		{
			vincular_no(raiz, novo);
		}
	}
	return novo;
}

void vincular_no(struct no * aux, struct no * novo)
{
	if (novo->n >= aux->n)
	{
		if (aux->d == NULL)
			aux->d = novo;
		else
			vincular_no(aux->d, novo);
	}
	else
	{
		if (aux->e == NULL)
			aux->e = novo;
		else
			vincular_no(aux->e, novo);
	}
}