#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;

class point
{
public:
	point(const point&);
	point(int, int);
	point(int);
	point();
	~point();
	void rotation(int);
	void polaire();
	void cartesienne();
	void initialise(int, int);
	void affiche();
	void deplace(int dx, int dy);
	void homothetie(int k);
	int getX();
	int getY();
private:
	double x, y;
	double rho, theta;
};

point::point()
{
	cout << "constructeur Point vide" << endl;
	x = 0;
	y = 0;
	polaire();
}

point::point(int p)
{
	cout << "constructeur Point 1 int" << endl;
	x = p;
	y = p;
	polaire();
}

point::point(int px, int py)
{
	cout << "constructeur Point 2int" << endl;
	x = px;
	y = py;
	polaire();
}

point::point(const point& p)
{
	cout << "constructeur point recopie" << endl;
	x = p.x;
	y = p.y;
	polaire();
}

point::~point()
{
	cout << "destructeur point" << endl;
}



void point::rotation(int alpha)
{
	double radian;
	radian = M_PI * alpha;
	radian = radian / 180;
	theta = theta + radian;
	cartesienne();
}

void point::cartesienne()
{
	x = rho * cos(theta);
	y = rho * sin(theta);
}

void point::polaire()
{
	rho = sqrt(x * x + y * y);
	theta = atan2(y, x);
}


void point::initialise(int px, int py)
{
	x = px;
	y = py;
	polaire();
}




void point::affiche()
{
	cout << "x : " << x;
	cout << "   y : " << y << endl;
	cout << "theta : " << theta;
	cout << "   rho : " << rho << endl;
}




void point::deplace(int dx, int dy)
{
	x = x + dx;
	y = y + dy;
	polaire();
}


void point::homothetie(int k)
{
	x = x * k;
	y = y * k;
	polaire();
}


int point::getX()
{
	return x;
}

int point::getY()
{
	return y;
}




class rectangle {
private:
	point p1, p2;
public:
	rectangle(const rectangle&);
	rectangle(int, int, int, int);
	rectangle(point, point);
	rectangle(point, int, int);
	rectangle();
	~rectangle();
	rectangle& operator=(const rectangle&);
	void affiche();
	void homothetie(int);
	void rotation(int);
	void deplace(int, int);
	void initialise(int, int, int, int);
	void initialise(point, int, int);
};

rectangle::rectangle() : p1(0, 0), p2(0, 0)
{
	cout << "constructeur Rectangle vide " << endl;
}


rectangle::rectangle(point pm, int l, int h) : p1(pm), p2(pm)
{

	cout << "constructeur Rectangle 1point " << endl;
	p2.deplace(l, h);
}


rectangle::rectangle(point pm1, point pm2) : p1(pm1), p2(pm2)
{
	cout << "constructeur Rectangle 2point " << endl;
}

rectangle::rectangle(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2)
{
	cout << "constructeur Rectangle int " << endl;
}

rectangle::rectangle(const rectangle& r) : p1(r.p1), p2(r.p2)
{
	cout << "constructeur Rectangle recopie " << endl;
}


rectangle::~rectangle()
{

	cout << "destructeur Rectangle " << endl;
}


rectangle& rectangle::operator=(const rectangle& r)
{
	p1 = r.p1;
	p2 = r.p2;
	return *this;
}


void rectangle::affiche()
{
	cout << "p1 :  ";
	p1.affiche();
	cout << "p2 :  ";
	p2.affiche();
}

void rectangle::homothetie(int k)
{
	p1.homothetie(k);
	p2.homothetie(k);
}

void rectangle::rotation(int alpha)
{
	p1.rotation(alpha);
	p2.rotation(alpha);
}

void rectangle::deplace(int dx, int dy)
{
	p1.deplace(dx, dy);
	p2.deplace(dx, dy);
}

void rectangle::initialise(int x1, int y1, int x2, int y2)
{
	p1.initialise(x1, y1);
	p2.initialise(x2, y2);
}

void rectangle::initialise(point pm, int l, int h)
{
	p1 = p2 = pm;
	p2.deplace(l, h);
}







class bouton
{
private:
	rectangle r;
	string txt;
public:
	bouton(const bouton&);
	bouton(int, int, int, int, char*);
	bouton(point, point, char*);
	bouton(point, int, int, char*);
	bouton();
	~bouton();
	bouton& operator=(const bouton&);
	void affiche();
	void homothetie(int);
	void rotation(int);
	void deplace(int, int);
	void initialise(int, int, int, int, char*);
	void initialise(point, int, int, char*);
};



bouton::bouton() : r()
{
	txt = "";
	cout << "constructeur Bouton vide " << endl;
	int* tab = new int[23];
}

bouton::bouton(int x1, int y1, int x2, int y2, char* t) : r(x1, y1, x2, y2)
{
	txt = t;
	cout << "constructeur Bouton int " << endl;
}

