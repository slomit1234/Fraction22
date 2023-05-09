#pragma once

#include <math.h>
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

using namespace std;

namespace ariel
{
    class Fraction
    {
		
	private:
	
	public:
        int numerator;
        int denominator;

   
        Fraction(float, float);
        Fraction(float);
        Fraction();
        //Fraction(const Fraction &other);
	
        int getNumerator() const
        {
            return numerator;
        }
        int getDenominator() const
        {
            return denominator;
        }
		
		void setNumerator(int nomi)
        {
            numerator = nomi;
        }
        void setDenominator(int denom)
        {
			denominator = denom;
        }
		
		void reduce()
        {
  
			int gcd = __gcd(abs(numerator), abs(denominator));
			
			if(gcd !=0)
			{
				numerator /= gcd;
				denominator /= gcd;
			}

        }
		
		static void reduce(int &numerator, int &denominator)
        {
  
			int gcd = __gcd(abs(numerator), abs(denominator));
            numerator /= gcd;
            denominator /= gcd;
        }


        Fraction operator+(const Fraction &other) const;
		Fraction operator+(float other);
		friend Fraction operator+(float other, const Fraction &fraction);
		
		Fraction operator-(const Fraction &other) const;
        Fraction operator-(float other);
		friend Fraction operator-(float other, const Fraction &fraction);
        
        Fraction operator*(const Fraction &other) const;
		Fraction operator*(float other);
		friend Fraction operator*(float other, const Fraction &fraction);
		
        Fraction operator/(const Fraction &other) const;
		Fraction operator/(float other);
		friend Fraction operator/(float other, const Fraction &fraction);
		
        bool operator<(const Fraction &other) const;
		bool operator<(float other);
		
        bool operator<=(const Fraction &other) const;
		bool operator<=(float other);
		
        bool operator>(const Fraction &other) const;
		bool operator>(float other);
		
        bool operator>=(const Fraction &other) const;
		bool operator>=(float other);
		
        bool operator==(const Fraction &other) const;        
		bool operator==(float other);
		
        bool operator!=(const Fraction &other) const;
		bool operator!=(float other);

        Fraction &operator++();
        Fraction operator++(int);
        Fraction &operator--();
        Fraction operator--(int);

        friend bool operator==(float other, const Fraction &fraction);
        friend bool operator!=(float other, const Fraction &fraction);
        friend bool operator>(float other, const Fraction &fraction);
        friend bool operator>=(float other, const Fraction &fraction);
        friend bool operator<(float other, const Fraction &fraction);
        friend bool operator<=(float other, const Fraction &fraction);

        friend ostream &operator<<(ostream &out, const Fraction &fraction);
        friend istream &operator>>(istream &inp,  Fraction &fraction);
		
    };
}