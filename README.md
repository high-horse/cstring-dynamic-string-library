# CString Dynamic String Library for C

A lightweight dynamic string library for C that provides safer and more flexible string manipulation than raw `char*`.

> ⚠️ Note: This library does **not support Unicode**. It operates on standard byte-based C strings.

---

## ✨ Features

- Dynamic string resizing
- Rich set of string manipulation utilities
- Simple struct-based design
- Array utilities for splitting strings
- Case-insensitive comparisons
- Trim, replace, insert, and more

---

## 📦 Installation

```bash
git clone https://github.com/high-horse/cstring-dynamic-string-library.git
cd cstring-dynamic-string-library
```

Include in your project:
```c
#include "cstring.h"
```

## Quick Example
```c
#include <stdio.h>
#include "cstring.h"

int main() {
    CString str = new_cstring("Hello");

    cstring_append(&str, ", World!");
    cstring_to_upper(&str);

    printf("%s\n", str.str);   // HELLO, WORLD!
    printf("Length: %d\n", cstring_len(&str));

    destroy_cstring(&str);
    return 0;
}
```

## Common Usage
### Create & Destroy
```c
CString s = new_cstring("Hello");
destroy_cstring(&s);
```

### Append / Prepend
```c
cstring_append(&s, " World");
cstring_prepend(&s, "Say: ");
cstring_append_cstring(&s1, &s2);

cstring_append_char(&s, '!');
cstring_prepend_char(&s, '#');
cstring_prepend_cstring(&s1, &s2);
```

### Insert
```c
cstring_insert(&s, 3, "INSERT");
cstring_insert_char(&s, 0, '*');  // AT_FIRST_INDEX
```

### Compare
```c
CString a = new_cstring("Hello");
CString b = new_cstring("hello");

cstring_equals(&a, &b);                 // false
cstring_equals_ignore_case(&a, &b);     // true
```

### Search
```c
cstring_contains(&s, "World");
cstring_indexof(&s, "World");

cstring_starts_with(&s, "Hello");
cstring_ends_with(&s, "!");
```

### Replace
```c
cstring_replace(&s, "World", "C");
cstring_replaceall(&s, "l", "x");
cstring_replace_char(&s, 'x', 'l');
```

### Trim
```c
CString s = new_cstring("   hello   ");

cstring_ltrim(&s);
cstring_rtrim(&s);
cstring_trim(&s);
```

### Case Conversion
```c
cstring_to_upper(&s);
cstring_to_lower(&s);
```

### Substring
```c
CString sub = cstring_substring(&s, 0, 5);
// remember to free
destroy_cstring(&sub);
```


### Reverse
```c
cstring_reverse(&s);
Remove Characters
cstring_remove(&s, "aeiou");  // removes vowels
```


### Repeat
```c 
CString repeated = cstring_repeat(&s, 3);
destroy_cstring(&repeated);
```

### Split
```c
CString s = new_cstring("a,b,c");

CStringArray arr = cstring_split(&s, ",");

for (size_t i = 0; i < arr.len; i++) {
    printf("%s\n", arr.item[i].str);
}

cstring_array_free(&arr);
destroy_cstring(&s);
```

## Data Structures
`CString`
```c
typedef struct {
    char *str;
    size_t len;
    size_t capacity;
} CString;
```

`CStringArray`
```c
typedef struct {
    CString *item;
    size_t len;
    size_t capacity;
} CStringArray;
```


## Important Notes
- Always call `destroy_cstring()` to avoid memory leaks
- Functions that modify strings may reallocate memory
- Indexing is 0-based
- Use:
  - `AT_FIRST_INDEX` (0)
  - `AT_LAST_INDEX` (-1) (if supported internally)
- Unicode / UTF-8 handling is **not supported**
- All operations are byte-based
