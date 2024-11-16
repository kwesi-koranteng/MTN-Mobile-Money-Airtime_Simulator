#include<iostream>
#include "secondRectangleClass.cpp"

using namespace std;



int main(){
	
	Rectangle rect;
	
	double length;
	double width;
	
	cout <<"*******************************************";
	cout << "\n\tAn Area Calculator" << endl;
	cout <<"*******************************************"<< endl;
	cout << "                                          "<< endl;
	cout << "\tTHE DIMENSIONS OF A RECTANGLE"<< endl;
	cout << "Enter the length of the rectangle: ";
	cin >> length;
	cout << "Enter the width of the rectangle: ";
	cin >> width;
	
	rect.setLength(length);
	rect.setWidth(width);
	
	cout << "\n\n The information is as follows :)"<< endl;

	cout << "_______________________________________" << endl;	
	cout << "Length\t\t|Width\t\t|Area"<< endl;
	cout << "_______________________________________" << endl;
	cout << rect.getLength() << "\t\t"<< rect.getWidth() << "\t\t"<< rect.getArea();

	

	
	return 0;
}
