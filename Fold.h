class Functional
{
    template<typename Accumulator, typename BeginIterator, typename EndIterator, typename Range>
    static Range FoldImpl(BeginIterator front, EndIterator back, Range initial)
    {
        if (front == back) return initial;
        Range sum = initial;
        for (BeginIterator index = front; index != back; ++ index) sum = Accumulator()(sum, * index);
        return sum;
    }
public:
    template<typename Action, typename Container, typename Range>
    static Range Fold(Container container, Range initial)
    {
        return FoldImpl<Action>(container.begin(), container.end(), initial);
    }
};