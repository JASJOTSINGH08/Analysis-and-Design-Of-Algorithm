import matplotlib.pyplot as plt
import csv

# Read data from CSV file
disks = []
times = []
with open('time_complexity.csv', 'r') as file:
    reader = csv.reader(file)
    next(reader)  # Skip header
    for row in reader:
        disks.append(int(row[0]))
        times.append(int(row[1]))

# Plot the data
plt.plot(disks, times, marker='o', linestyle='-')
plt.title('Time Complexity of Tower of Hanoi')
plt.xlabel('Number of Disks')
plt.ylabel('Time (microseconds)')
plt.grid(True)
plt.show()
