import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file into a pandas DataFrame
df = pd.read_csv('C:\\Users\\Dell\\OneDrive - Aakash Educational Services Ltd\\Desktop\\4th SEM\\output\\iterative_execution_times.csv')

# Plot the graph
plt.figure(figsize=(10, 6))
plt.plot(df['Low'], df['ExecutionTime'], marker='o', linestyle='-')
plt.xlabel('Low Index')
plt.ylabel('Execution Time (seconds)')
plt.title('Execution Time vs. Low Index')
plt.grid(True)
plt.show()
