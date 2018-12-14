class TEXT{

    private:
    class EVKD *Start;

    public:
    int Anz;
    
    TEXT(int Anz): Start(NULL) {};

    void anhaenge (char* In) {};      

    void einfuegeSortiert(EVKD * In, int Max){};

    void loesche(int Pos){};
};