import matplotlib.pyplot as plt

# Data
elements = [1000, 5000, 10000, 25000, 50000, 75000, 100000]

quicksort_times = [0, 2, 5, 23, 82, 173, 298]
bubblesort_times = [31, 689, 2748, 17241, 68919, 155018, 275990]
shakersort_times = [15, 333, 1320, 8310, 33173, 74428, 132764]

# Plotting
plt.figure(figsize=(10, 6))

# Quicksort
plt.plot(elements, quicksort_times, marker='o', label='Quicksort', linestyle='-')

# Bubblesort
plt.plot(elements, bubblesort_times, marker='o', label='Bubblesort', linestyle='-')

# Shakersort
plt.plot(elements, shakersort_times, marker='o', label='Shakersort', linestyle='-')

plt.xlabel('Number of Elements')
plt.ylabel('Time (ms)')
plt.title('Sorting Algorithm Performance')
plt.legend()
plt.grid(True)

# Big O notation discussion
plt.figure(figsize=(10, 4))
plt.title('Big O Notation')
plt.text(0.5, 0.5, 'Quicksort: O(n log n)\nBubblesort: O(n^2)\nShakersort: O(n^2)', horizontalalignment='center', verticalalignment='center', fontsize=12)
plt.axis('off')

# Show the plots
plt.show()
