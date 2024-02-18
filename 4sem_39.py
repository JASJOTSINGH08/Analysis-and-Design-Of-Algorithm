import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
df = pd.read_csv("C:\\Users\\Dell\\OneDrive - Aakash Educational Services Ltd\\Desktop\\4th SEM\\output\\search_ele_execution_times.csv")

# Plot the graph
plt.plot(df["Step"], df["ExecutionTime"], marker='o', linestyle='-')
plt.xlabel("Step")
plt.ylabel("Execution Time (s)")
plt.title("Execution Time vs. Step")
plt.grid(True)
plt.show()
