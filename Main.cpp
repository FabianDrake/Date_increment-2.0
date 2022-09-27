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
	int a�o;
public:
	void date(int, int, int);
	void validar_dia(int);
	void validar_a�o(int);
	void validar_mes(int);
	void bisiesto(int);
	void febrero(int);
	void dias_febrero(int);
	void undiamas(int);
	int losdiasdelmes(int);

	void Run();
};

void Date::date(int _dia, int _mes, int _a�o) {
	dia = _dia;
	mes = _mes;
	a�o = _a�o;
}

//-----------------------------------------------------------------------------------------------------------------

void Date::validar_dia(int _a�o) {
	this->a�o = _a�o;
	if (dia >= 1 && dia <= 31) {
		bisiesto(a�o);
	}
	else {
		cout << "EL DIA NO ES VALIDO \n";
		/*
		validar_dia(a�o);
		*/
	}
}

void Date::validar_mes(int _a�o) {
	this->a�o = _a�o;
	if (mes >= 1 && mes <= 12) {
		febrero(a�o);
	}
	else {
		cout << "EL MES NO ES VALIDO \n";
	}
}

void Date::validar_a�o(int _a�o) {
	this->a�o = _a�o;
	if (a�o >= 19990 && a�o <= 3000 || a�o >= 1 && a�o <= 99) {
		validar_mes(a�o);
	}
}

//------------------------------------------------------------------------------------------------------------------
// METODOS PARA LOS DIAS DE FEBRERO
void Date::febrero(int _a�o) {
	this->a�o = _a�o;
	if (mes == 2) {
		dias_febrero(a�o);
	}
	else {
		validar_dia(a�o);
	}
}

void Date::dias_febrero(int _a�o) {
	this->a�o = _a�o;
	if (dia >= 1 && dia <= 29) {
		bisiesto(a�o);
	}
	else {
		cout << "EL DIA NO ES VALIDO \n";
	}
}

//METODO PARA SACAR LOS A�OS NO BISIESTOS
void Date::bisiesto(int _a�o) {
	this->a�o = _a�o;

	cout << "LA FECHA INGRESADA FUE: " << dia << "/" << mes << "/" << a�o << endl;

	if (a�o % 4 != 0 || (a�o % 100 == 0 && a�o % 400 != 0)) {
		cout << "EL A�O NO ES BISIESTO\n";
		cout << "---------------------------------------\n";
	}
	else {
		cout << "EL A�O ES BISIESTO\n";
		cout << "---------------------------------------\n";
	}
}

//METODO PARA DARLE LOS DIAS CORRECTOS A CADA MESD EL A�O
int Date::losdiasdelmes(int _a�o) {
	int dias = 31;
	if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
		dias = 30;
	}
	else if (mes == 2) {
		dias = 28;
	}
	return dias;
}

//METODO PARA INCREMENTA DIA, MES Y A�O
void Date::undiamas(int _a�o) {
	this->a�o = _a�o;

	dia++;
	// Declaramos a dia mayor a los dias del mes (dias que se le asigno a a cada mes)
	if (dia > losdiasdelmes(mes)) {
		dia = 1;
		mes++;

		if (mes > 12) {
			mes = 1;
			a�o++;
		}
	}

	cout << "\nLa fecha del siguiente dia es:" << dia << "/" << mes << "/" << a�o;
	cout << "\n------------------------------------------------\n";
}


// sstream ME SIRVIO PARA CONVERTIR UN STRING EN INT/INT/INT DD/MM/AA
void Date::Run() {
	string fecha;
	cout << "Ingrese la fecha:  dd/mm/aa \n";
	cout << "Fecha: ";
	cin >> fecha;
	string diaa, mees, aa�o;
	stringstream input(fecha);

	getline(input, diaa, '/');
	getline(input, mees, '/');
	getline(input, aa�o, '/');

	cout << "\nDia:" << diaa << "\n";
	cout << "\nMes:" << mees << "\n";
	cout << "\nA�o:" << aa�o << "\n";

	dia = stoi(diaa);
	mes = stoi(mees);
	a�o = stoi(aa�o);

	if (dia == 0 || mes > 12 || a�o > 31) {
		cout << "Su fecha ingresada no es valida\n";
	}

	validar_a�o(a�o);
	undiamas(a�o);
}

int main() {
	Date o;
	o.Run();
}