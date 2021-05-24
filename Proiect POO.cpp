#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>
#include <sstream> //pt to_string

using namespace std;

void afisare(ostream& o, const string a) { // pt afisarea cu spatiu intre ele

    int i = 15; // nr de caractere din spatiul total
    int c = i - a.length();
    o << " ";
    for (int j = 0; j < c / 2; j++) { // daca e par
        o << " ";
    }
    o << a;
    for (int j = 0; j < (c + 1) / 2; j++) { // daca e impar
        o << " ";
    }
}

void spatii(ostream& o) { // pt afisarea cu spatiu inaintea produselor sa coincida cu capul de tabel
    for (int i = 0; i < 9; i++) {
        o << " ";
    }
}

// CLASE
class Produs {
protected:
    string nume;
    unsigned int volum_gramaj;
    unsigned int pret;
    unsigned int cantitate;
public:
    Produs(string a, unsigned int b, unsigned int c, unsigned int d) {
        nume = a,
        volum_gramaj = b;
        pret = c;
        cantitate = d;
    }
    void setNume(string newNume) {
        this->nume = newNume;
    }

    string getNume() {
        return this->nume;
    }

    void setVolumGramaj(unsigned int newVolumGramaj) {
        this->volum_gramaj = newVolumGramaj;
    }

    unsigned int getVolumGramaj() {
        return this->volum_gramaj;
    }

    void setPret(unsigned int newPret) {
        this->pret = newPret;
    }

    unsigned int getPret() {
        return this->pret;
    }

    void setCantitate(unsigned int newCantitate) {
        this->cantitate = newCantitate;
    }

    unsigned int getCantitate() {
        return this->cantitate;
    }

    operator string() {
        return this->nume;
    }

    Produs& operator- (int x) {
        this->setPret(this->pret - (this->pret * x) / 100);
        return *this;
    }

    unsigned int operator+ (Produs& n) {
        return this->pret + n.pret;
    }

    Produs(const Produs& obj) { //Copy Constructor
        nume = obj.nume;
        volum_gramaj = obj.volum_gramaj;
        pret = obj.pret;
        cantitate = obj.cantitate;
    }

    Produs& operator= (const Produs& obj) { //Assignment operator
        nume = obj.nume;
        volum_gramaj = obj.volum_gramaj;
        pret = obj.pret;
        cantitate = obj.cantitate;
        return *this;
    }

    ~Produs() { }

    friend ostream& operator<< (ostream& o, Produs& x);
};
ostream& operator<< (ostream& o, Produs& x) {
    afisare(o, x.nume);
    afisare(o, to_string(x.volum_gramaj));
    afisare(o, (to_string(x.pret) + " lei"));
    afisare(o, (to_string(x.cantitate) + " buc "));
    return o;
}

class Bautura : public Produs {
protected:
    unsigned int volum;
public:
    Bautura(string a, unsigned int b, unsigned int c, unsigned int d) : Produs(a, b, c, d) {
        volum = b;
    }
    friend ostream& operator<< (ostream& o, Bautura& x);
};
ostream& operator<< (ostream& o, Bautura& x) {
    afisare(o, x.nume);
    afisare(o, (to_string(x.volum) + "L"));
    afisare(o, (to_string(x.pret) + " lei"));
    afisare(o, (to_string(x.cantitate) + " buc "));
    return o;
}

class Alcool : public Bautura {
protected:
    unsigned int alcool;
public:
    Alcool(string a, unsigned int b, unsigned int c, unsigned int d, unsigned int o) : Bautura(a, b, c, d) {
        alcool = o;
    }
    friend ostream& operator<< (ostream& o, Alcool& x);
};
ostream& operator<< (ostream& o, Alcool& x) {
    o << *((Bautura*)&x); ///*((Bauturi*) &x) - asa afisez si partea din cls bauturilor
    afisare(o, (to_string(x.alcool) + "% alcool"));
    return o;
}

class Acidulate : public Bautura {
protected:
    string acid;
public:
    Acidulate(string a, unsigned b, unsigned int c, unsigned int d, string i) : Bautura(a, b, c, d) {
        acid = i;
    }
    friend ostream& operator<< (ostream& o, Acidulate& x);
};
ostream& operator<< (ostream& o, Acidulate& x) {
    o << *((Bautura*)&x);
    afisare(o, x.acid);
    return o;
}

