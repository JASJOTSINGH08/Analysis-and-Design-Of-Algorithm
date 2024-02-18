import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
df = pd.read_csv("C:\\Users\\Dell\\OneDrive - Aakash Educational Services Ltd\\Desktop\\4th SEM\\output\\cases_execution_times.csv")

# Plot the data
plt.plot(df['Low'], df['ExecutionTime'], marker='o', linestyle='-', label='Worst Case')
plt.plot(df['High'], df['ExecutionTime'], marker='o', linestyle='-', label='Best Case')
plt.title('Execution Time vs Range')
plt.xlabel('Range')
plt.ylabel('Execution Time (seconds)')
plt.grid(True)
plt.legend()
plt.show()
