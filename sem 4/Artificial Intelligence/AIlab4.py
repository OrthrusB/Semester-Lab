# #A*
# import heapq

# graph = {
#     'Arad': {'Zerind': 75, 'Timisoara': 118, 'Sibiu': 140},
#     'Zerind': {'Arad': 75, 'Oradea': 71},
#     'Oradea': {'Zerind': 71, 'Sibiu': 151},
#     'Timisoara': {'Arad': 118, 'Lugoj': 111},
#     'Lugoj': {'Timisoara': 111, 'Mehadia': 70},
#     'Mehadia': {'Lugoj': 70, 'Drobeta': 75},
#     'Drobeta': {'Mehadia': 75, 'Craiova': 120},
#     'Craiova': {'Drobeta': 120, 'Rimnicu Vilcea': 146, 'Pitesti': 138},
#     'Sibiu': {'Arad': 140, 'Oradea': 151, 'Fagaras': 99, 'Rimnicu Vilcea': 80},
#     'Rimnicu Vilcea': {'Sibiu': 80, 'Craiova': 146, 'Pitesti': 97},
#     'Fagaras': {'Sibiu': 99, 'Bucharest': 211},
#     'Pitesti': {'Rimnicu Vilcea': 97, 'Craiova': 138, 'Bucharest': 101},
#     'Bucharest': {'Fagaras': 211, 'Pitesti': 101, 'Giurgiu': 90, 'Urziceni': 85},
#     'Giurgiu': {'Bucharest': 90},
#     'Urziceni': {'Bucharest': 85, 'Hirsova': 98, 'Vaslui': 142},
#     'Hirsova': {'Urziceni': 98, 'Eforie': 86},
#     'Eforie': {'Hirsova': 86},
#     'Vaslui': {'Urziceni': 142, 'Iasi': 92},
#     'Iasi': {'Vaslui': 92, 'Neamt': 87},
#     'Neamt': {'Iasi': 87}
# }


# heuristic = {
#     'Arad': 366, 'Zerind': 374, 'Oradea': 380, 'Timisoara': 329,
#     'Lugoj': 244, 'Mehadia': 241, 'Drobeta': 242, 'Craiova': 160,
#     'Sibiu': 253, 'Rimnicu Vilcea': 193, 'Fagaras': 178, 'Pitesti': 98,
#     'Bucharest': 0, 'Giurgiu': 77, 'Urziceni': 80, 'Hirsova': 151,
#     'Eforie': 161, 'Vaslui': 199, 'Iasi': 226, 'Neamt': 234
# }

# def a_star_search(graph, start, goal):
#     # Priority queue to hold the nodes to explore
#     open_list = []
#     heapq.heappush(open_list, (0 + heuristic[start], 0, start, []))
#     # Set to hold explored nodes
#     closed_list = set()

#     while open_list:
        
#         _, cost, current_node, path = heapq.heappop(open_list)

#         if current_node in closed_list:
#             continue

#         # Add current node to the closed list
#         closed_list.add(current_node)

#         # Path to current node
#         path = path + [current_node]

#         # Check if we have reached the goal
#         if current_node == goal:
#             return path, cost

        
#         for neighbor, distance in graph[current_node].items():
#             if neighbor not in closed_list:
#                 total_cost = cost + distance
#                 heapq.heappush(open_list, (total_cost + heuristic[neighbor], total_cost, neighbor, path))

#     return None, None

# # Execute A* search from Arad to Bucharest
# path, cost = a_star_search(graph, 'Arad', 'Bucharest')
# print("Optimal Path:", path)
# print("Total Cost:", cost)


#Best first search
import heapq

# Define the graph as an adjacency list
graph = {
    'Arad': [('Zerind', 75), ('Sibiu', 140), ('Timisoara', 118)],
    'Zerind': [('Oradea', 71), ('Arad', 75)],
    'Oradea': [('Sibiu', 151), ('Zerind', 71)],
    'Sibiu': [('Oradea', 151), ('Arad', 140), ('Fagaras', 99), ('Rimnicu Vilcea', 80)],
    'Timisoara': [('Arad', 118), ('Lugoj', 111)],
    'Lugoj': [('Timisoara', 111), ('Mehadia', 70)],
    'Mehadia': [('Lugoj', 70), ('Drobeta', 75)],
    'Drobeta': [('Mehadia', 75), ('Craiova', 120)],
    'Craiova': [('Drobeta', 120), ('Rimnicu Vilcea', 146), ('Pitesti', 138)],
    'Rimnicu Vilcea': [('Sibiu', 80), ('Craiova', 146), ('Pitesti', 97)],
    'Fagaras': [('Sibiu', 99), ('Bucharest', 211)],
    'Pitesti': [('Rimnicu Vilcea', 97), ('Craiova', 138), ('Bucharest', 101)],
    'Bucharest': [('Fagaras', 211), ('Pitesti', 101), ('Giurgiu', 90), ('Urziceni', 85)],
    'Giurgiu': [('Bucharest', 90)],
    'Urziceni': [('Bucharest', 85), ('Hirsova', 98), ('Vaslui', 142)],
    'Hirsova': [('Urziceni', 98), ('Eforie', 86)],
    'Eforie': [('Hirsova', 86)],
    'Vaslui': [('Urziceni', 142), ('Iasi', 92)],
    'Iasi': [('Vaslui', 92), ('Neamt', 87)],
    'Neamt': [('Iasi', 87)],
}

# Define the straight-line distances to Bucharest
straight_line_distances = {
    'Arad': 366,
    'Bucharest': 0,
    'Craiova': 160,
    'Drobeta': 242,
    'Eforie': 161,
    'Fagaras': 176,
    'Giurgiu': 77,
    'Hirsova': 151,
    'Iasi': 226,
    'Lugoj': 244,
    'Mehadia': 241,
    'Neamt': 234,
    'Oradea': 380,
    'Pitesti': 100,
    'Rimnicu Vilcea': 193,
    'Sibiu': 253,
    'Timisoara': 329,
    'Urziceni': 80,
    'Vaslui': 199,
    'Zerind': 374,
}

def greedy_best_first_search(start, goal):
    # Priority queue to store the nodes to be explored
    priority_queue = []
    heapq.heappush(priority_queue, (straight_line_distances[start], start))
    # Set to keep track of visited nodes
    visited = set()
    # Dictionary to store the path
    came_from = {}

    while priority_queue:
        # Get the node with the smallest heuristic value
        _, current = heapq.heappop(priority_queue)

        # If we reached the goal, reconstruct the path
        if current == goal:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            path.reverse()
            return path

        # Mark the current node as visited
        visited.add(current)

        # Explore the neighbors
        for neighbor, cost in graph[current]:
            if neighbor not in visited:
                heapq.heappush(priority_queue, (straight_line_distances[neighbor], neighbor))
                came_from[neighbor] = current

    return None

# Test the function
start = 'Arad'
goal = 'Bucharest'
path = greedy_best_first_search(start, goal)
print(f"Path from {start} to {goal}: {path}")
