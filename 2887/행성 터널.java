import java.io.*;
import java.util.*;

class Edge implements Comparable<Edge>{
    int idx1, idx2;
    long dist;
    public Edge(int idx1, int idx2, long dist) {
        this.idx1 = idx1;
        this.idx2 = idx2;
        this.dist = dist;
    }

    @Override
    public int compareTo(Edge e) {
        if(this.dist < e.dist){
            return -1;
        }
        else if(this.dist > e.dist){
            return 1;
        }
        return 0;
    }
}
class Planet {
    int idx;
    int point;
    public Planet(int idx, int point){
        this.idx = idx;
        this.point = point;
    }
}
public class Main{
    public static int N;
    public static long answer;
    public static Planet[] x, y, z;
    public static int parents[];
    public static void _union(int a, int b){
        a = getParent(a);
        b = getParent(b);
        if(a < b)
            parents[b] = a;
        else
            parents[a] = b;
    }
    public static int getParent(int a){
        if(a == parents[a]){
            return a;
        }
        return parents[a] = getParent(parents[a]);
    }
    public static boolean find(int a, int b){
        a = getParent(a);
        b = getParent(b);
        if(a == b)
            return true;
        else
            return false;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        List<Edge> edges = new ArrayList<>();
        x = new Planet[N];  y = new Planet[N]; z = new Planet[N];
        parents = new int[N + 1];
        for(int i = 0; i < N; i++){
            parents[i] = i;
        }
        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            x[i] = new Planet(i, Integer.parseInt(st.nextToken()));
            y[i] = new Planet(i, Integer.parseInt(st.nextToken()));
            z[i] = new Planet(i, Integer.parseInt(st.nextToken()));
        }
        Arrays.sort(x, (p1, p2) -> p1.point - p2.point);
        for(int i = 0; i < N - 1; i++){
            edges.add(new Edge(x[i].idx, x[i + 1].idx, Math.abs(x[i].point - x[i + 1].point)));
        }
        Arrays.sort(y, (p1, p2) -> p1.point - p2.point);
        for(int i = 0; i < N - 1; i++){
            edges.add(new Edge(y[i].idx, y[i + 1].idx, Math.abs(y[i].point - y[i + 1].point)));
        }
        Arrays.sort(z, (p1, p2) -> p1.point - p2.point);
        for(int i = 0; i < N - 1; i++){
            edges.add(new Edge(z[i].idx, z[i + 1].idx, Math.abs(z[i].point - z[i + 1].point)));
        }
        Collections.sort(edges);
        for(Edge e : edges){
            if(!find(e.idx1, e.idx2)){
                _union(e.idx1, e.idx2);
                answer += e.dist;
            }
        }
        System.out.println(answer);
    }
}