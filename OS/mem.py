# First, let's implement a simple memory allocation system that uses the following algorithms:
# - First-Fit
# - Best-Fit
# - Worst-Fit

# We'll also need a way to visualize the memory as a 16x16 grid, with each cell representing a block of memory.

import matplotlib.pyplot as plt
import numpy as np
import matplotlib.colors as mcolors

# Define a class to represent memory block
class MemoryBlock:
    def __init__(self, size, start_address):
        self.size = size
        self.start_address = start_address
        self.is_free = True

# Define a class to manage memory allocation
class MemoryManager:
    def __init__(self, total_memory):
        self.total_memory = total_memory
        self.blocks = [MemoryBlock(total_memory, 0)]  # Start with all memory free

    def allocate(self, size, strategy):
        """
        Allocate memory using the given strategy
        """
        block, index = self.find_block(size, strategy)
        if block:
            # Split the block if it's larger than the requested size
            if block.size > size:
                new_block = MemoryBlock(block.size - size, block.start_address + size)
                self.blocks.insert(index + 1, new_block)
                block.size = size
            block.is_free = False
            return True
        return False

    def deallocate(self, start_address):
        """
        Deallocate memory at the given start address
        """
        for i, block in enumerate(self.blocks):
            if block.start_address == start_address and not block.is_free:
                block.is_free = True
                # Merge with adjacent free blocks
                self.merge()
                return True
        return False

    def find_block(self, size, strategy):
        """
        Find a block of memory to allocate based on the strategy
        """
        if strategy == 'first_fit':
            for i, block in enumerate(self.blocks):
                if block.is_free and block.size >= size:
                    return block, i
        elif strategy == 'best_fit':
            best_block = None
            best_index = -1
            for i, block in enumerate(self.blocks):
                if block.is_free and block.size >= size:
                    if best_block is None or block.size < best_block.size:
                        best_block = block
                        best_index = i
            return best_block, best_index
        elif strategy == 'worst_fit':
            worst_block = None
            worst_index = -1
            for i, block in enumerate(self.blocks):
                if block.is_free and block.size >= size:
                    if worst_block is None or block.size > worst_block.size:
                        worst_block = block
                        worst_index = i
            return worst_block, worst_index
        return None, -1

    def merge(self):
        """
        Merge adjacent free blocks
        """
        i = 0
        while i < len(self.blocks) - 1:
            current_block = self.blocks[i]
            next_block = self.blocks[i + 1]
            if current_block.is_free and next_block.is_free:
                current_block.size += next_block.size
                del self.blocks[i + 1]
            else:
                i += 1

    def visualize_memory(self):
        """
        Visualize the memory blocks
        """
        memory_grid = np.zeros((16, 16))
        current_address = 0
        for block in self.blocks:
            block_value = 0 if block.is_free else 1
            for i in range(block.size):
                row = (current_address + i) // 16
                col = (current_address + i) % 16
                memory_grid[row, col] = block_value
            current_address += block.size
        
        # Create a color map for free and allocated blocks
        cmap = mcolors.ListedColormap(['white', 'black'])
        plt.imshow(memory_grid, cmap=cmap)
        plt.axis('off')
        plt.show()

# Initialize the memory manager with 256 blocks
memory_manager = MemoryManager(256)

# For demonstration, let's allocate and deallocate some memory, and visualize the memory grid.
# We'll use a mix of different strategies.
memory_manager.allocate(7, 'first_fit')
memory_manager.allocate(13, 'first_fit')
memory_manager.allocate(19, 'first_fit')
memory_manager.allocate(11, 'first_fit')
memory_manager.deallocate(13)
# Visualize the memory after these operations
memory_manager.visualize_memory()
