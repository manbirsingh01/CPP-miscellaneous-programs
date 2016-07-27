#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Usuage: " << argv[0] << " <string(sentence)>"  << endl;
        exit(0);
    }
    string origStr = argv[1];
    cout << "Input string is : " << origStr << endl;
    stringstream ss(origStr);
    istream_iterator<std::string> begin(ss);
    istream_iterator<std::string> end;
    vector <string> vStr(begin,end);

    vector <string>::iterator itr = vStr.end();
    vector <string>::iterator itr1 = vStr.begin();
    
    cout << "Output string is : ";
    for(itr--; itr >= itr1 ; itr--)
    {
    	cout << *itr << " ";
    }
    cout << endl;

}
