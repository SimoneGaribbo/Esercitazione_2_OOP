#include <iostream>
#include <iomanip>
# include "complex.hpp"

int main(void)
{
	/* prova */
	complex_number<double> c1;
	std::cout << "c1=" << c1 << std::endl;
	
	complex_number<double> c2(8.32,-2.51);
	std::cout << "c2=" << c2 << std::endl;
	
	complex_number<float> c3(2.2,1.1);
	std::cout<< "float complex="<< c3 << std::endl;
	
	double r = c2.reale();
	std::cout << "La parte reale di c2 = " << r <<std::endl;

	double i = c2.immaginaria();
	std::cout << "La parte immaginaria di c2 = " << i <<std::endl;
	
	complex_number<double> c4 = c1.coniugato();
	std::cout << "Il coniugato di c1 = " << c4 <<std::endl;	

	complex_number<double> c5 = c2.coniugato();
	std::cout << "Il coniugato di c2 = " << c5 <<std::endl;	
	
	// Provo gli operatori:
	c1 += 2.1 ;
	std::cout << "c1 dopo somma = " << c1 <<std::endl;
	
	complex_number<double> somma1 = c2 + c4;
	std::cout << "c2 + c4 = " << somma1  <<std::endl;
	
	complex_number<double> somma2 = c2 + 3.1;
	std::cout << "c2 + 3.1 = " << somma2  <<std::endl;
	
	complex_number<double> somma3 = 3.1 + c2;
	std::cout << "3.1 + c2 = " << somma3  <<std::endl;
	
	std::cout <<std::endl;
	
	c1 *= c2 ;
	std::cout << "c1 dopo moltiplicazione = " << c1 <<std::endl;
	
	complex_number<double> c6(2.7, -5.002);
	std::cout << "c6  = " << c6 <<std::endl;
	
	complex_number<double> prod1 = c2 * c6;
	std::cout  << std::setprecision(16) << "c2 * c6 = " << prod1  <<std::endl;
	
	complex_number<double> prod11 = c6 * c2;
	std::cout  << "c6 * c2 = " << prod11  <<std::endl;
	
	complex_number<double> prod2 = c2 *7.8;
	std::cout << "c2 * 7.8 = " << prod2  <<std::endl;
	
	complex_number<double> prod3 = 7.8* c2;
	std::cout << "7.8 * c2 = " << prod3  <<std::endl;
	
	
	return 0;
}