#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class Stu
{
public:
	Stu()
	{
		this->id = 0;
		strcpy(this->name, "");
	}
	Stu(int id,char name[64])
	{
		this->id = id;
		strcpy(this->name, name);
	}
	int id;
	char name[64];
	Stu *next;
};
void AddStu(Stu **h)
{
	int id;
	char name[64];
	Stu *q = *h;
	Stu *ptr = NULL;
	for (int i = 0; i < 3; i++)
	{
		cout << "ÊäÈëId:";
		cin >> id;
		cout << "ÊäÈëname:";
		cin >> name;
		ptr = new Stu(id, name);
		q->next = ptr;
		q = ptr;
	}
}
void Print(Stu **h)
{
	Stu *ptr = (*h)->next;
	for (int i = 0; i < 3; i++)
	{
		cout << "id = " << ptr->id << endl;
		cout << "name = " << ptr->name << endl;
		ptr = ptr->next;
	}
}
int main()
{
	Stu *h = new Stu();
	AddStu(&h);
	Print(&h);

	return 0;
}
