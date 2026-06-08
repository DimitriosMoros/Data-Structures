// COS30008, Problem Set 4, 2026

#pragma once

#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"

template<typename T>
class List
{
private:
    using node = typename DoublyLinkedList<T>::node;

    node fHead;
    node fTail;
    size_t fSize;

public:

    using iterator = DoublyLinkedListIterator<T>;

    List() noexcept :
        fHead(nullptr),
        fTail(nullptr),
        fSize(0)
    {

    }

    ~List()
    {
        while (fTail)
        {
            fTail->next.reset();
            fTail = fTail->previous.lock();
        }

        fHead.reset();
    }

    List(const List& aOther) :
        fHead(nullptr),
        fTail(nullptr),
        fSize(0)
    {
        for (auto iter = aOther.begin(); iter != aOther.end(); ++iter)
        {
            push_back(*iter);
        }
    }

    List& operator=(const List& aOther)
    {
        if (this != &aOther)
        {
            List lTemp(aOther);
            swap(lTemp);
        }

        return *this;
    }

    List(List&& aOther) noexcept :
        fHead(nullptr),
        fTail(nullptr),
        fSize(0)
    {
        swap(aOther);
    }

    List& operator=(List&& aOther) noexcept
    {
        if (this != &aOther)
        {
            swap(aOther);
        }

        return *this;
    }

    void swap(List& aOther) noexcept
    {
        std::swap(fHead, aOther.fHead);
        std::swap(fTail, aOther.fTail);
        std::swap(fSize, aOther.fSize);
    }

    size_t size() const noexcept
    {
        return fSize;
    }

    template<typename U>
    void push_front(U&& aData)
    {
        node lNew = DoublyLinkedList<T>::makeNode(std::forward<U>(aData));
        node lNull;

        lNew->link(lNull, fHead);

        if (fHead)
        {
            fHead->previous = lNew;
        }
        else
        {
            fTail = lNew;
        }

        fHead = lNew;
        fSize++;
    }

    template<typename U>
    void push_back(U&& aData)
    {
        node lNew = DoublyLinkedList<T>::makeNode(std::forward<U>(aData));
        node lNull;

        lNew->link(fTail, lNull);

        if (fTail)
        {
            fTail->next = lNew;
        }
        else
        {
            fHead = lNew;
        }

        fTail = lNew;
        fSize++;
    }

    void remove(const T& aElement) noexcept
    {
        node lCurrent = fHead;

        while (lCurrent)
        {
            if (lCurrent->data == aElement)
            {
                if (lCurrent == fHead)
                {
                    fHead = lCurrent->next;
                }

                if (lCurrent == fTail)
                {
                    fTail = lCurrent->previous.lock();
                }

                lCurrent->isolate();
                fSize--;

                return;
            }

            lCurrent = lCurrent->next;
        }
    }

    const T& operator[](size_t aIndex) const
    {
        node lCurrent = fHead;

        for (size_t i = 0; i < aIndex; i++)
        {
            lCurrent = lCurrent->next;
        }

        return lCurrent->data;
    }

    iterator begin() const noexcept
    {
        return iterator(fHead, fTail).begin();
    }

    iterator end() const noexcept
    {
        return iterator(fHead, fTail).end();
    }

    iterator rbegin() const noexcept
    {
        return iterator(fHead, fTail).rbegin();
    }

    iterator rend() const noexcept
    {
        return iterator(fHead, fTail).rend();
    }
};