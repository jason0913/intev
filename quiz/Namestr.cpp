/*
usage of delete
*/
#include <iostream>
#include <string.h>

using namespace std;

class Namestr
{
public:
	Namestr()
	{
		static const char defalut_name[] = "defalut_name";
		static const char defalut_str[] = "defalut_str";

		pname = new char[strlen(defalut_name)+1];
		pdata = new char[strlen(defalut_str)+1];

		strcpy(pname,defalut_name);
		strcpy(pdata,defalut_str);
	}
	Namestr(const char * Pname,const char *Pdata)
	{
		pname = new char[strlen(Pname)+1];
		pdata = new char[strlen(Pdata)+1];

		strcpy(pname,Pname);
		strcpy(pdata,Pdata);
	}
	~Namestr()
	{
		delete pname;
		delete []pdata;
	};

	void print()
	{
		cout <<"name:"<<pname<<endl;
		cout <<"string:"<<pdata<<endl;
	}
private:
	char *pname;
	char *pdata;
	
};

int main(int argc, char const *argv[])
{
	Namestr *ptr = NULL;
	try
	{
		ptr = new Namestr[10];
		Namestr ns("kingsoft sting","this is test");
		ns.print();
	}
	catch(...)
	{
		cout<<"exception"<<endl;
	}
	delete []ptr;
	return 0;
}