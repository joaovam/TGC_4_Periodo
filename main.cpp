
#include "AdjacencyList.h"

using namespace std;

int main(int argc, char *argv[])
{
    try
    {

        AdjacencyList list = AdjacencyList(10);

        list.print();
    }
    catch (exception &e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}