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

    int get_min(){
        return this -> minute;
    }
    int get_sec(){
        return this -> secunde;
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
    void set_libera(bool b){
        this -> libera = b;
    }
    int get_capsule(){
        return capsule;
    }
    void decr_capsule(){
        this -> capsule -- ;
    }
    Durata get_timp(){
        return timp;
    }
    void set_timp(int m, int s){
        this -> timp.set_time(m, s);
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

    void actualizeazaTimp(Durata);

    void listeazaMasini ();

    void adaugaJob(int, Durata);


};

void Spalatorie::adaugaJob(int nr, Durata spalare)
{
    int mm = masini[nr].get_timp().get_min();
    int ms = masini[nr].get_timp().get_sec();
    int a = spalare.get_min(), b = spalare.get_sec();
    int caps = masini[nr].get_capsule();
    if (caps == 0 )
    {
        cout << "Masina " << nr << " nu mai are capsule!\n";
        return;
    }else {
        masini[nr].decr_capsule();
        masini[nr].set_libera(0);
        masini[nr].set_timp(mm + a, ms + b);
    }
}
void Spalatorie::actualizeazaTimp (Durata d){
        int i=0;
        for (i; i < this -> n; i++)
        {
            int mm = masini[i].get_timp().get_min();
            int ms = masini[i].get_timp().get_sec();
            int caps = masini[i].get_capsule();
            bool libera = masini[i].get_libera();
            int ok1 = 1, ok2 = 1;
            if (mm - d.get_min() < 0){
                masini[i].set_libera(1);
                masini[i].set_timp(0,0);
            }else
                if (mm - d.get_min() == 0){
                    if (ms - d.get_sec() <= 0){
                        masini[i].set_libera(1);
                        masini[i].set_timp(0,0);
                    }else {
                        masini[i].set_timp(mm - d.get_min(), ms - d.get_sec());
            }
                }
                else {
                    masini[i].set_timp(mm - d.get_min(), ms - d.get_sec());
            }

        }
    }


void Spalatorie::listeazaMasini(){
     cout << "Spalatoria in prezent : \n";
        for (int i = 0 ; i < n; i ++){
            cout << "Masina " << i << " este";
            Durata m = masini[i].get_timp();
            int mm = m.get_min(), ms = m.get_sec();
            if (masini[i].get_libera() == true)
                if (masini[i].get_capsule() > 0)
                    cout << " e libera\n";
                else cout<< " neutilizabila! Nu mai are capsule!\n";
            else
                if (ms < 10)
                    cout << " ocupata pentru inca " << mm << ":" << "0" << ms <<"\n";
                else
                    cout << " ocupata pentru inca " << mm << ":" << ms <<"\n";
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
       Masina(true, Durata(0, 0), 2),
       Masina(true, Durata(0, 0), 5),
    };
    Spalatorie spalatorie(
           3,
           masini
    );

    spalatorie.listeazaMasini();
    listeazaMasiniLibere(spalatorie);

    spalatorie.adaugaJob(
           1,
           Durata(1, 20)
    );
    spalatorie.listeazaMasini();

    spalatorie.actualizeazaTimp(Durata(1, 19));
    spalatorie.listeazaMasini();

    spalatorie.actualizeazaTimp(Durata(1, 0));
    spalatorie.listeazaMasini(); // metoda

    // adaugam inca o spalare la masina 1, ca sa ramana fara capsule
    spalatorie.adaugaJob(
           1,
           Durata(0, 35)
    );
    spalatorie.actualizeazaTimp(Durata(3, 0));

    // Incercam sa adaugam inca o spalare. Ar trebui sa afiseze mesajul "Masina 1 nu mai are capsule!"
    spalatorie.adaugaJob(
           1,
           Durata(0, 35)
    );
    // Ceea ce se poate observa si din listarea masinilor:
    spalatorie.listeazaMasini();


    return 0;
}
