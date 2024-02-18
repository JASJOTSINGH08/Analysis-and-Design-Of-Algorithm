#connected to 4sem_28.cpp
import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file into a pandas DataFrame
df = pd.read_csv('C:\\Users\\Dell\\OneDrive - Aakash Educational Services Ltd\\Desktop\\4th SEM\\output\\magic_square_execution_times.csv')

# Print the DataFrame to check data
print(df.head())

# Plot the graph
plt.plot(df['Step'], df['Execution Time'], marker='o', linestyle='-')
plt.xlabel('Step')
plt.ylabel('Execution Time (seconds)')
plt.title('Execution Time vs. Step for Magic Square')
plt.grid(True)
plt.show()
