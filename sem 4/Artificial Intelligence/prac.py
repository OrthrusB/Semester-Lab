def bfs(graph, start_node, goal_node):
    visited = set()  # Set for visited nodes to avoid repetition
    queue = [[start_node]]  # Initialize a queue with the start node as the initial path

    if start_node == goal_node:
        return [start_node]

    while queue:
        # Get the first path from the queue
        path = queue.pop(0)
        # Get the last node from the path
        node = path[-1]

        if node == goal_node:
            return path
        
        # If the node hasn't been visited, iterate over its neighbors
        if node not in visited:
            visited.add(node)
            for neighbour in graph.get(node, []):
                new_path = list(path)
                new_path.append(neighbour)
                queue.append(new_path)
                print('->'.join(new_path))
    
    return None

graph = {
    '1': ['2', '3'],
    '2': ['4', '5'],
    '3': ['6','7'],
    '4': ['8','9'],
    '5': ['10','11'],
    '6':[],
    '7' :['12','13'],
    '8': [], '9': [], '10': [], '11': [], '12': [], '13': []
}

start_node = '1'
goal_node = '13'
print("Following is the Breadth-First Search path:")
path = bfs(graph, start_node, goal_node)
if path:
    print("Path found:", '->'.join(path))
else:
    print("No path found")
