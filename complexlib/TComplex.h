#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>



template <class T>
class TComplex
{
protected:
	T re;
	T im;
public:
	TComplex(T re_ = 0, T im_ = 0);
	TComplex(const TComplex& p);
	//TComplex(const TComplex<T>& other);
	~TComplex();

	T GetRe();
	T GetIm();
	void SetRe(T r);
	void SetIm(T i);

	TComplex operator+ (const TComplex <T>& p);
	TComplex operator* (const TComplex <T>& p);
	TComplex operator/ (const TComplex <T>& p);
	TComplex operator- (const TComplex <T>& p);

	TComplex& operator+= (const TComplex <T>& p);
	TComplex& operator*= (const TComplex <T>& p);
	TComplex& operator/= (const TComplex <T>& p);
	TComplex& operator-= (const TComplex <T>& p);

	TComplex& operator= (const TComplex <T>& p);

	bool operator== (const TComplex <T>& p);
	bool operator!= (const TComplex <T>& p);

	T Magnitude() const;
	TComplex<T> Power(int n) const;

	T Argument() const;

	void PrintTrigonometricForm() const;

	template <class U>
	friend std::ostream& operator <<(std::ostream& o, TComplex<U>& b);

	template <class U>
	friend std::istream& operator>>(std::istream& i, TComplex<U>& b);
};
template<class T>
inline TComplex<T>::TComplex(T re_, T im_)
{
	re = re_;
	im = im_;
}

	template<class T>
	inline TComplex<T>::TComplex(const TComplex& p)
	{
		this->re = p.re;
		this->im = p.im;
	}

	//template<class T>
	//inline TComplex<T>::TComplex(const TComplex<T>& other) {
	//	re = other.re; 
	//	im = other.im;  
	//}

	template<class T>
	inline TComplex<T>::~TComplex()
	{
	}

	template<class T>
	inline T TComplex<T>::GetRe()
	{
		return re;
	}

	template<class T>
	inline T TComplex<T>::GetIm()
	{
		return im;
	}

	template<class T>
	inline void TComplex<T>::SetRe(T r)
	{
		re = r;
	}

	template<class T>
	inline void TComplex<T>::SetIm(T i)
	{
		im = i;
	}

	template<class T>
	inline TComplex<T> TComplex<T>::operator+(const TComplex<T>& p)
	{
		return TComplex(re + p.re, im + p.im);
	}

	template<class T>
	inline TComplex<T> TComplex<T>::operator*(const TComplex<T>& p)
	{
		return TComplex(re * p.re - im * p.im, re * p.im + im * p.re);
	}

	template<class T>
	inline TComplex<T> TComplex<T>::operator/(const TComplex<T>& p)
	{
		return TComplex((re * p.re + im * p.im) / (p.re * p.re + p.im * p.im),
			(re * p.im + im * p.re) / (p.re * p.re + p.im * p.im));
	}

	template<class T>
	inline TComplex<T> TComplex<T>::operator-(const TComplex<T>& p)
	{
		return TComplex(re - p.re, im - p.im);
	}

	template<class T>
	inline TComplex<T>& TComplex<T>::operator+=(const TComplex<T>& p)
	{
		re += p.re;
		im += p.im;
		return *this;
	}

	template<class T>
	inline TComplex<T>& TComplex<T>::operator*=(const TComplex<T>& p)
	{
		T new_re = re * p.re - im * p.im;  
		T new_im = re * p.im + im * p.re;  

		re = new_re; 
		im = new_im; 

		return *this;
	}

	template<class T>
	inline TComplex<T>& TComplex<T>::operator/=(const TComplex<T>& p)
	{
		T denominator = p.re * p.re + p.im * p.im;
		if (denominator == 0) {
			throw std::runtime_error("Division by zero!");
		}
		T new_re = (re * p.re + im * p.im) / denominator;
		T new_im = (im * p.re - re * p.im) / denominator;
		re = new_re;
		im = new_im;
		return *this;
	}

	//template<class T>
	//inline TComplex<T>& TComplex<T>::operator-=(const TComplex<T>& p)
	//{
	//	re = re - p.re;
	//	im = im - p.im;
	//	return *this;
	//}

	template<class T>
	inline TComplex<T>& TComplex<T>::operator=(const TComplex<T>& p)
	{
		if (this != &p)
		{
			re = p.re;
			im = p.im;
		}
		return *this;
	}

	template<class T>
	inline bool TComplex<T>::operator==(const TComplex<T>& p)
	{
		return (re == p.re) && (im == p.im);
	}

	template<class T>
	inline bool TComplex<T>::operator!=(const TComplex<T>& p)
	{
		return !(*this == p);
	}

	template<class T>
	T TComplex<T>::Magnitude() const {
		return std::sqrt(re * re + im * im);
	}

	template<class T>
	TComplex<T> TComplex<T>::Power(int n) const {
		if (n == 0) {
			return TComplex<T>(1, 0);  
		}

		T r = Magnitude();  
		T theta = std::atan2(im, re);  

		T new_r = std::pow(r, n); 
		T new_theta = theta * n;   

		return TComplex<T>(new_r * std::cos(new_theta), new_r * std::sin(new_theta));
	}

	template<class T>
	inline T TComplex<T>::Argument() const
	{
		return std::atan2(im, re);
	}

	template<class T>
	inline void TComplex<T>::PrintTrigonometricForm() const
	{
		T r = Magnitude();  // Ìîäóëü
		T theta = Argument();  // Àðãóìåíò (â ðàäèàíàõ)
		T theta_degrees = theta * 180 / M_PI;  // Àðãóìåíò â ãðàäóñàõ

		std::cout << r << " * (cos(" << theta_degrees << ") + i*sin(" << theta_degrees << "))" << std::endl;
	}

	template<class T>
	inline std::ostream& operator<<(std::ostream& o, TComplex<T>& b)
	{
		o << b.re;
		if (b.im >= 0)
		{
			o << " + " << b.im << "i" << std::endl; 
		}
		else
		{
			o << " - " << -b.im << "i" << std::endl;
		}
		return o;
	}

	template <class T>
	std::istream& operator>>(std::istream& i, TComplex<T>& b)
	{
		std::cout << "Enter real part: ";
		i >> b.re; 
		std::cout << "Enter imaginary part: ";
		i >> b.im; 
		return i; 
	}
