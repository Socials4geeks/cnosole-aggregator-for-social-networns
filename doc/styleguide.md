Отступы
=======

1. Один уровень отступа - 4 пробела (табуляции не использовать)
2. Уровни отступов соответствуют уровням вложенности кода
3. Части строки, получившиеся при разбиении длинной строки отделяются 2-мя уровнями вложенности
```
std::unordered_multimap <
        std::pair<std::string, std::string>,
        std::vector< std::pair<std::string, unsigned long long int> >
                very_verbose_and_long_variable_name =
                        /* ... */;
```
4. Операторы, кроме `++`, `--`, `->`, `.`, `-`(унарный), `+`(унарный) окружаем пробелами
   Пробелы можно опускать для лучшей читаемости, например, чтобы показать приоритет операций
5. Внутри скобок <>, {}, (), [] ставим пробелы в сложных/длинных выражениях и в случае вложенности
```
std::vector< std::pair<char, int> > arr = { {'a', 1}, {'b', 2}, {'c', 3}, };
arr[ 1 + (2 - 3*12) ] = ( (1+2) - (3 + 3) )*2;
```
6. При объявлении и вызове функций в скобках пробелы ставим
```
void foo( int arg1, int arg2 );
// ...
foo( 1, 2 );
```
7. Открывающую фигурную скобку ставим на той же строке, где и имя функции/класса/цикла и т.п.; ставим пробел перед этой скобкой
8. Закрывающая скобка на новой строке
```
void foo() {
    // body
}
```
9. В комментариях ставим пробел после //, если комментарий находится на той же строке, что и код, отделяем его от кода 2-мя пробелами:
```
// It's foo function
void foo() {
    do_something();  // Magic! Do'nt touch!
}
```

Описание классов
================

1. Сначала пишем public типы, поля и методы (именно в таком порядке), затем protected и private;
   Пробелы перед модификаторами доступа не ставим, поля выносмим на 1 уровень отступов;
   Вокруг двоеточия при наследовании и передачи параметров в конструкторы базовых классов ставим пробелы;
```
class MyClass : MyParent {
public:
    MyClass( int field );
protected:
    it field;
private:
    struct Data : AbstractData {
        int x. y;
    };
};
```

2. Описание всех методов, включая конструкторы пишем вне объявления классов.

Именование
==========

1. Публичные методы классов пишем с заглавной буквы в Camel-style
2. Имена классов и типов пишем с заглавной буквы в Camel-style
3. Имена переменных (включая объекты и поля классов) пишем с маленькой буквы, разделяя слова символом подчёркивания

P.S.:
Этих правил нужно придерживаться, но если отступление от них помогает сделать код понятнее и читаемее, то приемлемо и даже правильно отходить от них

Скобочки
==========

1. Фигурные скобки посе case и default в switch ставим всегда: открывающую - на той же строке через пробел, закрывающую перед следующим case/default

Инклуды
==========

1. Инклуды пишем сначала стандартные, затем - сторонние, после - наши

2. Инклуды своих файлов пишем в кавычках, а остальные - в угловых скобках

3. Отделяем подключение стандартных, сторонних и своих файлов одним переносом строки

4. В своих инклудах указываем расширение (.h), в остальных - нет

```
#include <string>
#include <vector>

#include <boost>
#include <cpprest>

#include "types.h"
#include "exceptions.h"
```

Документация
=============

1. Пишем документацию в коде на русском языке в стиле Doxygen.

2. Используем стиль Java-Doc:

```
/// short description

//*
  *
  *    **Подробное описание**
  *
  *//
```

3. После полей и методов пишем встрочную документацию:

```
//*
  *  \class ABC
  *  \breaf 
  *
  *  Подробное описание
  *//

class ABC {
public:
    ...
    int field;  ///< Некоторое поле
    ...
};
```

4. Команды Doxygen пишем через обратный слеш.

```
//*
  * \file
  * ...
  *//
```

5. В документации не стесняемся использовать Markdown, где это уместно.

```
//*
  *  \file
  *  \breaf Некоторый файл
  * 
  *  **Внимание!**
  *  Этот файл содержит следующие компоненты:
  *
  *  * Один компонент
  *  * Другой компонент
  *//
```
