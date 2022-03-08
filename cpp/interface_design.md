## How to design DLL interface

- Memory management. The user create the instance of IInterface by calling CreateInterface. And release the object by call IInterface::Release
- You just need to export the CreateInterface, and call methods by using the pure abstract class IInterface, which do not need to export.
- By declare destructor protected, can prevent the user from delete the interface outside of the DLL, which can cause "Cross-DLL problem".

```c++
namespace bestcpp{
	class IInterface
	{
	public:
        virtual void Print() = 0;
        virtual void Release() = 0;
    protected:
        // Note that, the use is not allow to create or destory the interface        
        virtual ~IInterface() {}
        // No need to declare the copy and assignment operator constructor as protected,
	    // because the user can not new a pure virtual class
	}
}
extern "C" BESTCPP_EXPORT IInterface* CreateInterface();
```

- Do not use C++ STL types as interface parameters or return types. If you want to use shared_ptr or other STL types, wrap using a custom class.

## How to use efficiently

```c++
// Method1 manually release
IInterface* iptr = CreateInterface();
iptr->Release();
```

```c++
// Method2 using smart pointer
struct PtrDeleter {
    template<class T>
    void operator()(T* obj) {
        if (obj) {
            obj->Release();
        }
    }
};
template<class T>
using UPtr = std::unique_ptr<T, PtrDeleter>;

UPtr<bestcpp::IInterface> iptr(CreateInterface());
// call Release automatically
```

