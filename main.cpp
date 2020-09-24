//Абдыкеримов Урмат Эмирбекович М8О-206Б-19

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void toLower(string& s) {
	for(auto& it: s) {
		it = tolower(it);
	}
}

class Address {
public:
	Address();
	Address(string, string, int, int);
	Address(const Address&);

	bool inCity(string);
	bool inStreet(string);
	
	bool operator== (const Address&);
	bool operator& (const Address&);

	void print();

private:
	string city;
	string street;
	int house;
	int apartment;
};

Address::Address() {
	city = "";
	street = "";
	house = 0;
	apartment = 0;
}

Address::Address(string c, string s, int h, int a) {
	toLower(c);
	toLower(s);
	city = c;
	street = s;
	house = h;
	apartment = a;
}

Address::Address(const Address& rhs) {
	city = rhs.city;
	street = rhs.street;
	house = rhs.house;
	apartment = rhs.apartment;
}

bool Address::inCity(string c) {
	return (c == city);
}

bool Address::inStreet(string s) {
	return (s == street);
}

bool Address::operator== (const Address& val) {
	return (val.city == city && street == val.street && house == val.house && apartment == val.apartment);
}

bool Address::operator& (const Address& val) {
	return (val.city == city && street == val.street && abs(house - val.house) == 1);	
}

void wht_clr(string& s) {
	while(*s.begin() == ' ') {
		s.erase(0, 1);
	}
	while(*s.rbegin() == ' ') {
		s.erase(s.size() - 1, 1);
	}
}

void Address::print() {
	cout << city << " " << street << " " << house << " " << apartment << endl;
}

Address operator"" _adrs(const char* val, unsigned) {
	string fl = val;
	wht_clr(fl);

	string city = fl.substr(0, fl.find(","));
	toLower(city);
	fl.erase(0, fl.find(",") + 1);
	wht_clr(city);
	wht_clr(fl);
	
	string street = fl.substr(0, fl.find(","));
	toLower(street);
	fl.erase(0, fl.find(",") + 1);
	wht_clr(street);
	wht_clr(fl);

	int house = atoi(fl.substr(0, fl.find(",")).c_str());
	fl.erase(0, fl.find(",") + 1);
	wht_clr(city);
	wht_clr(fl);
	
	int apartment = atoi(fl.c_str());
	return Address(city, street, house, apartment);
}
main() {
	
	Address a1 = "London,Baker,   26,     13"_adrs;
	cout << "First address is ";
	a1.print();

	string city, street;
	int house, apartment;
	cout << "Enter second address " << endl;
	cin >> city >> street >> house >> apartment;

	Address a2(city, street, house, apartment);

	cout << "Second address is ";
	a2.print();

	cout << "Equal : " << (a2 == a1) << endl;

	cout << "Enter city to check" << endl;
	cin >> city;
	cout << "Is address in city \"" << city << "\" " << a2.inCity(city) << endl;

	cout << "Enter street to check" << endl;
	cin >> street;
	cout << "Is address in street \"" << street << "\" " << a2.inStreet(street) << endl;

	cout << "Two addresses are near " << (a1 & a2) << endl;
}
