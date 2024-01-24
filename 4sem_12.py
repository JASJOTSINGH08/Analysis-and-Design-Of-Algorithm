import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
df = pd.read_csv("C:\\Users\\Dell\\OneDrive - Aakash Educational Services Ltd\\Desktop\\4th SEM\\output\\execution_times.csv6")

# Plot the data
plt.plot(df['Size'], df['ExecutionTime'], marker='o', linestyle='-')
plt.title('Execution Time vs Input Size')
plt.xlabel('Input Size')
plt.ylabel('Execution Time (seconds)')
plt.xscale('log')  # Set x-axis to logarithmic scale for better visualization
plt.grid(True)
plt.show()
