template<unsigned NumberOfItems, typename Accumulator, typename Magma>
Magma Fold(Magma magma[NumberOfItems])
{
    Magma sum = magma[0];
    for (unsigned index = 1; index < NumberOfItems; ++index) sum = Accumulator()(sum, magma[index]);
    return sum;
}