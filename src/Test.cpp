#include <fstream>
#include <iostream>
#include "Dosya.hpp"
using namespace std;

int main(){

	Dosya *dosya = new Dosya();
	dosya->DosyaOku();
	delete dosya;
}