class Aliment : public Produs {
protected:
    unsigned int gramaj;
public:
    Aliment(string a, unsigned int b, unsigned int c, unsigned int d) : Produs(a, b, c, d) {
        gramaj = b;
    }
    friend ostream& operator<< (ostream& o, Aliment& x);
};
ostream& operator<< (ostream& o, Aliment& x) {
    afisare(o, x.nume);
    afisare(o, (to_string(x.gramaj) + "g"));
    afisare(o, (to_string(x.pret) + " lei/Kg"));
    afisare(o, (to_string(x.cantitate) + " buc "));
    return o;
}

class Legume_Fructe : public Aliment {
protected:
    string tara;
public:
    Legume_Fructe(string a, unsigned int b, unsigned int c, unsigned int d, string t) : Aliment(a, b, c, d) {
        tara = t;
    }
    friend ostream& operator<< (ostream& o, Legume_Fructe& x);
};
ostream& operator<< (ostream& o, Legume_Fructe& x) {
    afisare(o, x.nume);
    afisare(o, (to_string(x.gramaj) + "Kg"));
    afisare(o, (to_string(x.pret) + " lei/Kg"));
    afisare(o, (to_string(x.cantitate) + " buc "));
    afisare(o, x.tara);
    return o;
}

class Carne : public Aliment {
protected:
    string animal;
public:
    Carne(string a, unsigned int b, unsigned int c, unsigned int d, string l) : Aliment(a, b, c, d) {
        animal = l;
    }
    friend ostream& operator<< (ostream& o, Carne& x);
};
ostream& operator<< (ostream& o, Carne& x) {
    afisare(o, x.nume);
    afisare(o, (to_string(x.gramaj) + "g"));
    afisare(o, (to_string(x.pret) + " lei"));
    afisare(o, (to_string(x.cantitate) + " buc "));
    afisare(o, x.animal);
    return o;
}

class Lactate : public Aliment {
protected:
    int volum;
    int grasime;
public:
    Lactate(string a, unsigned int b, unsigned int c, unsigned int d, int v, int m) : Aliment(a, b, c, d) {
        volum = v;
        grasime = m;
    }
    friend ostream& operator<< (ostream& o, Lactate& x);
};
ostream& operator<< (ostream& o, Lactate& x) {
    char verif;
    if (x.volum == 0)
        verif = 'g';
    else verif = 'L';
    afisare(o, x.nume);
    afisare(o, (to_string(x.gramaj) + verif));
    afisare(o, (to_string(x.pret) + " lei"));
    afisare(o, (to_string(x.cantitate) + " buc"));
    afisare(o, (to_string(x.grasime) + "% grasime"));
    return o;
}

class Comanda {
private:
    int id;
    static int nr_comanda;
public:
    Comanda() {
        id = nr_comanda;
        nr_comanda++;
    }
    int getNrComanda() {
        return nr_comanda;
    }
};

int Comanda::nr_comanda = 0;

