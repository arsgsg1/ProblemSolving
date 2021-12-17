import java.io.*;
import java.util.*;
/*
다익스트라를 구성할 때 인접 리스트로 사용할 자료구조로 어떤 것을 선택할 지 숙지할 것.
자바 우선순위 큐에서 정렬 순서를 어떻게 설정할 수 있는지
* */
class Pair implements Comparable<Pair>{
  public int first, second;
  public Pair(int first, int second){
    this.first = first;
    this.second = second;
  }

  @Override
  public int compareTo(Pair o) {
    if(this.first > o.first)
      return 1;
    else if(this.first < o.first)
      return -1;
    else
      return 0;
  }
}
public class Main {
  public static final int INF = 987654321;
  public static int N, E, v1, v2, answer;
  public static HashMap<Integer, HashMap<Integer, Integer>> graph = new HashMap<>();
  public static int[] dijkstra(int Start, int End){
    int dist[] = new int[N + 1], cur, cost;
    for(int i = 0; i < dist.length; i++)
      dist[i] = INF;

    Queue<Pair> q = new PriorityQueue<>();
    q.add(new Pair(0, Start));
    dist[Start] = 0;

    while(!q.isEmpty()){
      Pair p = q.poll();
      cur = p.second;
      cost = p.first;
      if(cost > dist[cur]) continue; //더 빠른길을 알고 있다면
      if(!graph.containsKey(cur)) continue;
      HashMap<Integer, Integer> m = graph.get(p.second);
      for(Integer next : m.keySet()){
        int nextCost = m.get(next).intValue() + dist[cur];
        if(nextCost < dist[next]){
          dist[next] = nextCost;
          q.add(new Pair(nextCost, next));
        }
      }
    }
    return dist;
  }
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken()); E = Integer.parseInt(st.nextToken());
    for(int i = 0; i < E; i++){
      st = new StringTokenizer(br.readLine());
      int s = Integer.parseInt(st.nextToken());
      int e = Integer.parseInt(st.nextToken());
      int d = Integer.parseInt(st.nextToken());
      if(!graph.containsKey(s))
        graph.put(s, new HashMap<>(){{put(e, d);}});
      else if(!graph.get(s).containsKey(e) || graph.get(s).get(e).intValue() > d)
        graph.get(s).put(e, d);

      if(!graph.containsKey(e))
        graph.put(e, new HashMap<>(){{put(s, d);}});
      else if(!graph.get(e).containsKey(s) || graph.get(e).get(s).intValue() > d)
        graph.get(e).put(s, d);
    }
    st = new StringTokenizer(br.readLine());
    v1 = Integer.parseInt(st.nextToken());
    v2 = Integer.parseInt(st.nextToken());
    int[] d, d1, d2;
    d = dijkstra(1, N);
    d1 = dijkstra(v1, N);
    d2 = dijkstra(v2, N);
    answer = Math.min(d[v1] + d1[v2] + d2[N], d[v2] + d2[v1] + d1[N]);
    if (answer >= INF || answer < 0) {
      System.out.println(-1);
    }
    else{
      System.out.println(answer);
    }
  }
}