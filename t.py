# %%

import math
# %%
math.sinh(1)
# %%
math.exp(2)
# %%
from decimal import Decimal

def e(x):
    s = Decimal('0')
    for i in range(1000):
        s += x/math.factorial(i)
        x *= x
    return s


# %%
e(Decimal('1'))
# %%
math.exp(1)
# %%

def sinh(x):
    return (e(x)-e(-x))/2

sinh(Decimal('1'))
# %%
math.sinh(1)
# %%
(math.exp(1)-math.exp(-1))/2
# %%
e(Decimal('-1'))
# %%
(e(Decimal('1'))-e(Decimal('-1')))
# %%

for i in range(100):
    if math.factorial(i)> 2147483647:
        print(i)
        break
# %%
