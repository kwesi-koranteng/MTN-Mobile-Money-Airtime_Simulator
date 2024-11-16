#include <iostream>
#include <fstream>

using namespace std;


int main(){

    string line;

    ifstream readFromFile("kwesi.txt");

    if(readFromFile.is_open()){
        getline(readFromFile, line);
        cout << line << endl;

        while(getline(readFromFile, line)){
        cout << line << endl;
        }

    }

    readFromFile.close();


    return 0;

}


