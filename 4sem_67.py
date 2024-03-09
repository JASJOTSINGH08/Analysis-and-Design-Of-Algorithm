import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file into a DataFrame
df = pd.read_csv('C:\\Users\\Dell\\OneDrive - Aakash Educational Services Ltd\\Desktop\\4th SEM\\output\\max_min_fnc.csv')

# Plot the data
plt.figure(figsize=(10, 6))
plt.plot(df['Traversal'], df['Execution Time (microseconds)'], marker='o', linestyle='-')
plt.title('Execution Time vs. Traversal')
plt.xlabel('Traversal')
plt.ylabel('Execution Time (microseconds)')
plt.grid(True)
plt.savefig('execution_times_plot.png')  # Save the plot as an image
plt.show()
