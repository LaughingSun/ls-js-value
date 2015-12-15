
### Container breakdown as ls-js-types

ls::js::Value uses 

`string_t` are sequential containers that contain key-value pairs with unique keys that meet the requirements of  Container, SequentialContainer, AllocatorAwareContainer and ContiguousContainer(since C++17); and must use a <charT> value.

String_t std and stl class candidates:

+ `template<class CharT, class Traits = std::char_traits<CharT>, class Allocator = std::allocator<CharT>> class basic_string;`

`array_t` are sequential containers that contain key-value pairs with unique keys that meet the requirements of Container, SequentialContainer and AllocatorAwareContainer; and must NOT use a <charT> element value.

Array_t std and stl class candidates:

+ `template<class T, std::size_t N > struct array;`
+ 

`object_t` are associative containers that contain key-value pairs with unique keys that meet the requirements of mapped_types, Container and AllocatorAwareContainer.

Object_t std and stl class candidates:

+ template<class Key, class T, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key>, class Allocator = std::allocator< std::pair<const Key, T>>> class unordered_map;
+ 


| ls-js-value type | class / concept    | description / notes            |
| ---------------- | ------------ | --------------- |
| string_t | basic_string | stores and manipulates sequences of characters |
|              |  | Character data general usage |
| array_t | array | static contiguous array |
|              | SequenceContainer | Fast access but fixed number of elements |
| array_t | vector | dynamic contiguous array |
|              | SequenceContainer | Fast access but mostly inefficient insertions/deletions |
| array_t | deque | double-ended queue |
|              | SequenceContainer | Efficient insertion/deletion at the beginning and at the end of the sequence |
| array_t | forward_list | singly-linked list |
|              | SequenceContainer | Efficient insertion/deletion in the middle of the sequence |
| array_t | list | doubly-linked list |
|              | SequenceContainer |  Efficient insertion/deletion in the middle of the sequence |
| object_t | map | desc |
|              | AssociativeContainer  | notes |
| object_t | unordered_map | desc |
|              | AssociativeContainer  | notes |

Reference and related links:

1. http://en.cppreference.com/w/cpp/concept/Container
2. http://en.cppreference.com/w/cpp/concept/AssociativeContainer
2. http://en.cppreference.com/w/cpp/concept/SequenceContainer
3. http://en.cppreference.com/w/cpp/concept/UnorderedAssociativeContainer
5. http://en.cppreference.com/w/cpp/string
4. http://en.cppreference.com/w/cpp/string/basic_string
4. http://en.cppreference.com/w/cpp/container
4. http://en.cppreference.com/w/cpp/container/map
5. http://en.cppreference.com/w/cpp/container/unordered_map
6. http://en.cppreference.com/w/cpp/container/array
7. http://en.cppreference.com/w/cpp/container/deque
8. http://en.cppreference.com/w/cpp/container/forward_list
9. http://en.cppreference.com/w/cpp/container/list
10. http://en.cppreference.com/w/cpp/container/vector
11. a
12. a
8. http://en.cppreference.com/w/cpp/memory/allocator


