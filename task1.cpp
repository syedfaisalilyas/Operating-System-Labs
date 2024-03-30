#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string cfilename;
	cout << "Enter the filename that you want to copy: ";
	cin >> cfilename;
	
	string wfilename;
	cout << "\n Enter the filename in which you want to copy: ";
	cin >> wfilename;
	
	ifstream readFile(cfilename);
	if (readFile.is_open())
	{	
		string dataArr[100];
		int count = 0;
		while(!readFile.eof())
		{
			getline(readFile, dataArr[count]);
			count++;
		}
		readFile.close();
	
	
		ofstream file(wfilename);
		if (file.is_open())
		{
			for (int i = 0; i < count; i++)
			{
				file << dataArr[i] <<endl;
			}
			file.close();
			cout << "Successfull!" << endl;
		}
		else
		{
			cerr << "Error creating the file " << endl;	
		}
	
	}
	else
	{
		cerr << "Error Opening the given file Or file not present !!!" << endl;
	}
	
	return 0;
}
