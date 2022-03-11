#include <iostream>
#include <cstring>

using namespace std;

class Bilet{
    string nume;
    bool clasa1;

public:
    Bilet(){
        nume = "-";
        clasa1 = 0;
    }
    Bilet(string _nume, bool _clasa1) {
        nume = _nume;
        clasa1 = _clasa1;
    }

    string getNume() {
        return nume;
    }
    void setNume(string _nume) {
        Bilet::nume = _nume;
    }

    void citeste () {
        getline(cin, nume);
        cin >> clasa1;
        cin.get();

    }

    int getClasa(){
        return clasa1;
    }

};

void statisticaZboruri (int n, Bilet bilete[]) {
    int zbor = 0;
    for (int i = 0; i < n; i ++)
    {
        int c1 = bilete[i].getClasa();
        if (c1 == true)
            zbor++;
    }
    cout << "Avem " << zbor << " bilete la clasa I, dar si " << n-zbor << " bilete la alte clase";
}

int main()
{

    int n;
    cin >> n;
    cin.get();
    Bilet b[11];
    for (int i = 0; i < n; i ++)
        b[i].citeste();
    for (int i = 0; i < n; i ++){
        string num = b[i].getNume();
        bool clasa1 = b[i].getClasa();
        cout<< num << " " << clasa1 << endl;
    }


    Bilet bilete[] =
            {
                    Bilet("Popescu Leuraș", true),
                    Bilet("Manolescu Alexandra", true),
                    Bilet("Popescu Mănăila", true)
            };
    statisticaZboruri(3, bilete);
    return 0;
}
