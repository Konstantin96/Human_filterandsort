#include "Filter.h"
#include "SortByKey.h"
#include "findByname.h"

void print(human h) {
	cout << h.getName() << "\t" << h.geSname() << "\n";
}

int main() {
	setlocale(LC_ALL, "ru");
	vector<human> vh;
	vh.push_back(human("Kostya", "Klyukin", 22));
	vh.push_back(human("Kostya", "Larin", 27));
	vh.push_back(human("Sasha", "Snaz", 27));
	vh.push_back(human("Lida", "Knaub", 24));
	vh.push_back(human("Liza", "Snaub", 22));

	string key, svalue;
	int ivalue;
	int g;
	do
	{	
		cout << "¬ведите 1 будет сделана фильтраци€       (1) \n";
		cout << "¬ведите 2 будет сделана сортировка       (2) \n";
		cout << "¬ведите 3 чтобы найти им€      (0 close) (3) : ";
		cin >> g;

		if (g == 1) {
			cout << "¬ведите ключ(name, sname, age): ";
			cin >> key;
			if (key == "name")
			{
				cout << "\nвведите строковое значение дл€ фильтрации: "; cin >> svalue;
				auto it = vh.erase(remove_if(vh.begin(), vh.end(), filter("name", svalue)), vh.end());
				for_each(vh.begin(), vh.end(), print);
			}
			else if (key == "sname")
			{
				cout << "\nвведите строковое значение дл€ фильтрации: "; cin >> svalue;
				auto it = vh.erase(remove_if(vh.begin(), vh.end(), filter("sname", svalue)), vh.end());
				for_each(vh.begin(), vh.end(), print);
			}
			else if (key == "age")
			{
				cout << "\nвведите числовое значение дл€ фильтрации: "; cin >> ivalue;
				auto it = vh.erase(remove_if(vh.begin(), vh.end(), filter("age", ivalue)), vh.end());
				for_each(vh.begin(), vh.end(), print);
			}
			else {
				cout << "\nошибка, вы ввели неправильное значение дл€ ключа\n";
			}
			system("pause");
		}

		else if (g == 2) {
			cout << "¬ведите ключ(name, sname, age): ";
			cin >> key;
			if (key == "name")
			{
				sort(vh.begin(), vh.end(), SortByKey(key));
				for_each(vh.begin(), vh.end(), print);
			}
			else if (key == "sname")
			{
				sort(vh.begin(), vh.end(), SortByKey(key));
				for_each(vh.begin(), vh.end(), print);
			}
			else if (key == "age")
			{
				sort(vh.begin(), vh.end(), SortByKey(key));
				for_each(vh.begin(), vh.end(), print);
			}
			else {
				cout << "\nошибка, вы ввели неправильное значение дл€ ключа\n";
			}
			system("pause");
		}

		else if (g == 3) {
			cout << "¬ведите им€: "; cin >> svalue;
			auto it = find_if(vh.begin(), vh.end(), findByName(svalue));
			if (it != vh.end())
				cout << it->getName() << " " << it->geSname() << "\t" << it->getAge() <<" года"<< endl;
			system("pause");
		}
		else if (g == 0) {
			cout << "                     ---------\n";
			cout << "                     |Bye Bye|\n";
			cout << "                     ---------\n";
			system("pause");
		}
		else {
			cout << "\nошибка, вы ввели неправильное значение!\n";
			system("pause");
		}

		system("cls");

	} while (g!=0);

	return 0;
}