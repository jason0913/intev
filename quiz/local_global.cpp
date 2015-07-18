#include <iostream>
using namespace std;

int vac = 3;

int main(int argc, char const *argv[])
{
	int vac = 10;
	::vac++;
	vac++;
	cout<<::vac<<endl;
	cout<<vac<<endl;
	return 0;
}
