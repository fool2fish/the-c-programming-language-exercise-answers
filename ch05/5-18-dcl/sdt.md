# Simplified Syntax-directed Translation Scheme

```
declaration:
    declaration-specifiers declarator  {printf("%s", declaration-specifiers)}

declaration-specifiers:
    storage-class-specifier declaration-specifiers?
  | type-specifier declaration-specifiers?
  | type-qualifier declaration-specifiers?

storage-class-specifier:
    "auto"
￼￼  | "register"
  | "static"
  | "extern"

type-specifier:
    "void"
  | "char"
  | "short"
  | "int"
  | "long"
  | "float"
  | "double"
  | "signed"
  | "unsigned"

type-qualifier:
    "const"
  | "volatile"

declarator:
    direct-declarator
  | pointer direct-declarator {printf("%s"), pointer}

direct-declarator:
    identifier
  | (declarator)
  | direct-declarator "[" digits? "]"
  | direct-declarator "(" params? ")"

pointer:
    "*" pointers?

params:
    [^)]*
```

提取左公因子

```
direct-declarator:
    direct-declarator-simple
  | direct-declarator director-declarator-postfix

direct-declarator-simple:
    identifier
  | (declarator)

director-declarator-postfix:
    "[" digits? "]"
  | "(" params? ")"
```

消除左递归

```
direct-declarator:
    direct-declarator-simple direct-declarator-arr-fn

direct-declarator-simple:
    identifier       {printf("%s: ", identifier)}
  | (declarator)

direct-declarator-arr-fn:
    director-declarator-postfix direct-declarator-arr-fn
  | epsilon

director-declarator-postfix:
    "[" digits? "]"  {printf("array[%s] of ", digits)}
  | "(" params? ")"  {printf("function(%s) returning ", params)}
```
