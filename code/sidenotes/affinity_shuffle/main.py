def affinity_function(a,b,x,n):
    return (a*x + b) % n 

def specialized_affinity_function(n, seed, base_function):
    a = 5
    b = seed 

    def _affinity_function(x):
        return base_function(a,b,x,n)
    return _affinity_function

def specialized_shuffle(array, affinity_function_base):
    this_affinity_function = specialized_affinity_function(len(array), 3, affinity_function_base)

    def _shuffled_element(index):
        return array[this_affinity_function(index)]
    return _shuffled_element

# ------------

array = [1,2,3,4,5,6,7,8,9,10,11,12]

shuffled_element = specialized_shuffle(array, affinity_function)

# bake this into the code
    # figure out what should be a parameter and what's not

# make sure that A is ok
    # A must be coprime with n
        # how to make sure?

# make this work as a generator that takes array
# write tests
    # list of len prime
    # list of len not prime

def main():
    for i, index in enumerate(array):
        print("{} {}".format(i+1, shuffled_element(index)))

if __name__ == "__main__":
    main()
