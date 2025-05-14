## H02: Hashing
### James Steward
### Description: 

## Part A: Conceptual Questions
#### 1. What is a hash table and why is collision resolution necessary?
A hash table is a data structure that stores key-value pairs, where a hash function maps each key to an index in an array. Collision resolution is necessary when two keys hash to the same index. Without it, only one key could be stored at each index, limiting the hash table’s functionality.

#### 2. Key differences between open hashing (chaining) and closed hashing (open addressing):
Open Hashing (Chaining): Uses linked lists at each table index to store multiple keys that hash to the same index.
Pros: Handles collisions efficiently, flexible size.
Cons: Extra memory for linked lists.
Closed Hashing (Open Addressing): When a collision occurs, it searches for another open slot within the table itself.
Pros: No extra memory overhead.
Cons: Clustering may occur, performance can degrade when table is full.

#### 3. Collision Resolution Techniques:
Linear Probing: When a collision occurs, check the next slot (i+1) until an empty slot is found.
Pros: Simple to implement.
Cons: Primary clustering (consecutive slots get filled).
Quadratic Probing: Checks slots at quadratic intervals (i+1², i+2², etc.) to resolve collisions.
Pros: Reduces primary clustering.
Cons: Secondary clustering may still occur.
Double Hashing: Uses a second hash function to determine the next slot when a collision occurs.
Pros: Minimizes clustering. 
Cons: More complex to implement.

#### 4. Which collision resolution technique can handle more values than table slots? 
Open Hashing (Chaining) can handle more values than table slots, as each slot can hold multiple values using a linked list or other data structure. 

#### 5. Worst-case performance (Big O) for collision resolution techniques: 
Open Hashing (Chaining): O(n) in the worst case, when all keys collide at the same index. Linear Probing: O(n) in the worst case, when the table is nearly full. Quadratic
Probing: O(n), but performs better than linear probing in practice. Double Hashing: O(n), but usually performs better than linear and quadratic probing. 

#### 6. How does the choice of table size affect the distribution of keys? 
A good table size (typically a prime number) ensures that keys are spread more evenly across the table, reducing collisions. A poor table size leads to clustering and poor distribution.

#### 7. Pitfalls of using a poor table size (e.g., round number or power of 2)?
Round Numbers: These often lead to bad key distributions as hash functions tend to align poorly with these numbers.
Powers of 2: Can cause patterns in the hash function, leading to clustering and inefficient storage.



## Part B: Reflection & Short-Answer Questions
#### 1. Real-World Impact:
Poor hash table size leads to performance degradation because of increased collisions, requiring more probing or more linked list entries, which increases access time.

#### 2. Open vs Closed Hashing in High-Load Scenarios:
Open Hashing: Handles high load better because chains can dynamically grow. It’s more flexible.
Closed Hashing: May suffer from clustering and degraded performance under high load due to limited slots.

#### 3. Hash Table for High-Frequency Trading:
Closed Hashing (Linear Probing) or Double Hashing would be preferred because of faster access times (lower memory overhead, more efficient probing).

#### 4. Hybrid Hash Table Design:
A hybrid hash table could combine open hashing for flexibility and closed hashing for efficiency, using open hashing for low load factors and closed hashing when the table is near capacity to optimize space and time.
