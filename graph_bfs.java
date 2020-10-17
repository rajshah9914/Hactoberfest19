import java.io.*;
import java.util.*;

t
    static void DFS(Graph graph,boolean visited[],int s){
        
        visited[s]=true;
        System.out.print(s+" ");

        for(Node t:graph.ar[s]){
            if(!visited[t.getDest()])
            {
                DFS(graph,visited,t.getDest());
            }
        }
        return;
    }
    static void BFS(Graph graph,int s){
        Queue <Integer> q=new LinkedList<Integer>();
        int y;
        
        boolean visited[] = new boolean[graph.v+1];        
        visited[s]=true;

        q.add(s);
        while(!q.isEmpty()){
            s=q.poll();
            System.out.print(s+" ");
            for(Node t:graph.ar[s]){
                if(!visited[t.getDest()])
                {
                    visited[t.getDest()]=true;
                    q.add(t.getDest());
                }
            }
        }
    }
}
class TestClass{
    public static void main(String args[])throws Exception{
        Scanner sc=new Scanner(System.in);
        System.out.println("How many vertices : ");
        int n=sc.nextInt();
        Graph graph=new Graph(n);
        for(int i=0;i<n;i++)
        {
            System.out.println("Enter the Src and Destination with weight:");
            graph.addEdge(graph,sc.nextInt(),sc.nextInt(),sc.nextInt());
        }
        graph.print(graph);
        boolean visited[]=new boolean[graph.v+1];
        System.out.println("Enter the num from which u want dfs :");
        int d=sc.nextInt();
        System.out.println("BFS :");
        graph.BFS(graph,d);
        System.out.println();
        System.out.println("DFS :");
        graph.DFS(graph,visited,d);
    }
}