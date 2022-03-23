#pragma once

#include <stddef.h>
#include <stdlib.h>

namespace oz {

template <typename T>
class List {
public:
    ~List()
    {
        if (mValues) {
            for (size_t i = 0; i < mSize; i++)
                delete mValues[i];
            free(mValues);
        }
    }
    inline size_t size() { return mSize; }
    T& at(size_t index)
    {
        // no bounds check lol
        return *mValues[index];
    }
    T& operator[](size_t index) { return at(index); }
    T pop(size_t index)
    {
        // no bounds check lol
        if (mSize == 1) {
            mSize = 0;
            T& val = *mValues[0];
            free(mValues);
            return val;
        } else if (index == mSize - 1) {
            mSize--;
            T& val = *mValues[index];
            mValues = (T**)realloc(mValues, mSize * sizeof(T*));
            return val;
        }
        T val = *mValues[index];
        T* valPtr = mValues[index];

        mSize--;
        memcpy(&mValues[index], &mValues[index + 1], (mSize - index) * sizeof(T*));
        mValues = (T**)realloc(mValues, mSize * sizeof(T*));

        delete valPtr;
        return val;
    }
    void pushBack(const T& val)
    {
        if (!mValues) {
            createIndex(1);
            mValues[0] = new T(val);
            return;
        }
        mValues = (T**)realloc(mValues, (mSize + 1) * sizeof(T*));
        mValues[mSize] = new T(val);
        mSize++;
    }
    void pushFront(const T& val)
    {
        if (!mValues) {
            createIndex(1);
            mValues[0] = new T(val);
            return;
        }
        T** newValues = (T**)malloc((mSize + 1) * sizeof(T*));
        memcpy(&newValues[1], mValues, mSize * sizeof(T*));
        free(mValues);
        mValues = newValues;
        mValues[0] = new T(val);
        mSize++;
    }

private:
    void createIndex(size_t size)
    {
        mSize = size;
        mValues = (T**)calloc(0, sizeof(T*) * mSize);
    }

private:
    T** mValues { nullptr };
    size_t mSize { 0 };
};

} // namespace oz