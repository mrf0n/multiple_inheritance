#include <iostream>
#include <string>
#include "Class.h"
using namespace std;

struct tree
{
	utvar* value;
	tree* left;
	tree* right;
	int height;
	explicit tree(utvar* id)
	{
		this->value = id;
		left = nullptr;
		right = nullptr;
		height = 1;
	}
};

int height(tree* node)
{
	return node ? node->height : 0;
}

void fixheight(tree* node)
{
	int hl = height(node->left);
	int hr = height(node->right);
	node->height = (hl > hr ? hl : hr) + 1;
}

tree* RR(tree* node) // правый поворот вокруг q
{
	tree* q = node->left;
	node->left = q->right;
	q->right = node;
	fixheight(node);
	fixheight(q);
	return q;
}

tree* LL(tree* node) // левый поворот вокруг q
{
	tree* q = node->right;
	node->right = q->left;
	q->left = node;
	fixheight(node);
	fixheight(q);
	return q;
}

void LR(tree*& node) //большой правый
{
	LL(node->right);
	RR(node);
}

void RL(tree*& node) //большой левый
{
	RR(node->left);
	LL(node);
}

int balance_factor(tree* node)
{
	return height(node->right) - height(node->left);
}

void update_height(tree* node)
{
	int left = height(node->left);
	int right = height(node->right);
	node->height = (left > right ? left : right) + 1;
}

void balans(tree* node)
{
	if (!node) return;
	balans(node->left);
	if (height(node->right) - height(node->left) == -2)
		if (height(node->left->right) - height(node->left->left) <= 0)
			LL(node);
		else
			LR(node);
	else
		if (height(node->right) - height(node->left) == 2)
			if (height(node->right->right) - height(node->right->left) >= 0)
				RR(node);
			else
				RL(node);
	balans(node->right);
}

void AddToTree(tree*& node, utvar* elem) // добавляемый ключ
{
	if (!node)
	{
		node = new tree(elem);
	}
	else
	{
		if (elem->getid() < node->value->getid())
		{
			AddToTree(node->left, elem);
		}
		if (elem->getid() > node->value->getid())
		{
			AddToTree(node->right, elem);
		}
	}
	balans(node);

}

tree* find_min(tree* node)
{
	return node->left ? find_min(node->left) : node;
}

tree* remove_min(tree* node)
{
	if (node->left == 0)
		return node->right;
	node->left = remove_min(node->left);
	balans(node);
	return node;
}

bool existance(tree* node, int id)
{
	if (!node) return false;
	if (id == node->value->getid()) return true;
	if (id < node->value->getid())
		existance(node->left, id);
	else return existance(node->right, id);
	return false;
}

tree* search(tree* node, int id)
{
	if (!node) return NULL;
	if (id == node->value->getid()) return node;
	if (id < node->value->getid())
		return search(node->left, id);
	else return search(node->right, id);

}

tree* remove(tree* node, const int id)
{
	if (!node) return nullptr;
	else if (id < node->value->getid())
	{
		node->left = remove(node->left, id);
	}
	else if (id > node->value->getid())
	{
		node->right = remove(node->right, id);
	}
	else if (id == node->value->getid())
	{
		tree* left = node->left;
		tree* right = node->right;
		delete node->value;
		delete node;
		if (!right) return left;
		tree* min = find_min(right);
		min->right = remove_min(right);
		min->left = left;
		balans(min);
		return min;
	}
	balans(node);
	return node;
}

void PrintTree(tree* node) //печать дерева
{
	if (node != NULL)
	{
		PrintTree(node->right);
		cout << node->value->type() << endl;
		node->value->print();
		cout << endl;
		PrintTree(node->left);
	}
}

void Pryamoy(tree* node) //прямой  клп
{
	if (!node) return;
	cout << node->value->type() << endl;
	node->value->print();
	Pryamoy(node->left);
	Pryamoy(node->right);
}

void Obratnyi(tree* node) //обратный  лпк
{
	if (!node) return;
	Obratnyi(node->left);
	cout << node->value->type() << endl;
	node->value->print();
	Obratnyi(node->right);
}

void Simm(tree* node)//симметричный  лкп
{
	if (!node) return;
	Simm(node->left);
	Simm(node->right);
	cout << node->value->type() << endl;
	node->value->print();
}

