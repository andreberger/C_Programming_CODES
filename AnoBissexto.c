#include <stdio.h>

main() {
  int ano;
  printf("\n==========ANO BISSEXTO==========\n");
  printf("\nDigite o ano: ");
  scanf("%d", &ano);

  if (ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0)) {
    printf("\nAno bissexto.\n");

  }

  else {
    printf("\nAno nao bissexto.\n");

  }

}
