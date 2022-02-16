# CPP Best Practices


## Code Style
- [read this](./code-style.md)

## Error Handle
- Using exceptions for business logical component or components that do not care performance.
- For low level algorithm components that performance is very important. Handle error by return error code.
- For COM style components on Windows platform, also handle error by return HRESULT.

## How To Use Exception
- Define your own exception types by deriving std::exception
- For interface that return pointers, always throw exception and do not return nullptr. This can eliminate annoying nullptr checks by the client.

## Optimize Performance
- [The Lost Art of Structure Packing](http://www.catb.org/esr/structure-packing/). Reordering members of structure or class to save memory if possible. The variables of same length grouped together.
