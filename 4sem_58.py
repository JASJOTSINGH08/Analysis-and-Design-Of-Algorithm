import matplotlib.pyplot as plt
import pandas as pd

# Read the CSV file
df = pd.read_csv('C:\\Users\\Dell\\OneDrive - Aakash Educational Services Ltd\\Desktop\\4th SEM\\output\\activity_selection_execution_times.csv')

# Extract data from the DataFrame
start_times = df['Start']
finish_times = df['Finish']
execution_times = df['ExecutionTime']

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(finish_times, execution_times, marker='o', linestyle='-')
plt.title('Execution Time vs. Finish Time')
plt.xlabel('Finish Time')
plt.ylabel('Execution Time (seconds)')
plt.grid(True)
plt.tight_layout()

# Save the plot as an image or show it
plt.savefig('execution_time_vs_finish_time.png')
plt.show()
