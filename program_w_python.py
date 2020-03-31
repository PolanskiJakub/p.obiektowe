import linecache


class samochod:
    def __init__(self,marka,model,typ_skrzyni,rocznik,pojemnosc,przebieg):
        self.marka = marka
        self.model = model
        self.typ_skrzyni = typ_skrzyni
        self.rocznik = rocznik
        self.pojemnosc = pojemnosc
        self.przebieg = przebieg
    def przypisanie(self):
        print('Podaj marke')
        self.marka=input()
        print('Podaj model')
        self.model = input()
        print('Podaj typ skrzyni biegow')
        self.typ_skrzyni=input()
        print('Podaj rocznik')
        self.rocznik=input()
        print('Podaj pojemnosc')
        self.pojemnosc=input()
        print('Podaj przebieg')
        self.przebieg=input()
    def dodanie_auta(self):
        plik = open('plik', 'a')
        plik.write("\n")
        plik.write("Marka" + "\n")
        plik.write(self.marka)
        plik.write("\n")
        plik.write("Model" + "\n")
        plik.write(self.model)
        plik.write("\n")
        plik.write("Typ skrzyni biegow" + "\n")
        plik.write(self.typ_skrzyni)
        plik.write("\n")
        plik.write("Rocznik" + "\n")
        plik.write(self.rocznik)
        plik.write("\n")
        plik.write("Pojemnosc" + "\n")
        plik.write(self.pojemnosc)
        plik.write("\n")
        plik.write("Przebieg" + "\n")
        plik.write(self.przebieg)
        plik.write("\n")
        plik.write("\n")
        plik.close()

def zlicznie():
    liczba = 0
    file = open('plik', 'r').read()
    lines = file.split('\n')
    for line in lines:
        if line == "Marka":
            liczba+=1
    return liczba+1

def numeracja(liczba):
    plik = open('plik', 'a')
    plik.write(str(liczba))
    plik.close()

def wyswietlanie():
    file = open('plik', 'r').read()
    lines = file.split('\n')
    for line in lines:
        print(line)

def wyswietlanie_warunkowe(liczba):
    k=0
    y = 11
    for z in range(0,liczba):
        tablica=linecache.getline('plik', y)
        if int(tablica)>2000:
            for x in range(0+k*14,14+k*14):
                wiersz = linecache.getline('plik', x)
                print(wiersz)
                if x==13+k*14:
                    k=k+14
        if int(int(tablica)<2000):
            k=k+14
        y+=14

def wyswietlanie_pojedynczego():
    print("Wybierz numer auta ktore chcesz wyswietlic" +"\n")
    x=input()
    for z in range(0+int(x)*14-14,14+14*int(x)-14):
        wiersz = linecache.getline('plik', z)
        print (wiersz)

def sortowanie(liczba):
    linijki = []
    rocznik = []
    ilosc = []
    import linecache
    file = open('plik', 'r').read()
    lines = file.split('\n')
    for z in range(0,liczba):
        rocznik.append(linecache.getline('plik', 9 + z * 14))
    for y in range(0,liczba):
        ilosc.append(rocznik[y])
    for i in range(len(rocznik) - 1, 0, -1):
        for j in range(i):
            if rocznik[j] > rocznik[j + 1]:
                rocznik[j], rocznik[j + 1] = rocznik[j + 1], rocznik[j]

    for z in range(0,liczba):
        print(rocznik[z])
    for x in range(0,liczba):
        for y in range(0,liczba):
            if(rocznik[x]==ilosc[y]):
                for z in range(0 + y*14, 14 + 14 * y):
                    wiersz = linecache.getline('plik', z)
                    print(wiersz)

def usuwanie(liczba):
    tab = []
    file = open('plik', 'r').read()
    lines = file.split('\n')
    for line in lines:
        tab.append(line)
    print("Prosze podac numer auta do usuniecia")
    a = input()
    zrodlo = open('plik').readlines()
    cel = open('plik', 'w')
    for s in zrodlo:
        for x in range(0,13):
            cel.write(s.replace(tab[x+ int(a)*14],"\n"))
    cel.close()



def main():
    auto = samochod("Audi", "Rs7", "Automatyczny", "2017", "4000", "200000")
    while True:
        print ("====================================================================================" + "\n")
        print ("|                                    MENU                                          |" + "\n")
        print ("|     1. Wprowadzanie danych nowego samochodu                                      |" + "\n")
        print ("|     2. Wyswietlanie listy samochodow                                             |" + "\n")
        print ("|     3. Wyswietlanie warunkowe listy samochodow(wiecej niz 2000 pojemnosci)       |" + "\n")
        print ("|     4. Wyswietlanie danych pojedynczego samochodu                                |" + "\n")
        print ("|     5. Posortowanie samochodow po wybranym parametrze                            |" + "\n")
        print ("|     6. Usuniecie samochodu z katalogu                                            |" + "\n")
        print ("|     7. Zakonczenie programu                                                      |" + "\n")
        print ("====================================================================================" + "\n")
        b = input()
        if b == "1":
            auto.przypisanie()
            liczba = zlicznie()
            numeracja(liczba)
            auto.dodanie_auta()
            continue
        if b == "2":
            wyswietlanie()
            continue
        if b == "3":
            liczba = zlicznie()
            wyswietlanie_warunkowe(liczba)
            continue
        if b == "4":
            wyswietlanie_pojedynczego()
            continue
        if b == "5":
            liczba =zlicznie()
            sortowanie(liczba)
        if b == "6":
            #liczba=zlicznie()
            usuwanie_d()
        if b == "7":
            break



    #print(liczba)
if __name__ == '__main__':
    main()

