#include<iostream>
#include<stdlib.h>
using namespace std;


struct dugum
{
	int veri;
	dugum * sol;
	dugum * sag;
};

typedef dugum eleman;

eleman* ekle(eleman* agac, int eklenecekDeger)
{
	if (agac == NULL)
	{

		eleman* kok = (eleman*)malloc(sizeof(eleman));


		kok->sag = NULL;
		kok->sol = NULL;


		kok->veri = eklenecekDeger;

		return kok;
	}


	if (agac->veri < eklenecekDeger)
	{
		agac->sag = ekle(agac->sag, eklenecekDeger);
	}
	else 
	{
		agac->sol = ekle(agac->sol, eklenecekDeger);
	}

	return agac;
}

void soldanKokeDolas(eleman* agac)
{

	if (agac == NULL)
	{
		return;
	}

	soldanKokeDolas(agac->sol);

	soldanKokeDolas(agac->sag);

	cout << agac->veri << " ";

}

int main()
{
	eleman* agac = NULL;
	int sayi;

	do
	{
		cout << "Sayi Giriniz <Cikis:0>	= ";
		cin >> sayi;

		if(sayi != 0)
			agac = ekle(agac, sayi);

	} while (sayi != 0);

	cout << "Postorder :		";
	soldanKokeDolas(agac);
	cout << endl;

	system("pause");
}