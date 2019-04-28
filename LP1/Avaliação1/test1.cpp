#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(11);
	vector<int>::iterator i = vec.begin();
	cout << *(i) << endl;

	return 0;
}
