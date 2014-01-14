# Simplified Production

```
declaration:
    declaration-specifiers declarator;

declaration-specifiers:
    storage-class-specifier declaration-specifiers?
  | type-specifier declaration-specifiers?
  | type-qualifier declaration-specifiers?

storage-class specifier:
    'auto'
￼￼  | 'register'
  | 'static'
  | 'extern'
  | 'typedef'

type-specifier:
    'void'
  | 'char'
  | 'short'
  | 'int'
  | 'long'
  | 'float'
  | 'double'
  | 'signed'
  | 'unsigned'

type-qualifier:
    'const'
  | 'volatile'

declarator:
  pointer? direct-declarator

direct-declarator:
    identifier
  | (declarator)
  | direct-declarator '[' digits? ']'
  | direct-declarator '(' parameter-type-list? ')'

pointer:
    '*' type-qualifier-list? pointer?

type-qualifier-list:
    type-qualifier type-qualifier-list?

parameter-type-list:
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
    '[' digits? ']'
  | '(' parameter-type-list? ')'
```

消除左递归

```
direct-declarator:
    direct-declarator-simple direct-declarator-arr-fn

direct-declarator-simple:
    identifier
  | (declarator)

direct-declarator-arr-fn:
    director-declarator-postfix direct-declarator-arr-fn
  | epsilon

director-declarator-postfix:
    '[' digits? ']'
  | '(' parameter-type-list? ')'
```
