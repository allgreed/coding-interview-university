# Allgreed's Coding Interview University

<!-- todo: Make TOC as prepush hook -->

<!-- Todo: Implement below -->

<!-- ### 2. Use Flashcards

To solve the problem, I made a little flashcards site where I could add flashcards of 2 types: general and code.
Each card has different formatting.

I made a mobile-first website so I could review on my phone and tablet, wherever I am.

Make your own for free:

- [Flashcards site repo](https://github.com/jwasham/computer-science-flash-cards)
- [My flash cards database (old - 1200 cards)](https://github.com/jwasham/computer-science-flash-cards/blob/master/cards-jwasham.db):
- [My flash cards database (new - 1800 cards)](https://github.com/jwasham/computer-science-flash-cards/blob/master/cards-jwasham-extreme.db):

Keep in mind I went overboard and have cards covering everything from assembly language and Python trivia to machine learning and statistics. It's way too much for what's required.

**Note on flashcards:** The first time you recognize you know the answer, don't mark it as known. You have to see the
same card and answer it several times correctly before you really know it. Repetition will put that knowledge deeper in
your brain.

An alternative to using my flashcard site is [Anki](http://ankisrs.net/), which has been recommended to me numerous times. It uses a repetition system to help you remember.
It's user-friendly, available on all platforms and has a cloud sync system. It costs $25 on iOS but is free on other platforms.

My flashcard database in Anki format: https://ankiweb.net/shared/info/25173560 (thanks [@xiewenya](https://github.com/xiewenya)) -->

<!-- 




 -->

<!-- Todo: Answer all question in arrays -->
<!-- Todo: Answer all question in lists -->
<!-- Todo: Answer all question in stacks -->
<!-- Todo: Answer all question in queues -->
<!-- Todo: Answer all question in hash tables -->

<!-- Todo: Add editorconfig to this project and write about it in the README -->

<!-- Todo: Unit testing C -->
<!-- Test case detection -->
<!-- Test suite per file -->
<!-- Assert like behavior, but on failure report also actual value and line -->
<!-- https://stackoverflow.com/questions/65820/unit-testing-c-code -->

## Shoutout and disclaimer

- This repo is a based on [Jwasham's Coding Interview University](https://github.com/jwasham/coding-interview-university)
- I implement everything in C, C++ and C++ with builtin-types
- I've removed all the non-free links or those that I consider of little value

## Prerequisites

**Note: Those are only required to run my code, not to do the course**

### Google test

- clone the repo

```sh
$   sudo git clone https://github.com/google/googletest.git /opt/gtest
```

- go into `/opt/gtest/googletest/make`

```sh
$   cd /opt/gtest/googletest/make
```

- test the Makefile

```sh
$   sudo make
$   sudo chmod +x sample1_unittest
$   ./sample1_unittest
```
- Gtest output should appear with tests passing, if so: you're all set!

#### Writing tests

- copy Makefile to a new project
- change locating variables, mine are:

```make
    GTEST_DIR = /opt/gtest/googletest
    USER_DIR = .
```

- test copied Makefile again with sample self-written test, example:

```cpp
#include "gtest/gtest.h"

TEST(Confirming_setup_ok, dummy)
{
    // this should pass
}

TEST(Confirming_setup_ok, this_passes)
{
    EXPECT_EQ(2 + 2, 4);
}

TEST(Confirming_setup_ok, this_fails)
{
    EXPECT_TRUE(false);
}
```

- incorporate [and refactor!] that Makefile into your flow

### Valgrind

```sh
    sudo apt install valgrind
```

<!-- Boost as a prerequisite to run complexity tests as well as some c++ builtin solutions -->

## How to use it
<!-- Add cool images here -->
<!-- Add shell command here -->
<!-- Add chmod +x on new_stuff.py into setup -->
0. See [Jwasham's repo](https://github.com/jwasham/coding-interview-university) for great non-technical content related to this course
2. Fork this repo
3. Clone the repo
4. Undo all checks <!-- todo: maybe a script for this? -->
5. Code 
6. Code unit fingers burn and your veins pump raw binary
7. Then code some more

<!-- Todo: Say where's what -> code / todos / extras -->

<!-- Todo: redo this -->

Code -> `./code`
Chapter -> eg. data_structures
Case -> inside a chapter -> eg. arrays

## How to create new assignment

Go inside course directory

```sh
    cd code
```

Go inside chapter folder / create one

```sh
    cd [chapter_name_underscores_plural_lowercase] / mkdir [chapter_name_underscores_plural_lowercase]
```

Trigger script with assignment name

```sh
    ../../new_case.py [assignment_name_underscores_singular_lowercase]
```

<!-- Todo: something to do diffs with jwasham to get new assignments, etc. if possible -->

