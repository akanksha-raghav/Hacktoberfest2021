import java.util.Scanner;
import java.util.Arrays;

class Node{
    int val;
    int weight;
    Node next;

    public Node(int val,int weight){
        this.val = val;
        this.weight = weight;
        this.next = null;
    }
}

class Graph{

    public Node[] CreateGraph(int n){
        Node[] Graph = new Node[n];
        return Graph;
    }

    /* This Function adds Edge between the Source and Destination */

    public void AddEdge(Node[] Graph,int src,int dest,int weight){


        if(Graph[src] == null){

            Graph[src] = new Node(dest,weight);
            return;

        }

        else{

            Node temp = new Node(dest,weight);

            temp.next = Graph[src];

            Graph[src] = temp;

        }

    }

    /* This Function returns the Index of the Node that has the Least Shortest Distance and is UnVisited. */

    public int MinIndex(int[] dist,boolean[] visited){
        int min = Integer.MAX_VALUE;
        int min_index = -1;

        for(int i = 0;i<dist.length;i++){

            if(!visited[i] && min > dist[i]){
                min = dist[i];
                min_index = i;
            }
        }

        return min_index;
    }

}


public class djikstra {
    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);

        Graph g = new Graph();


        System.out.print("Enter the Number of Nodes in the Graph : ");

        int num = scan.nextInt();

        Node[] Graph = g.CreateGraph(num);

        System.out.print("Enter the Total Number of Edges in the Graph : ");

        int edges = scan.nextInt();

        System.out.println("Now Enter all the Edges as Source Destination Weight");

        /* Storing the edges */

        for(int i = 0;i<edges;i++){
            int src = scan.nextInt();
            int dest = scan.nextInt();
            int weight = scan.nextInt();

            g.AddEdge(Graph, src, dest, weight);
            g.AddEdge(Graph, dest, src, weight);

        }

        System.out.print("Enter the Node from where you want to find the Shortest Distance to all the other Nodes : ");

        int start = scan.nextInt();

        /* Distance Array Which Stores the Shortest Distance from the Given Node to all other Nodes */

        int[] dist = new int[num];

        /* Boolean Array which stores whether a Node is Visited or Not */

        boolean[] visited = new boolean[num];

        /* Initialize all the Distances to MAX Values. */

        Arrays.fill(dist, Integer.MAX_VALUE);

        /* Initialize the Shortest Distance to reach the Start Node to 0 */

        dist[start] = 0;

        while(true){

            /* At Every Iteration Find the Node that has the least Shortest Distance Value and is Unvisited. */

            int min_index = g.MinIndex(dist, visited);

            /* If you haven't found any Node that has Shortest Distance and Unvisted then exit the loop */

            if(min_index == -1){
                break;
            }

            /* Mark the Node as Visited. */

            visited[min_index] = true;

            Node temp = Graph[min_index];

            /* Now Iterate over all it's Neighbours and update the values if the 
            (Shortest Distance to this Node) + (Edge Weight between this Node and Neighouring Node) 
            is less than the Shortest Distance to the neighbour in Distance Array  */

            while(temp != null){

                if(dist[temp.val] > dist[min_index] + temp.weight && !visited[temp.val]){
                    dist[temp.val] = dist[min_index] + temp.weight;
                }

                temp = temp.next;

            }
        }

        /* Printing the Shortest Distances from the Start Node to all the other Nodes */

        for(int i = 0;i<num;i++){
            System.out.print(dist[i] + " ");
        }

        System.out.println("");


        scan.close();

    }
}
