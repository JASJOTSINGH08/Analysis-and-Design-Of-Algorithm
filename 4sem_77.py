import matplotlib.pyplot as plt

# Lists to store data
sizes = []
avg_times = []

# Read data from the text file
with open('sum_of_array_result.txt', 'r') as file:
    for line in file:
        size, avg_time = map(int, line.strip().strip('()').split(','))
        sizes.append(size)
        avg_times.append(avg_time)

# Plot the data
plt.plot(sizes, avg_times, marker='o', linestyle='-')
plt.title('Average Time Complexity of Array Summation')
plt.xlabel('Array Size')
plt.ylabel('Average Time (microseconds)')
plt.grid(True)
plt.show()
