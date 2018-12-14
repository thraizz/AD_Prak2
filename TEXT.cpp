#include "EVDK.h"

void TEXT::anhaenge (char* In) {

    EVKD uebergabe(In);
    if(this->Start!=NULL){
        EVKD* temp(this->Start);
        while (temp->getNext() != null) {
            temp = temp->getNext();
        }
        temp->setNext(uebergabe);       
    }
}  

void TEXT::einfuegeSortiert(EVKD * In, int Max){
        
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

void TEXT::loesche(int Pos){
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