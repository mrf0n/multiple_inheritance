#pragma once
using namespace std;
#include <string>;
#include <iostream>
class utvar
{
protected:
	int id;
	utvar(int my_id);
public:
	virtual int getid() const;
	virtual string type();
	virtual ~utvar() = default;
	utvar() {};
	virtual void print();
};

class plita : public virtual utvar
{
protected:
	string color;
public:
	string type() override;
	virtual ~plita() = default;
	plita(int my_id, string my_color);
	void print() override;
};

class castrula : public virtual utvar
{
protected:
	int v;
public:
	string type() override;
	virtual ~castrula() = default;
	castrula(int my_id, int my_v);
	void print() override;
};

class e_plita : public virtual plita
{
protected:
	int p;
public:
	string type() override;
	virtual ~e_plita() = default;
	e_plita(int my_id, int my_p, string my_color);
	void print() override;
};

class gas_plita : public plita
{
protected:
	int rashod;
public:
	string type() override;
	virtual ~gas_plita() = default;
	gas_plita(int my_id, int my_rashod, string my_color);
	void print() override;
};

class varim_krek : public e_plita, public castrula
{
protected:
	bool fastovarka;
public:
	string type() override;
	virtual ~varim_krek() = default;
	varim_krek(int my_id, string my_color, int my_v, int my_p, bool my_fastovarka);
	void print() override;
};

