#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <ctime>
#include <iostream>
#include <Windows.h>
#include <io.h>



using namespace std;
typedef long long ll;

int main()
{
	string dirpath = "S:\\SS\\lvxing\\lvxing3\\";
	char suffixs[] = "*.*";
	

	_finddata_t file;
	long  lf;
	
	vector<string> fileNameList;
	char *p;
	p = (char *)malloc((dirpath.size() + 1)*sizeof(char));
	strcpy(p, dirpath.c_str());

	if ((lf = _findfirst(strcat(p, suffixs), &file)) != -1l)
	{
		do
		{
			string str(file.name);
			fileNameList.push_back(str);
			//cout << file.name << endl;
		} while (_findnext(lf, &file) == 0);
	}

	_findclose(lf);

	string strAdd = "1";

	for (vector<string>::iterator iter = fileNameList.begin(); iter != fileNameList.end(); ++iter)
	{
		string oldName = dirpath + *iter;

		int len = oldName.size();

		string newName = oldName.substr(0, len - 1);

		//cout << newName << endl;

		rename(oldName.c_str(), newName.c_str());
	}

	return 0;
}
