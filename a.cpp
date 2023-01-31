#include <iostream>
#include <cstring>
using namespace std;

enum yn {no, yes};
enum color {red, yellow, green, orange};

void out(enum yn x);
char *c[] = {"red", "yellow", "green", "orange"};

class fruit {
public:
	enum yn annual;
	enum yn perennial;
	enum yn tree;
	enum yn tropical;
	enum color clr;
	char name[40];
};

class Apple : public fruit {
	enum yn cooking;
	enum yn crunchy;
	enum yn eating;
public:
	void seta(char *n, enum color c, enum yn ck, enum yn crchy, enum yn e);
	void show();
};

class Orange : public fruit {
	enum yn juice;
	enum yn sour;
	enum yn eating;
public:
	void seto(char *n, enum color c, enum yn j, enum yn sr, enum yn e);
	void show();
};

void Apple::seta(char *n, enum color c, enum yn ck, enum yn crchy, enum yn e) {
	strcpy(name, n);
	annual = no;
	perennial = yes;
	tree = yes;
	tropical = no;

	clr = c;
	cooking = ck;
	crunchy = crchy;
	eating = e;

}

void Orange::seto(char *n, enum color c, enum yn j, enum yn sr, enum yn e) {
	strcpy(name, n);
	annual = no;
	perennial = yes;
	tree = yes;
	tropical = no;
	
	clr = c;
	juice = j;
	sour = sr;
	eating = e;
}

void Apple::show() {
	cout << name << " apple is: " << endl;
	cout << "Annual: "; out(annual);
	cout << "Perennial: "; out(perennial);
	cout << "Tree: "; out(tree);
	cout << "Tropical: "; out(tropical);
	cout << "Color: " << c[clr] << endl;
	cout << "Good for cooking: "; out(cooking);
	cout << "Crunchy: "; out(crunchy);
	cout << "Good for eating: "; out(eating);
	cout << endl;
}

void Orange::show() {
	cout << name << " orange is: " << endl;
	cout << "Annual: "; out(annual);
	cout << "Perennial: "; out(perennial);
	cout << "Tree: "; out(tree);
	cout << "Tropical: "; out(tropical);
	cout << "Color: " << c[clr] << endl;
	cout << "Good for juice: "; out(juice);
	cout << "Sour: "; out(sour);
	cout << "Good for eating: "; out(eating);
	cout << endl;
}

void out(enum yn x) {
	if(x==no) cout << "no" << endl;
	else cout << "yes" << endl;
}

int main()
{
	Apple a1, a2;
	Orange o1, o2;

	a1.seta("Red Delicious", red, no, yes, yes);
	a2.seta("Jonathan", red, yes, no, yes);

	o1.seto("Navel", orange, no, no, yes);
	o2.seto("Valencia", orange, yes, yes, no);

	a1.show();
	a2.show();
	
	o1.show();
	o2.show();
		
	return 0;
}