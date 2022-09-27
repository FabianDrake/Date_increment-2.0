#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

class Date {
protected:
	int dia;
	int mes;
	int año;
public:
	void date(int, int, int);
	void validar_dia(int);
	void validar_año(int);
	void validar_mes(int);
	void bisiesto(int);
	void febrero(int);
	void dias_febrero(int);
	void undiamas(int);
	int losdiasdelmes(int);

	void Run();
};

void Date::date(int _dia, int _mes, int _año) {
	dia = _dia;
	mes = _mes;
	año = _año;
}

//-----------------------------------------------------------------------------------------------------------------

void Date::validar_dia(int _año) {
	this->año = _año;
	if (dia >= 1 && dia <= 31) {
		bisiesto(año);
	}
	else {
		cout << "EL DIA NO ES VALIDO \n";
		/*
		validar_dia(año);
		*/
	}
}

void Date::validar_mes(int _año) {
	this->año = _año;
	if (mes >= 1 && mes <= 12) {
		febrero(año);
	}
	else {
		cout << "EL MES NO ES VALIDO \n";
	}
}

void Date::validar_año(int _año) {
	this->año = _año;
	if (año >= 19990 && año <= 3000 || año >= 1 && año <= 99) {
		validar_mes(año);
	}
}

//------------------------------------------------------------------------------------------------------------------
// METODOS PARA LOS DIAS DE FEBRERO
void Date::febrero(int _año) {
	this->año = _año;
	if (mes == 2) {
		dias_febrero(año);
	}
	else {
		validar_dia(año);
	}
}

void Date::dias_febrero(int _año) {
	this->año = _año;
	if (dia >= 1 && dia <= 29) {
		bisiesto(año);
	}
	else {
		cout << "EL DIA NO ES VALIDO \n";
	}
}

//METODO PARA SACAR LOS AÑOS NO BISIESTOS
void Date::bisiesto(int _año) {
	this->año = _año;

	cout << "LA FECHA INGRESADA FUE: " << dia << "/" << mes << "/" << año << endl;

	if (año % 4 != 0 || (año % 100 == 0 && año % 400 != 0)) {
		cout << "EL AÑO NO ES BISIESTO\n";
		cout << "---------------------------------------\n";
	}
	else {
		cout << "EL AÑO ES BISIESTO\n";
		cout << "---------------------------------------\n";
	}
}

//METODO PARA DARLE LOS DIAS CORRECTOS A CADA MESD EL AÑO
int Date::losdiasdelmes(int _año) {
	int dias = 31;
	if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
		dias = 30;
	}
	else if (mes == 2) {
		dias = 28;
	}
	return dias;
}

//METODO PARA INCREMENTA DIA, MES Y AÑO
void Date::undiamas(int _año) {
	this->año = _año;

	dia++;
	// Declaramos a dia mayor a los dias del mes (dias que se le asigno a a cada mes)
	if (dia > losdiasdelmes(mes)) {
		dia = 1;
		mes++;

		if (mes > 12) {
			mes = 1;
			año++;
		}
	}

	cout << "\nLa fecha del siguiente dia es:" << dia << "/" << mes << "/" << año;
	cout << "\n------------------------------------------------\n";
}


// sstream ME SIRVIO PARA CONVERTIR UN STRING EN INT/INT/INT DD/MM/AA
void Date::Run() {
	string fecha;
	cout << "Ingrese la fecha:  dd/mm/aa \n";
	cout << "Fecha: ";
	cin >> fecha;
	string diaa, mees, aaño;
	stringstream input(fecha);

	getline(input, diaa, '/');
	getline(input, mees, '/');
	getline(input, aaño, '/');

	cout << "\nDia:" << diaa << "\n";
	cout << "\nMes:" << mees << "\n";
	cout << "\nAño:" << aaño << "\n";

	dia = stoi(diaa);
	mes = stoi(mees);
	año = stoi(aaño);

	if (dia == 0 || mes > 12 || año > 31) {
		cout << "Su fecha ingresada no es valida\n";
	}

	validar_año(año);
	undiamas(año);
}

int main() {
	Date o;
	o.Run();
}