bouton::bouton(point pm1, point pm2, char* t) : r(pm1, pm2)
{
	txt = t;
	cout << "constructeur Bouton 2point " << endl;
}


bouton::bouton(point pm, int l, int h, char* t) : r(pm, l, h)
{
	txt = t;
	cout << "constructeur Bouton 1point " << endl;
}


bouton::bouton(const bouton& b) : r(b.r)
{
	txt = b.txt;
	cout << "constructeur Bouton recopie " << endl;
}


bouton::~bouton()
{
	cout << "destructeur Bouton " << endl;
}


bouton& bouton::operator=(const bouton& b)
{
	r = b.r;
	txt = b.txt;
	return *this;
}


void bouton::affiche()
{
	r.affiche();
	cout << "texte : " << txt << endl;
}


void bouton::homothetie(int k)
{
	r.homothetie(k);
}


void bouton::rotation(int alpha)
{
	r.rotation(alpha);
}


void bouton::deplace(int dx, int dy)
{
	r.deplace(dx, dy);
}


void bouton::initialise(int x1, int y1, int x2, int y2, char* t)
{
	r.initialise(x1, y1, x2, y2);
	txt = t;
}


void bouton::initialise(point pm, int l, int h, char* t)
{
	r.initialise(pm, l, h);

}

class menuA {
private:
	point ancrage;
	bouton* tab;
	int pas;
	int n;
public:
	menuA(const menuA&);
	menuA(int, char*);
	menuA(int, int, int, int, int, int, char*);
	menuA(int, point, point, int, char*);
	menuA();
	~menuA();
	menuA& operator=(const menuA&);
	void affiche();
	void homothetie(int);
	void rotation(int);
	void deplace(int, int);
	void initialise(point, int);
	void initialise(int, int, int, int, char*);
	void initialise(point, int, int, int, char*);

};

menuA::menuA()
{
	ancrage.initialise(0, 0);
	tab = NULL;
	pas = 0;
	n = 0;
}

menuA::menuA(int nb, char* txt)
{
	ancrage.initialise(10, 10);
	tab = new bouton[n = nb];
	pas = 20;
	for (int i = 0; i < n; i++)
	{
		tab[i] = bouton((40 * i) - (10 * i) + ((i + 1) * 10), ancrage.getY(), (i + 1) * 40, ancrage.getY() - 10, txt);
	}


}


menuA::menuA(int nb, int x, int y, int l, int h, int p, char* txt)
{
	ancrage.initialise(x, y);
	tab = new bouton[n = nb];
	pas = p;
	for (int i = 0; i < n; i++)
	{
		tab[i] = bouton(ancrage, l, h, txt);
		ancrage.deplace(pas, 0);
	}
}


menuA::menuA(int nb, point pm, point pm2, int l, char* txt)
{
	ancrage = pm;
	tab = new bouton[n = nb];
	pas = l;
	for (int i = 0; i < n; i++)
	{
		tab[i] = bouton(ancrage, pm2, txt);
		ancrage.deplace(pas, 0);
	}
}


menuA::menuA(const menuA& m)
{
	ancrage = m.ancrage;
	n = m.n;
	pas = m.pas;
	tab = new bouton[n];
	for (int i = 0; i < n; i++)
	{
		tab[i] = m.tab[i];
	}
}



void menuA::affiche()
{
	for (int i = 0; i < n; i++)
	{
		tab[i].affiche();
	}
}

menuA::~menuA()
{

	delete[] tab;
}


menuA& menuA::operator=(const menuA& m)
{
	ancrage = m.ancrage;
	n = m.n;
	pas = m.pas;
	delete[] tab;
	tab = new bouton[n];
	for (int i = 0; i < n; i++)
	{
		tab[i] = m.tab[i];
	}
	return *this;
}


void menuA::homothetie(int k)
{
	for (int i = 0; i < n; i++)
	{
		tab[i].homothetie(k);
	}
}


void menuA::rotation(int alpha)
{
	for (int i = 0; i < n; i++)
	{
		tab[i].rotation(alpha);
	}
}


void menuA::deplace(int dx, int dy)
{
	for (int i = 0; i < n; i++)
	{
		tab[i].deplace(dx, dy);
	}
}


void menuA::initialise(point pm, int n, int l, int h, char* txt)
{
	ancrage = pm;
	delete[] tab;
	tab = new bouton[n];
	for (int i = 0; i < n; i++)
	{
		tab[i] = bouton(ancrage, l, h, txt);
		ancrage.deplace(pas, 0);
	}
}



int main()
{

	int tab[126];
	for (int i = 0; i < 126; i++)
	{
		tab[i] = i;
	}
	
	// print the lenth of tab 
	cout << "the lenth of tab is : " << size(tab) << endl;
}