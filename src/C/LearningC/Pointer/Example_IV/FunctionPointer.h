// Roof : Function Pointer Usage
typedef void(*FPTR)(void);
void RoofFunc(void);
void roof_foo();
FPTR Roof_set_func(FPTR);