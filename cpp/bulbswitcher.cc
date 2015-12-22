/*
Consider k <= n, if k has ''x'' divisors, bulb k will be toggled
for ''x'' times.
if x is odd : the bulb is on at last
if x is even : the bulb is off at last
The problem turns to:
for i in [1,2,3,..,n], how many i have odd numbers of divisors
note that only the square number have odd numbers of divisors
there are floor(sqrt(n)) square number in n 
*/

#include <stdlib.h>
#include <math.h>

class Solution{
public:
  int bulbSwitch(int n){
    return static_cast<int>(std::sqrt(n));
  }
}