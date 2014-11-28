#ifndef PARAMETER_H
#define PARAMETER_H

#include <memory>
#include <string>
#include <typeinfo>
#include <functional>

using std::shared_ptr;
using std::string;
using std::type_info;
using std::function;


class BadTypeException {};


class AbstractParameter {
private:
    bool writeable = true;
public:
    virtual const type_info& getType() = 0;
    virtual const string& getString() = 0;
    virtual int getInt() = 0;
    virtual double getDouble() = 0;
    virtual bool getBool() = 0;
    virtual void* getPointer() = 0;

    virtual void setData(int i) = 0;
    virtual void setData(float f) = 0;
    //No bool, bitches. 'Cause fuckin' string is bool
    //virtual void setData(bool b) = 0;
    virtual void setData(void* pointer) = 0;
    virtual void setData(const string& data) = 0;

    bool isWritable() { return writeable; }
    void setWritable(bool writable) { this->writeable = writable; }
};

/*
A good example of a bad code. Hope no one ever see it. I'll never be proud by such decision.
Hope someone clever will tell a better way. Or I'll find it by myself. Sorry the gods of programming, i've betrayed you.
Very limited decision. Still there are problems with strings.
 */
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

    virtual double getDouble() {
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

    virtual void setData(void *data) {
        if (isWritable()) {
            this->data = *(T*) &data;
        }
    }

    virtual void setData(const string &data) {
        if (isWritable()) {
            //This strange code is for those cases when we have T as int
            this->data = *(T*)&data;
        }
    }

    virtual void setData(int data) {
        if (isWritable()) {
            this->data = *(T*) &data;
        }
    }

    virtual void setData(float data) {
        if (isWritable()) {
            this->data = *(T*) &data;
        }
    }

    /*virtual void setData(bool data){
        if (isWritable()) {
            this->data = *(T*) &data;
        }
    }*/
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

    virtual double getDouble() {
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

    virtual void setData(const void* data) override {
        if (isWritable()) {
            *this->data = *(T *) data;
        }
    }

    virtual void setData(const string &data) {
        if (isWritable()) {
            //The more i write it the more i think. Do i really need such changes?
            //Can't it be improved with some kind of magical macros?
            *this->data = *(T*)&data;
        }
    }

    virtual void setData(int data) {
        if (isWritable()) {
            *this->data = *(T *) &data;
        }
    }

    virtual void setData(float data) {
        if (isWritable()) {
            *this->data = *(T *) &data;
        }
    }

    /*virtual void setData(bool data) {
        if (isWritable()) {
            *this->data = *(T *) &data;
        }
    }*/

    void link(const T& object) {
        this->dataPointer = &object;
    }
};

template <class T, class U> class CallbackParameter: public AbstractParameter {
private:
    const type_info& type = typeid(T);
    function<void (U*, T)> setterCallback;
    function<T (U*)> getterCallback;
    U* caller;
public:
    CallbackParameter(U* caller): caller(caller) {};

    virtual const type_info &getType() {
        return type;
    }

    virtual const string &getString() {
        return "";
    }

    virtual int getInt() {
        return (int)getterCallback(caller);
    }

    virtual double getDouble() {
        return (double)getterCallback(caller);
    }

    virtual bool getBool() {
        return (bool)getterCallback(caller);
    }

    virtual void *getPointer() {
        return (void*)getterCallback(caller);
    }

    virtual void setData(int i) {
        setterCallback(caller, i);
    }

    virtual void setData(float f) {
        setterCallback(caller, f);
    }

    virtual void setData(void *pointer) {
        setterCallback(caller, pointer);
    }

    virtual void setData(const string &data) {}

    void setSetterFunction(function<void (U*, T)>& setter) {
        setterCallback = setter;
    }
    void setGetterFunction(function<T (U*)>& getter) {
        getterCallback = getter;
    }
};

template <class string, class U> class CallbackParameter: public AbstractParameter {
    function<void (U*, const string&)> setterCallback;
    function<const string& (U*)> getterCallback;
    U* caller;
public:
    CallbackParameter(U* caller): caller(caller) {};

    virtual const type_info &getType() {
        return typeid(string);
    }

    virtual string const &getString() {
        return getterCallback(caller);
    }

    virtual int getInt() { return 0; }
    virtual double getDouble() { return 0; }
    virtual bool getBool() { return false; }
    virtual void *getPointer() {}
    virtual void setData(int i) {}
    virtual void setData(float f) {}
    virtual void setData(void *pointer) {}

    virtual void setData(string const &data) {
        setterCallback(caller, data);
    }

    void setSetterFunction(function<void (U*, const string&)>& setter) {
        setterCallback = setter;
    }
    void setGetterFunction(function<const string& (U*)>& getter) {
        getterCallback = getter;
    }
};


typedef shared_ptr<AbstractParameter> ParameterPtr;

#endif