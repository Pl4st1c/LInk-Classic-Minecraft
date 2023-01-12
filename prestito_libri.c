#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <stdbool.h>

typedef struct {
  char ISBN[100];
  char libro[100];
  char genere[100];
  int flag;
}
libri;

void stp(FILE * fp);
void inserimento(FILE * fp);
void dlt(FILE * fp);
void dltdt(FILE * fp);
void rISBN(FILE * fp);
void rgen(FILE * fp);

int main() { //main
  FILE * fp;
  libri books;
  int sc, i;
  int rbt = 1;
  int count = 0;
  while (rbt != 0) {

    printf("\n1-Stampa libri presenti\n2-Inserisci nuovo libro\n3-Cancellare un libro\n4-Ricerca libri per genere\n5-Ricerca libri per ISBN\n6-Pulizia archivio\n7-Esci\n");
    printf("\ncosa vuoi fare:");
    scanf("%d", & sc); //per scegliere l'opzione nel menu
    switch (sc) {
    case 1: //stampa libri [fatto]
      fp = fopen("libreria.dat", "rb");

      stp(fp);

      fclose(fp);
      break;

    case 2: //input dei libri [fatto]

      fp = fopen("libreria.dat", "ab");

      inserimento(fp);
      fclose(fp);

      break;

    case 3: //elimina libri [cancella tutto]
      fp = fopen("libreria.dat", "ab");

      dlt(fp);

      fclose(fp);
      break;

    case 4: //ricerca per genere [fatto]
      fp = fopen("libreria.dat", "rb");
      rgen(fp);
      fclose(fp);
      break;

    case 5: //ricerca per ISBN [fatto]
      fp = fopen("libreria.dat", "rb");
      rISBN(fp);
      fclose(fp);
      break;

    case 6: //pulizia archivio [fatto]
      fp = fopen("libreria.dat", "wb");
      dltdt(fp);
      fclose(fp);
      break;

    case 7: //chiusura programma [fatto]

      exit(0);

      break;

    }
  }
}

void inserimento(FILE * fp) { //input libri
  libri book1;
  printf("\nInserisci il ISBN:");
  scanf("%s", book1.ISBN);
  printf("Inserisci il nome del libro:");
  scanf("%s", book1.libro);
  printf("Inserisci il genere del libro:");
  scanf("%s", book1.genere);
  book1.flag = 0;
  fwrite( & book1, sizeof(book1), 1, fp);
}

void stp(FILE * fp) { //output
  libri book2;
  while (fread( & book2, sizeof(book2), 1, fp) > 0) {
    if (book2.flag == 0) {
      printf("\nISBN: %s   |    libro: %s    |    Genere: %s\n", book2.ISBN, book2.libro, book2.genere);
    }
  }

}

void dlt(FILE * fp) { //cancellazione
  libri book3;
  int i = 0;
  int src = 0;
  printf("quale si vuole cancellare:");
  scanf("%d", & src);
  while (fread( & book3, sizeof(book3), 1, fp) > 0) {
    if (src == i) {
      book3.flag == 1;
      i++;
    }
  }

}

void dltdt(FILE * fp) {
  libri book6;
  int i = 0;
  for (i = 0; i < 0; i++) {

    book6.flag == 1;

  }
}

void rISBN(FILE * fp) {
  libri book7;
  char src[100];
  printf("Inserisci il codice ISBN:");
  scanf("%s", src);
  while (fread( & book7, sizeof(book7), 1, fp) > 0) {
    if ((book7.flag == 0) && (strcmp(src, book7.ISBN) == 0)) {

      printf("\nISBN: %s   |    libro: %s    |    Genere: %s\n", book7.ISBN, book7.libro, book7.genere);

    }
  }
}

void rgen(FILE * fp) {
  libri book8;
  char src[100];
  printf("Inserisci il genere:");
  scanf("%s", src);
  while (fread( & book7, sizeof(book7), 1, fp) > 0) {
    if ((book7.flag == 0) && (strcmp(src, book7.genere) == 0)) {

      printf("\nISBN: %s   |    libro: %s    |    Genere: %s\n", book7.ISBN, book7.libro, book7.genere);

    }
  }
}