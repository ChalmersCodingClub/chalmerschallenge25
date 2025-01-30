import matplotlib.pyplot as plt

def plot_data_from_file(file_path):
    try:
        # Read the data file
        with open(file_path, 'r') as file:
            lines = file.readlines()

        # Discard the first two lines
        data_lines = lines[2:]

        # Extract x and y values
        x_values = []
        y_values = []

        for line in data_lines:
            try:
                x, y = map(float, line.split())
                x_values.append(x)
                y_values.append(y)
            except ValueError:
                print(f"Skipping invalid line: {line.strip()}")

        # Plot the points
        plt.figure(figsize=(8, 6))
        plt.scatter(x_values, y_values, color='blue', label='Data Points')
        plt.title('Scatter Plot of Data Points')
        plt.xlabel('X')
        plt.ylabel('Y')
        plt.legend()
        plt.grid(True)
        plt.show()

    except FileNotFoundError:
        print(f"Error: File not found at {file_path}")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

# Specify the path to your file here
file_path = 'data.txt'  # Replace with your actual file path
plot_data_from_file("/home/erwinia/Documents/Problemsetting/chalmerschallenge25/problems/bergstoppar/data/secret/group4/019-g4-3.in")
