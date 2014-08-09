#Topological Sorting

The goal of topological sorting is to be able to process the vertices of a DAG (Directed Acyclic Graph) in a way that every vertex
is processed before all the vertices to which it points.


#DFS
It turns out that a standard recursive DFS can be used for reverse topological sorting.
A postoder numbering puts the vertices in reverse topological order.

#IN-DEGREES
An alternative is topologically sorting a DAG by removing sources.