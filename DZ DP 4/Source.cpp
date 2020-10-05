#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;
int GetRandomNumber()
{
	srand(time(0));
	return rand() % 100 + 0;
}
class Database
{
protected:
	const string connectionString = "kriolt.txt";
	bool isConnect = false;
public:
	void Log(string path)
	{
		ofstream out;
		out.open(path, ios::app);
		string msg;
		cout << "Enter message: ";
		cin >> msg;
		if (out.is_open())
		{
			out << msg << endl;
		}
		out.close();
	}
	bool IsConnect(string connectionString)
	{
		if (connectionString != this->connectionString)
		{
			cout << "Error: file path is incorrect" << endl;
		}
		int percent = GetRandomNumber();
		if (percent >= 41)
		{
			this->isConnect = 1;
		}
		else if (percent <= 40)
		{
			this->isConnect = 0;
		}
	}
};

class DatabaseProxy : public Database
{
private:
	Database * _database = new Database();
	string tempConnectionString = "lTkrt.txt";
public:
	void Log()
	{
		if (_database == nullptr)
		{
			_database = new Database();
		}
		if (_database->IsConnect("kriolt.txt") == false)
		{
			_database->Log(tempConnectionString);
		}
		else
		{
			_database->Log("kriolt.txt");
		}
	}
};


void main()
{

	system("pause");
}



