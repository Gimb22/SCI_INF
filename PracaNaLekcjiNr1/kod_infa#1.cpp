#include <iostream>
#include <string>

using namespace std;

//Tworzenie programu umożliwiającego szyfrowanie wiadomości. 

string szyfr_cezara(string text, int klucz = 0) {
	if (klucz == 0) {
		cout << "Podaj klucz szyfrowania od 1 do 26: \n";
		cin >> klucz;
	}

	string output = "";

	int limit;
	if (klucz > 26 || klucz < 0) {
		return "Błąd, podałeś złą liczbę\n";
	}
	for (char& i : text) {
		limit = int(i) + klucz;
		i = limit % ('z' + 1);
		if (i > 'a' - 1) {
			output += i;
		}
		else {
			output += i + 'a';
		}
	}
	return output;
}

string szyfr_przestawieniowy(string text) {

    int dlugosc = text.length();
    if (dlugosc % 2 != 0) dlugosc -= 1;
	    for (int i = 0; i < dlugosc; i += 2) {
        char Char1 = text[i];
        char Char2 = text[i + 1];
        text[i] = Char2;
        text[i + 1] = Char1;
		}
    return text;
}

string oba(string text) {
	return szyfr_cezara(szyfr_przestawieniowy(text));
}

string odszyfrowanie(string text) {
    for (int i = 1; i < 27; i++) {
        cout << "Klucz: " << i << " tekst: " << szyfr_cezara(text, i) << endl;
    }
	return "koniec";
}

int main()
{
    setlocale(LC_CTYPE, "Polish");
    string ciag;
    char wybor;

    cout << "Podaj ciąg znaków: ";
    getline(cin, ciag);

    cout << "\nWybierz algorytm sortujący:";
    cout << "\n1. Szyfr cezara ";
    cout << "\n2. Szyfr przestawieniowy";
    cout << "\n3. Oba szyfry";
    cout << "\n4. Odszyfruj szyfr cezara\n\n";

    cin >> wybor;
	switch (wybor)
	{
	case '1':
		cout << szyfr_cezara(ciag) << endl;
		break;
	case '2':
		cout << szyfr_przestawieniowy(ciag) << endl;
		break;
	case '3':
		cout << oba(ciag) << endl;
		break;
	case '4':
		cout << odszyfrowanie(ciag) << endl;
		break;
	default:
		cout << "co?\n";
		break;
	}
}
