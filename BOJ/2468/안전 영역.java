import java.io.*;
import java.util.*;
//1차: MLE, 2차: 방문 배열 boolean으로 실패

public class Main {
  static int N;
  static int[][] arr;
  static boolean[][] visit;
  static int[] dr = {1, 0, -1, 0};
  static int[] dc = {0, 1, 0, -1};
  static boolean inRange(int r, int c){
    return 0 <= r && 0 <= c && r < N && c < N;
  }
  static boolean canVisit(int r, int c, int h){
    return visit[r][c] == false && arr[r][c] > h;
  }
  static void bfs(int row, int col, int h){
    Queue<int[]> q = new ArrayDeque<>();
    q.add(new int[]{row, col});
    visit[row][col] = true;
    int r, c, nr, nc;
    while(!q.isEmpty()){
      int[] tmp = q.poll();
      r = tmp[0]; c = tmp[1];
      for(int i = 0; i < 4; i++){
        nr = r + dr[i];
        nc = c + dc[i];
        if(!inRange(nr, nc)) continue;
        if(canVisit(nr, nc, h)){
          q.add(new int[]{nr, nc});
          visit[nr][nc] = true;
        }
      }
    }
  }
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    arr = new int[N][N];
    for(int i = 0; i < N; i++){
      st = new StringTokenizer(br.readLine());
      for(int j = 0; j < N; j++){
        arr[i][j] = Integer.parseInt(st.nextToken());
      }
    }
    //input end
    int answer = 0;
    for(int h = 0; h <= 100; h++){
      visit = new boolean[N][N];
      int cnt = 0;
      for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
          if(canVisit(r, c, h)){
            bfs(r, c, h);
            cnt++;
          }
        }
      }
      answer = Math.max(answer, cnt);
    }
    System.out.println(answer);
  }
}