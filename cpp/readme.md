# CPP Best Practices


## Code Style
- [read this](./code-style.md)

## Error Handle
- Using exceptions for business logical component or components that do not care performance.
- For low level algorithm components that performance is very important. Handle error by return error code.
- For COM style components on Windows platform, also handle error by return HRESULT.

## Optimize Performance
- [The Lost Art of Structure Packing](http://www.catb.org/esr/structure-packing/). Reordering members of structure or class to save memory if possible. The variables of same length grouped together.
