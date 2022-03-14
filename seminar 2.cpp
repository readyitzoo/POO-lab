#include <iostream>

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


}

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

int main()
{

    return 0;
}