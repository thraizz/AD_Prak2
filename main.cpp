#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include "TEXT.h"
#include "EVKD.h"


int main()
{   
    /**
    char * test1 = "Schmitz, Anna";
    char * test2 = "Schmitz, Thorsten";
    int str = strcmp(test1, test2);
    printf ("Ergebnis strcmp: %d\n",str);
    EVKD testobj1=EVKD(test1);
    EVKD testobj2=EVKD(test2);
    str = strcmp(testobj1.getDaten(), testobj2.getDaten());
    printf ("Ergebnis von objekt-bezogenem strcmp: %d\n", str);
    bool str2;    str2 = (testobj1 > testobj2);
    printf ("Ergebnis von Methode: %d\n", str2);
    **/

	int choice, anzIn, ein;
	char *eingabe;
	TEXT *text = new TEXT();
	EVKD *evkd;
	const char * name[] = { "Schmitz, Josef","Mueller, Josi","Schmitz, Anna",
						"Mueller, Josef","Schmitz, Josi","Mueller, Anna",
						"Meier, Josef","Zacher, Josi","Anker, Anna" };


	do{
        printf("Waehlen Sie eine der Möglichkeiten:\n");
        printf("1 - Listenobjekt erstellen\n");
        printf("2 - Liste anzeigen\n");
        printf("3 - Element anhaenge\n");
        printf("4 - Element sortiert einfuegen\n");
        printf("5 - Element loeschen\n");
        printf("6 - Liste sortieren\n");
        printf("12 - Ende\n\n");

		switch(choice){

			case 1:  
                printf("Erstelle die Listenobjekte...\n");
				text = new TEXT();
				for(int i = 0; i < 9; i++){
					text->anhaenge(name[i]);
				}
				break;

			case 2: 
                printf("Der Inhalt der Liste ist: ");
				text->zeigeDich();
				break;

			case 3:
                printf("Gib das Wort ein, das angehaenget werden soll");
				eingabe = new char[anzIn];
				cin.getline(eingabe, anzIn);
				cin.clear();
				text->anhaenge(eingabe);
				delete[] eingabe;
				break;

			case 4: 
                printf("Bitte Wort eingeben");
				eingabe = new char[anzIn];
				cin.getline(eingabe, anzIn);
				cin.clear();
				evkd = new EVKD(eingabe);
				text->einfuegeSortiert(evkd, text->Anz);
				delete[] eingabe;
				break;

			case 5:  
                printf("Welches Element soll geloescht werden?");
				cin >> ein;
        		cout << "\n\n\n\n";
				text->loesche(ein);
				break;

			case 6:
                printf("Liste wird sortiert");
				text->iSort();
				break;

		}

	} while(choice != 12);
}