void stoc() {

    // DESIGN
    cout << "\n\n\n";
    cout << "\t                                       " << "STOC";
    cout << "\n";
    cout << "\t  ------------------------------------------------------------------------------------ \n";
    cout << "\t       NUME     |    CANTITATE    |     PRET     |    VALABIL   |    OBSERVATII       \n";
    cout << "\t  ------------------------------------------------------------------------------------ \n";
    // PRODUSE
    Alcool a("Vin", 2, 18, 50, 13.15);
    spatii(cout);
    cout << a << endl;
    Legume_Fructe c2("Avocado", 100, 6, 30, "Tara:Mexic");
    spatii(cout);
    cout << c2 << endl;
    Acidulate b("Pepsi", 2, 4, 80, "bautura carbogazoasa");
    spatii(cout);
    cout << b << endl;
    Lactate e1("Lapte", 2, 5, 30, 1, 2);
    spatii(cout);
    cout << e1 << endl;
    Carne d1("Piept", 500, 25, 13, "pui");
    spatii(cout);
    cout << d1 << endl;
    Lactate e2("Iaurt grecesc", 0, 40, 3, 50, 3);
    spatii(cout);
    cout << e2 << endl;
    Alcool a1("Bere", 1, 5, 40, 5);
    spatii(cout);
    cout << a1 << endl;
    Legume_Fructe c("Mere", 200, 12, 60, "Tara: Spania");
    spatii(cout);
    cout << c << endl;
    Alcool a2("Gin", 1, 2, 38, 40);
    spatii(cout);
    cout << a2 << endl;
    Legume_Fructe c1("Ceapa", 180, 3, 50, "Tara: Romania");
    spatii(cout);
    cout << c1 << endl;
    Acidulate b1("Sprite", 2, 4, 70, "bautura carbogazoasa");
    spatii(cout);
    cout << b1 << endl;
    Carne d("Muschiulet", 350, 23, 6, "porc");
    spatii(cout);
    cout << d << endl;
    Acidulate b2("Schweppes", 1, 5, 65, "bautura carbogazoasa");
    spatii(cout);
    cout << b2 << endl;
    Lactate e("Branza", 500, 10, 5, 0, 5);
    spatii(cout);
    cout << e << endl;

    cout << "\t --------------------------------------------------------------------------------------\n";
}

void comanda() {
    Comanda nr;
    stoc();
    cout << "\n\n";

    int zi, luna, an, cantitate, pret;
    string produs;

    cout << "Va rugam sa introduceti data: "; cin >> zi >> luna >> an;

    while (zi <= 0 or zi > 31 or luna <= 0 or luna > 12) {
        cout << endl << "DATA GRESITA! Va rugam sa reintroduceti data: ";
        cin >> zi >> luna >> an;
    }

    cout << endl << "Introduceti produsul pe care doriti sa-l cumparati: "; cin >> produs;
    cout << endl << "Introduceti cantitatea produsului: "; cin >> cantitate;
    cout << endl << "Introduceti pretul produsului: "; cin >> pret;

    // CITIRE RANDURI NR COMANDA PENTRU ID UNIC
    string txt;
    ifstream CitireComenzi("Comenzi.txt");
    while (getline(CitireComenzi, txt)) {
        getline(CitireComenzi, txt);
        getline(CitireComenzi, txt);
        getline(CitireComenzi, txt);
        getline(CitireComenzi, txt);
        getline(CitireComenzi, txt);
        getline(CitireComenzi, txt);
        getline(CitireComenzi, txt);
        Comanda* nr = new Comanda;
        delete nr;
    }
    CitireComenzi.close();

    //AFISARE
    cout << "\n\n";
    cout << " -----------------------" << endl;
    cout << " |COMANDA DUMNEAVOASTRA|" << endl;
    cout << " -----------------------" << endl;
    cout << "NR. COMANDA: " << nr.getNrComanda() << endl;
    cout << "DATA: " << zi << "." << luna << "." << an << endl;
    cout << "\nPRODUS COMANDAT: " << produs << endl;
    cout << "CANTITATE: " << cantitate << " buc" << endl;
    cout << "PRET: " << pret << " lei/buc" << endl;
    int total;
    total = cantitate * pret;
    cout << "\nTOTAL: " << total << " lei";
    cout << "\n";
    cout << "\n     COMANDA DVS VA AJUNGE IN 2-3 ZILE LUCRATOARE. VA MULTUMIM SI VA MAI ASTEPTAM!\n" << endl;

    // FISIER
    ofstream Comenzi;
    Comenzi.open("Comenzi.txt", ios::app);
    Comenzi << nr.getNrComanda() << endl;
    Comenzi << "Data: " << zi << "." << luna << "." << an << endl;
    Comenzi << "-----------------" << endl;
    Comenzi << "Produs: " << produs << endl;
    Comenzi << "Cantitate: " << cantitate << " buc" << endl;
    Comenzi << "Pret: " << pret << " lei/buc" << endl;
    Comenzi << "TOTAL: " << total << " lei" << endl;
    Comenzi << endl;
    Comenzi.close();

    system("pause");
    exit(0);
}


