#include<iostream> 
using namespace std;

class Complex {
private:
	int real, imag;
public:
	Complex(int tempReal, int tempImag) : real(tempReal), imag(tempImag) {}
	Complex() : real(0), imag(0) {}


	// This is automatically called when '+' is used with 
	// between two Complex objects 
	Complex operator + (Complex const& obj) {
		Complex tempClass;

		printf("real value of tempClass: %d\n", tempClass.real);
		printf("real value of obj      : %d\n", obj.real);
		printf("real value             : %d\n\n\n", real);

		tempClass.imag = imag + obj.imag;
		tempClass.real = real + obj.real;

		printf("real value of tempClass: %d\n", tempClass.real);
		printf("real value of obj      : %d\n", obj.real);
		printf("real value             : %d\n", real);

		return tempClass;
	}

	Complex operator - (Complex const& obj) {
		Complex tempClass;

		tempClass.imag = imag - obj.imag;
		tempClass.real = real - obj.real;

		return tempClass;
	}

	Complex operator * (Complex const& obj) {
		Complex tempClass;

		tempClass.imag = imag * obj.imag;
		tempClass.real = real * obj.real;

		return tempClass;
	}

	Complex operator / (Complex const& obj) {
		Complex tempClass;

		tempClass.imag = imag / obj.imag;
		tempClass.real = real / obj.real;

		return tempClass;
	}
	void print() { cout << real << " + i" << imag << endl; }
};

int main()
{
	Complex c1(10, 5), c2(2, 4);
	Complex c3 = c1 + c2; 
	//Complex c4 = c1 - c2;
	//Complex c5 = c1 * c2;
	//Complex c6 = c1 / c2;

	printf("Values of c1: "); c1.print();
	printf("Values of c2: "); c2.print();
	printf("Values of c3: "); c3.print();
	//printf("Values of c4: "); c4.print();
	//printf("Values of c5: "); c5.print();
	//printf("Values of c6: "); c6.print();





}
