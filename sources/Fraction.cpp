#include "Fraction.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string.h>

using namespace std;

namespace ariel
{
    // Constructors
    Fraction::Fraction(float numerator, float denominator) : numerator(numerator), denominator(denominator)
    {
		if(denominator == 0)
		{
			throw invalid_argument("Fraction can't be created if denominator is 0");
		}
		else
		{
			reduce();
		}
		
    }
	
    Fraction::Fraction(float numerator) : numerator(1000 * numerator), denominator(1000)
    {
		reduce();
    }
	
    Fraction::Fraction() : numerator(0), denominator(1)
    {
		reduce();
    }
	/*
    Fraction::Fraction(const Fraction &other) : numerator(other.getNumerator()), denominator(other.getDenominator())
    {
		if(denominator == 0)
		{
			throw invalid_argument("Fraction can't be created if denominator is 0");
		}
		else
		{
			reduce();
		}
    }
	*/
    Fraction Fraction::operator+(const Fraction &other) const
    {
        int num;
        int denom;
		int a;
		int b;
		/*
		if (__builtin_smul_overflow(numerator, other.denominator, &a) || __builtin_smul_overflow(other.numerator, denominator, &b), __builtin_smul_overflow(denominator, other.denominator, &denom))
			throw overflow_error("Overflow");

		if (__builtin_sadd_overflow(a, b, &num))
			throw overflow_error("Overflow");
		*/
		 num = numerator*other.denominator + other.numerator*denominator;
		 denom = denominator*other.denominator;
		 reduce(num, denom);
		
        return Fraction(num, denom);
    }
	
    Fraction Fraction::operator-(const Fraction &other) const
    {
		int num;
        int denom;
		int a;
		int b;
		/*
		if (__builtin_smul_overflow(numerator, other.denominator, &a) || __builtin_smul_overflow(other.numerator, denominator, &b) || __builtin_smul_overflow(denominator, other.denominator, &denom))
			throw overflow_error("Overflow");

		if (__builtin_ssub_overflow(a, b, &num))
			throw overflow_error("Overflow");
		cout << "- frac frac" << num << denom << endl;
		*/
		
		 num = numerator*other.denominator - other.numerator*denominator;
		 denom = denominator*other.denominator;
		 reduce(num, denom);
		 
        return Fraction(num, denom);
    }
	
    Fraction Fraction::operator*(const Fraction &other) const
    {
		int num;
        int denom;
		/*
		if (__builtin_smul_overflow(numerator, other.numerator, &num) || __builtin_smul_overflow(denominator, other.denominator, &denom))
			throw overflow_error("Overflow");
		*/
		
		num = numerator*other.numerator;
		denom = denominator*other.denominator;
		reduce(num, denom);
        return Fraction(num, denom);
    }
	
    Fraction Fraction::operator/(const Fraction &other) const
    {
		int num;
        int denom;
		
		if(denominator == 0 || other.numerator == 0)
		{
			throw invalid_argument("Fraction can't be created if denominator is 0");
		}
		/*
		if (__builtin_smul_overflow(numerator, other.denominator, &num) || __builtin_smul_overflow(denominator, other.numerator, &denom))
			throw overflow_error("Overflow");
		*/
		num = numerator*other.denominator;
		denom = denominator*other.numerator;
		reduce(num, denom);
		
        return Fraction(num, denom);
    }
	
    bool Fraction::operator<(const Fraction &other) const
    {
		float f1 = ((float)numerator / (float)denominator);
		float f2 = ((float)other.getNumerator() / (float)other.getDenominator());
		cout << "** \n" << f1 <<" " <<  f2 << endl;
        return (f1 < f2) ? true : false ;
    }
	
    bool Fraction::operator<=(const Fraction &other) const
    {
		float f1 = ((float)numerator / (float)denominator);
		float f2 = ((float)other.getNumerator() / (float)other.getDenominator());
		cout << "<= $$ \n" << f1 <<" " <<  f2 << endl;
        return (f1 <= f2)? true : false ;
    }
	
    bool Fraction::operator>(const Fraction &other) const
    {
		float f1 = ((float)numerator / (float)denominator);
		float f2 = ((float)other.getNumerator() / (float)other.getDenominator());
		cout << "> $$ \n" << f1 <<" " <<  f2 << endl;
        return (f1 > f2) ? true : false ;
    }
	
    bool Fraction::operator>=(const Fraction &other) const
    {
		float f1 = ((float)numerator / (float)denominator);
		float f2 = ((float)other.getNumerator() / (float)other.getDenominator());
		cout << ">= $$ \n" << f1 <<" " <<  f2 << endl;
        return (f1 >= f2) ? true : false ;
    }
	
    bool Fraction::operator==(const Fraction &other) const
    {
		float f1 = ((float)this->getNumerator())/((float)this->getDenominator());
		float f2 = ((float)other.getNumerator())/((float)other.getDenominator());
		cout << "** \n" << f1 <<" " <<  f2 << endl;
        return (f1 == f2) ? true : false ;
    }
    bool Fraction::operator!=(const Fraction &other) const
    {
		float f1 = ((float)this->getNumerator())/((float)this->getDenominator());
		float f2 = ((float)other.getNumerator())/((float)other.getDenominator());
        return (f1 != f2) ? true : false ;
    }

