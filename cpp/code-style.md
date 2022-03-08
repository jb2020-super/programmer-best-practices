# Code Styles

- `CamelCase`: Class names, function names.
- `snake_case`: Local variables, function parameters.
- `m_snake_case`: Non-static class member variables.
- `UPPER_CASE`: Macros, static member variables, const variables.
- Using `{}`to initialize variables.
- Using `nullptr` for null pointer, instead of `0 or NULL`.
- Using `#pragma once` to guard header files.
- Always using `{}` for blocks.
- Avoid very long code lines, less than 80 characters.
- Using `""` to include local files
- Always using namespaces
- Using `const` for not changed parameters. Using `const &` for non-basic data types.

```c++
#pragma once
#include <iostream>
#include "MyHeaders.h"

namespace style{
class ExampleClass
{
public:
    ExampleClass(){}
    ~ExampleClass(){}
    virtual ThisIsInterface(const int params_name) = 0;
    void DoSomething(const std::string &str){
        int local_vars{10};
        if (condition1() ||
           condition2() ||
           condition3()){
            // good idea
        }
    }
private:
    inline const static int MAX_SIZE{100}; // need c++17
    const double PI{3.14};
    
    int m_array[MAX_SIZE]{};
    int m_vars{0};
    int* m_ptr{nullptr};
}
}
```

## Reference

- https://github.com/cpp-best-practices/cppbestpractices/blob/master/03-Style.md
- https://kotaku.com/the-exceptional-beauty-of-doom-3s-source-code-5975610