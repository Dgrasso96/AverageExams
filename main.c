#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define DIM 20

typedef struct
{
	char nome[20];
	int crediti;
	int voto;
}esami;

typedef struct
{
	float media_art;
	int n_es;
	float media_pond;
	int tot_cred;
}media;

int input(esami e[]);
media calcolo(esami e[], int n);
void stampa(media m);

main()
{
	esami esm[DIM];
	media m;

	int n_esami;

	n_esami = input(esm);
	m = calcolo(esm, n_esami);
	stampa(m);
}

int input(esami e[])
{
	int i;
	char continua = 'y';

	i = 0;

	do
	{
		printf("Inserisci nome esame: ");
		scanf("%s", e[i].nome);
		printf("Inserisci crediti esame: ");
		scanf("%d", &e[i].crediti);
		printf("Inserisci voto esame: ");
		scanf("%d", &e[i].voto);
		i++;
		printf("\nVuoi continuare?(y/n): ");
		scanf("\n%c", &continua);
	} while (continua =='y');

	return i;
}

media calcolo(esami e[], int n)
{
	media m;
	int i;

	m.media_art = 0;
	m.media_pond = 0;
	m.tot_cred = 0;
	m.n_es = n;

	for (i = 0; i < n; i++)
	{
		m.media_art = m.media_art + e[i].voto;
		m.media_pond = m.media_pond + (e[i].voto * e[i].crediti);
		m.tot_cred = m.tot_cred + e[i].crediti;
	}

	m.media_art = m.media_art / m.n_es;
	m.media_pond = m.media_pond / m.tot_cred;

	return m;
}

void stampa(media m)
{
	printf("\nMedia artimetica: %.1f\n", m.media_art);
	printf("Media ponderata: %.1f\n", m.media_pond);
	printf("Crediti totali: %d\n", m.tot_cred);
}