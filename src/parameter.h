#ifndef SCRIPT_PARAMETER_H
#define SCRIPT_PARAMETER_H

#include <memory>
#include <string>
#include <typeinfo>
#include <functional>

namespace Core {

class BadTypeException : public std::exception {
};


class AbstractParameter {
private:
    bool writeable = true;
public:
    virtual const std::type_info& getType() = 0;
    virtual const std::string& getString() = 0;
    virtual int getInt() = 0;
    virtual double getDouble() = 0;
    virtual bool getBool() = 0;
    virtual void* getPointer() = 0;

    virtual void setData(int i) = 0;
    virtual void setData(float f) = 0;
    virtual void setData(void* pointer) = 0;
    virtual void setData(const std::string& data) = 0;

    bool isWritable() { return writeable; }

    void setWritable(bool writable) { this->writeable = writable; }
};

/*
A good example of a bad code. Hope no one ever see it. I'll never be proud by such decision.
Hope someone clever will tell a better way. Or I'll find it by myself. Sorry the gods of programming, i've betrayed you.
Very limited decision. Still there are problems with strings.
 */
template<class T>
class Parameter : public AbstractParameter {
private:
    const std::type_info& type = typeid(T);
protected:
    T data;
public:
    virtual const std::type_info& getType() { return type; }

    virtual std::string const& getString() {
        if (typeid(std::string) != type) {
            throw BadTypeException();
        }
        return *(std::string * )(&data);
    }

    virtual int getInt() {
        if (typeid(int) != type) {
            throw BadTypeException();
        }
        return *(int*) (&data);
    }

    virtual double getDouble() {
        if (typeid(float) != type) {
            throw BadTypeException();
        }
        return *(float*) (&data);
    }

    virtual bool getBool() {
        if (typeid(bool) != type) {
            throw BadTypeException();
        }
        return *(bool*) (&data);
    }

    virtual void* getPointer() {
        if (typeid(void*) != type) {
            throw BadTypeException();
        }
        return nullptr;
    }

    virtual void setData(void* data) {
        if (isWritable()) {
            this->data = *(T*) &data;
        }
    }

    virtual void setData(const std::string& data) {
        if (isWritable()) {
            //This strange code is for those cases when we have T as int
            this->data = *(T*) &data;
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

class PointerParameter : public Parameter<void*> {
public:
    virtual void* getPointer() {
        return data;
    }
};

template<class T>
class LinkedParameter : public AbstractParameter {
private:
    const std::type_info& type = typeid(T);
    void* dataPointer;
public:
    virtual const std::type_info& getType() { return type; }

    virtual std::string const& getString() {
        if (typeid(std::string) != type) {
            throw BadTypeException();
        }
        return *(std::string*) dataPointer;
    }

    virtual int getInt() {
        if (typeid(int) != type) {
            throw BadTypeException();
        }
        return *(int*) dataPointer;
    }

    virtual double getDouble() {
        if (typeid(float) != type) {
            throw BadTypeException();
        }
        return *(float*) dataPointer;
    }

    virtual bool getBool() {
        if (typeid(bool) != type) {
            throw BadTypeException();
        }
        return *(bool*) dataPointer;
    }

    virtual void* getPointer() {
        if (typeid(void*) != type) {
            throw BadTypeException();
        }
        return (void*) dataPointer;
    }

    virtual void setData(const void* data) override {
        if (isWritable()) {
            *this->data = *(T*) data;
        }
    }

    virtual void setData(const std::string& data) {
        if (isWritable()) {
            //The more i write it the more i think. Do i really need such changes?
            //Can't it be improved with some kind of magical macros?
            *this->data = *(T*) &data;
        }
    }

    virtual void setData(int data) {
        if (isWritable()) {
            *this->data = *(T*) &data;
        }
    }

    virtual void setData(float data) {
        if (isWritable()) {
            *this->data = *(T*) &data;
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

template<class T, class U>
class CallbackParameter : public AbstractParameter {
private:
    const std::type_info& type = typeid(T);
    std::function<void(U*, T)> setterCallback;
    std::function<T(U*)> getterCallback;
    U* caller;
public:
    CallbackParameter(U* caller) : caller(caller) {};

    virtual const std::type_info& getType() {
        return type;
    }

    virtual const std::string& getString() {
        throw BadTypeException();
    }

    virtual int getInt() {
        return (int) getterCallback(caller);
    }

    virtual double getDouble() {
        return (double) getterCallback(caller);
    }

    virtual bool getBool() {
        return (bool) getterCallback(caller);
    }

    virtual void* getPointer() {
        return (void*) getterCallback(caller);
    }

    virtual void setData(int i) {
        setterCallback(caller, i);
    }

    virtual void setData(float f) {
        setterCallback(caller, f);
    }

    virtual void setData(void* pointer) {
        setterCallback(caller, *(T*) pointer);
    }

    virtual void setData(const std::string& data) {}

    void setSetterFunction(const std::function<void(U*, T)>& setter) {
        setterCallback = setter;
    }

    void setGetterFunction(const std::function<T(U*)>& getter) {
        getterCallback = getter;
    }
};

template<class U>
class CallbackParameter<std::string, U> : public AbstractParameter {
    std::function<void(U*, const std::string&)> setterCallback;
    std::function<const std::string&(U*)> getterCallback;
    U* caller;
public:
    CallbackParameter(U* caller) : caller(caller) {};

    virtual const std::type_info& getType() {
        return typeid(std::string);
    }

    virtual std::string const& getString() {
        return getterCallback(caller);
    }

    virtual int getInt() { return 0; }

    virtual double getDouble() { return 0; }

    virtual bool getBool() { return false; }

    virtual void* getPointer() { return nullptr; }

    virtual void setData(int i) {}

    virtual void setData(float f) {}

    virtual void setData(void* pointer) {}

    virtual void setData(std::string const& data) {
        setterCallback(caller, data);
    }

    void setSetterFunction(std::function<void(U*, const std::string&)>& setter) {
        setterCallback = setter;
    }

    void setGetterFunction(std::function<const std::string&(U*)>& getter) {
        getterCallback = getter;
    }
};


typedef std::shared_ptr <AbstractParameter> ParameterPtr;

} // namespace Core

#endif // SCRIPT_PARAMETER_H