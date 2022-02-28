import java.io.*;
import java.util.*;

public class Main {
  static int N, M, K;
  static char[][] arr;
  static boolean[][][] visit; //row, col, 벽 부순횟수
  static int[] dr = {1, 0, -1, 0};
  static int[] dc = {0, 1, 0, -1};
  static boolean inRange(int r, int c){
    return 0 <= r && 0 <= c && r < N && c < M;
  }
  static boolean canBreak(int r, int c, int broken, int day){
    if(arr[r][c] == '0') return false; //빈 칸
    else if(broken >= K) return false; //부순 횟수 초과
    else if(day == 1) return false; //밤이면 못부숨
    return true;
  }
  static int bfs(int row, int col){
    Queue<int[]> q = new LinkedList<>();
    int r, c, nr, nc, nextbk, bk = 0, cnt = 1, day = 0, nextday;
    q.add(new int[]{row, col, cnt, bk, day});
    visit[row][col][bk] = true;
    while(!q.isEmpty()){
      int[] temp = q.poll();
      r = temp[0];
      c = temp[1];
      cnt = temp[2];
      bk = temp[3];
      day = temp[4];
      nextday = (day + 1) % 2;
      nextbk = bk + 1;
      if(r == N - 1 && c == M - 1) return cnt;
      if(day == 1){
        visit[r][c][bk] = true;
        q.add(new int[]{r, c, cnt + 1, bk, nextday});
      }
      for(int i = 0; i < 4; i++){
        nr = r + dr[i];
        nc = c + dc[i];
        if(!inRange(nr, nc)) continue;

        if(arr[nr][nc] == '0' && visit[nr][nc][bk] == false){
          visit[nr][nc][bk] = true;
          q.add(new int[]{nr, nc, cnt + 1, bk, nextday});
        }
        else if(canBreak(nr, nc, bk, day) && visit[nr][nc][nextbk] == false){
          visit[nr][nc][nextbk] = true;
          q.add(new int[]{nr, nc, cnt + 1, nextbk, nextday});
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