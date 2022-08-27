#include <iostream>
#include <fstream>
#include <sstream>
#include "Radix.hpp"
#include "Dosya.hpp"
#include "AVL.hpp"

using namespace std;

void Dosya::DosyaOku(){
		
	AVL *avl = new AVL();
	ifstream dosyaOku("Sayilar.txt");
	char bosluk = ' ';
	int boslukAdet = 0;
	int i = 0;
	int elemanSayisi = 0;
	string metin;
		
	if (dosyaOku.is_open()) {
		while (getline(dosyaOku, metin)) {
			
			if(metin[0] == bosluk) boslukAdet--;
			if(metin[metin.length()-1] == bosluk) boslukAdet--;
			for(int i = 0; i < metin.length();i++) {
				if(metin[i] == bosluk) boslukAdet++;
			}
			elemanSayisi =boslukAdet + 1;

			int *dizi = new int[elemanSayisi];
			int toplam = 0;
			int index = 0;
			string s(metin);
			istringstream iss(s);
			while (iss >> sub)
			{
				dizi[index] = stoi(sub);
				toplam += dizi[index];
				index++;
			}	
	        
			Radix *radix = new Radix();
			radix->radixsort(dizi, index);
			avl->Add(toplam, elemanSayisi, dizi);
			delete radix;
			boslukAdet = 0;
		}
		avl->preorder();
		dosyaOku.close();
		delete avl;
	}
}
void Dosya::deleteElement(int* &arr, int elemanSayisi, int silinecekindis) 
{ 
    int newCapacity = elemanSayisi - 1;
    int *copyArr = new int[newCapacity];
    if (newCapacity ==  silinecekindis) //son eleman siliniyorsa
    { 
        for (int i = 0; i < elemanSayisi; i++){
            if(i !=  silinecekindis){
                copyArr[i] = arr[i];
            } 
        }
        delete arr;
        arr = copyArr;
    }
    else if(silinecekindis == 0){
        for (int i = 0; i < elemanSayisi; i++){
            if(i != newCapacity){
                copyArr[i] = arr[i+1];
            }
        }
        delete arr;
        arr = copyArr;
    }
}
   



