#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <cstdio>
using namespace std;

class samochod
{
private:
    string marka,model,typ_skrzyni;;
    int rocznik;
    float pojemnosc;
    long int przebieg;
public:
    void przypisanie()
    {
    cout<<"Prosze podac marke"<<endl;
    cin>>marka;
    cout<<"Prosze podac model"<<endl;
    cin>>model;
    cout<<"Prosze podac typ skrzyni biegow"<<endl;
    cin>>typ_skrzyni;
    cout<<"Prosze podac rocznik"<<endl;
    cin>>rocznik;
    cout<<"Prosze podac pojemnosc"<<endl;
    cin>>pojemnosc;
    cout<<"Prosze podac przebieg"<<endl;
    cin>>przebieg;
    }
    void dodanie(int liczba_aut)
    {
    ofstream plik_tekstowy;
    plik_tekstowy.open("D:/plik tekstowy/plik_tekstowy.txt",ios_base::app);
    plik_tekstowy<<liczba_aut+1<<endl;
    plik_tekstowy<<"marka"<<endl<<marka<<endl<<"model"<<endl<<model<<endl<<"typ skrzyni biegow"<<endl<<typ_skrzyni<<endl<<"rocznik"<<endl<<rocznik<<endl;
    plik_tekstowy<<"pojemnosc"<<endl<<pojemnosc<<endl<<"przebieg"<<endl<<przebieg<<endl<<endl;
    }

};
void wyswielenie_warunkowe(int liczba_aut)
{
    int x=0,y=1,b=0;
    string linia,slowo;
    string *tablica_stringow2= new string[liczba_aut*12+1];
    int *tablica= new int[liczba_aut];
    int *prawda= new int[liczba_aut];
    ifstream plik_tekstowy("D:/plik tekstowy/plik_tekstowy.txt");
    if(plik_tekstowy)
    {
        while(getline(plik_tekstowy, linia))
        {


            if(linia=="pojemnosc")
            {
            getline(plik_tekstowy, linia);
            tablica[x]=strtol(linia.c_str(),NULL,10);
            if(tablica[x]>2000)
            {
                prawda[x]=1;
            }
            if(tablica[x]<=2000)
            {
                prawda[x+1]=0;
            }
            x++;
        }
        }
       }
    ifstream plik("D:/plik tekstowy/plik_tekstowy.txt");
    if(plik)
    {
        while(getline(plik,linia))
        {
           string tmp;
            sprintf((char*)tmp.c_str(), "%d", y);
            string str = tmp.c_str();
            if(linia==str)
                {
                    for(int z=0+b;z<12+b;z++)
                    {
                        getline(plik,linia);
                        tablica_stringow2[z]=linia;
                    }
                    b=b+12;
                    y++;
                }
        }
    }
    for(int a=0;a<liczba_aut;a++)
    {
        if(prawda[a]==1)
            {
                for(int z=0+12*a;z<12+12*a;z++)
                    {
                        cout<<tablica_stringow2[z]<<endl;
                    }
            }
    }


}
void wyswietlanie_podanego_auta(string liczba)
{
  ifstream plik_tekstowy("D:/plik tekstowy/plik_tekstowy.txt");
 if(plik_tekstowy)
    {
        string linia;
        while(getline(plik_tekstowy, linia))
        {
            if(linia==liczba)
                for(int x=0;x<12;x++)
            {
                getline(plik_tekstowy, linia);
                cout<<linia<<endl;
            }


        }
    }
}
void wyswielenie()
{
    int liczba_aut=0;
    ifstream plik_tekstowy("D:/plik tekstowy/plik_tekstowy.txt");
 if(plik_tekstowy)
    {
        string linia;
        while(getline(plik_tekstowy, linia))
        {
            if(linia=="marka")
                liczba_aut++;
            cout << linia << endl;
        }
    }
    else
    {
        cout << "B£¥D: nie mozna otworzyc pliku do odczytu." << endl;
    }
    cout<<"Ilosc samochodow wynosi w liscie wynosi: "<<liczba_aut<<endl;

}
void ilosc_aut(int &liczba_aut)
{
    liczba_aut=0;
    ifstream plik_tekstowy("D:/plik tekstowy/plik_tekstowy.txt");
 if(plik_tekstowy)
    {
        string linia;
        while(getline(plik_tekstowy, linia))
        {
            if(linia=="marka")
                liczba_aut++;
        }
    }

}
void sortowanie_wzgledem_roku(int liczba)
{
    int x=0,y=1,b=0;
    int *roczniki = new int[liczba];
    string *tablica_string = new string[liczba*12+1];
    int *tablica= new int[liczba];
    ifstream plik_tekstowy("D:/plik tekstowy/plik_tekstowy.txt");
 if(plik_tekstowy)
    {
        string linia;
        while(getline(plik_tekstowy, linia))
        {
            if(linia=="rocznik")
                {
                    getline(plik_tekstowy, linia);
                    tablica[x]=strtol(linia.c_str(),NULL,10);
                    roczniki[x]=tablica[x];
                    x++;
                }

        }
    }
    ifstream plik("D:/plik tekstowy/plik_tekstowy.txt");
    if(plik)
    {
        string linia;
        while(getline(plik, linia))
        {
            string tmp;
            sprintf((char*)tmp.c_str(), "%d", y);
            string str = tmp.c_str();
            if(linia==str)
                {
                    for(int z=0+b;z<12+b;z++)
                    {
                        getline(plik,linia);
                        tablica_string[z]=linia;
                    }
                    b=b+12;
                    y++;
                }
        }

    }
    for(int i=0;i<liczba;i++)
		for(int j=1;j<liczba-i;j++)
		if(tablica[j-1]>tablica[j])
			swap(tablica[j-1], tablica[j]);
        for(int o=0;o<liczba;o++)
        {
            for(int i=0;i<liczba;i++)
            {
                if(tablica[o]==roczniki[i])
                for(int z=0+12*i;z<12+12*i;z++)
                {
                    cout<<tablica_string[z]<<endl;
                }
            }

}
delete tablica;
delete roczniki;
delete tablica_string;

}
void usuniecie_auta(string liczba)
{
    string a;
    string linia;
  ifstream plik_tekstowy("D:/plik tekstowy/plik_tekstowy.txt");
 if(plik_tekstowy)
    {
        cout<<linia<<endl;
        while(getline(plik_tekstowy, linia))
        {
            cout<<linia<<endl;
            if(linia==liczba)
                for(int x=0;x<12;x++)
            {
                getline(plik_tekstowy, linia);
                plik_tekstowy>>a;
            }


        }
    }
}




