import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file into a DataFrame
df = pd.read_csv('horner_time_complexity.csv')

# Extract step numbers and time complexity values
steps = df['Step']
time_complexity = df['Time (nanoseconds)']

# Plot the data
plt.plot(steps, time_complexity, marker='o', linestyle='-')
plt.title('Time Complexity of Horner\'s Rule')
plt.xlabel('Step')
plt.ylabel('Time (nanoseconds)')
plt.grid(True)
plt.show()
