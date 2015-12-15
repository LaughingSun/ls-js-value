
# Containers

## Containers feature support

| library      | string_t | array_t | object_t | seq | assoc | char | comp | multi |
| ------------ | :------: | :-----: | :------: | :-: | :---: | :--: | :--: | :---: |
| string       | yes      |         |          | yes |       | yes  | yes  |       |
| array        |          | yes     |          | yes |       |      | yes  |       |
| vector       |          | yes     |          | yes |       |      | yes  |       |
| deque        |          | yes     |          | yes |       |      | yes  |       |
| forward_list |          | yes     |          | yes |       |      | yes  |       |
| list         |          | yes     |          | yes |       |      | yes  |       |
| stack        |          | yes     |          | yes |       |      | yes  |       |
| queue        |          | yes     |          | yes |       |      | yes  |       |
| priority_queue|         | yes     |          | yes |       |      | yes  |       |
| map          |          |         | yes      |     | yes   |      | yes  |       |
| set          |          |         |          |     | yes   |      | yes  |       |
| unordered_map|          |         | yes      |     | yes   |      | yes  |       |
| unordered_set|          |         |          |     | yes   |      | yes  |       |
| multimap     |          |         |          |     | yes   |      | yes  | yes   |
| multiset     |          |         |          |     | yes   |      | yes  | yes   |
| unordered_multimap|     |         |          |     | yes   |      | yes  | yes   |
| unordered_multiset|     |         |          |     | yes   |      | yes  | yes   |



## ls::js::Value::* interface types:

### Containers suitable as a ls::js::Value::string_t

`string_t` are sequential containers that contain key-value pairs with unique keys that meet the requirements of  Container, SequentialContainer, AllocatorAwareContainer and ContiguousContainer(since C++17); and must use a <charT> value.

String_t&lt;SequenceContainers, class char_traits, class Allocator&gt; std and stl class candidates:

+ `template<class CharT, class Traits = std::char_traits<CharT>, class Allocator = std::allocator<CharT>> class basic_string;`

### Containers suitable as a ls::js:Value::array_t

`array_t` are sequential containers that contain key-value pairs with unique keys that meet the requirements of Container, SequentialContainer and AllocatorAwareContainer; and must NOT use a <charT> element value.

Array_t&lt;SequenceContainers, class !char_traits, class Allocator&gt; std and stl class candidates:

+ `template<class T, std::size_t N > struct array;`
+ `template<class T, class Allocator = std::allocator<T>> class deque;`
+ `template<class T, class Allocator = std::allocator<T>> class forward_list;`
+ `template<class T, class Allocator = std::allocator<T>> class list;`
+ `template<class T, class Allocator = std::allocator<T>> class vector;`
+ `template<class T, class Container = std::deque<T>> class stack;`
+ `template<class T, class Container = std::vector<T>, class Compare = std::less<typename Container::value_type>> class priority_queue;`
+ `template<class T, class Container = std::deque<T>> class queue;`
+ `template<class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key>> class set;`

### Containers suitable as a ls::js:Value::object_t

`object_t` are associative containers that contain key-value pairs with unique keys that meet the requirements of mapped_types, Container and AllocatorAwareContainer.

Object_t&lt;AssociativeContainer | UnorderedAssociativeContainer&gt; std and stl class candidates:

+ `template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T>>> class map;`
+ `template<class Key, class T, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key>, class Allocator = std::allocator< std::pair<const Key, T>>> class unordered_map;`


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
3. http://en.cppreference.com/w/cpp/concept/SequenceContainer
4. http://en.cppreference.com/w/cpp/concept/UnorderedAssociativeContainer
5. http://en.cppreference.com/w/cpp/string
6. http://en.cppreference.com/w/cpp/string/basic_string
7. http://en.cppreference.com/w/cpp/container
8. http://en.cppreference.com/w/cpp/container/map
9. http://en.cppreference.com/w/cpp/container/unordered_map
10. http://en.cppreference.com/w/cpp/container/array
11. http://en.cppreference.com/w/cpp/container/deque
12. http://en.cppreference.com/w/cpp/container/forward_list
13. http://en.cppreference.com/w/cpp/container/list
14. http://en.cppreference.com/w/cpp/container/vector
15. http://en.cppreference.com/w/cpp/container/stack
16. http://en.cppreference.com/w/cpp/container/priority_queue
17. http://en.cppreference.com/w/cpp/container/queue
18. http://en.cppreference.com/w/cpp/container/set
19. http://en.cppreference.com/w/cpp/memory/allocator


