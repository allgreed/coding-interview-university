### Hash table

Started @: 2017-11-02 15:44
Finished @: yyyy-mm-dd hh:mm

- [ ] Videos:
    - [x] [Hashing with Chaining (video)](https://www.youtube.com/watch?v=0M_kIqhwbFo&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=8)
    - [x] [Table Doubling, Karp-Rabin (video)](https://www.youtube.com/watch?v=BRO7mVIFt08&index=9&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
    - [x] [Open Addressing, Cryptographic Hashing (video)](https://www.youtube.com/watch?v=rvdJDijO2Ro&index=10&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
    - [x] [PyCon 2010: The Mighty Dictionary (video)](https://www.youtube.com/watch?v=C4Kc8xzcA68)
    - [ ] [(Advanced) Randomization: Universal & Perfect Hashing (video)](https://www.youtube.com/watch?v=z0lJ2k0sl1g&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp&index=11)
    - [ ] [(Advanced) Perfect hashing (video)](https://www.youtube.com/watch?v=N0COwN14gt0&list=PL2B4EEwhKD-NbwZ4ezj7gyc_3yNrojKM9&index=4)

- [x] Online Courses:
    - [x] [Core Hash Tables (video)](https://www.coursera.org/learn/data-structures-optimizing-performance/lecture/m7UuP/core-hash-tables)
    - [x] [Phone Book Problem (video)](https://www.coursera.org/learn/data-structures/lecture/NYZZP/phone-book-problem)
    - [x] distributed hash tables:
        - [Instant Uploads And Storage Optimization In Dropbox (video)](https://www.coursera.org/learn/data-structures/lecture/DvaIb/instant-uploads-and-storage-optimization-in-dropbox)
        - [Distributed Hash Tables (video)](https://www.coursera.org/learn/data-structures/lecture/tvH8H/distributed-hash-tables)

- [x] implement with array using linear probing
    - hash(k, m) - m is size of hash table
    - add(key, value) - if key already exists, update value
    - exists(key)
    - get(key)
    - remove(key)

- [ ] Implement in:
    - [x] C (division method)
    - [x] Do a benchmark to prove it's truly constant time
    - [x] Redo C with multiplication method + refactor
    - [x] Redo C makefile so that it works as desired (make runs only units, make complexity runs units, than complexity test [maybe parametrize this])

    - [ ] C++ (universal hashing) (first video 48:51)
    - [ ] Do a C++ benchmark

    - [ ] C++ with builtin types (built-in hash)
    - [ ] Do a benchmark vs. STDLib

- [ ] Do a benchmark of any hashing function for hashing for a certain type of keys, plot distribution to a graph (Python)

<!-- templates -->
    <!-- cpp makefile -> make template not list -->

<!-- templates -->
    <!-- Makefile -> valgrind takes variable target -->

<!-- temapltes -->
    <!-- Change "valgrind" to "memeleak" in report section -->

<!-- templates -->
    <!-- Add complexity test rules for makefile -->

<!-- templates -->
    <!-- Redo makefile to be more generic -->
