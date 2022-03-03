import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
class Pair{
    Integer y, x;
    public Pair(Integer y, Integer x){
        this.y = y;
        this.x = x;
    }
    public Integer first(){
        return this.y;
    }
    public Integer second(){
        return this.x;
    }
}
public class Main {
    static int N, Start, End, answer = 1000000000;
    static boolean[] visited = new boolean[100001];
    static ArrayList<Pair>[] graph;
    public static void dfs(int cur, int sum, int max_w){
        if(cur == End){
            answer = sum - max_w;
            return;
        }
        visited[cur] = true;
        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur].get(i).first();
            int nextCost = sum + graph[cur].get(i).second();
            if(visited[next] == false){
                dfs(next, nextCost, Math.max(max_w, graph[cur].get(i).second()));
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        Start = Integer.parseInt(st.nextToken());
        End = Integer.parseInt(st.nextToken());
        graph = new ArrayList[N + 1];
        for(int i = 0; i < N + 1; i++)
            graph[i] = new ArrayList<>();
        for(int i = 0; i < N - 1; i++){
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            graph[s].add(new Pair(e, d));
            graph[e].add(new Pair(s, d));
        }
        dfs(Start, 0, 0);
        System.out.println(answer);
    }
}