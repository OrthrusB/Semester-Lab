def bfs(graph, start_node, goal_node):
    visited = set()
    queue = [[start_node]]
    
    if start_node == goal_node:
        return [start_node]
    
    while queue:
        path = queue.pop(0)
        node = path[-1]
        
        if node not in visited:
            visited.add(node)
            for neighbour in graph[node]:
                new_path = list(path)
                new_path.append(neighbour)
                queue.append(new_path)
                if neighbour == goal_node:
                    return new_path
    
    return None


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
goal_node = 11

path = bfs(graph, start_node, goal_node)
print("Path from", start_node, "to", goal_node, ":", path)
