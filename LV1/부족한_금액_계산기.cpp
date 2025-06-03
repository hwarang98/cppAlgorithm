#include <string>

using namespace std;

long long solution(int price, int money, int count)
{
    long long totalPrice = (long long)price * count * (count + 1) / 2;
    long long lackPrice = totalPrice - money;
    return lackPrice > 0 ? lackPrice : 0;
}
