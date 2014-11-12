#ifndef PARAMETER_H
#define PARAMETER_H

#include <memory>
#include <string>
#include <typeinfo>

using std::shared_ptr;
using std::string;
using std::type_info;


class BadTypeException {};


class AbstractParameter {
public:
    virtual const type_info& getType() = 0;
    virtual const string& getString() = 0;
    virtual int getInt() = 0;
    virtual float getFloat() = 0;
    virtual bool getBool() = 0;
    virtual void* getPointer() = 0;
};


template <class T> class Parameter: public AbstractParameter {
private:
    const type_info& type = typeid(T);
protected:
    T data;
public:
    virtual const type_info& getType() { return type; }

    virtual string const &getString() {
        if (typeid(string) != type){
            throw BadTypeException();
        }
        return *(string*)(&data); }

    virtual int getInt() {
        if (typeid(int) != type){
            throw BadTypeException();
        }
        return *(int*)(&data); }

    virtual float getFloat() {
        if (typeid(float) != type){
            throw BadTypeException();
        }
        return *(float*)(&data); }

    virtual bool getBool() {
        if (typeid(bool) != type){
            throw BadTypeException();
        }
        return *(bool*)(&data);
    }

    virtual void *getPointer() {
        if (typeid(void*) != type){
            throw BadTypeException();
        }
        return nullptr;
    }

    void setData(const T& data) {
        this->data = data;
    }
};

class PointerParameter: public Parameter<void*> {
public:
    virtual void* getPointer() {
        return data;
    }
};

template <class T> class LinkedParameter: public AbstractParameter {
private:
    const type_info& type = typeid(T);
    void* dataPointer;
public:
    virtual const type_info& getType() { return type; }

    virtual string const &getString() {
        if (typeid(string) != type){
            throw BadTypeException();
        }
        return *(string*)dataPointer; }

    virtual int getInt() {
        if (typeid(int) != type){
            throw BadTypeException();
        }
        return *(int*)dataPointer; }

    virtual float getFloat() {
        if (typeid(float) != type){
            throw BadTypeException();
        }
        return *(float*)dataPointer; }

    virtual bool getBool() {
        if (typeid(bool) != type){
            throw BadTypeException();
        }
        return *(bool*)dataPointer;
    }

    virtual void *getPointer() {
        if (typeid(void*) != type){
            throw BadTypeException();
        }
        return *dataPointer;
    }

    void setData(const T& data) {
        *this->data = data;
    }

    void link(const T& object) {
        this->dataPointer = &object;
    }
};

typedef shared_ptr<AbstractParameter> ParameterPtr;

#endif