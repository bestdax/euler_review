digit_sum = 0
for c in str(2**1000):
    digit_sum += int(c)

print(f'The answer is: {digit_sum}')
