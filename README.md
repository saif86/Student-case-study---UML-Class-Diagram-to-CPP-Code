# UML-Class-Diagram-to-CPP-Code
Example of converting a UML Class diagram to C++ class

## UML Class Diagram
![class](https://user-images.githubusercontent.com/41892175/46647021-3c434100-cbc0-11e8-8f93-d4d955c180ec.jpg)

*where*
  * *vis* = visibility (+ for public, - for private)
  * *attribute* = data member (aka field)
  * *operation* = method (or constructor)

###Note:
  * The *arg list* is a list of parameter types (e.g., int, double, String); parameter names are **not** included in the UML class diagram
  * Methods that don't return a value (i.e. void methods) should give a *return type* of void
  * Class (i.e. static) methods and fields are indicated by underlining
  * Constant (i.e. final) fields are indicated via naming convention: constants should be in ALL_CAPS
  
## Example: Student UML Class diagram
![student](https://user-images.githubusercontent.com/41892175/46647243-97c1fe80-cbc1-11e8-8287-f6559ee43fb8.png)

## Corresponding C++ Class

