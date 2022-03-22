# *STL*

### [Deque](https://en.cppreference.com/w/cpp/container/deque)

- deque stands for `double ended queue`
- designed to perform fast insertion and removal from both ends

```c++
#include<deque>

int main()
{
    std::deque<int> numbers = {1,2,3,4,5};
}
```

- dont use `numbers[i]` to access ith index instead use `numbers.at(i)` :  it gives bound check
- clear elements by `numbers.clear()`
- inserting new data
  - `numbers.push_front(data)`
  - `numbers.push_back(data)`
  - `numbers.insert(iterator_to_pos, data)` : note that iterator will still point to prev data
  - `numbers.emplace(iterator_to_pos, data)`: iterator points to newly assinged data
- erasing data
  - `numbers.pop_front()`
  - `numbers.pop_back()`
  - `numbers.erase(start_iterator, end_iterator)` or `numbers.erase(start_iterator)`
- swapping
  - `numbers.swap(other_nums)`

### [Forward list](https://en.cppreference.com/w/cpp/container/forward_list)

- Similar to linked list

- designed to perform fast insertion and deletion at middle of the container

```c++
#include<forward_list> // only forward moving is allowed
#include<algorithms>

int main()
{
    std::forward_list<int> num = {10,20,30,40,50};
    // no access to [] operator for accessing specific index
    num.front(); // accessing front element (head)
    num.clear(); // clearing the container
   	// inserting element in front
    auto it = num.before_begin();
    num.insert_after(it, 10); //inserting pos after current iterator
    // erasing element
    auto it = std::find(num.begin(), num.end(), 13);
    num.erase_after(it); // erasing 14 (pos after current iterator)
    
    num.push_front(); // inserting element in front
    num.pop_front(); // removing from front
    
    std::forward_list<int> num2 = {6,7,8,9,10};
    num.swap(num2); // swapping 2 forward lists
    
    num.merge(num2); // merginng two list, num will get modified
    
    // removig element
    num.remove(1); // removing first instance of data 1
    num.remove_if([](int x){return x < 4;}); // condtional remove
    
    num.reverse(); // reversing list
    num.sort(); // sorting the list
}
```



### [List](https://en.cppreference.com/w/cpp/container/list)

- Doubly linked list

```c++
#include<list> // bi-directional
#include<algorithms>

int main()
{
    std::list<int> num = {1,2,3,4,5};
    num.front(); //front element
    num.back(); // last element
    // fwd and bwd iterators are supported
    num.clear(); // clearing all elements
    // inserting
    num.push_front(16); // adding in front
    num.push_back(19); // adding in back
    auto it = std::find(num.begin(), num.end(), 13);
    num.insert(it, 14); // insert at pos after it
    // removal
	auto it = std::find(num.begin(), num.end(), 13);
    num.erase(it);
    num.pop_front(); // removing from front
    num.pop_back(); // removing from last
    
    std::forward_list<int> num2 = {6,7,8,9,10};
    num.swap(num2); // swapping 2 forward lists
    
    num.merge(num2); // merginng two list, num will get modified
    
    // removig element
    num.remove(1); // removing first instance of data 1
    num.remove_if([](int x){return x < 4;}); // condtional remove
    
    num.reverse(); // reversing list
    num.sort(); // sorting the list
}
```



### [vector](https://en.cppreference.com/w/cpp/container/vector)

- dynamic arrays

```c++
#include<vector>
int main()
{
    std::vector<int> v = {1,2,3,4,5};
	//dont use v[i] instead use .at()
    int index = 1;
    std::cout << v.at(index);
}
```



### [Array](https://en.cppreference.com/w/cpp/container/array)

```c++
#include<array>

int main()
{
    std::array<int> arr = {1,2,3,4,5};
}
```



### [Pairs](https://en.cppreference.com/w/cpp/utility/pair)

```c++
#include<utility>
int main()
{
    std::pair<int, int> p = std::make_pair(1,2);
    // accessing key and value using C++17 way
    auto [key, value] = p;
    std::cout << key << " " << value;
}
```



### [set](https://en.cppreference.com/w/cpp/container/set)

```c++
#include<iostream>
#include<utility>
#include<set>
#include<functional>

bool compare_ints(int l, int r)
{
    return l < r;
}

int main()
{
    std::set<int> s = {5,4,3,2,1};
    // checking if insertion is success or not
    auto [data, is_sucess] = s.insert(1); // returns a set (iterator to data, boolean for success)
    if(is_sucess)
        std::cout <<  "data: " << *data << " is inserted" << std::endl;
    else
        std::cout << "something went wrong" << std::endl;
    
    // we can also customize the way set store elements
    // by default set uses std::less functor for storing data in inc order
    std::set<int, std::greater<int>> num {11,12,13,14}; // store in dec order
    
    // you can also pass custom functors as
    class IntCompare // custom int comparator functor to return a < b
    {
        public:
        	bool operator()(int left, int right)const
            {
                return left < right;
            }
    }
    
    std::set<int, IntCompare> num {5,4,3,2,1}; // store in inc order
    
    // you can also use function pointers and lambda functions but syntax gets wierd
    // for that you need to use .insert() method to insert elements
    
    std::set<int, bool(*)(int, int)> num(compare_ints); // passing function pointer
    num.insert({5,4,3,2,1});
    
    
   std::set<int, std::function<bool(int, int)>> num([](int l, int r){
       return l < r;
   }); // passing lambda function
   num.insert({5,4,3,2,1});
}
```



### [map](https://en.cppreference.com/w/cpp/container/map)

```c++
#include<map>
int main()
{
    
}
```



### priority queue

```c++
#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<functional>

template<typename T, typename Q, typename P>
void print(std::priority_queue<T, Q, P> q)
{
   while (!q.empty())
   {
       std::cout << q.top() << " ";
       q.pop();
   }
   std::cout << std::endl;
   
}

class IntCompare // custom int comparator functor to return a < b
    {
        public:
            IntCompare()=default;
        	bool operator()(int left, int right)const
            {
                return left < right;
            }
    };

int main()
{
    // IntCompare cmp;
    // std::function<bool(int, int)> f = cmp;
    //std::priority_queue<int, std::vector<int>, f> q; not gonna work (it should be a type)
    std::priority_queue<int, std::vector<int>, IntCompare> q;
    q.push(5);
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);

    print(q);

}

```

