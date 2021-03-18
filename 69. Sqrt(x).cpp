int mySqrt(int x)
{
    int num = x, count = 0;
    while (num)
    {
        num >>= 1;
        count++;
    }
    count /= 2;
    while (count < 46340 && count * count < x && (count + 1) * (count + 1) <= x)
        count++;
    return count;
}

int mySqrt(int x)
{
    if (x <= 1)
    {
        return x;
    }

    int left = 1, right = x;
    int mid;

    while (left < right)
    {

        mid = left + (right - left) / 2;

        if (x / mid == mid)
        {
            return mid;
        }
        else if (x / mid < mid)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return mid;
}
// bit level solution
//Since sqrt(x) is composed of binary bits, I calculate sqrt(x) by deciding every bit from the most significant to least significant.Since an integer n can have O(log n) bits with each bit 
// decided within constant time, this algorithm has time limit O(log n), actually, because an Integer can have at most 32 bits, I can also say this algorithm takes O(32) = O(1) time.
int mySqrt(int x)
{
    unsigned int res = 0;
    for (int i = 15; i >= 0; i--)
    {
        if ((res + (1 << i)) * (res + (1 << i)) <= x)
            res += (1 << i);
    }
    return res;
}