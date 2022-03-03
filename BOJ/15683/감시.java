import java.io.*;
import java.util.*;

public class Main {

  static int N, M, answer = Integer.MAX_VALUE;
  static int CCTV = 0;
  static int[][] arr;
  static int visit[][];
  static int[] dr = {-1, 0, 1, 0};
  static int[] dc = {0, 1, 0, -1};

  static boolean inRange(int r, int c) {
    return 0 <= r && 0 <= c && r < N && c < M;
  }

  static void Observe(int r, int c, int dir, boolean op) {
    int nr = r, nc = c;
    while (inRange(nr, nc)) {
      if (arr[nr][nc] <= 0 && op == true) //빈 칸이고 감시가 활성화
      {
        arr[nr][nc] -= 1;
      }
      else if (arr[nr][nc] < 0 && op == false) //감시 칸 원복
      {
        arr[nr][nc] += 1;
      }
      else if (arr[nr][nc] == 6) //벽
      {
        break;
      }
      nr += dr[dir];
      nc += dc[dir];
    }
  }

  static void ObserveWithcctvType(int r, int c, int type, int dir, boolean op) {
    if (type == 1) {
      Observe(r, c, dir % 4, op);
    } else if (type == 2) {
      Observe(r, c, dir % 4, op);
      Observe(r, c, (dir + 2) % 4, op);
    } else if (type == 3) {
      Observe(r, c, dir, op);
      Observe(r, c, (dir + 1) % 4, op);
    } else if (type == 4) {
      Observe(r, c, dir, op);
      Observe(r, c, (dir + 1) % 4, op);
      Observe(r, c, (dir + 3) % 4, op);
    } else {
      Observe(r, c, dir, op);
      Observe(r, c, (dir + 1) % 4, op);
      Observe(r, c, (dir + 2) % 4, op);
      Observe(r, c, (dir + 3) % 4, op);
    }
  }

  static void Calculate() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (arr[i][j] == 0) {
          cnt++;
        }
      }
    }
    answer = Math.min(answer, cnt);
  }

  static void dfs(int row, int col, int cnt) {
    if (cnt == 0) {
      Calculate();
      return;
    }
    int r, c = col;
    for (r = row; r < N; r++) {
      for (; c < M; c++) {
        for (int d = 0; d < 4; d++) {
          if (visit[r][c] == 0
              && 1 <= arr[r][c]
              && arr[r][c] <= 5) {
            visit[r][c] = d + 1;
            ObserveWithcctvType(r, c, arr[r][c], d, true);
            dfs(r, c, cnt - 1);
            ObserveWithcctvType(r, c, arr[r][c], d, false);
            visit[r][c] = 0;
          }
        }
      }
      c = 0;
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    arr = new int[N][M];
    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < M; j++) {
        arr[i][j] = Integer.parseInt(st.nextToken());
        if (1 <= arr[i][j] && arr[i][j] <= 5) {
          CCTV++;
        }
      }
    }
    //Input End
    visit = new int[N][M];
    dfs(0, 0, CCTV);
    System.out.println(answer);
  }
}