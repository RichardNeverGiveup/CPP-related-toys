#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include<stdlib.h>

#define MAXSIZE 50000  //define the maxsize of the arr to keep our py script,30000 is enough for 450 lines of code. 


void py2bin() // covert our py source code to binary file with our special encoding style.
{
	ifstream ifs("Test.py", ios::in);
	ofstream ofs("Test.bin", ios::out | ios::binary);

	if (!ifs.is_open())
	{
		cout << "failed to open your file!" << endl;
		return;
	}

	char arr[MAXSIZE] = { EOF };

	int count = 0;
	char c;
	while ((c = ifs.get()) != EOF)
	{
		c += 1;  // encoding our script by char.
		arr[count] = c;
		count += 1;
		//ofs.write((const char *)&c, sizeof(c));
	}
	ifs.close();

	//ofs.write((const char *)&arr, sizeof(arr));

	for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
	{
		//arr[i] -= 1;
		if (arr[i] != EOF)
		{
			ofs << arr[i];
		}
	}
	ofs.close();
}
void bin2py() //covert our bin to original py file
{
	ifstream ifs("Test.bin", ios::out | ios::binary);
	ofstream ofs("Test-recover.py", ios::out | ios::binary); // you can specify which folder you want here.

	if (!ifs.is_open())
	{
		cout << "failed to open your file!" << endl;
		return;
	}

	char arr[MAXSIZE] = { EOF };
	int count = 0;
	char c;
	while ((c = ifs.get()) != EOF)
	{
		c -= 1; // decoding our bin file to py script
		arr[count] = c;
		count += 1;
		//ofs.write((const char *)&c, sizeof(c));
	}
	ifs.close();

	//ofs.write((const char *)&arr, sizeof(arr));

	for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
	{
		//arr[i] -= 1;
		if (arr[i] != EOF)
		{
			ofs << arr[i];
		}
	}
	ofs.close();
}

void run_recovered_py_and_delete()
{
	//system("\"C:\\Program Files\\Internet Explorer\\iexplore.exe\" ");
	//system("cd C:\\Users\\E905825\\source\\repos\\python_warper\\python_warper && python Test-recover.py");
	//system("dir");
	//system("Test-recover.py"); //&& del Test-recover.py");
	system("Test-recover.py && del Test-recover.py");
	//system("del Test-recover.py");

}
// 需要注意的是python脚本在结束部分不能有input（）这种让进程停止的语句存在，不然会出现卡在运行PY，来不及删除PY。
int main()
{
	py2bin();
	bin2py();
	run_recovered_py_and_delete();
	system("pause");
	return 0;
}
