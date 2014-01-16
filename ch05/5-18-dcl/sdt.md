# Simplified Syntax-directed Translation Scheme

```
declaration:
    declaration_specifiers declarator  {printf("%s", declaration_specifiers)}

declaration_specifiers:
    storage_class_specifier declaration_specifiers?
  | type_specifier declaration_specifiers?
  | type_qualifier declaration_specifiers?

storage_class_specifier:
    "auto"
￼￼  | "register"
  | "static"
  | "extern"

type_specifier:
    "void"
  | "char"
  | "short"
  | "int"
  | "long"
  | "float"
  | "double"
  | "signed"
  | "unsigned"

type_qualifier:
    "const"
  | "volatile"

declarator:
    direct_declarator
  | pointers direct_declarator {printf("%s"), pointers}

direct_declarator:
    identifier
  | (declarator)
  | direct_declarator "[" digits? "]"
  | direct_declarator "(" params? ")"

pointers:
    "*" pointers?

params:
    [^)]*
```

提取左公因子

```
direct_declarator:
    direct_declarator_simple
  | direct_declarator director_declarator_postfix

direct_declarator_simple:
    identifier
  | (declarator)

director_declarator_postfix:
    "[" digits? "]"
  | "(" params? ")"
```

消除左递归

```
direct_declarator:
    direct_declarator_simple direct_declarator_arr_fn

direct_declarator_simple:
    identifier       {printf("%s: ", identifier)}
  | (declarator)

direct_declarator_arr_fn:
    director_declarator_postfix direct_declarator_arr_fn
  | epsilon

director_declarator_postfix:
    "[" digits? "]"  {printf("array[%s] of ", digits)}
  | "(" params? ")"  {printf("function(%s) returning ", params)}
```
