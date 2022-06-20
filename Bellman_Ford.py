#class graph
class Graph:

	#pembuatan graph dengan argumen banyaknya vertex
	def __init__(self, vertices):
		self.V = vertices #banyaknya vertex
		self.graph = [] #graph

	#fungsi pembuatan edge
	#u = vertex asal, v = vertex tujuan, w = weight
	def addEdge(self, u, v, w): 
		self.graph.append([u, v, w])
		
	#fungsi print dataset jarak
	def printArr(self, dist):
		print("Jarak ke tiap vertex:\n")
		print("\tVertex\t  |\tJarak")
		print("\t----------------------")
		for i in range(self.V):
			print("\t  {0}\t  |\t  {1}".format(i, dist[i]))
	
	# fungsi algoritma bellmanford
	# argumen berisi vertex asal
	def BellmanFord(self, src):
		# menyiapkan dataset jarak dan mengisinya dengan tak hingga (infinity) 
		dist = [float("Inf")] * self.V
		dist[src] = 0 #terkecuali, vertex asal diisi dengan 0


		# iterasi maksimal n-1 kali
		for _ in range(self.V - 1):
			# Update dataset jarak dengan jarak vertex yang ditraverse ditambah edge ke v
			for u, v, w in self.graph:
				if dist[u] != float("Inf") and dist[u] + w < dist[v]:
						dist[v] = dist[u] + w
						
		# print dataset jarak
		self.printArr(dist)

g = Graph(6)
g.addEdge(0, 1, 1)
g.addEdge(0, 3, 2)
g.addEdge(1, 2, 1)
g.addEdge(2, 4, 1)
g.addEdge(2, 5, 2)
g.addEdge(3, 1, 4)
g.addEdge(3, 4, 3)
g.addEdge(4, 5, 1)

# Print jawaban
g.BellmanFord(0)