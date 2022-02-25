## Singleton

Thread safe singleton template. How to use?

```c++
#include "Singleton.h"
class Factory : public Singleton<Factory>
{
public:
	void Create();
}
```

 [Singleton.h](Singleton.h) 