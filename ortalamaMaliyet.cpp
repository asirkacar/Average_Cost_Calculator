#include <iostream>
#include <vector>

using namespace std;

void ortalama(double adet[], double fiyat[])
{
	double maliyet=0, ortalama=0, adetToplam=0; 
	

	for (int i=0; i<2; i++)
	{
		adetToplam = adetToplam + adet[i];
		maliyet = maliyet + fiyat[i];
	}
		
	cout<<"adetToplam: "<<adetToplam<<endl;
	cout<<"maliyet: "<<maliyet<<endl;
	ortalama = maliyet / adetToplam;
	
	cout<<"ortalama: "<<ortalama;
}

void surekliOrtalama(const vector<double>& adet, const vector<double>& fiyat)
{
    double maliyet = 0, ortalama = 0, adetToplam = 0;

    for (int i = 0; i < adet.size(); i++)
    {
        adetToplam += adet[i];
        maliyet += fiyat[i];
    }

    cout << "adetToplam: " << adetToplam << std::endl;
    cout << "maliyet: " << maliyet << std::endl;

    ortalama = maliyet / adetToplam;

    cout << "ortalama: " << ortalama;
}

int main()
{
	double *pYeniFiyat, yeniFiyat=0;
	int giris;
	cout<<"Surekli Alim Girmek Icin 1 yada Belli Sayida Alim Girmek Icin 2 ye bas: "; cin>>giris;
	
	switch(giris)
	{
		case 1:
			{
			
			char s;
			int a=1;
			double *pAdetGiris, *pFiyatGiris, adetGiris, fiyatGiris;
			vector <double> adet;
			vector <double> fiyat;
			pAdetGiris = &adetGiris;
			pFiyatGiris = &fiyatGiris;
			while(a>0)
			{
				cout<<"Adet: "; cin>>*pAdetGiris;
				cout<<"Alis Fiyati: "; cin>>*pFiyatGiris;
				*pFiyatGiris = (*pAdetGiris) * (*pFiyatGiris);
				adet.push_back(*pAdetGiris);
				fiyat.push_back(*pFiyatGiris);
				cout<<"Devam Etmek Ýstiyormusun [e/h]"; cin>>s;
				if(s=='h') a=0;
			}
			surekliOrtalama(adet, fiyat);
			break;
			}
			
		case 2:
			{
			
			int alimSayisi;
			cout<<"Kac Alim Yapildi: "; cin>>alimSayisi;
	
			double adet[alimSayisi], fiyat[alimSayisi];
	
			pYeniFiyat = &yeniFiyat;
	
			for (int i=0; i<alimSayisi; i++)
			{
				cout<<"Adet: "; cin>>adet[i];
				cout<<"Alis Fiyati: "; cin>>*pYeniFiyat;
				fiyat[i] = adet[i] * (*pYeniFiyat);
			}
			ortalama(adet, fiyat);
			break;	
			}
		default:
			cout<<"Yanlis Giris";
			break;	
	}	
}
