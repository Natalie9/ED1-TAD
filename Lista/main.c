#include <stdio.h>
#include <stdlib.h>
#include "arranjo.h"

int main(int argc, char *argv[])
{
  TipoLista lista;
  TipoItem item;
  int vetor[MaxTam];
  int i, j, n, ver_vazia;

  FLVazia(&lista);
  printf("Entre com o numero de elemento na lista: \n");
  scanf("%d", &n);

  /*Lendo o vetor[i] */
  for (i = 0; i < n; i++)
  {
    printf("Entre com o elemento da lista de posicao %d : ", i);
    scanf("%d", &vetor[i]);
  }

  /*Insere cada chave na lista */
  printf("Os elementos inseridos na lista sao : ");

  for (i = 0; i < n; i++)
  {
    item.Chave = vetor[i];
    LInsere(item, &lista);
    printf(" %d ", item.Chave);
  }

  printf("\nImprmindo a lista digitada. \n");
  LImprime(lista);

  printf("Removendo um elemento da lista (se existir) ");

  /*Retira cada chave da lista */

  /*lendo o elemento escolhido para remocao pelo usuario  */
  printf("\nQual eh a posicao do elemento a ser removido ? \n");
  scanf("%d", &j);
  /*retira chave apontada */
  LRetira(j, &lista, &item);
  if (j <= lista.Ultimo)
    printf("Retirou o elemento %d que esta na posicao: %d da lista.\n", item.Chave, j);

  printf("Imprmindo a lista apos as remocoes.\n");
  LImprime(lista);
  printf("Verificando se a lista esta vazia.\n");
  ver_vazia = LEhVazia(lista);
  if (ver_vazia == 1) // 1 eh verdade
    printf("A lista esta vazia.\n");
  else
    printf("A lista nao esta vazia.\n");

  verifica_ordem(lista);

  printf("Copiando a lista L1 para a lista L2.\n");
  TipoLista lista2;
  lista2 = copiaLista(lista);
  LImprime(lista2);

  printf("Copiando a lista L1 para a lista L2 sem elementos repetidos.\n");
  lista2 = copiaSemRepeticao(lista);
  LImprime(lista2);

  printf("Copiando a lista L1 invertida para a lista L2\n");
  lista2 = copiaListaInvertida(lista);
  LImprime(lista2);

  printf("Invertendo L1\n");
  inverteLista(&lista);
  LImprime(lista);
  inverteLista(&lista);

  printf("\nIntercalando lista 1 e lista 2\n");
  TipoLista lista3;
  lista3 = intercalarLista(lista, lista2);
  LImprime(lista3);
  return (0);
}
