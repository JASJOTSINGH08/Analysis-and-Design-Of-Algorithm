import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
data = pd.read_csv('C:\\Users\\Dell\\OneDrive - Aakash Educational Services Ltd\\Desktop\\4th SEM\\output\\output.csv')

# Extract the data for plotting
array_sizes = data['Array Size']
times = data['Time (ms)']

# Plot the graph
plt.plot(array_sizes, times, marker='o', linestyle='-')

# Add labels and title
plt.xlabel('Array Size')
plt.ylabel('Time (ms)')
plt.title('Time Complexity Graph')

# Show grid
plt.grid(True)

# Show plot
plt.show()
