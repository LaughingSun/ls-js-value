
### Container breakdown as ls-js-types

ls::js::Value uses 

`string_t` are sequential containers that contain key-value pairs with unique keys that meet the requirements of mapped_types, Container, SequentialContainer and AllocatorAwareContainer; and must use a <charT> value.

`array_t` are sequential containers that contain key-value pairs with unique keys that meet the requirements of Container, SequentialContainer and AllocatorAwareContainer; and must NOT use a <charT> element value.

`object_t` are associative containers that contain key-value pairs with unique keys that meet the requirements of mapped_types, Container and AllocatorAwareContainer.



| ls-js-value type | stl class    | desc            |
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

