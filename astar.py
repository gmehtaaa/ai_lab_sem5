import tkinter as tk
import math
import heapq
import time

def a_star(grid, start, goal):
    rows, cols = len(grid), len(grid[0])
    moves = [(-1, 0, 1), (1, 0, 1), (0, -1, 1), (0, 1, 1),
             (-1, -1, 1.5), (-1, 1, 1.5), (1, -1, 1.5), (1, 1, 1.5)]
    
    def h(a, b):
        return math.dist(a, b)

    open_set = [(h(start, goal), 0, start, [start])]
    seen = set()

    while open_set:
        f, g, node, path = heapq.heappop(open_set)
        if node in seen:
            continue
        seen.add(node)
        if node == goal:
            return path, g
        for dx, dy, cost in moves:
            nx, ny = node[0] + dx, node[1] + dy
            if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny] == 1:
                if (nx, ny) not in seen:
                    new_g = g + cost
                    heapq.heappush(open_set, (new_g + h((nx, ny), goal), new_g, (nx, ny), path + [(nx, ny)]))
    return None, float('inf')

def visualize(grid, path, start, goal):
    rows, cols = len(grid), len(grid[0])
    size = 60
    root = tk.Tk()
    root.title("A* Path Visualization")
    root.lift()
    root.attributes('-topmost', True)
    root.after_idle(root.attributes, '-topmost', False)
    canvas = tk.Canvas(root, width=cols*size, height=rows*size)
    canvas.pack()
    for i in range(rows):
        for j in range(cols):
            canvas.create_rectangle(j*size, i*size, (j+1)*size, (i+1)*size,
                                    fill="blue" if grid[i][j] == 0 else "white", outline="black")
    for (i, j) in path:
        canvas.create_rectangle(j*size, i*size, (j+1)*size, (i+1)*size, fill="green", outline="black")
        root.update()
        time.sleep(0.2)
    si, sj = start
    gi, gj = goal
    canvas.create_rectangle(sj*size, si*size, (sj+1)*size, (si+1)*size, fill="yellow", outline="black")
    canvas.create_text(sj*size + size//2, si*size + size//2, text="S", font=("Arial", 16, "bold"))
    canvas.create_rectangle(gj*size, gi*size, (gj+1)*size, (gi+1)*size, fill="red", outline="black")
    canvas.create_text(gj*size + size//2, gi*size + size//2, text="E", font=("Arial", 16, "bold"))
    root.mainloop()

if __name__ == "__main__":
    n, m = map(int, input("Enter grid size (rows cols): ").split())
    grid = [list(map(int, input().split())) for _ in range(n)]
    sx, sy = map(int, input("Enter start position (row col): ").split())
    gx, gy = map(int, input("Enter goal position (row col): ").split())
    path, cost = a_star(grid, (sx, sy), (gx, gy))
    if path:
        print("Path found:", path)
        print("Minimum cost:", cost)
        visualize(grid, path, (sx, sy), (gx, gy))
    else:
        print("No path found.")
