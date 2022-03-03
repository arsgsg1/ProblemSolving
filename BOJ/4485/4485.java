import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
class Node{
    public int r, c;
    public Node(int r, int c){
        this.r = r;
        this.c = c;
    }
}
public class Main {
    static int arr[][] = new int[126][126];
    final static int[] dirRow = {1, 0, -1, 0};
    final static int[] dirCol = {0, 1, 0, -1};
    static int N;
    public static void bfs(int [][] dist){
        int r, c, nr, nc;
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(0, 0));
        dist[0][0] = arr[0][0];
        while(!q.isEmpty()){
            Node n = q.poll();
            r = n.r; c = n.c;
            for(int i = 0; i < 4; i++){
                nr = r + dirRow[i];
                nc = c + dirCol[i];
                if(nr < 0 || nc < 0 || nr >= N || nc >= N)
                    continue;
                int nextCost = dist[r][c] + arr[nr][nc];
                if(dist[nr][nc] > nextCost){
                    q.add(new Node(nr, nc));
                    dist[nr][nc] = nextCost;
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        int T = 1, answer = 0, dist[][];
        while(true) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            if(N == 0) break;
            dist = new int[N][N];

            for(int i = 0; i < N; i++)
                for(int j = 0; j < N; j++)
                    dist[i][j] = 987654321;

            for(int i = 0; i < N; i++){
                st = new StringTokenizer(br.readLine());
                for(int j = 0; j < N; j++){
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            bfs(dist);
            answer = dist[N - 1][N - 1];
            System.out.println("Problem " + T++ + ": " + answer);
        }
    }
}