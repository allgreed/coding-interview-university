# Non trivial questions

## C

### typedef struct {} NAME vs struct NAME {}?

Struct does not exist as a type, therefore "struct" before each occurrence of NAME would be required. As it's not very pretty typedef can be utilized.

### How to make function inline?

Don't think about it. The compiler does it for you.

### Weird header error -> redefined consts. Why did they happen?

[Stack](https://stackoverflow.com/questions/24216008/multiple-definition-of-const-variables-at-header-file)

Because `#include` just pastes the file contents, therefore 2 `.o` files are generated with exactly the same consts definitions and the linker can't process it :c

#### Another solution

When working with templates it's best not to split headers and implementation [to allow template specification for all types] which also solves this problem ^^

### How does this work ???

```c
// Returns nearest greater binary power

input--;
input |= input >> 1;
input |= input >> 2;
input |= input >> 4;
input |= input >> 8;
input |= input >> 16;
input++;
```
