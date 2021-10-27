fib = []

fib.append(0)
fib.append(1)

for i in range(2, 491):
    fib.append(fib[i - 1] + fib[i - 2])

while(True):
    t = int(input())
    if(t == -1): break
    print("Hour ", t, ": ", fib[t], " cow(s) affected", sep = "")