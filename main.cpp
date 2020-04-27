#include <iostream>
#include <vector>
#include "Markup.h"
#include "Finanse.h"
#include "DataMenager.h"
#include "ExpenseMenager.h"

using namespace std;

int main() {

    char wybor;
    Finanse finanse("Users.xml","Income.xml","Expense.xml");

    while(true)
    {
        if(finanse.czyUzytkownikJestZalogowany()==false)
        {
            wybor = finanse.wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                finanse.rejestracjaUzytkownika();
                break;
            case '2':
                finanse.logowanieUzytownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout<<endl<<"Nie ma takiej opcji w menu."<<endl<<endl;
                system("pause");
                break;
            }
        }
        else
        {
            wybor = finanse.wybierzOpcjeZMenuUzytkownika();
            switch (wybor)
            {
            case '1':
                finanse.dodajIncome();
                break;
            case '2':
                finanse.dodajItem();
                break;
            case'3':
                finanse.sortowanie();
                finanse.wyswietlItemyZTegoMiesiaca();
                finanse.obliczWydatkiZObecnegoMiesiaca();
                system("pause");
                break;
            case '4':
                finanse.sortowanie();
                finanse.wyswietlItemyZPoprzedniegoMiesiaca();
                finanse.obliczWydatkiZPoprzedniegoMiesiaca();
                system("pause");
                break;
            case '5':
                finanse.sortowanie();
                finanse.wyswietlItemyZPodanegoZakresu();
                system("pause");
                break;
            case '6':
                finanse.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '7':
                finanse.wylogowanieZalogowanegoUzytkownika();
                break;
            }
        }
    }
    return 0;
}
