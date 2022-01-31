//
// Created by Swayam Singh on 30/01/22.
//

#ifndef CONCEPTS_BOXCONTAINER_H
#define CONCEPTS_BOXCONTAINER_H

#include <memory>
#include <concepts>

template <typename T = int>
requires std::is_default_constructible_v<T>
class BoxContainer
{
    static const size_t DEFAULT_CAPACITY = 30;
    static const int EXPAND_STEPS = 5;
private:
    std::shared_ptr<T[]> m_items;
    int m_capacity;
    int m_size;
public:
    
    // constructors
    explicit BoxContainer(int capacity=DEFAULT_CAPACITY);
    BoxContainer(const BoxContainer & source) requires std::copyable<T> ;
    ~BoxContainer();
    
    // getters
    int size() const {return m_size;}
    int capacity() const {return m_capacity;}
    T get_item(int index) const {return m_items[index];}
    
    // custom functions
    void add(const T & item);
    bool remove_item(const T & item);
    size_t remove_all(const T & item);
    
    // operator overload
    void operator += (const BoxContainer & right);
    BoxContainer  operator + (const BoxContainer & right) const;
    void operator = (const BoxContainer & right);

    // friend std::ostream & operator << <T> (std::ostream & out, const BoxContainer<T> & source)
    friend std::ostream & operator <<(std::ostream & out, const BoxContainer<T> & source) // this is not a friend function, it's just a wierd C++ arrangement
    {
        out << "BoxContainer: [ size : " << source.m_size << ", capacity: " << source.m_capacity <<", items: ";
        for(int i{0}; i<source.m_size; i++)
            out << source.m_items[i] << " ";
        out << "]" << std::endl;
        return out;
    }

private:
    void expand(int new_capacity);
};

template <typename T>
requires std::is_default_constructible_v<T>
BoxContainer<T>::BoxContainer (int capacity)
{
    std::shared_ptr<T[]> temp (new T [capacity]);
    m_items = temp;
    temp.reset();
    m_capacity = capacity;
    m_size = 0;
}

template <typename T> 
requires std::is_default_constructible_v<T>
BoxContainer<T>::BoxContainer(const BoxContainer<T> & source) requires :: std::copyable<T>
{
    std::shared_ptr<T[]> temp(new T [source.m_capacity]);
    m_items = temp;
    temp.reset();
    m_capacity = source.m_capacity;
    m_size = source.m_size;
    
    for(int i{0}; i<source.size(); ++i)
    {
        m_items[i] = source.m_items[i];
    }
}

template <typename T>
requires std::is_default_constructible_v<T>
BoxContainer<T>::~BoxContainer()
{
    this->m_items.reset();
}
/*
template <typename T>
inline std::ostream & operator << (std::ostream &out, const BoxContainer<T> & source)
{
    out << "BoxContainer: [ size : " << source.size() << ", capacity: " << source.capacity() <<", items: ";
    for(int i{0}; i<source.size(); i++)
        out << source.get_item(i) << " ";
    out << "]" << std::endl;
    return out;
}
*/

/*
template <typename T> // using all private member functions
inline std::ostream & operator << (std::ostream &out, const BoxContainer<T> & source)
{
    out << "BoxContainer: [ size : " << source.m_size << ", capacity: " << source.m_capacity <<", items: ";
    for(int i{0}; i<source.m_size; i++)
        out << source.m_size << " ";
    out << "]" << std::endl;
    return out;
}
*/

template <typename T>
requires std::is_default_constructible_v<T>
void BoxContainer<T>::expand (int new_capacity)
{
    if(m_capacity >= new_capacity)
        return;
    std::shared_ptr<T[]> new_items (new T [new_capacity]);
    
    for(int i{0}; i<m_size; i++)
        new_items[i] = m_items[i];
    
    m_items.reset();
    m_items = new_items;
    new_items.reset();
    m_capacity = new_capacity;
}

template <typename T>
requires std::is_default_constructible_v<T>
void BoxContainer<T>::add (const T &item)
{
    if(m_size == m_capacity)
        expand (m_capacity+EXPAND_STEPS);
    m_items[m_size] = item;
    ++m_size;
}

template <typename T>
requires std::is_default_constructible_v<T>
bool BoxContainer<T>::remove_item (const T &item)
{
    int index_to_remove = -1;
    for(int i{}; i<m_size; ++i)
    {
        if(m_items[i] == item)
        {
            index_to_remove = i;
            break;
        }
    }
    if (index_to_remove < 0)
        return false;
    m_items[index_to_remove] = m_items[m_size-1];
    --m_size;
    return true;
}

template <typename T>
requires std::is_default_constructible_v<T>
size_t BoxContainer<T>::remove_all (const T &item)
{
    size_t remove_count{};
    
    bool removed = remove_item (item);
    if (removed)
        ++remove_count;
    
    while(removed)
    {
        removed = remove_item (item);
        if(removed)
            ++remove_count;
    }
    return remove_count;
}

template <typename T>
requires std::is_default_constructible_v<T>
void BoxContainer<T>::operator+= (const BoxContainer<T> &right)
{
    if(this->m_size + right.m_size > this->m_capacity)
        expand (m_capacity + right.m_size);
    
    for(int i{0}; i<right.m_size; ++i)
        this->m_items[this->m_size + i] = right.m_items[i];
    m_size += right.m_size;
}

template <typename T>
requires std::is_default_constructible_v<T>
BoxContainer<T> BoxContainer<T>::operator+ (const BoxContainer<T> &right) const
{
    BoxContainer result;
    result += *this;
    result += right;
    return result;
}

template <typename T>
requires std::is_default_constructible_v<T>
void BoxContainer<T>::operator = (const BoxContainer<T> &right)
{
    if(this->m_capacity < right.m_capacity)
        expand (right.m_capacity);
    std::shared_ptr<T[]> new_items (new T [right.m_capacity]);
    for(int i{0}; i<right.m_size; ++i)
        new_items[i] = right.m_items[i];
    this->m_items.reset();
    this->m_items = new_items;
    new_items.reset();
    m_size = right.m_size;
    m_capacity = right.m_capacity;
}


#endif //CONCEPTS_BOXCONTAINER_H
