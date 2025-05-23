class Solution:
    def divide(self, dividend, divisor):
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        if dividend == INT_MIN and divisor == -1:
            return INT_MAX

        sign = -1 if (dividend < 0) ^ (divisor < 0) else 1

        dividend = abs(dividend)
        divisor = abs(divisor)
        quotient = 0

        for i in range(31, -1, -1):
            if (dividend >> i) >= divisor:
                quotient += 1 << i
                dividend -= divisor << i

        return sign * quotient
