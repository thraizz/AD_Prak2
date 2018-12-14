#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <iomanip>
using namespace std;

class EVKD{
    private:
    char *Daten;
    int Anz;
    EVKD *Next;

    public:
    EVKD(){}
    EVKD(char * LPSZDaten, EVKD *N=NULL): Daten(LPSZDaten), Next(N){}
    EVKD(const EVKD &E1) {
        Daten = E1.Daten;
        Anz = E1.Anz;
        Next = E1.Next;
    }
    char * getDaten() {return Daten; }
    int getAnzahl() {return Anz; }
    EVKD * getNext() {
        EVKD * nextEVKD = this->Next;
        return nextEVKD;
        }
    void setNext(EVKD &N){Next = &N;}

    bool operator== (EVKD &E1) {
        if(strcmp(this->Daten, E1.Daten)==0){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator> ( EVKD &E1) {
        int strVal;
        strVal = strcmp(this->Daten, E1.getDaten());
        if(strVal<0){
            return true;
        }
        else{
            return false;
        }
    }
};

class TEXT{
    private:
    EVKD *Start;
    public:
    int Anz;
    TEXT(int Anz=0): Start(NULL) {};

    void anhaenge (const char* In) {
        EVKD uebergabe((char*)In);
        if(this->Start!=NULL){
            EVKD* temp(this->Start);
            for(int i=0;i<Anz;i++){
                if(temp->getNext()==NULL){temp->setNext(uebergabe);}
                else{temp->getNext();}
            }
        }
        else{
            this->Start = &uebergabe;
        }
    }

    void einfuegeSortiert(EVKD * In, int Max){
        if(Anz+1>Max){
            printf("Objekt konnte nicht eingefügt werden, da die aktuelle Anzahl schon %d beträgt und kein weiteres Objekt aufnehmen kann.",Anz);
            return;
        }
        if(this->Start==NULL){
            this->Start=&(*In);
            return;
        }
        if(In>Start){
            In->setNext((*Start));
            Start=&(*In);
            return;
        }
        EVKD * vergleich(Start);
        for(int i=0; i<Anz; i++){
            // Wenn das nächste Objekt mit dem verglichen werden soll nicht existiert
            // sind wir am Ende der Liste angelagt und können einfügen.
            if(vergleich->getNext() == NULL){
                vergleich->setNext((*In));
            }
            
            // Wenn In zwischen dem aktuellen und dem nächste liegt, füge dort ein.
            else if ((*In)>(*vergleich) && vergleich->getNext()>In){
                EVKD temp = EVKD(In->getDaten(), vergleich->getNext());
                vergleich->setNext((*In));
            }

            // Kein treffer, wiederhole mit nächstem Objekt
            else{
                vergleich = vergleich->getNext();
            }
            
        }
    }

    void loesche(int Pos){
        if(Pos>this->Anz){
            printf("Element an Position %d konnte nicht gelöscht werden, da es außerhalb der Elemente liegt.",Pos);
            return;
        }
        EVKD *preobj(this->Start);
        if(preobj==NULL){
            printf("Element an Position %d konnte nicht gelöscht werden, da es keine Elemente gibt.",Pos);
            return;
        }
        for(int i=0; i<Pos-1;i++){
            preobj=(preobj->getNext());
        }
        EVKD *posobj(preobj->getNext());
        EVKD *nextobj(posobj->getNext());
        if(posobj!=NULL){
            if(nextobj!=NULL){
               preobj->setNext(*nextobj);
               delete posobj;
            }
            else{
                // (*preobj).setNext(nullptr);
                delete posobj;
            }
        }
        else{
            printf("Das Element exisitert nicht.");
        }
    }
};

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
