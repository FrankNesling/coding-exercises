import time
# how many possible ways to go n steps with possible stepsizes [x,y, ...]

def step_count(n, stepsizes):
  if n == 0:  # valid step combination
    return 1
  elif n < 0: # invalid step combination
    return 0

  return sum(step_count(n-s, stepsizes) for s in stepsizes)

def mem_count(n, stepsizes, cache = {}):
  if n == 0:  # valid step combination
    return 1
  elif n < 0: # invalid step combination
    return 0

  # add element to cache if not yet calculated
  if n not in cache:
    cache[n] = sum(mem_count(n-s, stepsizes, cache) for s in stepsizes)

  return cache[n]


stepcount = int(input("How many stepsizes?\n"))
stepsizes = []

print("Which stepsizes?")
for k in range(stepcount):
  stepsizes.append(int(input()))

n = int(input("How many steps?\n"))

start = time.time()
print(step_count(n, stepsizes))
end = time.time()
print(f'Elapsed time: {end - start}')

print("With memoization: ")
start = time.time()
print(mem_count(n, stepsizes))
end = time.time()
print(f'Elapsed time: {end - start}')