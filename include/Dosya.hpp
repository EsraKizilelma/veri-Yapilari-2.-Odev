#ifndef DOSYA_HPP
#define DOSYA_HPP
#include <iostream>
using namespace std;

class Dosya{
	private:
		string metin = "";
		string sub;
	public:
		void DosyaOku();
		void deleteElement(int *&,int ,int );
};
#endif