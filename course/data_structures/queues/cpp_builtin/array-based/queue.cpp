template <typename T>
Queue<T>::Queue() : Queue(DEFAULT_CAPACITY) {}

template <typename T>
Queue<T>::Queue(int desired_capacity)
{
    circular_buffer.set_capacity(desired_capacity);
}

template <typename T>
void Queue<T>::enqueue(T value)
{
    circular_buffer.push_back(value);
}

template <typename T>
T Queue<T>::dequeue()
{
    T retval = circular_buffer.front();
    circular_buffer.pop_front();
    return retval;
}

template <typename T>
bool Queue<T>::empty()
{
    return circular_buffer.empty();
}

template <typename T>
bool Queue<T>::full()
{
    return circular_buffer.full();
}
