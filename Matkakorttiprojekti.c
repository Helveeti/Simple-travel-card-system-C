// Matkakorttiprojekti.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdafx.h"

#define HELSINKIHINTA (float)3.0
#define SEUTUHINTA (float)4.80

enum Matkatyyppi { HELSINKI, SEUTU };

struct Matkakortti
{
	char omistaja[41];
	float saldo;
};


// prototyyppi vaaditaan, jos kutsu on ennen määrittelyä
void tulostaValikko();
void alustaKortti(struct Matkakortti* kortti);
void nollaaKortti(struct Matkakortti* kortti);
void lataaSaldo(struct Matkakortti* kortti);
int matkusta(struct Matkakortti* kortti, enum Matkatyyppi tyyppi);
void vahvista();

int main(int argc, char *argv[])
{
	//alustaStringit();
	tulostaValikko();
	return 0;
}

void tulostaValikko()
{
	char v;
	struct Matkakortti kortti;  // kortti on struct Matkakortti -tyyppinen muuttuja
	nollaaKortti(&kortti); // huolehditaan ettei kortti näytä kamalalta, jos sitä ei alusteta

	do
	{
		system("cls");
		printf("---------------------------------Valikko------------------------------");
		printf("\n\n\n\n");
		printf("\t\t\tAlusta matkakortti\t\t1");
		printf("\n\t\t\tLataa saldoa\t\t\t2");
		printf("\n\t\t\tMatkusta Helsingissä\t\t3");
		printf("\n\t\t\tMatkusta seutuliikenteessä\t4");
		printf("\n\t\t\tTulosta kortin tiedot\t\t5");
		printf("\n\t\t\tLopetus\t\t\t\t6");
		printf("\n\t\t\tValitse:");


		v = _getch();

		vahvista();

		switch (v)
		{
		case '1': 	alustaKortti(&kortti); // kortti välitetään aliohjelmalle muuttujaparametrina (käyttäen osoitinta)

					//printf("\n\n\t\tMatkakortti alustetaan täällä...");
			_getch();
			break;

		case '2':   lataaSaldo(&kortti);
			_getch();

			break;
		case '3':
			if (matkusta(&kortti, HELSINKI))
			{
				printf("\n\t\t\tHyvää matkaa!");
				printf("\n\t\t\tSaldo: %.2f ", kortti.saldo);
			}
			else
			{
				printf("\n\t\t\tRahasi eivät riitä.");
				printf("\n\t\t\tSaldo: %.2f ", kortti.saldo);
			}
			_getch();
			break;
		case '4':	//if 
			if (matkusta(&kortti, SEUTU))
			{
				printf("\n\n\t\t\tHyvää matkaa!");
				printf("\n\t\t\tSaldo: %.2f ", kortti.saldo);
			}
			else
			{
				printf("\n\n\t\t\tRahasi eivät riitä.");
				printf("\n\t\t\tSaldo: %.2f ", kortti.saldo);
			}
			_getch();
			break;
		case '5':
			printf("\n\n\n\t\t\tKortin tiedot:");
			printf("\n\t\t\tNimi: %s ", kortti.omistaja);
			printf("\n\t\t\tSaldo: %.2f ", kortti.saldo);
			_getch();
			break;

		case '6':

			break;

		}
	} while (v != '6');

}


void alustaKortti(struct Matkakortti* kortti)
{
	char nimi[41];

	printf("\nAnna kortin haltijan nimi:");
	gets(nimi);

	for (int i = 0; nimi[i] != '\0'; i++) {
		kortti->omistaja[i] = nimi[i];
	}
	kortti->saldo = 0.0;

	printf("\n\n --- Kortin aloitus saldo: %.2f euroa. ---", kortti->saldo);

	printf("\nKortti alustettu...\nKortin tiedot: %s %.2f", kortti->omistaja, kortti->saldo);
}

void nollaaKortti(struct Matkakortti* kortti)
{
	for (int i = 0; kortti->omistaja[i] != '\0'; i++) {
		kortti->omistaja[i] = '\0';
	}
	kortti->saldo = 0.0;
}

void lataaSaldo(struct Matkakortti* kortti)
{
	int summa = 0.0;
	printf("\nAnna kortille ladattava summa:");
	scanf_s("%d", &summa);
	getchar();

	kortti->saldo += (float) summa;

	printf("\nKortin uusi saldo: %.2f", kortti->saldo);
}
// Tehtävä5: katsoo kortilta, onko saldo riittävä ja jos on, niin pienentää sitä
int matkusta(struct Matkakortti* kortti, enum Matkatyyppi tyyppi)
{
	if (!tyyppi && kortti->saldo >= HELSINKIHINTA)
		kortti->saldo -= HELSINKIHINTA;

	else if (tyyppi && kortti->saldo >= SEUTUHINTA)
		kortti->saldo -= SEUTUHINTA;

	else return 0;
}

void vahvista()
{
	printf("\n\nPress any key to continue...");
	_getch();
}
