/*
* 물통 용량의 크기가 200 이하이고, 3개이므로 상태 배열로 나타낼 수 있다.
* 각 물통의 용량 상태를 boolean 배열로 관리하며 bfs를 돌려 모든 경우를 탐색할 수 있다.
* */
import java.io.*;
import java.util.*;
class Node{
  int a, b, c;
  public Node(int a, int b, int c){
    this.a = a;
    this.b = b;
    this.c = c;
  }
}
public class Main {
  private static int A, B, C;
  private static boolean[][][] visit = new boolean[201][201][201];
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    A = Integer.parseInt(st.nextToken());
    B = Integer.parseInt(st.nextToken());
    C = Integer.parseInt(st.nextToken());

    Queue<Node> q = new LinkedList<>();
    q.add(new Node(0, 0, C));

    TreeSet<Integer> answer = new TreeSet<>();
    answer.add(C);

    while(!q.isEmpty()){
      int a = q.peek().a;
      int b = q.peek().b;
      int c = q.peek().c;
      q.poll();
      if(visit[a][b][c])
        continue;
      visit[a][b][c] = true;
      if(a == 0) answer.add(c);

      //A -> B
      if(a + b > B) q.add(new Node((a + b - B), B, c));
      else q.add(new Node(0, a + b, c));

      //A -> C
      if(a + c > C) q.add((new Node((a + c - C), b, C)));
      else q.add(new Node(0, b, a + c));

      //B -> A
      if(b + a > A) q.add((new Node(A, (a + b - A), c)));
      else q.add(new Node(a + b, 0, c));
      //B -> C
      if(b + c > C) q.add((new Node(a, (b + c - C), C)));
      else q.add(new Node(a, 0, b + c));
      //C -> A
      if(a + c > A) q.add((new Node(A, b, (a + c - A))));
      else q.add(new Node(a + c, b, 0));
      //C -> B
      if(b + c > B) q.add((new Node(a, B, (b + c - B))));
      else q.add(new Node(a, b + c, 0));
    }
    for (Integer i : answer)
      System.out.print(i + " ");
    System.out.println();
  }
}