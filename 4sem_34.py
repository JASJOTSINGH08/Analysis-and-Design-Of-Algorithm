import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file into a pandas DataFrame
df = pd.read_csv('C:\\Users\\Dell\\OneDrive - Aakash Educational Services Ltd\\Desktop\\4th SEM\\output\\merge_sort_execution_times.csv')

# Plot the graph
plt.plot(df['n'], df['Time'], label='Execution Time')
plt.plot(df['n'], df['Log(n)'], label='Log(n)')
plt.xlabel('Input Size (n)')
plt.ylabel('Time (seconds) / Log(n)')
plt.title('Merge Sort Execution Time vs. Input Size')
plt.legend()
plt.grid(True)
plt.show()