    Fraction Fraction::operator+(float other)
    {
		Fraction x = Fraction(other);
		return x + *this ;	
    }
	
    Fraction Fraction::operator-(float other)
    {
		Fraction x = Fraction(other);
		cout << "- float other" << other << x.getNumerator() << x.getDenominator() << endl;
		return *this - x;	
    }
	
    Fraction Fraction::operator*(float other)
    {
		Fraction x = Fraction(other);
		return x * *this ;	
    }
	
    Fraction Fraction::operator/(float other)
    {
		Fraction x = Fraction(other);
		return *this / x ;	
    }
	
    bool Fraction::operator<(float other)
    {
		float floatFraction = ((float)this->getNumerator()) /  ((float)this->getDenominator());
		cout << "< $ \n"<< other << floatFraction << endl;
        return floatFraction < other ? true :  false ;
    }
	
    bool Fraction::operator<=(float other)
    {
		float floatFraction = ((float)this->getNumerator()) /  ((float)this->getDenominator());
		cout << "<= $ \n"<< other << floatFraction << endl;
        return floatFraction <= other ? true :  false ;
    }
	
    bool Fraction::operator>(float other)
    {
		float floatFraction = ((float)this->getNumerator()) /  ((float)this->getDenominator());
		cout << "< $ \n"<< other << floatFraction << endl;
        return floatFraction > other? true :  false ;
    }
	
    bool Fraction::operator>=(float other)
    {
		float floatFraction = ((float)this->getNumerator()) /  ((float)this->getDenominator());
        return floatFraction >= other ? true :  false ;
    }
    bool Fraction::operator==(float other)
    {
		float floatFraction = ((float)this->getNumerator()) /  ((float)this->getDenominator());
		cout << "33333" << endl;
        return other == floatFraction ?  true :  false ;
    }
    bool Fraction::operator!=(float other)
    {
		float floatFraction = ((float)this->getNumerator()) /  ((float)this->getDenominator());
        return other != floatFraction ?  true :  false ;
    }

    Fraction &Fraction::operator++()
    {
		numerator += denominator;
        reduce(this->numerator, this->denominator);
		cout << "++++++\n"<< this->numerator << this->denominator << endl;
        return *this;
    }

    Fraction Fraction::operator++(int)
    {
		Fraction temp(numerator, denominator);
        ++(*this);
		cout << "++++++2222\n"<< this->numerator << this->denominator << endl;
        return temp;
		
    }

    Fraction &Fraction::operator--()
    {
		numerator -= denominator;
        reduce(this->numerator, this->denominator);
        return *this;
    }

    Fraction Fraction::operator--(int)
    {
		Fraction temp(numerator, denominator);
        --(*this);
        return temp;

    }
	
	bool operator==(float other, const Fraction &fraction){
		cout << "*===*\n" <<((float)fraction.getNumerator()/(float)fraction.getDenominator())<< " \n "<< endl;
		return ((float)fraction.getNumerator()/(float)fraction.getDenominator()) == other ? true: false ;
	}
	bool operator!=(float other, const Fraction &fraction){
		return ((float)fraction.getNumerator()/(float)fraction.getDenominator()) != other ? true: false ;
	}
	
	bool operator>(float other, const Fraction &fraction){
		cout << "> $$$ \n" <<  ((float)fraction.getNumerator()/(float)fraction.getDenominator()) << " "<< other << endl;
		return  other > ((float)fraction.getNumerator()/(float)fraction.getDenominator()) ?  true: false;
	}
	
	bool operator>=(float other, const Fraction &fraction){
		return  other >=  ((float)fraction.getNumerator()/(float)fraction.getDenominator()) ?  true: false;
	}
	
	bool operator<(float other, const Fraction &fraction){
		cout << "*** \n" << ((float)fraction.getNumerator()/(float)fraction.getDenominator())  << " "<< other << endl;
		return  other < ((float)fraction.getNumerator()/(float)fraction.getDenominator()) ?  true: false;
	}
	
	bool operator<=(float other, const Fraction &fraction){
		
		return other <= ((float)fraction.getNumerator()/(float)fraction.getDenominator()) ?  true: false ;
	}
	
	Fraction operator/(float other, const Fraction &fraction){
			Fraction x = Fraction(other);
            return x / fraction  ;	
	}
	
	Fraction operator*(float other, const Fraction &fraction)
	{
		Fraction x = Fraction(other);
		return x * fraction ;	
	}
	
	Fraction operator-(float other, const Fraction &fraction)
	{
		Fraction x = Fraction(other);
		cout << "- float other hpp"<< x.getNumerator() << x.getDenominator() << endl;
		return x - fraction ;				
	}
	
	Fraction operator+(float other, const Fraction &fraction)
	{
		Fraction x = Fraction(other);
		return x + fraction ;	
	}
		
    ostream &operator<<(std::ostream &out, const Fraction &fraction)
    {
		out << fraction.getNumerator() << "/" << fraction.getDenominator();
        return out;
    }
	
    istream &operator>>(std::istream &inp,  Fraction &fraction)
    {
		int num, den;
		char slash;
		inp >> num >> den;
		
		if (inp.fail() || den == 0)
			throw runtime_error("error");

		if (den < 0)
		{
			num *= -1;
			den *= -1;
		}

		fraction.setNumerator(num);
		fraction.setDenominator(den);
		
		fraction.reduce();
        return inp;
    }
	
}