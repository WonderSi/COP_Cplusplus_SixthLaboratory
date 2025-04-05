//
// client2.cpp
// To compile, use: cl Client2.cpp Create.cpp GUIDs.cpp UUID.lib
//
#include <iostream>
#include <objbase.h>

#include "iface.h"
#include "create.h"

using namespace std;

void trace(const char* msg) { cout << "Client 2:\t" << msg << endl; }

//
// Client2 - использует интерфейсы IX и IY
//
int main()
{
    HRESULT hr;

    // Get the name of the component to use.
    char name[40];
    cout << "Enter the filename of a component to use [Cmpnt?.dll]: ";
    cin  >> name;
    cout << endl;

    // Create component by calling the CreateInstance function in the DLL.
    trace("Get an IUnknown pointer.");
    IUnknown* pIUnknown = CallCreateInstance(name);
    if (pIUnknown == NULL)
    {
        trace("CallCreateInstance Failed.");
        return 1;
    }

    trace("Get interface IX.");
    IX* pIX;
    hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);

    if (SUCCEEDED(hr))
    {
        trace("Succeeded getting IX.");
        pIX->Fx();          // Use interface IX.
        pIX->Release();
    }
    else
    {
        trace("Could not get interface IX.");
    }

    trace("Get interface IY.");
    IY* pIY;
    hr = pIUnknown->QueryInterface(IID_IY, (void**)&pIY);

    if (SUCCEEDED(hr))
    {
        trace("Succeeded getting IY.");
        pIY->Fy();          // Use interface IY.
        pIY->Release();
    }
    else
    {
        trace("Could not get interface IY.");
    }

    trace("Release IUnknown interface.");
    pIUnknown->Release();

    return 0;
}
