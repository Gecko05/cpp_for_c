| **Declarations and Initializations** |
| :---: |
| int i = 3, *p = &i; |
| char c = 'b'; |
| float x = 2.14, *q = &x; |

| **Expression** | **Type** | **Value** |
| --- | --- | --- |
| i + c | int | 101 |
| x + i | float | 5.14 |
| p + i | int * | p + (3*sizeof(int)) |
| p == &i | bool | true |
| *p - *q | float | -0.86 |
| static_cast<int>(x + i) | int | 5 |