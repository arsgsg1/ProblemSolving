import java.util.*;
class Solution {
  static int From, To;
  static boolean[] visit;
  static HashMap<Integer, List<Integer>> graph = new HashMap<>();

  static int bfs(int start) {
    int cnt = 1;
    Queue<Integer> q = new ArrayDeque<>();
    q.add(start);
    visit[start] = true;
    while (!q.isEmpty()) {
      int cur = q.poll();
      for (int next : graph.get(cur)) {
        if ((cur == From && next == To) ||
            (cur == To && next == From)) {
          continue;
        }
        if (visit[next] == false) {
          visit[next] = true;
          q.add(next);
          cnt++;
        }
      }
    }
    return cnt;
  }

  public int solution(int n, int[][] wires) {
    int answer = Integer.MAX_VALUE;
    //그래프 구성
    for (int i = 1; i <= n; i++) {
      graph.put(i, new ArrayList<>());
    }
    for (int i = 0; i < wires.length; i++) {
      int from = wires[i][0];
      int to = wires[i][1];
      graph.get(from).add(to);
      graph.get(to).add(from);
    }
    //엣지 하나씩 제거
    int A, B;
    for (int i = 0; i < wires.length; i++) {
      From = wires[i][0];
      To = wires[i][1];
      visit = new boolean[n + 1];
      A = -1;
      B = -1;
      for (int j = 1; j <= n; j++) {
        if (visit[j] == false) {
          if (A < 0) {
            A = bfs(j);
          } else if (B < 0) {
            B = bfs(j);
          }
        }
      }
      answer = Math.min(answer, Math.abs(A - B));
    }
    return answer;
  }
}