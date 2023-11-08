#include <stdio.h>

/* 介绍
宏定义是C/C++语言中的一种预处理指令，可以用来定义常量、函数以及代码片段。在代码中合理使用宏定义可以提高代码的可读性、可维护性和可重用性。本文将介绍几种在C/C++中使用宏定义的技巧。

宏定义技巧一：定义常量
在C/C++中，我们经常需要使用一些常量，如π、e等，可以使用宏定义来定义这些常量，例如下面的代码定义了π的值并使用：

#define PI 3.14159265358979323846
...
double area = PI * r * r;
使用宏定义定义常量可以减少代码中的魔法数字，提高代码的可读性和可维护性。

宏定义技巧二：定义函数
在C/C++中，我们可以使用宏定义来定义函数。与使用函数定义不同，使用宏定义定义的函数在代码中将被替换为宏定义中的代码片段，从而减少了函数调用的开销，提高了代码的性能。例如下面的代码定义了一个求平方的宏定义：

#define SQUARE(x) ((x)*(x))
...
int a = 3;
int b = SQUARE(a); // b = 9
需要注意的是，使用宏定义定义函数也有一些限制，如不能使用return语句等。

宏定义技巧三：参数化宏定义
在C/C++中，我们可以使用参数来定义宏定义，从而使宏定义更加灵活和可重用。例如下面的代码定义了一个参数化宏定义，用来比较两个数的大小：

#define MAX(a, b) ((a) > (b) ? (a) : (b))
...
int a = 3;
int b = 5;
int max = MAX(a, b); // max = 5
使用参数化宏定义可以方便地定义一些通用的代码片段，提高代码的可重用性。

宏定义技巧四：使用#ifdef保护宏定义
在C/C++中，我们可以使用#ifdef来保护宏定义，以防止多次定义或未定义。例如下面的代码使用#ifdef语句来保护一个宏定义：

#ifndef SQUARE
#define SQUARE(x) ((x)*(x))
#endif
这段代码的意思是，如果SQUARE宏没有被定义，那么就定义它。如果已经被定义了，那么就跳过这个定义。这样可以避免在多个文件中多次定义同一个宏，从而减少编译错误的发生。

宏定义技巧五：使用宏定义进行调试
在C/C++中，我们可以使用宏定义来进行调试，以便在需要时打印输出调试信息。例如下面的代码定义了一个宏来输出调试信息：

#ifdef DEBUG
#define DEBUG_PRINT(x) printf x
#else
#define DEBUG_PRINT(x) do {} while (0)
#endif
这段代码的意思是，如果定义了DEBUG宏，那么就使用printf函数输出调试信息。否则，就使用一个空语句块来忽略这个宏。在代码中使用DEBUG_PRINT宏可以方便地输出调试信息，而在正式发布时只需要将DEBUG宏注释掉即可。

宏定义技巧六：使用宏定义进行字符串拼接
在C/C++中，我们可以使用宏定义来进行字符串拼接，从而方便地生成一些代码。例如下面的代码定义了一个宏来进行字符串拼接：

#define STRINGIFY(x) #x
#define STRING_CONCAT(x, y) x##y
...
int STRING_CONCAT(a, 1) = 2;
const char* str = STRINGIFY(hello world);
这段代码的意思是，使用STRINGIFY宏可以将一个宏定义转换为字符串，使用STRING_CONCAT宏可以将两个宏定义拼接在一起。在代码中使用这两个宏可以方便地生成一些字符串常量和变量名。

宏定义技巧七：使用宏定义进行条件编译
在C/C++中，我们可以使用宏定义来进行条件编译，以便根据不同的条件编译不同的代码。例如下面的代码定义了一个宏来控制是否编译某段代码：

#ifdef DEBUG
// debug code
#else
// release code
#endif
这段代码的意思是，如果定义了DEBUG宏，那么就编译debug code，否则就编译release code。在代码中使用#ifdef语句可以根据不同的条件编译不同的代码，从而方便地进行调试和发布。

宏定义技巧八：使用宏定义进行类型转换
在C/C++中，我们可以使用宏定义来进行类型转换，从而方便地将一种类型转换为另一种类型。例如下面的代码定义了一个宏来将一个指针转换为一个整数：

#define PTR2INT(p) ((int)(intptr_t)(p))
...
int* p = new int(10);
int n = PTR2INT(p);
这段代码的意思是，使用PTR2INT宏可以将一个指针转换为一个整数。在代码中使用这个宏可以方便地进行类型转换，从而方便地进行一些操作。

宏定义技巧九：使用宏定义进行位操作
在C/C++中，我们可以使用宏定义来进行位操作，从而方便地进行一些位运算。例如下面的代码定义了一些宏来进行位操作：

#define SET_BIT(x, n) ((x) |= (1 << (n)))
#define CLEAR_BIT(x, n) ((x) &= ~(1 << (n)))
#define TOGGLE_BIT(x, n) ((x) ^= (1 << (n)))
#define TEST_BIT(x, n) ((x) & (1 << (n)))
...
unsigned int num = 0x12345678;
SET_BIT(num, 3); // set the 3rd bit to 1
CLEAR_BIT(num, 7); // clear the 7th bit to 0
TOGGLE_BIT(num, 15); // toggle the 15th bit
if (TEST_BIT(num, 2)) { // test the 2nd bit
    // do something
}
这段代码的意思是，使用SET_BIT宏可以将一个数的某一位设置为1，使用CLEAR_BIT宏可以将一个数的某一位清零，使用TOGGLE_BIT宏可以将一个数的某一位取反，使用TEST_BIT宏可以测试一个数的某一位是否为1。在代码中使用这些宏可以方便地进行位操作，从而方便地进行一些操作。

宏定义技巧十：使用宏定义进行变量定义
在C/C++中，我们可以使用宏定义来进行变量定义，从而方便地生成一些常量或变量。例如下面的代码定义了一个宏来生成一个常量：

#define DEFINE_CONST(type, name, value) \\\\
    const type name = value;
...
DEFINE_CONST(int, MAX_NUM, 100);
这段代码的意思是，使用DEFINE_CONST宏可以方便地生成一个常量，它的类型、名称和值都由宏定义传入。在代码中使用这个宏可以方便地生成一些常量，从而方便地进行一些操作。

宏定义技巧十一：使用宏定义进行异常处理
在C/C++中，我们可以使用宏定义来进行异常处理，从而方便地发现和处理异常。例如下面的代码定义了一个宏来检查一个指针是否为空：

#define CHECK_PTR(ptr) \\\\
    do { \\\\
        if ((ptr) == nullptr) { \\\\
            throw std::invalid_argument("null pointer"); \\\\
        } \\\\
    } while (0)
...
int* p = nullptr;
CHECK_PTR(p); // throw an exception
这段代码的意思是，使用CHECK_PTR宏可以方便地检查一个指针是否为空，如果为空就抛出一个异常。在代码中使用这个宏可以方便地进行异常处理，从而方便地发现和处理异常。

宏定义技巧十二：使用宏定义进行多线程编程
在C/C++中，我们可以使用宏定义来进行多线程编程，从而方便地创建和操作线程。例如下面的代码定义了一个宏来创建一个线程：

#define CREATE_THREAD(func, arg) \\\\
    do { \\\\
        std::thread t(func, arg); \\\\
        t.detach(); \\\\
    } while (0)
...
void* thread_func(void* arg) {
    // do something
    return nullptr;
}
CREATE_THREAD(thread_func, nullptr);
这段代码的意思是，使用CREATE_THREAD宏可以方便地创建一个线程，它的函数和参数都由宏定义传入。在代码中使用这个宏可以方便地进行多线程编程，从而方便地创建和操作线程。

宏定义技巧十三：使用宏定义进行模板编程
在C++中，我们可以使用宏定义来进行模板编程，从而方便地生成一些模板类或函数。例如下面的代码定义了一个宏来生成一个模板类：

#define DEFINE_TEMPLATE_CLASS(name, T) \\\\
    template <typename T> \\\\
    class name { \\\\
    public: \\\\
        void func(T t) {} \\\\
    };
...
DEFINE_TEMPLATE_CLASS(TemplateClass, int);
这段代码的意思是，使用DEFINE_TEMPLATE_CLASS宏可以方便地生成一个模板类，它的名称和类型都由宏定义传入。在代码中使用这个宏可以方便地进行模板编程，从而方便地生成一些模板类或函数。

宏定义技巧十四：使用宏定义进行泛型编程
在C++中，我们可以使用宏定义来进行泛型编程，从而方便地生成一些泛型代码。例如下面的代码定义了一个宏来生成一个泛型函数：

#define GENERATE_FUNCTION(name, T) \\\\
    T name(T t) { \\\\
        return t; \\\\
    }
...
GENERATE_FUNCTION(generic_func, int);
这段代码的意思是，使用GENERATE_FUNCTION宏可以方便地生成一个泛型函数，它的名称和类型都由宏定义传入。在代码中使用这个宏可以方便地进行泛型编程，从而方便地生成一些泛型代码。

宏定义技巧十五：使用宏定义进行元编程
在C++中，我们可以使用宏定义来进行元编程，从而方便地生成一些元数据或代码。例如下面的代码定义了一个宏来生成一个元数据：

#define DEFINE_METADATA(name, type, value) \\\\
    const type name = value;
...
DEFINE_METADATA(METADATA_NAME, std::string, "metadata");
这段代码的意思是，使用DEFINE_METADATA宏可以方便地生成一个元数据，它的名称、类型和值都由宏定义传入。在代码中使用这个宏可以方便地进行元编程，从而方便地生成一些元数据或代码。*/




#define SET_BIT(x, n) ((x) |= (1 << (n)))
#define CLEAR_BIT(x, n) ((x) &= ~(1 << (n)))
#define TOGGLE_BIT(x, n) ((x) ^= (1 << (n)))
#define TEST_BIT(x, n) ((x) & (1 << (n)))

#define STRINGIFY(x) #x
#define STRING_CONCAT(x, y) x##y


int main()
{
    void test1(void);
    int num = 0b10001;
    SET_BIT(num, 3); // set the 3rd bit to 1

    printf("%d", num); 


    CLEAR_BIT(num, 7); // clear the 7th bit to 0
    TOGGLE_BIT(num, 15); // toggle the 15th bit

    test1();

}

void test1(void)
{
    int a, b, c, d, f;
    a = 2;
    b = 4;
    c = 8;
    d = 7;
    f=(a > b) ? 1 : (c > d) ? 2 : 5;
    printf("%d", f);
}
