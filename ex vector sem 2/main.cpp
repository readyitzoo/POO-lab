#include <iostream>
#include <climits>

using namespace std;

class Vector {
    int *a;
    int n;
    int maxim_admis;

public:
    Vector(){
        n = 0;
        a = new int[maxim_admis];
        maxim_admis = 1000;
    }

    Vector (int n, int v[])
    {
        a = new int[n] ;
        this -> n = n;
        maxim_admis = n;
        for (int i = 0; i < this -> n; i ++)
            a[i] = v[i];
    }

    Vector (Vector &);

    ~Vector ();

    void inserare (int);

    friend void afisare (Vector);

    void sterge ();

    int nrElem ();

    int pozElem(int);
};

inline Vector::~Vector(){
    delete[] a;
    n = 0;
    maxim_admis = 0;
}

Vector::Vector(Vector &v){
    n = v.n;
    maxim_admis = v.maxim_admis;
    a = new int [maxim_admis];
    for (int i=0; i < n; i++)
        a[i] = v.a[i];
}

void Vector::inserare(int x)
{
    if (n+1 > maxim_admis)
        {
            maxim_admis += 4;
            int *p;
            p = new int[maxim_admis];
            for (int i = 0; i < n; i++)
                p[i] = a[i];
            delete[] a;
            a = p;
            a[n++] = x;
        }
    else
        a[n++] = x;

}

void afisare (Vector afis)
{
    for (int i=0; i = afis.n; i++)
        cout<< afis.a[i] << " ";
    cout<< endl;
}

void Vector::sterge()
{
    if (n==0){
        cout<< "nu exista elemente in vector!\n";
        return;
    }
    --n;

}

int Vector::nrElem(){
    cout << n << endl;
}

int Vector::pozElem(int i){
    if (i < 0 || i >= n)
    {
        cout << "Pozitia" << i << "nu exista in vector \n";
        return INT_MAX;
    }
    return a[i];
}

int main()
{

    return 0;
}
