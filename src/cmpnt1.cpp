//
// cmpnt1.cpp
// To compile, use: cl /LD Cmpnt1.cpp GUIDs.cpp UUID.lib Cmpnt1.def
//
#include <objbase.h>

#include <iostream>

#include "iface.h"

void trace(const char* msg) {
  std::cout << "Component 1:\t" << msg << std::endl;
}

//
// Component
//
class CA : public IX {
  // IUnknown implementation
  virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
  virtual ULONG __stdcall AddRef();
  virtual ULONG __stdcall Release();

  // Interface IX implementation
  virtual void __stdcall Fx() { std::cout << "Fx" << std::endl; }

 public:
  // Constructor
  CA() : m_cRef(0) {}

  // Destructor
  ~CA() { trace("Destroy self."); }

 private:
  long m_cRef;
};

HRESULT __stdcall CA::QueryInterface(const IID& iid, void** ppv) {
  if (iid == IID_IUnknown) {
    trace("Return pointer to IUnknown.");
    *ppv = static_cast<IX*>(this);
  } else if (iid == IID_IX) {
    trace("Return pointer to IX.");
    *ppv = static_cast<IX*>(this);
  } else {
    trace("Interface not supported.");
    *ppv = NULL;
    return E_NOINTERFACE;
  }
  reinterpret_cast<IUnknown*>(*ppv)->AddRef();
  return S_OK;
}

ULONG __stdcall CA::AddRef() { return InterlockedIncrement(&m_cRef); }

ULONG __stdcall CA::Release() {
  if (InterlockedDecrement(&m_cRef) == 0) {
    delete this;
    return 0;
  }
  return m_cRef;
}

//
// Creation function
//
extern "C" IUnknown* CreateInstance() {
  IUnknown* pI = static_cast<IX*>(new CA);
  pI->AddRef();
  return pI;
}
