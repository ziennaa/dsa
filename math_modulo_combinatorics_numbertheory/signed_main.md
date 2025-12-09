why prefer signed main over int main in cp
genrally it's wrong
mostly used when we're doing 
```
#define int long long
```
if we wrote ``` int main ``` it would turn into ``` long long main ``` which violates cpp standards, writing signed avoid macro and still makes main as int function. 


so if we use ```signed``` anywhere else, would it mean the same thing?
in plain cpp   
``` int ``` is signed by default
when using 
```define int long long```    `int` evrywhere becomes `long long`
`signed` doesn't change, because the macro only replaces the token `int` 