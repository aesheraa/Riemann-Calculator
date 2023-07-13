
/*  in this project Im coding program that calculate the Riemann sum of third- order equations.
As input the the program , the coefficients of a third-degree function ,
the range to be used in calculating the riemann sum and the information on how  many equal parts this interval should be divided into,
the progrem will present the entered equation and the riemann sum to the user as a result.
Generate the codes using the structures and function axplained below. */


#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

struct denklem {

	double a, b, c, d;
};

void function(struct denklem* d) {
	cout << " y= " << d->a << " x^3" ;
    cout << (d->b < 0 ? "-" : "+") << abs(d->b) << "x^2";
	cout << (d->c < 0 ? "-" : "+") << abs(d->c) << "x";
	cout << (d->d < 0 ? "-" : "+") << abs(d->d) << endl;
}

double function(struct denklem* d, double x) {
	return d->a * x * x * x + d->b  * x * x + d->c * x + d->d;

}

double riemann_calculator(struct denklem* d, double a, double b, int n) {

	double x, y, total = 0, dx = (b - a) / n;
	for (int i = 0; i < n; ++i) {
		x = a + i * dx + dx / 2;
		y = function(d, x);
		total += y * dx;

	}

	return total;

}


int main() {

	struct denklem f;
	double first, last;
		int dikdortgen_number;

	cout << fixed << setprecision(1);

	cout << " denklem katsayilarini gir:"<< endl;
	cin >> f.a >> f.b >> f.c >> f.d;
	cout << "girilen denklem: " << endl;
	function(&f);

	cout << " aralik degerlerini ve bolum sayisini girin " << endl;
	cin >> first >> last >> dikdortgen_number;

	cout << " riemann toplamý " << endl;
	cout << riemann_calculator(&f, first, last, dikdortgen_number);

	return 0;
}