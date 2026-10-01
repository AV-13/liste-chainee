#include <stdio.h>
#include "liste.h"

int main(void)
{
    Maillon *liste = NULL;
    for (int i = 1; i <= 5; i++) liste = liste_inserer(liste, i * 10);

    printf("liste     : ");
    liste_afficher(liste);
    printf("blocs     : %d\n", liste_blocs_en_circulation());
    printf("longueur  : %d\n", liste_longueur(liste));
    printf("contient 30 : %s\n", liste_contient(liste, 30) ? "oui" : "non");

    int max;
    if (liste_maximum(liste, &max)) printf("maximum   : %d\n", max);
    else                            printf("maximum   : liste vide\n");
    if (liste_maximum(NULL, &max))  printf("maximum (NULL) : %d\n", max);
    else                            printf("maximum (NULL) : liste vide\n");

    Maillon *seconde = NULL;
    for (int i = 1; i <= 3; i++) seconde = liste_inserer(seconde, i);
    printf("seconde   : ");
    liste_afficher(seconde);

    liste_liberer(liste);
    liste_liberer(seconde);
    printf("liberee\n");
    printf("blocs     : %d\n", liste_blocs_en_circulation());
    return 0;
}
