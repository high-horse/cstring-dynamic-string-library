#include "cstring.h"
#include <stdio.h>


int main() {
    CString parent = new_cstring("hello world");
    CString child = cstring_substring(&parent, 0, 100);
    printf("child => |%s|\n len => %d\n", child.str, (int)child.len);
    
    cstring_reverse(&child);
    printf("child => |%s|\n", child.str, (int)child.len);
    
    
    return EXIT_SUCCESS;
}

void test() {

    CString first = new_cstring("Hellot");
    CString second = new_cstring("hello");
    CString third = new_cstring("");
    
    printf("first %s \t second %s\n", first.str, second.str);
    printf("is empty => %d\n", cstring_isempty(&third));
    
    printf("compares => %d\n", cstring_compare(&first, &second));
    printf("equals => %d\n", cstring_equals(&first, &second));
    printf("equals ignore case => %d\n",
            cstring_equals_ignore_case(&first, &second));
    printf("cstring_find => %d\n", cstring_indexof(&first, "t"));
    printf("contains => %d \n", cstring_contains(&first, "Hello"));
    
    printf("cstring_starts_with => %d\n", cstring_starts_with(&first, "H"));
    printf("cstring_ends_with => %d\n", cstring_ends_with(&first, "t"));
    
    // if(!){
    //     perror("FAILED TO APPEND:");
    //     exit(EXIT_FAILURE);
    // }
    if (!cstring_append(&second, " world")) {
        perror("FAILED TO APPEND:");
        exit(EXIT_FAILURE);
    }
    printf("second %s\n", second.str);
    cstring_append_char(&first, ' ');
    cstring_append_cstring(&first, &second);
    printf("first =>%s \n second =>%s\n", first.str, second.str);
    
    cstring_prepend(&first, "prepended ");
    printf("first =>%s \n second =>%s\n", first.str, second.str);
    return;
}

void test_again() {
    CString a = new_cstring("");
    CString s = new_cstring("world");
    printf("A len => %d\t capacity => %d\t value =>%s\n", (int)a.len,
            (int)a.capacity, a.str);
    // printf("S len => %d\t capacity => %d\t value =>%s\n", (int)s.len,
    // (int)s.capacity, s.str);
    
    cstring_prepend_cstring(&a, &s);
    printf("A len => %d\t capacity => %d\t value =>%s\n", (int)a.len,
            (int)a.capacity, a.str);
    // printf("S len => %d\t capacity => %d\t value =>%s\n", (int)s.len,
    // (int)s.capacity, s.str);
    
    cstring_append_char(&a, 'a');
    printf("A len => %d\t capacity => %d\t value =>%s\n", (int)a.len,
            (int)a.capacity, a.str);
    // printf("S len => %d\t capacity => %d\t value =>%s\n", (int)s.len,
    // (int)s.capacity, s.str);
    
    cstring_append(&a, "some unholy aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    printf("A len => %d\t capacity => %d\t value =>%s\n", (int)a.len,
            (int)a.capacity, a.str);
    
    cstring_append(&a, "some unholy bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
    printf("A len => %d\t capacity => %d\t value =>%s\n", (int)a.len,
            (int)a.capacity, a.str);
    
    cstring_append(&a, "some unholy bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
    printf("A len => %d\t capacity => %d\t value =>%s\n", (int)a.len,
            (int)a.capacity, a.str);
    
    cstring_append_cstring(&a, &a);
    printf("A len => %d\t capacity => %d\t value =>%s\n", (int)a.len,
            (int)a.capacity, a.str);
}

void test_replace() {
    CString a = new_cstring("hello, hello, hello, hello");
    // printf("%d %d\n", &a , &a == &a);
    printf("A len => %d\t capacity => %d\t value =>%s\n", (int)a.len,
            (int)a.capacity, a.str);
    
    // cstring_prepend_cstring(&a, &a);
    // cstring_insert(&a, AT_LAST_INDEX, "-help-");
    cstring_replaceall(&a, "hell", "help");
    // cstring_prepend_cstring(&a, &a);
    // cstring_prepend_cstring(&a, &a);
    
    printf("A len => %d\t capacity => %d\t value =>%s\n", (int)a.len,
            (int)a.capacity, a.str);
}

void test_trim() {
    CString a = new_cstring("         hello        ");
    printf("a str => |%s| \n", a.str);
    
    cstring_ltrim(&a);
    printf("a str => |%s| \n", a.str);
    cstring_rtrim(&a);
    printf("a str => |%s| \n", a.str);
    cstring_append(&a, "            ");
    cstring_prepend(&a, "            ");
    printf("a str => |%s| \n", a.str);
    cstring_trim(&a);
    printf("a str => |%s| \n", a.str);
}


void test_upper_lower_case() {
    CString a = new_cstring("hello world| 123| %^&*(");
    printf("a str => |%s| \n", a.str);
    cstring_to_upper(&a);
    printf("a str => |%s| \n", a.str);
    cstring_to_lower(&a);
    printf("a str => |%s| \n", a.str);
    
}


void test_split() {
    CString greet = new_cstring("hello world good morning   h   n ");
    CStringArray results =  cstring_split(&greet, " ");
    printf("results.len => %zu\n", results.len);
    for (size_t i = 0; i < results.len; i++) {
        printf("result[%zu] => %s\n", i, results.item[i].str);
    }
    
    cstring_array_free(&results);
}