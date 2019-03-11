# 关于 SSC 的代码风格的定义

By SteveXMH

## 语法

1. 语法上使用 C11 语言规范，保证 MinGW, MinGW-w64, MSVC 的 i686, x86_64 编译目标可以编译通过。
2. 尽可能的留有注释（别留没意义的），保证其他开发者可以理解你的代码。
3. 如果有时间，尽可能的减少警告的发生（可以请 Alex 帮助修改）
4. 如果有时间，尽可能地优化性能（可以请 Alex 帮助优化）
5. 请务必在编译器参数中加入 `-Wall -Werror` 以保证源代码的语法完整。

## 文件

1. 文件请使用简短的，无空格的英文单词或部分简写词组，每个单词以大写首字母来区分。

    例如 `SteveScratchCScratchObject.c` 可以简写成 `SSCScratchObj.c` 。

    如果无必要，你也可以直接写成 `ScratchObj.c` （可以做一些宏定义当语法糖啥的 XD）

2. 文件中的代码保证是使用在你这个文件名的意义上的，不要另作他用。

    比如 `SSCBlock.c` 的模块拖拽代码丢进了 `PaletteBuilder.c` 里头
    （批评一下自己）

3. 每个头文件的开头要用文档注释写明这个头文件和对应的源文件所负责的功能是什么。

4. 头文件为了防止嵌套包含，请加入此类格式的宏定义：
    长度可以随意，保证独一无二即可

5. 如需修改文件名称请务必通知其他开发者以便及时修改代码（最好一开始就定好名字）

```c
#ifndef HEADER_XXX//路径到你的头文件 (例如: HEADER_SSC_SCRATCH_PALETTEBUILDER)
#define HEADER_XXX//路径到你的头文件

// 在这里插入你的函数定义...

#endif //HEADER_XXX//路径到你的头文件
```

6. 如果遇到需要引用库头文件的话，请先加入到 位于 src 文件夹中的 Libs.h 头文件中，然后再嵌入这个库文件。

7. 任何文件请使用 UTF-8 编码保存。

## 函数

1. 函数命名请使用以下划线为空格分割线的命名方式，并将所有字母**小写**

    每个作用于 SSC 的函数前缀必须是 `ssc_` ，方便辨认。

    例子：`ssc_widget_init(void)`

2. 函数定义中要用文档注释写明这个函数的功能和各个参数的用途，还有其返回值的说明。

3. 不要使用 `printf()` 等控制台调试输出函数，改用 `print()` 宏定义，这样在发布程序时可以减小 `printf` 的调用次数。

```c

#ifdef DEBUG
#define print(...) printf(__VA_ARGS__)
#else
#define print(...)
#endif // DEBUG

```

### 宏定义

1. 函数命名请使用以下划线为空格分割线的命名方式，并将所有字母**大写**，命名请尽量简单易懂。

	每个作用于 SSC 的宏定义前缀必须是 `SSC_` ，方便辨认。



## 结构

1. 如果结构简单易于操作的话则建议直接使用结构，如果需要对其进行继承和函数等操作则建议使用 `GObject`。
2. 建议使用 `GObject` 构造你的对象，对象名称格式与文件命名格式大体相似，另外还需遵守 GObject 官方的使用规则。
3. 每个结构和成员都应该提供相应的文档注释方便编辑。
4. 每个结构成员的命名应该简单明了，使用驼峰式命名规则。
5. 如果只是临时使用结构变量（即只在一个函数中使用而不会返回给上一个函数使用的变量）就请不要使用指针变量。

## 指针

这里特别提一下，定义指针变量时应将星号放置在类型的右侧，名称的左侧，且贴附于名称，如果在函数定义时没有填入名称则贴附于类型。

例如：

`SSCString *str`

`ssc_string_get(SSCString*);`

## Glade 布局

1. 命名遵循 CSS 命名方式，以减号为分隔符 `-` 分割每个单词，尽可能的简单明了，并以 `ssc-` 为前缀，例如 `ssc-stage`。
2. 请开发用户页面的程序开发者制作控件存在性检测代码，防止遗失了控件却仍然继续执行的问题。
3. 不要遗留太多无用控件。

## GObject （对象）

1. 创建一个对象请务必先遵守官方规定的相关格式和风格：[点此前往官方文档](https://developer.gnome.org/gobject/stable/)
2. 任何 SSC 对象的命名都应该以开头为大写的 `SSC` 命名，并以大写字母分割各个单词，例如 `SSCBlock` `SSCSprite` `SSCScratchObj`
3. 对象的构造函数的后缀为 `_new` ，如果有另外的构造需求可以以 `_new_with_***`  为后缀。
4. 如无必需，请不要显式的释放对象的内存， GObject 自己拥有一套计数形式的内存管理，最好可以在创建对象的时候定义一个销毁对象的函数并以 `_destroy` 为后缀。
5. getter 和 setter 函数（获取对象成员值和设置对象成员值）请使用 `_set_属性名称` 和 `_get_属性名称` 为后缀，方便辨认。

附赠：一个简单的 GObject 定义参考代码（假设对象名称为 `SSCString` 并用于存储一个字符串指针）

SSCString.h
```c
#ifndef HEADER_SSCSTRING
#define HEADER_SSCSTRING

// 此处就不包含 Libs.h 了
#include <gtk/gtk.h>

typedef struct SSCString
{
    GObject parent_instance; // 你的类型继承了什么类，注意这个一定要放在第一位！
    /* 你的类成员 */
    char *str; // 我们的字符串指针存放在这里
}SSCString;

// 类结构体，请注意该类型名称是
// 实例结构体名称 + Class
// 一般这里不需要添加任何东西，仿照下面的结构照抄即可
// 严格按照此命名格式！
// 否则 G_DEFINE_TYPE 会出错！
typedef struct SSCStringClass
{
    GObjectClass parent_class; // 你的类型继承了什么类，注意这个一定要放在第一位！
}SSCStringClass;

/*
  G_DEFINE_TYPE(
      类型名称(直接写名称，不需要加引号),
      函数前缀(直接写名称，不需要加引号),
      GType 父类型
  )
*/
G_DEFINE_TYPE(SSCString, ssc_string, G_TYPE_OBJECT); // 让宏帮我们定义剩下的函数 :D

/*
注： G_DEFINE_TYPE 将会帮我们定义以下函数，而我们需要在源文件里实现它：
对象前缀_init(对象实例 *self);
对象前缀_class_init(对象结构 *class);
然后剩下的就是我们的函数了 :P
*/

static void ssc_string_set(SSCString*,const char*); /** 设置字符串指针 */
static char* ssc_string_get(SSCString*); /** 获取字符串指针 */

#endif
```

SSCString.c
```c
#include "SSCString.h"

// 实现的话好简单的说 XD

// 初始化类实例
static void
ssc_string_init(SSCString *self)
{
    self->str = NULL; 
}

// 初始化类结构
static void
ssc_string_class_init(SSCStringClass *self)
{
    // 一般情况什么都不用写
}

static void ssc_string_set(SSCString *self,const char *str)
{
    // 需不需要释放旧字符串的指针就看你们心情了 XD
    self->str = str;
}

static char* ssc_string_get(SSCString *self)
{
    return self->str;
}

// 至此，一个简单的 GObject 类就完成了

```