void returnare_produs() {
    // DESIGN
    cout << "\n";
    cout << "                        --------------------" << endl;
    cout << "                        | RETURNARE PRODUS |" << endl;
    cout << "                        --------------------" << endl;
    cout << "\n";

    int zi, luna, an;
    string nume_produs;

    cout << "Introduceti data: "; cin >> zi >> luna >> an;

    while (zi <= 0 or zi > 31 or luna <= 0 or luna > 12) {
        cout << endl << "DATA GRESITA! Va rugam sa reintroduceti data: ";
        cin >> zi >> luna >> an;
    }

    cout << endl << "Introduceti numele produsului pe care il doriti sa-l returnati: "; cin >> nume_produs;

    cout << "\n\n    COMANDA DVS VA FI RETURNATA. NE CEREM SCUZE PENTRU ORICE INCONVENIENTA. VA MAI ASTEPTAM!" << endl;

    // FISIER
    ofstream Returnare;
    Returnare.open("Returnari.txt", ios::app);
    Returnare << "Data: " << zi << "." << luna << "." << an << endl;
    Returnare << "Produs returnat: " << nume_produs << endl;
    Returnare << "----------------------------" << endl;
    Returnare.close();

    system("pause");
    exit(0);
}

void anulare_comanda() {
    system("cls");

    // DESIGN
    cout << "\n";
    cout << "                        -------------------" << endl;
    cout << "                        | ANULARE COMANDA |" << endl;
    cout << "                        -------------------" << endl;
    cout << "\n";

    int nr_comanda;
    cout << "Introduceti nr. comenzii: "; cin >> nr_comanda;

    cout << "\n\n        COMANDA DVS A FOST ANULATA. VA MAI ASTEPTAM!" << endl;

    //FISIER
    string deletetxt, txt;
    deletetxt = to_string(nr_comanda);
    ifstream StergereComenzi;
    StergereComenzi.open("Comenzi.txt");
    ofstream temp;
    temp.open("temp.txt");

    while (getline(StergereComenzi, txt)) {
        if (txt != deletetxt)
            temp << txt << endl;
        else {
            getline(StergereComenzi, txt);
            getline(StergereComenzi, txt);
            getline(StergereComenzi, txt);
            getline(StergereComenzi, txt);
            getline(StergereComenzi, txt);
            getline(StergereComenzi, txt);
            getline(StergereComenzi, txt);
        }
    }

    temp.close();
    StergereComenzi.close();
    remove("Comenzi.txt");
    rename("temp.txt", "Comenzi.txt");

    system("pause");
    exit(0);
}

// UTILIZATOR
class Utilizator {
    string username = "user";
    string pass = "utilizator";
public:
    string user;
    string parola;
    bool acces = false;
    Utilizator() {
    }
    void logare_c() {

        // DESIGN
        cout << "\n";
        cout << "\t          ------------\n";
        cout << "\t          |  LOGARE  |\n";
        cout << "\t          ------------\n";
        // LOGARE
        cout << "             username: ";
        cin >> user;
        cout << "             parola: ";
        char c;
        while (c = _getch(), c != 13) {
            cout << '*';
            parola += c;
        }
        if (c == 13) { //
            if (user == username && parola == pass) {
                cout << "\n----------------------------------------------------\n";
                cout << "           LOGARE REUSITA! BUN VENIT! :) ";
                acces = true;
                cout << "\n\n\t";
                system("pause");
            }
            else {
                cout << "\n----------------------------------------------------\n";
                cout << "                 ACCES INTERZIS!";
                cout << "\nNE PARE RAU, USERNAME - UL SI PAROLA NU SE POTRIVESC!" << endl;
                cout << "\n\n\t";
                system("pause");
                parola = ""; // goleste memoria
                cout << endl;
                system("cls");
                logare_c();
            }
        }
    }
};


// CHELTUIELI
class DataValComanda {
public:
    int luna;
    int an;
    int total;
    DataValComanda() {}
    friend ifstream& operator>> (ifstream& i, DataValComanda& d);
};

ifstream& operator>> (ifstream& i, DataValComanda& d) {
    string txt;
    string aux;
    string a;
    getline(i, txt);
    getline(i, txt);
    d.luna = stoi(txt.substr(9, 2));
    d.an = stoi(txt.substr(12, 4));
    getline(i, txt);
    getline(i, txt);
    getline(i, txt);
    getline(i, txt);
    getline(i, txt);
    aux = txt.substr(txt.find(" ") + 1);
    d.total = stoi(aux.substr(0, aux.find(" ")));
    getline(i, txt);

    return i;
}

