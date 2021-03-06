# Data Structures

## Contiguous DS:
- Single slab of memory
- Examples: Array, matrices, heaps and hash tables.

## Linked DS
- Linked by pointers
- Ex: Lists, trees, graph adjacency lists


## Arrays

- Constant access time given index,
- Space efficieny as contains only data; no structure
- No end-of-record needed,
- efficient in iteration due to memory locality;
- cannot resize during execution


## Dynamic Arrays
- doubles size when limit reached; this involves:
    - allocating contigious 2x space,
    - copy content to new array,
    - free space

    __Note:__
        
    Assuming starting with 1 unit space, how many times elements needs to be recopied after n insertions?
    Ans: 1st element will be copied on 2nd,4th, 8th,... lgn insertion so total movement = half elements moving once + quarter moving twice +
    ...
    = n/2 + 2*n/4 + 3*n/8 + ... + lgn*n/n
    < n/2 + 2n/4 + 3n/8 + 4n/16 + ... infi
    < 2n
        
    implies: dynamic arrays behave as if all the elements were copied twice on average. Total work in managing is O(n)!


## Linked Structures
### LinkedList
- Basic operations: Searching, Insertion & deletion
- Overflow can never happen unless memory is actually full
- Insertion & deletion are simpler
- With large records, moving pointers is easier than moving records
- Needs extra space for storing pointers
- No efficient random access
- Array provide better memory locality and cache perf than random
    pointer jumping
- Recursive objects. Chopping element off, leaves linked list.



## Containers
- Support storage and retrieval of data items independent of content.
- Containers are distinguished by the retrieval order they support. In two
    most imp ones, retrieval order depends on insertion order.
- By contrast dictionaries are abstract data types that retrieve based on
    key values or content.
- Stacks and queues can be implemented by using arrays or linked lists. The
    key issue is whehter an upper bound on container size is known which
    permits statically-allocated array.

### Stacks 
- Retrieval by last-in, first-out (LIFO),
- Simple and efficent,
- Best when order doesn't matter,
- Push/Pop
    - push(x,s): Insert item x at top of stack s
    - pop(s): Return and remove the top item of stack s
- LIFO tends to happen in executing recursive algorithms.

### Queue
- Retrieval by First-in, First-out (FIFO),
- Used to minimize the MAXIMUM time spent waiting. Notice that the average waiting time for LIFO and FIFO are the same.
- Trickier to implement,
- Best when order is important,
- Enqueue/Dequeue
    - Enqueue(x, q): Insert item x at the back of queue q
    - Dequeue(q): Return and remove the front item from queue q.
- Example usage: Breadth-First search in graphs

    
    
### Dictionaries
- Priority queues can be implemented using dictionary's MIN/MAX operation
- Binary search tree and hash tables are powerful implementation of dictionary.
- Common operations:
    - Search(D, k)
    - Insert(D, x)
    - Delete(D, x)
    Some dictionary datastructures also support:
    - Max(D)
    - Min(D)
    - Predecessor(D, k)
        - Successor(D, k)

## Assymptotic worst case analysis

                    Unsorted array          Sorted array
    Search          O(n)                    O(logn)
    Insert          O(1)                    O(n)
    Delete          O(1)*                   O(n)
    Successor       O(n)                    O(1)
    Predecessor     O(n)                    O(1)
    Min             O(n)                    O(1)
    Max             O(n)                    O(1)

    * Deletion in unsorted array is simply deleting the element
    * referenced by the pointer and swapping the A[n] element in its place and
    * decrementing n.



                    S_U         D_U         S_S         D_S
    Search          O(n)        O(n)        O(n)        O(n)
    Insert          O(1)        O(1)        O(n)        O(n)
    Delete          O(n)        O(1)        O(n)        O(1)
    Successor       O(n)        O(n)        O(1)        O(1)
    Predecessor     O(n)        O(n)        O(n)        O(1)
    Min             O(n)        O(n)        O(1)        O(1)
    Max             O(n)        O(n)        O(1)*       O(1)*            

    S_U: Singly unsorted, D_U: Doubly unsorted, S_S: Singly sorted,
    D_S: Doubly sorted

    * Maintain a separate pointer to the last element. The cost for
    * maintaining it can be charged from insertion and deletion which
    * are already O(n) for S_S. For D_S its just a matter of pointer
    * manipulation.



### Binary Search Trees
- Designed specifically for fast search AND flexible update as arrays and linked list provide either of those.
- Criteria:
    - All nodes on left subtree of x have keys < x
    - All nodes on right subtree of x have keys > x
- Above criteria implies there is exactly one labeling that makes a BST.

      Tree node labelling:

        3       3      2      1       1
        2       1      1 3      3       2
    1         2             2         3

- Traversal is O(n) operation, n=# of nodes
    
    
### Balanced Search Tree
- Adjusts tree on insertion/deletion so that MAX(height) ~ log(n).
- Ex: Red-Black trees, Splay trees.


### Priority Queue
- Provides following operations:
    - Insert(Q,x)
    - Find-Minimum(Q)/Find-Maximum(Q)
    - Delete-Minimum(Q)/Delete-Maximum(Q)
- Ex: Heap


                    unsorted array      sorted array        balanced tree
        insert      O(1)                O(n)                O(logn)
        min*        O(1)                O(1)                O(1)
        delete      O(n)                O(1)                O(logn)

- For min: store the min in a pointer variable and update on deletion/insertion
