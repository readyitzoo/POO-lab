#include <iostream>

using namespace std;

class Durata{
    int minute, secunde;
public:
    Durata(){
        minute = 0;
        secunde = 0;
        cout << "durata = 0" ;
    }
    Durata (int min, int sec){
        this -> minute = min;
        this -> secunde = sec;
    }

};

class Masina{
    bool libera;
    Durata timp;
    int capsule;

public:

    Masina (){
        libera = 1;
        capsule = 0;
    }
    Masina (bool a, Durata d, int nr)
    {
        libera = a;
        timp = d;
        capsule = nr;
    }

    bool get_libera(){
        return libera;
    }
    int get_capsule(){
        return capsule;
    }
    Durata get_timp(){
        return timp;
    }

};

class Spalatorie {
    int n;
    int masini[];

public:
    Spalatorie (){
        n = 0;
    }
    Spalatorie (int _n, int m[]){
        this -> n = _n;
//        for (int i = 0 ; i < n; i ++)
//            this -> masini[i] = m[i];
    }
    void listeazaMasini ();

    void adaugaJob(int)

};


void Spalatorie::listeazaMasini(){
        for (int i = 0 ; i < n; i ++){
            cout << "Masina " << i << " este";
            int caps = Masina::get_capsule(masini[i]);
            int min = masini[i].get_timp();
            if (Masina::get_libera(i) == 1) (Masina::get_capsule(masini[i]) > 0)
                cout << " libera\n";
            else if (Masina::get_timp)
        }
    }


int main()
{

    return 0;
}
