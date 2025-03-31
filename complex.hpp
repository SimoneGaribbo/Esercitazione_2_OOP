#pragma once
# include <math.h>

/* Classe per i numeri complessi*/
template<typename F> requires std::floating_point<F>
class complex_number
{
    F r, imm;
	
public:
    /* Default constructor */
    complex_number()
        : r(0), imm(0)
    {}
    
    /* User-defined constructor. Se viene inizializzato un numero reale,
	 *questo viene convertito in numero complesso con parte immaginaria nulla.
     */
    explicit complex_number(F a)
        : r(a), imm(0)
    {
        std::cout << "converting constructor called" << std::endl;
    }
    
    /* User-defined constructor. Prende parte reale e parte immaginaria */
    complex_number(F a, F b)
        : r(a), imm(b)
    {}
    
    /* Restituisce la parte reale*/
    F reale(void) const {
        return r;
    }
    
    /* Restituisce la parte immaginaria*/
    F immaginaria(void) const {
        return imm;
    }
	
	/* Calcola il coniugato di un complesso */	
	complex_number coniugato(void) {
		complex_number c = *this;
    return complex_number(c.reale(), -c.immaginaria());
	}
    
    /* Define the += operator between complex.*/
    complex_number& operator+=(const complex_number& other) {
        F a = r;
        F b = imm;
        F c = other.r;
        F d = other.imm;
        r = a+c;
        imm = b+d;
        return *this;
	}
	
	/* Define operator+ in terms of operator += */
	complex_number operator+(const complex_number& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }

    /* Define the += operator between a rational on the left
     * and an I on the right.*/
    complex_number& operator+=(const F& other) {
        r += other;
        return *this;
	}
	
	/* Define operator+ in terms of operator +=*/
	complex_number operator+(const F& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }
    
	/* Define the += operator between complex.*/
	complex_number& operator*=(const complex_number& other) {
        F a = r;
        F b = imm;
        F c = other.r;
        F d = other.imm;
        r = a*c-b*d;
        imm = a*d+b*c;
        return *this;
	}
	
	complex_number operator*(const complex_number& other) const {
        complex_number ret = *this;
        ret *= other;
        return ret;
    }
    
	complex_number& operator*=(const F& other) {
        r *= other;
		imm *= other;
        return *this;
	}
	
	complex_number operator*(const F& other) const {
        complex_number ret = *this;
        ret *= other;
        return ret;
    }
};

template<typename F>
complex_number<F>
operator+(const F& n, const complex_number<F>& c)
{
    return c + n;
}

template<typename F>
complex_number<F>
operator*(const F& n, const complex_number<F>& c)
{
    return c * n;
}

/* Overload di <<, stampa i complessi. */
template<typename F>
std::ostream&
operator<<(std::ostream& os, const complex_number<F>& c) {
    if (c.immaginaria() < 0){
		if (c.immaginaria() == -1.0)
			os << c.reale() << "-" << "i";
		else
			os << c.reale() << "-" << fabs(c.immaginaria()) << "i";
	}
    else if (c.immaginaria() > 0){
		if (c.immaginaria() == 1.0)
			os << c.reale() << "+" << "i";
		else
			os << c.reale() << "+" << c.immaginaria() << "i";
	}
	else
		os << c.reale();

    return os;
}


