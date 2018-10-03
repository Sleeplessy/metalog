# metalog

A meta-template style log system.

Currently only contains very basic features(really very basic). More updates would come these days.

## Usage

Put this repo in your include path, and include the main header in your source like:
```C++
#include <metalog/metalog.hpp>
```
or include the sparerate headers if you like:
```C++
#include <metalog/core/printable.hpp>
#include <metalog/core/content.hpp>
```

## Example

I do have plans for unit tests but not now, please went to the "main.cc" contains in the repo.

In my macOS using clang, the output of the example would be:
```
foo printable:true
da printable:true
i printable:true
3zig printable:false
test
test
```