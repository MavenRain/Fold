template<typename Accumulator, typename BeginIterator, typename EndIterator, typename Range>
Range Fold(BeginIterator front, EndIterator back, Range initial)
{
    if (front == back) return initial;
    Range sum = initial;
    for (BeginIterator index = front; index != back; ++ index) sum = Accumulator()(sum, * index);
    return sum;
}
template<typename Action, typename Container, typename Range>
Range Fold(Container container, Range initial)
{
    return Fold<Action>(container.begin(), container.end(), initial);
}