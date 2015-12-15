
### Container breakdown as ls-js-types

| ls-js-value type | stl class    | desc            |
| ---------------- | ------------ | --------------- |
| string_t | basic_string | stores and manipulates sequences of characters |
|              |  |  |
| array_t | array | static contiguous array |
|              |  | Fast access but fixed number of elements |
| array_t | vector | dynamic contiguous array |
|              |  | Fast access but mostly inefficient insertions/deletions |
| array_t | deque | double-ended queue |
|              |  | Efficient insertion/deletion at the beginning and at the end of the sequence |
| array_t | forward_list | singly-linked list |
|              |  | Efficient insertion/deletion in the middle of the sequence |
| array_t | list | doubly-linked list |
|              |  |  |
