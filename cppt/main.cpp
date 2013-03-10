//#include <boost/stdcpp.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
#include <boost/timer.hpp>
 
using namespace boost;
 
int main()
{
    timer t;
    cout << "max timespan: " << t.elapsed_max() / 3600 << "h" << endl;
    cout << "min timespan: " << t.elapsed_min() << "s" << endl;
 
    cout << "now time elapsed: " << t.elapsed() << "s" << endl;
 
    return EXIT_SUCCESS;
}

