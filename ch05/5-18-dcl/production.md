# 产生式

```
start -> keywords dcl

keywords -> keyword keywords
          | epsilon

dcl -> "*" direct-dcl
     | direct-dcl

direct-dcl -> direct-dcl postfix
            | direct-dcl'

direct-dcl' -> id
             | "(" dcl ")"
             | epsilon

postfix -> "(" params ")"
         | "[" length "]"

params -> param "," params
        | epsilon

param -> start

length -> digits
        | epsilon
```

消除左递归

```
direct-dcl -> direct-dcl' B

B -> postfix B
   | epsilon
```