def depth_first_search(graph, start_node, goal_node):
    visited = set()
    stack = [[start_node]]
    
    if start_node == goal_node:
        return [start_node]
    
    while stack:
        path = stack.pop()
        node = path[-1]
        
        if node not in visited:
            visited.add(node)
            
            for neighbour in graph[node]:
                new_path = list(path)
                new_path.append(neighbour)
                stack.append(new_path)
                
                if neighbour == goal_node:
                    return new_path
    
    return None

# Define the graph and nodes outside the function
graph = {
    1: [2, 3, 4],
    2: [5, 6],
    3: [],
    4: [7, 8],
    5: [9, 10],
    6: [],
    7: [11, 12],
    8: [],
    9: [],
    10: [],
    11: [],
    12: []
}

start_node = 1
goal_node = 12

path = depth_first_search(graph, start_node, goal_node)
print("Path from", start_node, "to", goal_node, ":", path)
