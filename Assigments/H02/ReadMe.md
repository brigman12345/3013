## H02: Hashing
### James Steward
### Description: 

## Part A: Conceptual Questions

#### 1. What is a hash table and why is collision resolution necessary?
A hash table is a data structure that organizes data into key-value pairs using a hash function to compute an index. Collision resolution is necessary because different keys may hash to the same index. Without resolving collisions, only one value could be stored per index, severely limiting usability.

#### 2. Key differences between open hashing (chaining) and closed hashing (open addressing):
Open Hashing (Chaining): Each index in the table holds a collection (e.g., a dynamic array or binary tree) to manage multiple keys that hash to the same index.  
Pros: Adapts well to growing datasets.  
Cons: Requires extra memory for the structures used at each index.

Closed Hashing (Open Addressing): Searches the table itself for the next available slot when a collision occurs.  
Pros: No need for external memory allocation.  
Cons: Can degrade in performance at high load factors.

#### 3. Collision Resolution Techniques:
Linear Probing: If a collision occurs at index i, check i+1, i+2, etc., until a free slot is found.  
Pros: Easy to implement.  
Cons: Can cause clustering, reducing performance.

Quadratic Probing: Checks slots at increasing square distances (i+1², i+2², etc.).  
Pros: Less clustering than linear probing.  
Cons: Still vulnerable to secondary clustering and may not find a slot if the table isn’t sized properly.

Double Hashing: Uses a second hash function to determine the step size when searching for a new slot.  
Pros: Reduces clustering significantly.  
Cons: Slightly more complex to implement.

#### 4. Which collision resolution technique can handle more values than table slots?
Open Hashing (Chaining) can store more elements than there are table slots because each slot can contain a list or another structure that grows as needed.

#### 5. Worst-case performance (Big O) for collision resolution techniques: 
Open Hashing (Chaining): O(n), if all keys hash to the same index.  
Linear Probing: O(n), when the table is nearly full and many probes are needed.  
Quadratic Probing: O(n), but typically performs better than linear probing.  
Double Hashing: O(n) in worst case, but often performs close to O(1) if well-designed.

#### 6. How does the choice of table size affect the distribution of keys?
Using a table size that is a prime number helps distribute keys more uniformly, minimizing collisions. Non-prime sizes can create patterns that reduce randomness and hurt performance.

#### 7. Pitfalls of using a poor table size (e.g., round number or power of 2)?
Round Numbers: These can align poorly with the output of hash functions, leading to more collisions.  
Powers of 2: May cause repetitive placement patterns due to bit alignment, creating clustering and reducing table efficiency.

## Part B: Reflection & Short-Answer Questions

#### 1. Real-World Impact:
In a cloud-based key-value store, using an inefficient table size can result in frequent collisions, increasing the time to retrieve or insert data and degrading performance during peak usage.

#### 2. Open vs Closed Hashing in High-Load Scenarios:
Open Hashing: Performs better with high volumes because structures like lists or trees can grow. Suitable for log systems or user session tracking.  
Closed Hashing: Becomes inefficient as the load factor approaches 1, since probing increases and performance drops.

#### 3. Hash Table for High-Frequency Trading:
Closed Hashing with Double Hashing is ideal due to predictable lookup times and compact memory use, which is critical in time-sensitive environments like financial trading systems.

#### 4. Hybrid Hash Table Design:
A hybrid system could use chaining initially and switch to open addressing if memory usage crosses a threshold. For example, use chaining when load factor < 0.7, then switch to linear probing for higher efficiency when memory gets tight.
