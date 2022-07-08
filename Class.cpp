#include "Class.h"
#include <string>;
#include <iostream>

utvar::utvar(int my_id)
{
	id = my_id;
}
int utvar::getid() const { return id; }
void utvar::print()
{
	cout << "ID: " << id << endl;
}
void plita::print()
{
	utvar::print();
	cout << "color: " << color << endl;
}
plita::plita(int my_id, string my_color) : utvar(my_id)
{
	color = my_color;
}
castrula::castrula(int my_id, int my_v) : utvar(my_id)
{
	v = my_v;
}
void castrula::print()
{
	utvar::print();
	cout << "objem: " << v << endl;
}
e_plita::e_plita(int my_id, int my_p, string my_color) : plita(my_id, my_color), utvar(my_id)
{
	p = my_p;
}
void e_plita::print()
{
	plita::print();
	cout << "power: " << p << endl;
}
gas_plita::gas_plita(int my_id, int my_rashod, string my_color) : plita(my_id, my_color), utvar(my_id)
{
	rashod = my_rashod;
}
void gas_plita::print()
{
	{
		plita::print();
		cout << "rashod: " << rashod << endl;
	}
}
varim_krek::varim_krek(int my_id, string my_color, int my_v, int my_p, bool my_fastovarka) : e_plita(my_id, my_p, my_color), plita(my_id, my_color), castrula(my_id, my_v), utvar(my_id)
{
	fastovarka = my_fastovarka;
}
void varim_krek::print()
{
	e_plita::print();
	cout << "objem: " << v << endl;
	cout << "skorovarka: " << fastovarka << endl;
}
string utvar::type()
{
	return{};
}
string varim_krek::type()
{
	return "varim_krek";;
}
string gas_plita::type()
{
	return "gas_plita";
}
string e_plita::type()
{
	return "e_plita";
}
string castrula::type()
{
	return "Castrula";
}
string plita::type()
{
	return "plita";
}