int main()
{
    int liczba_aut=0;
    int b;
    string c;
    samochod autoM;
    cout<<"Autor: Jakub Polanski "<<endl;
	do{
    cout<<"===================================================================================="<<endl;
	cout<<"|                                    MENU                                          |"<<endl;
	cout<<"|     1. Wprowadzanie danych nowego samochodu                                      |"<<endl;
	cout<<"|     2. Wyswietlanie listy samochodow                                             |"<<endl;
	cout<<"|     3. Wyswietlanie warunkowe listy samochodow(wiecej niz 2000 pojemnosci)       |"<<endl;
	cout<<"|     4. Wyswietlanie danych pojedynczego samochodu                                |"<<endl;
	cout<<"|     5. Posortowanie samochodow po wybranym parametrze                            |"<<endl;
	cout<<"|     6. Usuniecie samochodu z katalogu                                            |"<<endl;
	cout<<"|     7. Zakonczenie programu                                                      |"<<endl;
	cout<<"===================================================================================="<<endl;
	cin>>b;
	switch(b)
	{
	case 1:
	    ilosc_aut(liczba_aut);
        autoM.przypisanie();
        autoM.dodanie(liczba_aut);
        break;
	case 2:
        wyswielenie();
		break;
	case 3:
	    ilosc_aut(liczba_aut);
        wyswielenie_warunkowe(liczba_aut);
        break;
    case 4:
        cout<<"Podaj numer auta ktore chcesz wyswietlic"<<endl;
        cin>>c;
        ilosc_aut(liczba_aut);
        wyswietlanie_podanego_auta(c);
    	break;
 	case 5:
        ilosc_aut(liczba_aut);
        sortowanie_wzgledem_roku(liczba_aut);
 	    break;
    case 6:
        cout<<"Prosze podac numer auta do usuniecia"<<endl;
        cin>>c;
        ilosc_aut(liczba_aut);
        usuniecie_auta(c);
        break;
 	    }
}while(b!=7);





    return 0;
}
