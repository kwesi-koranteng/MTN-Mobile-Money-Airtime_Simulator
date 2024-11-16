#include <iostream>

using namespace std;


string firstname(){
	string fname;
	cout << "Enter your first name: "<< endl;
	cin >>  fname;
	return fname;	
}

bool validation(int a){
	return (a >= 1 && a <= 3);
}

string option(){
	int a;
	string surname[] = {"Opuku", "Barak", "Adambro"};
	cout <<"Select a surname from 3 options"<< endl;
 	cout << "1. Opuku\n2. Barak\n3. Adambro\n";
 	cout << "Answer: "<< endl;
    cin >> a;
    
    
	if(validation(a)){
		return surname[a - 1];
	}else{
		cout<< "Invalid input! Pick 1-3" << endl;
		exit(0);
	}
	
	
	
}

int main(){
	
	string firstn = firstname();
	
	string secondn = option();
	
	cout << firstn << " " << secondn << endl; 
	
	
	
	
	return 0;
}
