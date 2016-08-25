#ifndef _TYPES_H_
#define _TYPES_H_

#include "ref.h"

// simple linked list, list and rest are both refstructs
refstruct(list, {
    struct list *rest;
    void *first;
});
#define EMPTY NULL


// a string type
refstruct(string, {
    char *str;
    size_t length;
    bool is_static;
});


// a fixed point numeric type
refstruct(fixed, {
    size_t num;
    size_t den;
});


#define STATIC(s) _string((s), 0)

void string_destructor(string *string_v);
size_t string_hash(string *string_v);
bool string_equals(string *a, string *b);
string *_string(char *str, bool is_static);
list *_list(void *elem, list *rest);
fixed *_fixed(size_t, size_t);
void *strcopy(void *);
void *strappend(void *, void *);
#endif
