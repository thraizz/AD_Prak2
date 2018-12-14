#include "EVKD.h"

bool EVKD::operator> ( EVKD &E1) {

        int strVal;
        strVal = strcmp(this->Daten, E1.getDaten());

        if(strVal<0)
            return true;
        
        
        return false;
        
}

bool EVKD::operator== (EVKD &E1) {
    if(strcmp(this->Daten, E1.Daten)==0){
        return true;
    }
    
    return false;

}

void EVKD::setNext(EVKD &N){
        Next = &N;
}

int EVKD::getAnzahl() { 
        return Anz; 
}  
   
EVKD* EVKD::getNext(){
        EVKD * nextEVKD = this->Next;
        return nextEVKD;
}