// //
// // Created by Swayam Singh on 30/01/22.
// //

// #include "BoxContainer.h"
// BoxContainer::BoxContainer (int capacity)
// {
//     std::shared_ptr<value_type[]> temp (new value_type [capacity]);
//     m_items = temp;
//     temp.reset();
//     m_capacity = capacity;
//     m_size = 0;
// }

// BoxContainer::BoxContainer (const BoxContainer &source)
// {
//     std::shared_ptr<value_type[]> temp(new value_type [source.m_capacity]);
//     m_items = temp;
//     temp.reset();
//     m_capacity = source.m_capacity;
//     m_size = source.m_size;
    
//     for(int i{0}; i<source.size(); ++i)
//     {
//         m_items[i] = source.m_items[i];
//     }
// }

// BoxContainer::~BoxContainer ()
// {
//     this->m_items.reset();
// }

// void BoxContainer::stream_insert (std::ostream &out) const
// {
//     out << "BoxContainer: [ size : " << m_size << ", capacity: " << m_capacity <<", items: ";
//     for(int i{0}; i<m_size; i++)
//         out << m_items[i] << " ";
//     out << "]" << std::endl;
// }

// void BoxContainer::expand (int new_capacity)
// {
//     if(m_capacity >= new_capacity)
//         return;
//     std::shared_ptr<value_type[]> new_items (new value_type [new_capacity]);
    
//     for(int i{0}; i<m_size; i++)
//         new_items[i] = m_items[i];
    
//     m_items.reset();
//     m_items = new_items;
//     new_items.reset();
//     m_capacity = new_capacity;
// }

// void BoxContainer::add (const BoxContainer::value_type &item)
// {
//     if(m_size == m_capacity)
//         expand (m_capacity+EXPAND_STEPS);
//     m_items[m_size] = item;
//     ++m_size;
// }

// bool BoxContainer::remove_item (const BoxContainer::value_type &item)
// {
//     int index_to_remove = -1;
//     for(int i{}; i<m_size; ++i)
//     {
//         if(m_items[i] == item)
//         {
//             index_to_remove = i;
//             break;
//         }
//     }
//     if (index_to_remove < 0)
//         return false;
//     m_items[index_to_remove] = m_items[m_size-1];
//     --m_size;
//     return true;
// }

// size_t BoxContainer::remove_all (const BoxContainer::value_type &item)
// {
//     size_t remove_count{};
    
//     bool removed = remove_item (item);
//     if (removed)
//         ++remove_count;
    
//     while(removed)
//     {
//         removed = remove_item (item);
//         if(removed)
//             ++remove_count;
//     }
//     return remove_count;
// }

// void BoxContainer::operator+= (const BoxContainer &right)
// {
//     if(this->m_size + right.m_size > this->m_capacity)
//         expand (m_capacity + right.m_size);
    
//     for(int i{0}; i<right.m_size; ++i)
//         this->m_items[this->m_size + i] = right.m_items[i];
//     m_size += right.m_size;
// }

// BoxContainer BoxContainer::operator+ (const BoxContainer &right) const
// {
//     BoxContainer result;
//     result += *this;
//     result += right;
//     return result;
// }

// void BoxContainer::operator = (const BoxContainer &right)
// {
//     if(this->m_capacity < right.m_capacity)
//         expand (right.m_capacity);
//     std::shared_ptr<value_type[]> new_items (new value_type [right.m_capacity]);
//     for(int i{0}; i<right.m_size; ++i)
//         new_items[i] = right.m_items[i];
//     this->m_items.reset();
//     this->m_items = new_items;
//     new_items.reset();
//     m_size = right.m_size;
//     m_capacity = right.m_capacity;
// }
