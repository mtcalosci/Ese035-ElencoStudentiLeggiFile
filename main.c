#include <stdio.h>
#include <stdlib.h>

// Definisci le costanti
#define N 2
#define MAX_STRLEN 30


// Definisci il tipo di dato struct s_studente
struct s_studente {
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    int eta;
    char classe[MAX_STRLEN+1];
};

// Definisci studente come struct s_studente
struct s_studente studente[N];


int main(int argc, char** argv) {
    // Dichiara le variabili locali
    int letti, i;
    FILE *puntaFile;
    char nomeFile[MAX_STRLEN+1];
    
    // Codice per la richiesta del nome del file
    printf("Inserisci il nome del file da aprire in lettura: ");
    scanf("%s", nomeFile);
    
    // Codice per l'apertura del file, la lettura e la stampa a schermo
    puntaFile = fopen(nomeFile, "rb");
    if(puntaFile == NULL) {
        printf("Non sono riuscito ad aprire il file %s in lettura\n", nomeFile);
    }
    
    letti = fread(studente, sizeof(studente), N, puntaFile);
    /* La precedente chiamata di fread legge _al massimo_ N record, se disponibili
       nel file. Il numero di record effettivamente letto è riportato in letti*/
    while(letti) {
        printf("Letti %d record\n", letti);
        for(i = 0; i < letti; i++) {
            printf("%s; %s; %d; %s\n",studente[i].nome,studente[i].cognome,studente[i].eta,studente[i].classe);
        }
        letti = fread(studente, sizeof(studente), N, puntaFile);
    }
    fclose(puntaFile);
    
    
    return (EXIT_SUCCESS);
}