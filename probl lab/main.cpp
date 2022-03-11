#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Film {
    string titlu;
    int likes;

public:
    string getTitlu(){
        return titlu;
    }
    int getLikes(){
        return likes;
    }
    void setTitlu(string _titlu){
        Film::titlu = _titlu;
    }
    void setLikes(int _likes){
        Film::likes = _likes;
    }

    Film(){
        titlu = "-";
        likes = -1;
    }

    Film (string _titlu, int _likes)
    {
        titlu = _titlu;
        likes = _likes;
    }

    void citeste()
    {
        getline(cin, titlu);
        cin>> likes;
        cin.get();
    }


};

bool compara(int a, int b, Film filme[])
{
    int A = filme[a].getLikes();
    int B = filme[b].getLikes();
    return A>B;
}

void afisarePopulare (int n, Film filme[], int k)
{
    int i=0, j=0;
    for (i; i<n-1; i++)
        for (j = i+1; j<n; j++)
        {
            if (filme[i].getLikes() < filme[j].getLikes())
            {
                Film aux;
                aux = filme[i];
                filme[i] = filme[j];
                filme[j] = aux;
            }
        }
    for (i = 0; i < k; i++)
    {
        cout << filme[i].getTitlu() << " " << filme[i].getLikes() << endl;
    }

}

int main()
{
    int n, i;
    cin>>n;
    cin.get();
    Film f[n];
    for (i=0; i<n; i++) {
        f[i].citeste();
        int l = f[i].getLikes();
        string t = f[i].getTitlu();
        cout << l << " " << t << endl;
    }
    afisarePopulare(n, f, 2);
    return 0;
}
