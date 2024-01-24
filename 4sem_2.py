import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
df = pd.read_csv("C:\\Users\\Dell\\OneDrive - Aakash Educational Services Ltd\\Desktop\\4th SEM\\output\\execution_times.csv")

# Plotting the graph
plt.plot(df['Size'], df['ExecutionTime'], marker='o')
plt.title('Selection Sort Execution Time')
plt.xlabel('Input Size')
plt.ylabel('Execution Time (seconds)')
plt.xscale('log')  # Use a logarithmic scale for better visualization
plt.show()
