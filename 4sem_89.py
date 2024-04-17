import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file into a DataFrame
df = pd.read_csv('time_complexity.csv', header=None, names=['Time (microseconds)'])

# Plot the data
plt.plot(df.index, df['Time (microseconds)'], marker='o', linestyle='-')
plt.xlabel('Permutation')
plt.ylabel('Time (microseconds)')
plt.title('Time Complexity of Truth Table Permutations')
plt.grid(True)
plt.show()