void delete_tree(tree* node)
{
	if (!node) return;
	delete_tree(node->left);
	delete_tree(node->right);
	delete node->value;
	delete node;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	tree* main_tree = nullptr;
	bool flag = true;
	while (flag)
	{
		int chislo, class_, id;
		cout << "1 - Добавить элемент" << endl;
		cout << "2 - Удалить элемент" << endl;
		cout << "3 - Вывод дерева" << endl;
		cout << "4 - Выход" << endl;
		try
		{
			cin >> chislo;
			switch (chislo)
			{
			case 1:
			{
				cout << "Введите инвентарный номер: ";
				cin >> id;
				if (existance(main_tree, id))
				{
					cout << "Уже существует элемент с таким ID" << endl;
					tree* temp = main_tree;
					PrintTree(search(temp, id));
				}
				else
				{
					cout << "Выберите класс элемента:" << endl;
					cout << "1 - Плита" << endl;
					cout << "2 - Кастрюлька" << endl;
					cout << "3 - Электрическая плита" << endl;
					cout << "4 - Газовая плита" << endl;
					cout << "5 - Мультиварка" << endl;
					cin >> class_;
					switch (class_)
					{
					case 1:
					{
						string color;
						cout << "Введите цвет: ";
						cin >> color;
						utvar* elem = new plita(id, color);
						//elem->id = id;
						AddToTree(main_tree, elem);
						break;
					}
					case 2:
					{
						int v;
						cout << "Введите обЪем: ";
						cin >> v;
						utvar* elem = new castrula(id,v);
						//elem->id = id;
						AddToTree(main_tree, elem);
						break;
					}
					case 3:
					{
						int p; string color;
						cout << "Введите мощность плиты в кВт: ";
						cin >> p;
						cout << "Введите цвет: ";
						cin>> color;
						utvar* elem = new e_plita(id,p,color);
						//elem->id = id;
						AddToTree(main_tree, elem);
						break;
					}
					case 4:
					{
						int ras; string color;
						cout << "Введите расход газа: ";
						cin >> ras;
						cout << "Введите цвет: ";
						cin >> color;
						utvar* elem = new gas_plita(id,ras,color);
						//elem->id = id;
						AddToTree(main_tree, elem);
						break;
					}
					case 5:
					{
						string color; int mv; int mp; bool fastovarka;
						cout << "Введите цвет: ";
						cin >> color;
						cout << "Введите обЪем: ";
						cin >> mv;
						cout << "Введите мощность плиты в кВт: ";
						cin >> mp;
						cout << "Есть ли функция скороварки (0-нет, 1-есть)";
						cin>> fastovarka;
						utvar* elem = new varim_krek(id,color,mv,mp,fastovarka);
						//elem->id = id;
						AddToTree(main_tree, elem);
						break;
					}
					default:
					{
						cout << "Такого класса нет";
						break;
					}
					}
				}
				break;
			}
			case 2:
			{
				int id;
				try
				{
					cout << "Введите инвентарный номер элемента, который хотите удалить: ";
					cin >> id;
					if (existance(main_tree, id))
					{
						main_tree = remove(main_tree, id);
					}
					else
					{
						cout << "Такого инвентарного номера нет" << endl;
					}
				}
				catch (exception e)
				{
					cout << e.what() << endl;
				}
				break;
			}
			case 3:
			{
				int metod;
				cout << "1 - Прямой" << endl;
				cout << "2 - Обратный" << endl;
				cout << "3 - Симметричный" << endl;
				try
				{
					cin >> metod;
					switch (metod)
					{
					case 1:
					{
						cout << endl;
						Pryamoy(main_tree);
						break;
					}
					case 2:
					{
						cout << endl;
						Obratnyi(main_tree);
						break;
					}
					case 3:
					{
						cout << endl;
						Simm(main_tree);
						break;
					}
					default:
					{
						cout << "Такого обхода нет" << endl;
						break;
					}
					}
				}
				catch (exception e)
				{
					cout << e.what() << endl;
				}
				break;
			}
			case 4:
			{
				delete_tree(main_tree);
				flag = false;
				break;
			}
			default:
			{
				cout << "Такого действия нет" << endl;
				break;
			}
			}
		}
		catch (exception e)
		{
			cout << e.what() << endl;
			continue;
		}
	}
}
