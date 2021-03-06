#ifndef BASE_STORAGE_H
#define BASE_STORAGE_H

#include <vector>

#include "types.h"

/** 
    @module storage
    Общий модуль, описывающий интерфейс хранилища и связанных классов
**/

class Storage;
class Handler;
template <class T>
struct Serializer;

/**
    @class Storage
    Абстрактный базовый класс хранилища данных
    Является интерфейсом для остальных хранилищ
**/

class Storage {
  protected:
    char* buffer;  /// Промежуточный буфер
    size_t buffer_size;  /// Размер буфера
    std::vector<Handler> handlers;

  public:
    Storage();
    virtual ~Storage();
    Storage( Storage& storage );
    Storage( Storage&& storage );
    /// Аллоцирующий конструктор, выделяющий сразу size байт под данные
    Storage( size_t size );
    /// Конструктор, заполняющий буфер данными
    Storage( char* data, size_t bytes );
    /// Сохраняет bytes байтов данных data по ключу key
    virtual Status Set( std::string key, char* data, size_t bytes ) = 0;
    /// Возвращает указатель на загруженный объект данных по ключу key
    virtual Status Get( std::string key, char*& data, size_t& bytes ) = 0;
};

/**
    @class Handler
    Абстрактный базовый класс хендлера
    Предназначен для манипуляций с конкретным объектом хранилищем
    Является общим интерфейсом для всех хранилищ
**/

class Handler {
  public:
    /// Открыть объект хранилища
    virtual void open() = 0;
    /// Закрыть объект хранилища
    virtual void close() = 0;
    /// Открыт ли объект хранилища
    virtual bool is_open() = 0;
    virtual void write(char* data, size_t size) = 0;
    virtual void read(char*& data, size_t& size) = 0;
};

/**
    @class Serialiser
    Абстрактный базовый шаблон класс сериализатора
    Отвечает за сериализацию данных в бинарное представление и обратно
    Для определения поведения для конкретных данных определить конкретизацию шаблона
**/

template <class T>
struct Serializer {
    char* encode( T& data );
    T decode( char* data );
};

#include "serializer.hpp"

#endif  // BASE_STORAGE_H