void chelt_l() {
    int luna;
    cout << "\nIntroduceti luna: ";
    cin >> luna;
    cout << "\n";
    switch (luna) {
    case 1:
        cout << "TOTAL Ianuarie: ";
        break;
    case 2:
        cout << "TOTAL Februarie: ";
        break;
    case 3:
        cout << "TOTAL Martie: ";
        break;
    case 4:
        cout << "TOTAL Aprilie: ";
        break;
    case 5:
        cout << "TOTAL Mai: ";
        break;
    case 6:
        cout << "TOTAL Iunie: ";
        break;
    case 7:
        cout << "TOTAL Iulie: ";
        break;
    case 8:
        cout << "TOTAL August: ";
        break;
    case 9:
        cout << "TOTAL Septembrie: ";
        break;
    case 10:
        cout << "TOTAL Octombrie: ";
        break;
    case 11:
        cout << "TOTAL Noiembrie: ";
        break;
    case 12:
        cout << "TOTAL Decembrie: ";
        break;
    }
    ifstream Fisier;
    Fisier.open("Comenzi.txt");
    DataValComanda nr;
    int sum = 0;
    while (!Fisier.eof()) {
        Fisier >> nr;
        if (nr.luna == luna) {
            sum += nr.total;
        }
    }
    cout << sum << " lei" << endl;
}

void chelt_a() {
    int an;
    cout << "Introduceti anul: ";
    cin >> an;
    cout << "\n";
    cout << "TOTAL " << an << ": ";
    ifstream Fisier;
    Fisier.open("Comenzi.txt");
    DataValComanda nr;
    int sum = 0;
    while (!Fisier.eof()) {
        Fisier >> nr;
        if (nr.an == an) {
            sum += nr.total;
        }
    }
    cout << sum << " lei" << endl;
}

void utilizator() {
    // USERNAME + PAROLA
    Utilizator utilizator;
    utilizator.logare_c();
    system("cls");

    //DESIGN
    cout << "\n\n\n";
    cout << "\t--------------------------------------\n";
    cout << "\t|            UTILIZATORI             |\n";
    cout << "\t|       ----------------------       |\n";
    cout << "\t|      1. Cheltuieli lunare          |\n";
    cout << "\t|      2. Cheltuieli anuale          |\n";
    cout << "\t|      3. Iesire                     |\n";
    cout << "\t-------------------------------------\n";
    cout << "\t   " << "Introduceti alegerea dvs: ";

    int i;
    cin >> i;
    if (i == 1) {
        system("cls");
        chelt_l();
    }
    else if (i == 2) {
        system("cls");
        chelt_a();
    }
    else {
        cout << "\n";
        cout << "                VA MAI ASTEPTAM! " << endl;
        exit(0);
    }
}

// MENIU PRINCIPAL
void meniu_principal() {
    //DESIGN
    cout << "\n\n\n";
    cout << "\t" << "BINE ATI VENIT LA MAGAZINUL NOSTRU!";
    cout << "\n";
    cout << "\t----------------------------------\n";
    cout << "\t|             MENIU              |\n";
    cout << "\t|            -------             |\n";
    cout << "\t|      1. Adaugare comanda       |\n";
    cout << "\t|      2. Returnare produs       |\n";
    cout << "\t|      3. Anulare comanda        |\n";
    cout << "\t|      4. Utilizatori            |\n";
    cout << "\t|      5. Iesire                 |\n";
    cout << "\t----------------------------------\n";
    cout << "\t   " << "Introduceti alegerea dvs: ";

    int i;
    cin >> i;
    if (i == 1) {
        system("cls");
        comanda();
    }
    else if (i == 2) {
        system("cls");
        returnare_produs();
    }
    else if (i == 3) {
        system("cls");
        anulare_comanda();

    }
    else if (i == 4) {
        system("cls");
        utilizator();
    }
    else {
        system("cls");
        cout << "\n\n\n";
        cout << "       VA MAI ASTEPTAM! ";
        exit(0);
    }
}

int main() {
    meniu_principal();
    return 0;
}