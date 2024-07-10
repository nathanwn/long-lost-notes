# C++ Standard Template Library (C++ STL)
----------------

* Author: Nhat M. Nguyen
* Created: May 31, 2018
* Updated: Apr 30, 2020

----------------
# Contents
<!-- TOC depthFrom:1 depthTo:6 withLinks:1 updateOnSave:1 orderedList:0 -->

- [0. Headnotes](#0-headnotes)
	- [0.1. C++11](#01-c11)
	- [0.2. Iterators](#02-iterators)
- [1. `std::vector`](#1-stdvector)
	- [1.1. Introduction](#11-introduction)
	- [1.2. `include` directive](#12-include-directive)
	- [1.3. Declaration](#13-declaration)
	- [1.4. Member functions](#14-member-functions)
		- [1.4.1. Operator `[]`](#141-operator-)
		- [1.4.2. `size`](#142size)
		- [1.4.3. `push_back` and `emplace_back`](#143-pushback-and-emplaceback)
	- [1.5. Range-based loop](#15-range-based-loop)
- [2. `std::algorithm`](#2-stdalgorithm)
	- [2.1. `include` directive](#21-include-directive)
	- [2.2. `std::fill`](#22-stdfill)
	- [2.3. `std::sort`](#23-stdsort)
		- [2.3.1. Simple sorting](#231-simple-sorting)
		- [2.3.2. Nontrivial sorting (pre-C++11)](#232-nontrivial-sorting-pre-c11)
		- [2.3.3. Lambda functions](#233-lambda-functions)
	- [2.4. Binary search](#24-binary-search)
		- [2.4.1 `std::binary_search`](#241-stdbinarysearch)
		- [2.4.2. `std::lower_bound`](#242-stdlowerbound)
		- [2.4.3. `std::upper_bound`](#243-stdupperbound)
- [3. `std::utility`](#3-stdutility)
	- [3.1. `include` directive](#31-include-directive)
	- [3.2. `std::swap`](#32-stdswap)
	- [3.3. `std::pair`](#33-stdpair)
		- [3.3.1. Introduction](#331-introduction)
		- [3.3.2. Declaration](#332-declaration)
		- [3.3.2. Member variables](#332-member-variables)
		- [3.3.4. `std::make_pair`](#334-stdmakepair)
		- [3.3.5. Sorting](#335-sorting)
- [4. Hash table & Map](#4-hash-table-map)
    - [4.1. `std::unordered_map`](#41-stdunorderedmap)
		- [4.1.1. Introduction](#411-introduction)
		- [4.1.2. `include` directive](#412-include-directive)
		- [4.1.3. Declaration](#413-declaration)
		- [4.1.4. Access the value of a key](#414-access-the-value-of-a-key)
		- [4.1.5. Insert a key-value pair](#415-insert-a-key-value-pair)
		- [4.1.6. Checking if a key exists](#416-checking-if-a-key-exists)
		- [4.1.7. Looping through all elements](#417-looping-through-all-elements)
	- [4.2. `std::map`](#42-stdmap)
		- [4.2.1. Introduction](#421-introduction)
        - [4.2.2. `include` directive](#422-include-directive)
        - [4.2.3. Usage](#423-usage)
	- [4.3. Comparison between `map` and `unordered_map`](#43-comparison-between-map-and-unorderedmap)
- [5. `std::set`](#5-stdset)
	- [5.1. Introduction](#51-introduction)
	- [5.2. `include` directive](#52-include-directive)
	- [5.3. Member functions](#53-member-functions)
- [6. Abstract Data Types](#6-abstract-data-types)
	- [6.1. Queue](#61-queue)
		- [6.1.1. `include` directive](#611-include-directive)
		- [6.1.2. Notable member functions](#612-notable-member-functions)
	- [6.2. Stack](#62-stack)
		- [6.2.1. `include` directive](#621-include-directive)
		- [6.2.2. Notable member functions](#622-notable-member-functions)
	- [6.3. Deque](#63-deque)
		- [6.3.1. `include` directive](#631-include-directive)
		- [6.3.2. Notable member functions](#632-notable-member-functions)
	- [6.4. Priority Queue](#64-priority-queue)
		- [6.4.1. `include` directive](#641-include-directive)
		- [6.4.2. Declaration](#642-declaration)
		- [6.4.3. Notable member functions](#643-notable-member-functions)
- [7. `std::bitset`](#7-stdbitset)

<!-- /TOC -->

----------------
## 0. Headnotes

* If you want to use the STL features the way I mention in this note, please set
your compiler option to at least C++11. The way to do it may vary according
to your IDE. If you are using MS Visual Studio, the good news is
the compiler option is always set to the latest version of C++ (currently it is C++17 I think).
If you are using other IDEs, please Google how to do it.

### 0.1. C++11
* If you want to use the STL features the way I mentioned in this note, please set
your compiler option to at least C++11. The way to do it may vary according
to your IDE. If you are using MS Visual Studio, the good news is
the compiler option is always set to the latest version of C++ (currently it is C++17 I think).
If you are using other IDEs, please Google how to do it. If you are compiling with the terminal,
your compiling command should look like this:
```
g++ -std=c++11 -Wall -Wextra main.cpp -o main
# you can replace c++11 with c++14 or c++17 if you want newer versions of C++
```

### 0.2. Iterators
An iterator is a pointing to a memory address of a container.
The address can be:
* the begin address of the container.
* the end address of the container.
* the address of an element in the container.

You will see how iterators are used in the following sections.

----------------

## 1. `std::vector`

### 1.1. Introduction

`std::vector` is a great alternative for arrays.
* Similarity: both acts as lists of items
* Difference:
    * the size of the array must be known when it is declared and
    unchanged throughout the program.
    * when a vector is declared, the specific size is not required, and
    it can be changed throughout the lifetime of the program.


### 1.2. `include` directive
```cpp
#include <vector>
```


### 1.3. Declaration
Example of vector declaration:
```cpp
    std::vector<int> vi;             // empty vector of integer
    std::vector<vector<double> > vd; // empty vector of vector of double (2D)
    std::vector<Student> students;   // empty vector of objects of class Student

    std::vector<int> vi2(n);         // vector of integer containing n empty elements
    std::vector<int> vi2(n, 3);      // vector of integer containing n elements whose
                                     //     values are all 3
```

### 1.4. Member functions

#### 1.4.1. Operator `[]`
Access the element at a position (similar to array).

#### 1.4.2. `size`
Return the size of the vector.
*The return type is `unsigned int`. Oftentimes, you want to cast to `int` to
avoid compiler's warning.*

```cpp
    for (int i = 0; i < (int) v.size(); i++) {
        std::cout << "Element number " << i << " is " << v[i] << "\n";
    }
```

#### 1.4.3. `push_back` and `emplace_back`
Both `push_back` and `emplace_back` add an element to the end of the vector.
`push_back` has been around with C++ for a long time while `emplace_back`
is a new feature introduced with C++11.

*Reminder: if you forgot to set Code::Blocks setting to C++14, please return to
my previous instruction.*

```cpp
    std::vector<int> v;       // v = {}
    v.push_back(1);           // v = {1}
    v.emplace_back(2);        // v = {1, 2}
```

There is almost no difference between `push_back` and `emplace_back` when we add
elements to a vector of primitive types (`int`, `double`, `char`, etc.).

However, when it comes to vectors of objects, there are differences:
* `push_back` creates an object, then copy/move it to the end of the vector,
while `emplace_back` creates the object directly at the end of the vector.
Therefore, `emplace_back` is faster.
* Syntax:

```cpp
class Student() {
    private:
        std::string id;
        std::string name;

    public:
        Student(std::string _id, std::string _name) {
            id   = _id;
            name = _name;
        }
}


int main() {
    std::vector<Student> students;
    students.push_back(Student("12345", "Sherlock Holmes"));  // you need to pass the whole constructor
    students.emplace_back("12345", "Sherlock Holmes");        // you only need to pass the parameters of the constructor
                                                              // emplace_back will call the constructor for you!
    return 0;
}
```

### 1.5. Range-based loop
Another great feature introduced with C++11 is range-based loops for
`std::vector` and some other containers. Range-based loops make code much more
readable.

```cpp
int main() {
    std::vector<Student> students;

    for (int i = 0; i < (int) students.size(); i++) {
        std::cout << students[i].name << "\n";
    }

    // The following loop does the same thing
    for (Student &student : students) {
        std::cout << student.name << "\n";
    }
}
```

Be careful when using range-based loop: you should know when you should get element by-reference and when you should get by-value.

```cpp
int main() {
    std::vector<int> nums;

    // This loop does NOT change the vector at all
    for (int x : nums) {
        x++;
    }

    // But this loop does
    for (int& x : nums) {
        x++;
    }

    std::vector<std::string> words;

    // This loop is fast
    for (std::string& word : words) {
        // ...
    }

    // This loop is slow - think about WHY
    for (std::string word : words) {
        // ...
    }
}
```

----------------

## 2. `std::algorithm`

### 2.1. `include` directive
```cpp
#include <algorithm>
```


### 2.2. `std::fill`

`std::fill` fills the range `[begin, end)` of an array or a vector with the
same value.

* **Syntax**
```
    std::fill(ptr_begin, ptr_end);
```
where `ptr_begin` is the pointer to the beginning of the container,
`ptr_end` is the pointer to the end of the container.


* **Example**

```cpp
    int n = 5;
    int x = 3;

    int a[n];
    std::fill(a, a + n, x); // a = {3, 3, 3, 3, 3}

    std::vector<int> v(n);
    std::fill(v.begin(), v.end(), x); // v = {3, 3, 3, 3, 3}
```

### 2.3. `std::sort`

#### 2.3.1. Simple sorting
`std::sort` sorts the range `[begin, end)` of an array or a vector in
non-decreasing order.
* **Syntax**
```cpp
    std::sort(ptr_begin, ptr_end);
```

* **Example**
```cpp
    std::sort(a, a + n);           // array a
    std::sort(v.begin(), v.end()); // vector v
```


#### 2.3.2. Nontrivial sorting (pre-C++11)

*From C++11, these methods for complex sorting can be replaced with
lambda functions. See next part for more information*.

* To sort in reverse order, there are two ways:
  * use `std::greater` from the header `std::functional`.
  * use the `rbegin()` and `rend()` iterators instead of `begin()` and `end()`.

```cpp
#include <algorithm>  // std::sort
#include <functional> // std::greater

const int N = 10;

int main() {
    int a[N];
    vector<int> v(N);

    std::sort(a, a + n, greater<int>());
    std::sort(v.begin(), v.end(), greater<int>());
    std::sort(v.rbegin(), v.rend());
    return 0;
}
```

* To sort class/struct objects, use operator overloading.

```cpp
#include <algorithm>
#include <string>
#include <vector>

class Student {
    private:
        std::string name;
        double gpa;
        double bonus;
    public:
        Student() {}

        Student operator < (const Student& other) {
            if (gpa < other.gpa) {
                return true;
            }
            if (gpa == other.gpa) {
                if (bonus < other.bonus) {
                    return true;
                }
            }
            return false;
        }

        ~Student() {}
};


int main() {
    std::vector<Student> students;

    // ...

    std::sort(student.begin(), student.end()); // just use std::sort normally
                                               // like primitive types here

    return 0;
}
```

#### 2.3.3. Lambda Functions
Lambda functions can be used to define special rules for `std::sort`.

```cpp
#include <algorithm>
#include <string>
#include <vector>

struct Student {
    public:
        std::string name;
        double gpa;
};


int main() {
    std::vector<Student> students;

    // ...

    std::sort(student.begin(), student.end(), [](Student& student_1, Student& student_2) {
        return student_1.gpa < student_2.gpa;
    });


    std::vector<int> nums;

    // ...

    std::sort(nums.begin(), nums.end(), [](int x, int y) {
        return x > y; // sort in non-increasing order
    });

    return 0;
}
```


### 2.4. Binary search

#### 2.4.1 `std::binary_search`

```cpp
    std::binary_search(ptr_begin, ptr_end, val);
```

Return `true` if an element equals to `val` is found, and `false` otherwise.


#### 2.4.2. `std::lower_bound`
```cpp
    std::lower_bound(ptr_begin, ptr_end, val);
```
Returns an iterator pointing to the first element in the range
`[ptr_begin, ptr_end)` which is ![equation](http://latex.codecogs.com/gif.latex?%5Cleq) `val`.

To get the position:

```cpp
    int pos = std::lower_bound(ptr_begin, ptr_end, val) - ptr_begin;
```


#### 2.4.3. `std::upper_bound`
```cpp
    std::upper_bound(ptr_begin, ptr_end, val);
```

To get the position:

```cpp
    int pos = std::upper_bound(ptr_begin, ptr_end, val) - ptr_begin;
```

Returns a pointer pointing to the first element in the range
`[ptr_begin, ptr_end)` which is ![equation](http://latex.codecogs.com/gif.latex?%3E) `val`.


----------------

## 3. `std::utility`

### 3.1. `include` directive
```cpp
#include <utility>
```

### 3.2. `std::swap`
The function `swap` is used to swap two numbers.
* **Syntax**
```cpp
    std::swap(a, b);
```

### 3.3. `std::pair`

#### 3.3.1. Introduction
`std::pair` is a data type which pairs together two different values.


#### 3.3.2. Declaration
* **Example**
```cpp
    std::pair<std::string, int> pair_1;  // empty pair of a std::string and an int
    std::pair<int, int> pair_2 = {1, 2}; // a pair of integers 1 and 2
```

#### 3.3.2. Member variables
A `std::pair` object has two member variables, `first` and `second`.
* **Example**
```cpp
    std::pair<int, int> pair_2 = {1, 2};
    std::cout << "a.first: "  << a.first  << "\n";
    std::cout << "a.second: " << a.second << "\n";
```


#### 3.3.4. `std::make_pair`
A `std::pair` object can be created using the function `std::make_pair`.
* **Example**
```cpp
    const int N = 10;
    std::vector<std::pair<int, int> > points;
    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        points.push_back(std::make_pair(x, y));
    }
```

#### 3.3.5. Sorting
`std::sort` sorts an array or a vector of `std::pair` in non-decreasing order
based on the **first** element.


----------------

## 4. Hash table & Map

## 4.1. `std::unordered_map`

#### 4.1.1. Introduction
In C++ STL, `std::unordered_map` is implemented using **hash table**.

#### 4.1.2. `include` directive
```cpp
#include <unordered_map>
```

#### 4.1.3. Declaration
* **Syntax**
```cpp
    std::unordered_map<key_type, val_type> umap;
```

#### 4.1.4. Access the value of a key
The value of a key can be accessed using the `[]` operator.

* **Syntax**
```cpp
    umap[key]
```


#### 4.1.5. Insert a key-value pair
There are 3 ways to insert a key-value pair:

1. `std::unordered_map::emplace`

* **Syntax**
```cpp
    umap.emplace(key, value);
```

* **Example**
```cpp
    std::unordered_map<std::string, int> age_table;

    age_table.emplace("Alan", 30);
    age_table.emplace("John", 25);
    age_table.emplace("Michael", 33);
```

2. `std::unordered_map::insert`

* **Syntax**
```cpp
    umap.insert(pair);
```
The type of `pair` is `std::pair`. Usually, `insert` is used alongside
`std::make_pair` like this:
```cpp
    umap.insert(std::make_pair(key, val));
```

* **Example**
```cpp
    std::unordered_map<std::string, int> age_table;

    age_table.insert(std::make_pair("Alan", 30));
    age_table.insert(std::make_pair("John", 25));
    age_table.emplace(std::make_pair("Michael", 33));
```


3. `std::unordered_map::operator[]`
The `[]` operator can also be used to insert a key-value pair into
`std::unordered_map`. However, this use is **not recommended**, since
it would make the code unclear.

*The way the `[]` operator work: if the key does not exist, it will
invoke the default constructor to create the key-value pair.*

* **Syntax**
```cpp
    umap[key] = val;
```

* **Example**
```cpp
    std::unordered_map<std::string, int> age_table;

    age_table["Alan"] = 30;
    age_table["John"] = 25;
    age_table["Michael"] = 33;
```

#### 4.1.6. Checking if a key exists
To check if a key exists, use `find()`. The function returns the iterator `end()`
if the key does not exist.
```cpp
    if (age_table.find("Alan") != age_table.end()) {
        std::cout << "Key exists\n";
    }
```


### 4.2. `std::map`

#### 4.2.1. Introduction
Similar to `std::unordered_map`, `std::map` is also a container of elements
where each element is a key-value pair.

The difference is that `std::map` does not implement a hash table, but a
**self-balancing binary search tree** (red-black tree, to be more precise).


### 4.2.2. `include` directive
```cpp
#include <map>
```

### 4.2.3. Usage
The use of `std::map` is mostly the same as `std::unordered_map`:

When looping through all elements, `std::map` keeps its element in
non-decreasing order of the keys by default.


### 4.3. Comparison between `map` and `unordered_map`

|                         | `unordered_map`       | `map`                                  |
|-------------------------|-----------------------|----------------------------------------|
| **ordering**            | (keys) non-decreasing | random                                 |
| **searching/accessing** | O(log(n))             | O(1) (average case); O(n) (worst case) |
| **inserting/deleting**  | O(log(n))             | O(1) (average case); O(n) (worst case) |


----------------

## 5. `std::set`
### 5.1. Introduction
* `std::set` implements a red-black tree, keeping its elements in non-decreasing order.
(similar to `std::map`)
* Each element in `std::set` is **unique**. If the same element is inserted multiple
times, `std::set` only keeps one element.


### 5.2. `include` directive
```cpp
#include <set>
```

### 5.3. Member functions
* `insert`
* `emplace`
* `erase`

----------------

## 6. Abstract Data Types
### 6.1. Queue
#### 6.1.1. `include` directive

```cpp
#include <queue>
```

#### 6.1.2. Notable member functions
* `empty`: check whether queue is empty
* `size`: return size of queue
* `top`: access next element
* `push`: insert element
* `emplace`: construct and insert element
* `pop`: remove top element


### 6.2. Stack

#### 6.2.1. `include` directive
```cpp
#include <stack>
```

#### 6.2.2. Notable member functions
* `empty`: check whether stack is empty
* `size`: return size of stack
* `top`: access next element
* `push`: insert element
* `emplace`: construct and insert element
* `pop`: remove top element


### 6.3. Deque
#### 6.3.1. `include` directive
```cpp
#include <deque>
```

#### 6.3.2. Notable member functions
* `empty`: check whether deque is empty
* `size`: return size of deque
* operator `[]`: access element at a position
* `front`: access element at the front
* `back`: access element at the back
* `push_front`: insert element at the front
* `emplace_front`: construct and insert element at the front
* `push_back`: insert element at the back
* `emplace_back`: construct and insert element at the back
* `pop_front`: remove element at the front
* `pop_back`: remove element at the back


### 6.4. Priority Queue
#### 6.4.1. `include` directive
* `include` directive:
```cpp
#include <queue>
```

#### 6.4.2. Declaration
The default `std::priority queue` is a min heap. To get a max heap, use
`std::greater` from `std::functional`.

* **Example**
```cpp
    priority_queue <int> pq_min;
    priority_queue <int, vector<int>, greater<int> > pq_max;
```

#### 6.4.3. Notable member functions
Similar to `std::queue`.

----------------

### 7. `std::bitset`
A `std::bitset` object stores bits (0 and 1). It is similar to a `bool` array,
except that every element occupies only 1 bit of memory.

`std::bitset` costs less memory and is also faster than arrays or vectors.
Therefore, it is used for optimization.
