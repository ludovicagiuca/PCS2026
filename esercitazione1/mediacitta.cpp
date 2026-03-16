#include <fstream>
#include <iostream>

using namespace std;

int main(void) {
    cout << "Inserisci file (es: file.txt): \n";
    string filename;
    cin >> filename;
    ifstream ifs(filename);
    if ( ifs.is_open() ) {
        string citta;
        double temp1;
        double temp2;
        double temp3;
        double temp4;
        while (ifs >> citta >> temp1 >> temp2 >> temp3 >> temp4) {
            double media = (temp1+temp2+temp3+temp4)/4;
            cout << citta << " " << media << "\n";
        }
    }
    else {
        cerr <<"Impossibile aprire il file\n";
    }
    return 0;
}