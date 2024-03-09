import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file into a DataFrame
df = pd.read_csv('C:\\Users\\Dell\\OneDrive - Aakash Educational Services Ltd\\Desktop\\4th SEM\\output\\shortest_paths.csv')

# Plot the data
plt.figure(figsize=(10, 6))
plt.plot(df['Vertex'], df['Distance'], marker='o', linestyle='-')
plt.title('Shortest Paths from Source Vertex')
plt.xlabel('Vertex')
plt.ylabel('Distance')
plt.grid(True)
plt.savefig('shortest_paths.png')  # Save the plot as an image
plt.show()
