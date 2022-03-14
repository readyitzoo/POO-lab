#include <iostream>

using namespace std;

class Durata{
    int minute, secunde;
public:
    Durata(){
        this -> minute = 0;
        this -> secunde = 0;
    }
    Durata (int m, int s){
        this -> minute = m;
        this -> secunde = s;
    }
    void set_time(int m, int s){
        this -> minute = m;
        this -> secunde = s;
    }
    struct timp{
        int m, s;
    };
    timp get_time(){
        timp t;
        t.m = this -> minute;
        t.s = this -> secunde;
        return t;
    }


};

class Masina{
    bool libera;
    Durata timp;
    int capsule;

public:
    Masina (){
        libera = true;
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
//    void set_libera(){
//        timp.minute = 0;
//        timp.secunde = 0;
//    }
    int get_capsule(){
        return capsule;
    }

    Durata get_timp(){
        return timp;
    }

};

class Spalatorie {
    int n;
    Masina masini[];

public:
    Spalatorie (){
        n = 0;
    }
    Spalatorie (int _n, Masina m[]){
        this -> n = _n;
        for (int i = 0 ; i < n; i ++)
            this -> masini[i] = m[i];
    }
    Masina get_masina (int i){
        return masini[i];
    }
    int get_n(){
        return n;
    }
    void listeazaMasini ();

    void adaugaJob(int);

};


void Spalatorie::listeazaMasini(){
        for (int i = 0 ; i < n; i ++){
            cout << "Masina " << i << " este";
            Durata::timp m = masini[i].get_timp().get_time();
            if (masini[i].get_libera() == true)
                if (masini[i].get_capsule() > 0)
                    cout << " e libera\n";
                else cout<< " neutilizabila! Nu mai are capsule!\n";
            else
                if (m.s < 10)
                    cout << " ocupata pentru inca " << m.m << ":" << "0" << m.s <<"\n";
                else
                    cout << " ocupata pentru inca " << m.m << ":" << m.s <<"\n";
        }
    }

void listeazaMasiniLibere(Spalatorie &spalatorie)
{
    int i;
    int n = spalatorie.get_n();
    cout << "Urmatoarele masini sunt libere: ";
    for (i = 0; i < n; i ++)
    {
        Masina m = spalatorie.get_masina(i);
        if (m.get_libera() == true)
            cout << i << " ";
    }
    cout << endl;

}
int main()
{
     Masina masini[5] = {
           Masina(true, Durata(0, 0), 3),
           Masina(true, Durata(0, 0), 0),
           Masina(false, Durata(1, 17), 5),
   };

   Spalatorie spalatorie(
           3,
           masini
   );
      listeazaMasiniLibere(spalatorie);
   spalatorie.listeazaMasini();


    return 0;
}
