#include <iostream>
#include <string>
using namespace std;

class excursion
{
	private:
		string name;
		string date;
		int duration;
		int cost;
	public:
		excursion();
		excursion(string n, string date, int dur, int cost);
};
excursion::excursion():name("none"), date("none"), duration(0),cost(0){}
excursion::excursion(string n, string date, int dur, int cost) : name(n), date(date), duration(dur), cost(cost) {}

class pedexcursion : public excursion
{
	private:
		string guide;
		double salary;
		int cost;
		int proz;
	public:
		pedexcursion();
		pedexcursion(string g, int c, int p);
		void input();
		void print(pedexcursion arr[], int size);
		void bubblesort(pedexcursion arr[], int size);
		
};
pedexcursion::pedexcursion():guide("unknown"),salary(0),cost(0),proz(0){}
pedexcursion::pedexcursion(string g, int c, int p): guide(g), salary(c*p/100),cost(c),proz(p){}
void pedexcursion::input()
{
	cout << "name of guide : ";
	cin >> guide;
	cout << "cost of excursion : ";
	cin >> cost;
	cout << "prozent : ";
	cin >> proz;
	salary = cost * proz / 100;
}
void pedexcursion::print(pedexcursion arr[], int size)
{
	for (int i = 0;i < size;i++)
	{
		cout << arr[i].guide << endl;
	}
}
void pedexcursion::bubblesort(pedexcursion arr[],int size)
{
	pedexcursion temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j].salary < arr[j + 1].salary) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main()
{
	pedexcursion arr[10];
	int n;
	cout << "input count of guides : ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		arr[i] = pedexcursion();
		arr[i].input();
	}
	arr->bubblesort(arr,n);
	arr->print(arr, n);
	return 0;
}

//додати відсоток зарплатні і цілу ціну екскурсії


//Створити базовий клас ЕКСКУРСІЯ(задаються назва, дата, тривалість, вартість).
//Створити похідний клас ПІШОХІДНА ЕКСКУРСІЯ(задаються дані про гіда та частка заробітку гіда у вартості).
//Для введених даних про екскурсії обчислити сумарний заробіток
//для кожного гіда і відсортувати заробітки гідів за спаданням.