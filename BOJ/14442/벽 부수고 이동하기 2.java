import java.io.*;
import java.util.*;

public class Main {
  static int N, M, K;
  static char[][] arr;
  static boolean[][][] visit;
  static int[] dr = {1, 0, -1, 0};
  static int[] dc = {0, 1, 0, -1};
  static boolean inRange(int r, int c){
    return 0 <= r && 0 <= c && r < N && c < M;
  }
  static boolean canBreak(int r, int c, int broken){
    if(arr[r][c] == '0') return false;
    else if(broken >= K) return false;
    return true;
  }
  static int bfs(int row, int col){
    Queue<int[]> q = new ArrayDeque<>();
    int bk = 0, nextbk = 0, r, c, nr, nc, cnt;
    q.add(new int[]{row, col, bk, 1}); //row, col, 벽 부순 횟수, 경로
    while(!q.isEmpty()){
      int[] temp = q.poll();
      r = temp[0];
      c = temp[1];
      bk = temp[2];
      cnt = temp[3];
      if(r == N - 1 && c == M - 1) return cnt;
      for(int i = 0; i < 4; i++){
        nr = r + dr[i];
        nc = c + dc[i];
        nextbk = bk + 1;
        if(!inRange(nr, nc)) continue;
        if(arr[nr][nc] == '0' && visit[nr][nc][bk] == false){
          visit[nr][nc][bk] = true;
          q.add(new int[]{nr, nc, bk, cnt + 1});
        }
        else if(canBreak(nr, nc, bk) && visit[nr][nc][nextbk] == false){
          visit[nr][nc][nextbk] = true;
          q.add(new int[]{nr, nc, nextbk, cnt + 1});
        }
      }
    }
    return -1;
  }
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken()); M = Integer.parseInt(st.nextToken()); K = Integer.parseInt(st.nextToken());
    arr = new char[N][M];
    visit = new boolean[N][M][K + 1];
    for(int i = 0; i < N; i++){
      String str = br.readLine();
      for(int j = 0; j < M; j++){
        arr[i][j] = str.charAt(j);
      }
    }
    //input end
    System.out.println(bfs(0, 0));
  }
}